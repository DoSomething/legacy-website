<?php
/*
 * Script to run after deployments.
 * Checks the dosomething.info file to determine if new modules need to be enabled.
 *
 * to run: drush --script-path=../bin/ php-script enable_modules.php --site=site_key
 *
 */

// Get all modules from the default  json file.
$default_modules = json_decode(file_get_contents("../bin/default.modules.json"));

// Enable default modules
enable_modules_if_needed($default_modules);

// Get site specifc modules if any
$key = drush_get_option("key");
$affiliate_file_path = "../bin/" . $key . ".modules.json";
if (isset($key) && file_exists($affiliate_file_path)) {
  $site_modules = json_decode(file_get_contents($affiliate_file_path));
  enable_modules_if_needed($site_modules);
}

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
    echo "Enabled new modules. \n";
  }
  else {
    echo "No new modules to enable. \n";
  }
}
