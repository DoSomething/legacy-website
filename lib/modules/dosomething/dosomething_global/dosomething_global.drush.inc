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
      'examples' => [
        'drush ds-global-titles-fix campaign'
          => 'Fixes Campaign\'s title.',
      ],
    ],
    'ds-global-field-fix' => [
      'description' => 'Fixes translatable field values.',
      'arguments' => [
        'field' => 'Field name to fix.',
      ],
      'required-arguments' => TRUE,
      'examples' => [
        'drush ds-global-field-fix field_call_to_action'
          => 'Fixes Call to Action field.',
      ],
    ],
    'ds-replace-neutral-with-english' => [
      'description' => 'Changes languge-neutral nodes into English.',
      'arguments' => [
        'bundle' => 'The content type to fix.',
      ],
      'required-arguments' => TRUE,
      'examples' => [
        'drush ds-replace-neutral-with-english campaign'
          => 'Fixes Campaign\'s languge-neutral nodes.',
      ],
    ],
    'ds-fields-resque' => [
      'description' => 'Fixes fields lost during enabling translation.',
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

/**
 * Callback for ds-global-field-fix command.
 *
 * Fixes translatable field values.
 *
 * @see entity_translation_translatable_form_submit();
 */
function drush_dosomething_global_ds_global_field_fix($field) {
  print t('Replacing field values for !field.', [
    '!field'  => $field,
  ]) . PHP_EOL;

  $batch = [
    'title' => t('Enabling translation for the @field field', ['@field' => $field]),
    'operations' => [['entity_translation_translatable_batch', [TRUE, $field, TRUE]]],
    'finished' => 'entity_translation_translatable_batch_done',
    'file' => drupal_get_path('module', 'entity_translation') . '/entity_translation.admin.inc',
    'progressive' => FALSE
  ];
  batch_set($batch);
  drush_backend_batch_process();
}

/**
 * Callback for ds-replace-neutral-with-english command.
 */
function drush_dosomething_global_ds_replace_neutral_with_english($bundle) {
  // Check if bundle exists.
  $node_def = entity_get_info('node');
  if (empty($node_def['bundles']) || empty($node_def['bundles'][$bundle])) {
    return 'Wrong bundle provided.';
  }

  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $bundle)
    ->propertyCondition('language', LANGUAGE_NONE)
    ->addMetaData('account', user_load(1));
  $result = $query->execute();

  if (empty($result['node'])) {
    return 'No language neutral nodes left.';

  }
  $nids = array_keys($result['node']);
  $nodes = entity_load('node', $nids);
  foreach ($nodes as $node) {
    $node->language = 'en';
    node_save($node);
  }
  return 'Processed ' . count($nids) . ' nodes.';
}

/**
 * Callback for ds-fields-resque command.
 */
function drush_dosomething_global_ds_fields_resque($bundle) {
  // Check if bundle exists.
  $node_def = entity_get_info('node');
  if (empty($node_def['bundles']) || empty($node_def['bundles'][$bundle])) {
    return 'Wrong bundle provided.';
  }

  // Get translatable fields.
  $fields = array_keys(field_info_instances('node', $bundle));
  $translatable_fields = [];
  foreach ($fields as $field) {
    $field_info = field_info_field($field);
    if ($field_info['translatable']) {
      $translatable_fields[] = $field;
    }
  }

  // Get all the nodes.
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $bundle)
    ->addMetaData('account', user_load(1));
  $result = $query->execute();
  if (empty($result['node'])) {
    return 'No nodes found.';
  }
  $nids = array_keys($result['node']);
  $nodes = entity_load('node', $nids, [], FALSE);
  foreach ($nodes as $node) {
    $changed = FALSE;
    foreach ($translatable_fields as $field) {
      // Check if the info is missing from data table.
      $data_table_name = 'field_data_' . $field;
      $result = db_select($data_table_name)
      ->condition('entity_id', $node->nid)
      ->countQuery()
      ->execute()
      ->fetchField();
      if ($result) {
        continue;
      }

      // Look for the info in the last revision of revisions table.
      $revision_table = 'field_revision_' . $field;
      $field_revision = db_select($revision_table, 'r')
      ->fields('r', ['revision_id'])
      ->orderBy('r.revision_id', 'DESC')
      ->condition('entity_id', $node->nid)
      ->execute()
      ->fetchField();
      if (!$field_revision) {
        continue;
      }

      // Load the particular revision of the node.
      $last_node = node_load($node->nid, $field_revision);
      if (empty($last_node) || empty($last_node->{$field})) {
        continue;
      }

      // Override existing field with the old one.
      $old_value = reset($last_node->{$field});
      $node->{$field}['en'] = $old_value;
      $changed = TRUE;
      drush_log('Fixing node #' . $node->nid . ': ' . $field . '.', 'status');
    }
    if ($changed) {
      node_save($node);
      drush_log('Saving node #' . $node->nid . '.', 'ok');
    }
  }
}
