<?php
/*
 * Script to run after deployments.
 * Checks the dosomething.info file to determine if new modules need to be enabled.
 *
 * to run: drush --script-path=../bin/ php-script enable_modules.php
 *
 */

// Parse the data in the info file.
$info = drupal_parse_info_file('../lib/profiles/dosomething/dosomething.info');
$modules = $info['dependencies'];

// Enable modules
enable_modules_if_needed($modules);

/**
 * Enable modules if disabled.
 *
 * @param array $modules
 *  An array of modules
 */
function enable_modules_if_needed($modules) {
  foreach ($modules as $module) {
    // Check if modules are disabled.
    $result = db_select('system', 's')
            ->fields('s', ['status'])
            ->condition('name', $module, '=')
            ->condition('status', 0, '=')
            ->execute();
    if ($result->fetchAssoc()) {
      // Create an array of modules to enable.
      $to_enable[] = $module;
    }
  }
  if ($to_enable) {
    module_enable($to_enable);
    echo 'Enabled ' . print_r($to_enable);
  }
  else {
    echo 'No new modules to enable';
  }
}
