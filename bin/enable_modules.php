<?php
/*
 * Script to run after deployments.
 * Checks the dosomething.info file to determine if new modules need to be enabled.
 *
 * to run: drush --script-path=../bin/ php-script enable_modules.php
 *
 */

// Get all modules from the default  json file.
$modules = json_decode(file_get_contents("../bin/default.modules.json"));


// Enable modules
enable_modules_if_needed($modules);

/**
 * Enable modules if disabled.
 *
 * @param array $modules
 *  An array of modules
 */
function enable_modules_if_needed($modules) {
  foreach ($modules as $module => $status) {
    // Check if the status in the file matches current status.
    $result = db_select('system', 's')
            ->fields('s', array('status'))
            ->condition('name', $module, '=')
            ->condition('status', $status, '<>')
            ->execute();
    if ($result->fetchAssoc()) {
      // Create an array of modules to enable.
      $to_enable[] = $module;
    }
  }
  if ($to_enable) {
    module_enable($to_enable);
    echo "Enabled new modules.";
  }
  else {
    echo "No new modules to enable";
  }
}
