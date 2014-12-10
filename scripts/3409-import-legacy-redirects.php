<?php

/**
 * https://github.com/DoSomething/dosomething/issues/3409
 *
 * Based on a redirect CSV formatted like this:
 *
 * https://gist.github.com/mshmsh5000/d7e00a8c70946c4431d5
 *
 * And a reference CSV (created for issue #3404) formatted like this:
 *
 * https://gist.github.com/mshmsh5000/23f284dc3a2b3d2565eb
 *
 * 1. Check the redirect target URL against the reference CSV to make sure
 *    we're not creating double-redirects. In those cases, change the
 *    target URL to its final destination as specific in the reference CSV.
 *
 * 2. Check that the final redirect URL is valid in the target Drupal app.
 *
 * 3. Import the redirect into the target Drupal app.
 *
 * 4. Export a list of all created redirects to $OUTPUT_FILE.
 *
 *
 * REQUIREMENTS:
 *
 * 1. $DATA_FILE needs to point to your CSV. Path is relative to docroot.
 *
 * 2. $REDIRECT_REFERENCE_FILE needs to point to the CSV created by the script
 *    for #3404.
 *
 * 3. Execute like this:
 *
 *    drush --script-path=../scripts/ php-script 3409-import-legacy-redirects.php
 */

$DATA_FILE = '../scripts/redirects.legacy.csv';
$HAS_COLUMN_HEADERS = true; // If true, skip the first row.

// Full reference redirect file from issue 3414.
$REDIRECT_REFERENCE_FILE = '../scripts/redirects.processed.csv';

$reference_redirects = RedirectHelper3409::readReferenceCSV($REDIRECT_REFERENCE_FILE);

if (empty($reference_redirects)) {
  die(sprintf("Couldn't open '%s' for reading!", $REDIRECT_REFERENCE_FILE));
}

$OUTPUT_FILE = '../scripts/redirects.legacy.processed.csv';

$REDIRECT_BASE_URL = 'https://www.dosomething.org/';

$urls = array();
$count = 0;

// This will hold processed contents, to be written to $OUTPUT_FILE.
$processed = array();

$messages = array();

