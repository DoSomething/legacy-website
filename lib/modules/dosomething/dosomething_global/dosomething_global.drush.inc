<?php
/**
 * @file
 * Drush commands for dosomething_global.module.
 */


/**
 *  Implements hook_drush_command
 */
function dosomething_global_drush_command() {
  return [
    'ds-global-titles-fix' => [
      'description' => 'Fixes translatable title values.',
      'arguments' => [
        'bundle' => 'The content type to fix.',
      ],
      'required-arguments' => TRUE,
    ],
  ];
}

/**
 * Callback for ds-global-titles-fix command.
 *
 * Fixes translatable title values.
 */
function drush_dosomething_global_ds_global_titles_fix($bundle) {
  // Check if bundle exists.
  $node_def = entity_get_info('node');
  if (empty($node_def['bundles']) || empty($node_def['bundles'][$bundle])) {
    return 'Wrong bundle provided.';
  }

  $legacy_field = 'title';
  print t('Replacing field values for !field in !bundle bundle.', [
    '!field'  => $legacy_field,
    '!bundle' => $bundle,
  ]) . PHP_EOL;

  title_field_replacement_batch_set('node', $bundle, $legacy_field);
  drush_backend_batch_process();

  return t('Done') . '.';
}
