<?php

/**
 * https://github.com/DoSomething/dosomething/issues/3414
 *
 * Based on a redirect CSV formatted like this:
 *
 * https://gist.github.com/mshmsh5000/23f284dc3a2b3d2565eb
 *
 * 1. Look up the beta canonical path for each row.
 * 2. Create a unique row for every source-alias pair in legacy.
 *    -- REVISED: Every source on our list has only one alias.
 * 3. Output updated data to a new CSV.
 *
 *
 * REQUIREMENTS:
 *
 * 1. You need both 'default' and 'legacy' DB targets defined in your settings.
 *
 * Example: https://gist.github.com/mshmsh5000/b763c566ca66662c505b
 *
 * 2. $DATA_FILE needs to point to your CSV. Path is relative to docroot.
 *
 * 3. $OUTPUT_FILE needs to a path to a non-existing file. This script will
 *    generate $OUTPUT_FILE. The parent directory must be writable by the
 *    process owner running this script.
 *
 * 4. Execute like this:
 *
 *    drush --script-path=../scripts/ php-script 3414-redirect-reconciliation.php
 */

$DATA_FILE = '../scripts/redirects.csv';
$HAS_COLUMN_HEADERS = true; // If true, skip the first row.

$OUTPUT_FILE = '../scripts/redirects.processed.csv';

$urls = array();
$count = 0;

// This will hold processed contents, to be written to $OUTPUT_FILE.
$processed = array();

if (FALSE !== ($fh = fopen($DATA_FILE, 'r'))) {

  if (!flock($fh, LOCK_SH)) {
    die(sprintf("Couldn't lock '%s' for reading!", $DATA_FILE));
  }

  // STEP 1: Find beta canonical paths.
  while ($row = fgetcsv($fh)) {

    $count++;

    // Clean up $row, which has two useless columns at 1 and 2.
    $row = array($row[0], $row[3], $row[4], $row[5]);

    array_walk($row, function(&$elm) {
      $elm = trim($elm);
    });

    // First row is column headers.
    if ($HAS_COLUMN_HEADERS && $count == 1) {
      $processed[] = $row;
      continue;
    }

    // Save incomplete rows to the new file as well, but don't process.
    if (empty($row[2])) {
      // echo sprintf("%d: No beta alias...skipping", $count), PHP_EOL;
      $processed[] = $row;
      continue;
    }

    // echo sprintf("%d: Looking up beta alias '%s'", $count, $row[2]), PHP_EOL;

    // Need to use the alias in [4] to look up the canonical path in [5].
    $beta_canonical = db_select('url_alias', NULL, array('target' => 'default'))
      ->fields('url_alias', array('source'))
      ->condition('alias', $row[2], '=')
      ->execute()
      ->fetchAssoc();

    if (!empty($beta_canonical['source'])) {
      $row[3] = trim($beta_canonical['source']);
    }

    $processed[] = $row;
  }

  echo sprintf("Step 1 complete: Processed %d rows", count($processed)), PHP_EOL;

  // STEP 2: Look up all legacy aliases, create a row for each
  //
  // REVISED: Skipping. None of these source paths has multiple aliases.

  $count = 0;
  $rows_added = 0; // Tracks how many new rows were created in this step.
  $final = array(); // Final output array.

  foreach ($processed as $row) {
    $count++;

    $final[] = $row;

    // Skip header row.
    if ($count == 1) {
      continue;
    }

    // Empty legacy canonical path: skip.
    if (empty($row[1])) {
      continue;
    }

    // All the known aliases for this legacy canonical path.
    $aliases = array($row[0]);

    $legacy_aliases = db_select('url_alias', NULL, array('target' => 'legacy'))
                    ->fields('url_alias', array('alias'))
                    ->condition('source', $row[1], '=')
                    ->execute();

    while ($legacy_alias = $legacy_aliases->fetchAssoc()) {
      $path_from_db = RedirectHelper3414::normalizePath($legacy_alias['alias']);

      // Add any new aliases as new rows.
      if (!in_array($path_from_db, $aliases)) {
        $aliases[] = $path_from_db;
        $row[0] = $path_from_db;
        $final[] = $row;
        $rows_added++;
      }
    }

    // Find redirects.
    $legacy_redirects = db_select('redirect', NULL, array('target' => 'legacy'))
                        ->fields('redirect', array('source'))
                        ->condition('redirect', $row[1], '=')
                        ->execute();

    while ($legacy_redirect = $legacy_redirects->fetchAssoc()) {
      $redirect = RedirectHelper3414::normalizePath($legacy_redirect['source']);

      // Add any new redirect paths as new rows.
      if (!in_array($redirect, $aliases)) {
        $aliases[] = $redirect;
        $row[0] = $redirect;
        $final[] = $row;
        $rows_added++;
      }
    }
  }

  echo sprintf("Step 2 complete: %d new rows added", $rows_added), PHP_EOL;

  // UN-RELEASE THE HOUNDS
  flock($fh, LOCK_UN);
}

fclose($fh);

// STEP 3: Write final array to new CSV at $OUTPUT_FILE.

if (FALSE === ($fh = fopen($OUTPUT_FILE, 'w+'))) {
  die(sprintf("EPIC FAIL: Can't open '%s' for writing", $OUTPUT_FILE));
}

if (!flock($fh, LOCK_EX)) {
  die(sprintf("EPIC FAIL: Can't lock '%s' for writing", $OUTPUT_FILE));
}

foreach ($final as $row) {
  fputcsv($fh, $row);
}

flock($fh, LOCK_UN);
fclose($fh);

echo sprintf("Finished: %d rows written to '%s'", count($final), $OUTPUT_FILE), PHP_EOL;


/**
 * Helper class for this script.
 *
 * Class RedirectHelper3414
 */
class RedirectHelper3414 {

  /**
   * Normalize aliases / paths for comparison and storage.
   * @param $path
   * @return string
   */
  static public function normalizePath($path) {
    $path = trim($path);
    if ('/' != $path[0]) {
      return '/' . $path;
    }
    return $path;
  }
}
