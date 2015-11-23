<?php

/**
 * https://github.com/DoSomething/phoenix/issues/3404
 *
 * Based on a redirect CSV formatted like this:
 *
 * https://gist.github.com/mshmsh5000/23f284dc3a2b3d2565eb
 *
 * 1. Create a redirect from column A (legacy alias) to column D (beta canonical).
 * 2. Create a redirect from column B (legacy canonical) to column D (beta canonical).
 * 3. Using Drupal redirect calls, write these to the database.
 *
 *
 * REQUIREMENTS:
 *
 * 1. $DATA_FILE needs to point to your CSV. Path is relative to docroot.
 *
 * 2. Execute like this:
 *
 *    drush --script-path=../scripts/ php-script 3404-create-redirects.php
 */

$DATA_FILE = '../scripts/redirects.processed.csv';
$HAS_COLUMN_HEADERS = true; // If true, skip the first row.

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
    if (empty($row[2])) {
      echo sprintf('Line %d: Skipping: no beta path', $count), PHP_EOL;
      continue;
    }

    // Clean up $row.
    array_walk($row, function(&$elm) {
      $elm = trim($elm);
    });

    // Redirect target, before any modifications.
    $target = $row[2];

    // Handle redirect targets that are complete URLs.
    $url_prepend = '';
    if (isset($REDIRECT_BASE_URL) && !preg_match('/^http/', $target)) {
      $url_prepend = $REDIRECT_BASE_URL;
    }
    else {
      // Handle redirect targets that refer to beta.dosomething.org.
      $target = preg_replace('/beta.dosomething.org/', 'www.dosomething.org', $target);

      printf('***** Handled full URL: %s', $target); echo PHP_EOL;
    }

    // Use the Drupal core redirect functions to make proper redirect objects.
    // Big ups to https://www.drupal.org/project/path_redirect_import from
    // which I done stole the logic.
    for ($i = 0; $i <= 1; $i++) {
      if (!empty($row[$i])) {

        $source_parts = RedirectHelper3404::parseUrl($row[$i]);

        $data = array(
          'line_no' => $count,
          'source' => $source_parts['url'],
          'redirect' => $url_prepend . $target,
          'status_code' => 301,
          'language' => LANGUAGE_NONE,
        );

        $insert_results = RedirectHelper3404::saveRedirect($data);
        $processed[] = $data;

        if (!$insert_results['success']) {
          $messages[] = $insert_results['message'];
        }
        else {
          $count++;
        }
      }
    }
  }

  if ($count > 0) {
    $messages[] = t('@count row(s) imported.', array('@count' => $count));
    $success = TRUE;
  }

  print_r(array('success' => $success, 'message' => $messages));

  echo sprintf('Complete: Processed %d rows', count($processed)), PHP_EOL;

  // print_r($processed);

  // UN-RELEASE THE HOUNDS
  flock($fh, LOCK_UN);
}

fclose($fh);



/**
 * Helper class for this script.
 *
 * @class RedirectHelper3404
 */
class RedirectHelper3404 {

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