if (FALSE !== ($fh = fopen($DATA_FILE, 'r'))) {

  if (!flock($fh, LOCK_SH)) {
    die(sprintf("Couldn't lock '%s' for reading!", $DATA_FILE));
  }

  while ($row = fgetcsv($fh)) {

    $count++;

    // First row is column headers.
    if ($HAS_COLUMN_HEADERS && $count == 1) {
      continue;
    }

    // We need this column, because it contains the beta canonical.
    if (empty($row[1])) {
      echo sprintf("Line %d: Skipping: no target redirect path", $count), PHP_EOL;
      continue;
    }

    // Clean up $row.
    array_walk($row, function(&$elm) {
      $elm = trim($elm);
    });

    printf("%d: %s", $count, $row[0]); echo PHP_EOL;

    // Use the Drupal core redirect functions to make proper redirect objects.
    // Big ups to https://www.drupal.org/project/path_redirect_import from
    // which I done stole the logic.
    if (!empty($row[0])) {

      // If the redirect target is itself getting redirected in the
      // $REDIRECT_REFERENCE_FILE, use that final redirect destination
      // instead. This will be the "beta canonical path".
      if ($alternate_path = RedirectHelper3409::locateRedirectTarget($row[1], $reference_redirects)) {
        printf("***** Alternate for %s => %s", $row[1], $alternate_path); echo PHP_EOL;
      }

      $target = (!empty($alternate_path)) ? $alternate_path : $row[1];

      $source_parts = RedirectHelper3409::parseUrl($row[0]);

      $break = false;

      // Handle redirect targets that are complete URLs.
      $url_prepend = '';
      if (isset($REDIRECT_BASE_URL) && !preg_match('/^http/', $target)) {
        $url_prepend = $REDIRECT_BASE_URL;
      }
      else {
          // Handle redirect targets that refer to beta.dosomething.org.
          $target = preg_replace('/beta.dosomething.org/', 'www.dosomething.org', $target);

          printf("***** Handled full URL: %s", $target); echo PHP_EOL;
      }

      // Now, if the path exists in the beta app, consider this redirect valid.
      $redirect = '';
      if (drupal_valid_path($target)) {
        $redirect = $url_prepend . $target;
      } else {
        continue;
      }

      $data = array(
        'line_no' => $count,
        'source' => $source_parts['url'],
        'redirect' => $redirect,
        'status_code' => 301,
        'language' => LANGUAGE_NONE,
      );

      $insert_results = RedirectHelper3409::saveRedirect($data);
      $processed[] = $data;

      if (!$insert_results['success']) {
        $messages[] = $insert_results['message'];
      }
      else {
        $count++;
      }
    }
  }

  if ($count > 0) {
    $messages[] = t('@count row(s) imported.', array('@count' => $count));
    $success = TRUE;
  }

  print_r(array('success' => $success, 'message' => $messages));

  echo sprintf("Complete: Processed %d rows", count($processed)), PHP_EOL;

  // print_r($processed);

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

foreach ($processed as $row) {
  fputcsv($fh, $row);
}

flock($fh, LOCK_UN);
fclose($fh);

echo sprintf("Finished: %d rows written to '%s'", count($processed), $OUTPUT_FILE), PHP_EOL;



/**
 * Helper class for this script.
 *
 * @class RedirectHelper3409
 */
class RedirectHelper3409 {

  /**
   * Normalize aliases / paths for comparison and storage.
   * @param string $path
   * @return string
   */
  static public function normalizePath($path) {
    $path = trim($path);
    if ('/' != $path[0]) {
      return '/' . $path;
    }
    return $path;
  }

  /**
   * Cribbed from path_redirect_import: Finalize and save the redirect object.
   *
   * @param array $data
   * @return array
   * @see https://www.drupal.org/project/path_redirect_import
   */
  static public function saveRedirect($data) {
    $redirect = (object) $data;
    if ($redirect->redirect != '<front>') {
      $parts = redirect_parse_url($redirect->redirect);
      if (!empty($parts['query'])) {
        $redirect->redirect_options['query'] = $parts['query'];
      }
      if (!empty($parts['scheme']) && $parts['scheme'] == 'https') {
        $redirect->redirect_options['https'] = TRUE;
      }

      if (!url_is_external($parts['url'])) {
        if (drupal_lookup_path('source', $parts['url'], $redirect->language) || drupal_valid_path($parts['url']) || is_file($parts['url'])) {
          $redirect->redirect = drupal_get_normal_path($parts['url'], $redirect->language);
        }
        else {
          $redirect->redirect = FALSE;
        }
      }
      else {
        $redirect->redirect = $parts['url'];
      }
    }

    redirect_object_prepare($redirect);
    redirect_hash($redirect);
    $existing = redirect_load_by_hash($redirect->hash);
    if ($existing && $redirect->override) {
      $query = isset($redirect->source_options['query']) ? $redirect->source_options['query'] : array();
      $rid = redirect_load_by_source($redirect->source, $redirect->language, $query);
      $redirect->rid = $rid->rid;
    }
    if ($existing && !$redirect->override) {
      return array(
        'success' => FALSE,
        'message' => filter_xss(t('Line @line_no: The source "@source" is already being redirected.', array(
          '@line_no' => $data['line_no'],
          '@source' => $data['source'],
        ))),
      );
    }
    elseif (empty($redirect->redirect)) {
      return array(
        'success' => FALSE,
        'message' => filter_xss(t('Line @line_no: The destination "@dest" URL/path does not exist.', array(
          '@line_no' => $data['line_no'],
          '@dest' => $data['redirect'],
        ))),
      );
    }
    else {
      redirect_save($redirect);
    }
    return array('success' => TRUE);
  }

  /**
   * Given a path and a reference array, find any redirect target, if it
   * exists, for the path. Return the redirect target if found or a blank
   * string if not.
   *
   * @param string $path
   * @param array $reference
   * @return string
   */
  static public function locateRedirectTarget($path, $reference) {
    $needle = trim($path);

    foreach ($reference as $row) {

      // Continue for missing beta canonical paths.
      if (empty($row[3])) {
        continue;
      }

      if ($row[0] == $needle || $row[1] == $needle) {
        return $row[3];
      }

    }

    return '';
  }

  /**
   * Given a path to a CSV as defined in issue 3414, read in to an associative
   * array and return.
   *
   * @param string $path
   * @return array
   */
  static public function readReferenceCSV($path) {
    $parsed = array();

    $col_headers = true;

    if (FALSE !== ($fh = fopen($path, 'r'))) {

      if (!flock($fh, LOCK_SH)) {
        die(sprintf("Couldn't lock '%s' for reading!", $path));
      }

      while ($row = fgetcsv($fh)) {

        // Skip column headers (first row).
        if ($col_headers) {
          $col_headers = false;
          continue;
        }

        $parsed[] = $row;
      }
    }

    return $parsed;
  }

  /**
   * Copy of redirect_parse_url() so we don't have to enable that module.
   *
   * @param $url
   * @return array
   */
  static public function parseUrl($url) {
    $original_url = $url;
    $url = trim($url, " \t\n\r\0\x0B\/");
    $parsed = parse_url($url);

    if (isset($parsed['fragment'])) {
      $url = substr($url, 0, -strlen($parsed['fragment']));
      $url = trim($url, '#');
    }
    if (isset($parsed['query'])) {
      $url = substr($url, 0, -strlen($parsed['query']));
      $url = trim($url, '?&');
      $parsed['query'] = drupal_get_query_array($parsed['query']);
    }

    // Convert absolute to relative.
    if (isset($parsed['scheme']) && isset($parsed['host'])) {
      $base_secure_url = rtrim($GLOBALS['base_secure_url'] . base_path(), '/');
      $base_insecure_url = rtrim($GLOBALS['base_insecure_url'] . base_path(), '/');
      if (strpos($url, $base_secure_url) === 0) {
        $url = str_replace($base_secure_url, '', $url);
        $parsed['https'] = TRUE;
      }
      elseif (strpos($url, $base_insecure_url) === 0) {
        $url = str_replace($base_insecure_url, '', $url);
      }
    }

    $url = trim($url, '/');

    // Convert to frontpage paths.
    if ($url == '<front>') {
      $url = '';
    }

    //$parsed['url'] = http_build_query($url, HTTP_URL_STRIP_QUERY | HTTP_URL_STRIP_FRAGMENT);
    $parsed['url'] = $url;

    // Allow modules to alter the parsed URL.
    drupal_alter('redirect_parse_url', $parsed, $original_url);

    return $parsed;
  }
}
