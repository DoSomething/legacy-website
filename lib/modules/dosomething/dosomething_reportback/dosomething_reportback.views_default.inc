<?php
/**
 * @file
 * dosomething_reportback.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_reportback_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'node_reportbacks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dosomething_reportback';
  $view->human_name = 'Node Reportbacks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Reportbacks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any reportback';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'rbid' => 'rbid',
    'created' => 'created',
    'uid' => 'uid',
    'mail' => 'mail',
    'quantity' => 'quantity',
    'fid' => 'fid',
    'updated' => 'updated',
  );
  $handler->display->display_options['style_options']['default'] = 'updated';
  $handler->display->display_options['style_options']['info'] = array(
    'rbid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'quantity' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'fid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Copy';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No reportbacks found.';
  $handler->display->display_options['empty']['area']['format'] = 'markdown';
  /* Relationship: Reportback: User uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'dosomething_reportback';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Reportbacks: Reportback image fid */
  $handler->display->display_options['relationships']['fid']['id'] = 'fid';
  $handler->display->display_options['relationships']['fid']['table'] = 'dosomething_reportback_file';
  $handler->display->display_options['relationships']['fid']['field'] = 'fid';
  $handler->display->display_options['relationships']['fid']['label'] = 'Image';
  /* Field: Reportback: Reportback rbid */
  $handler->display->display_options['fields']['rbid']['id'] = 'rbid';
  $handler->display->display_options['fields']['rbid']['table'] = 'views_entity_reportback';
  $handler->display->display_options['fields']['rbid']['field'] = 'rbid';
  $handler->display->display_options['fields']['rbid']['label'] = 'Rbid';
  $handler->display->display_options['fields']['rbid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rbid']['separator'] = '';
  $handler->display->display_options['fields']['rbid']['link_to_entity'] = 1;
  /* Field: Reportback: Last Updated */
  $handler->display->display_options['fields']['updated']['id'] = 'updated';
  $handler->display->display_options['fields']['updated']['table'] = 'dosomething_reportback';
  $handler->display->display_options['fields']['updated']['field'] = 'updated';
  $handler->display->display_options['fields']['updated']['label'] = 'Updated';
  $handler->display->display_options['fields']['updated']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['updated']['alter']['path'] = 'reportback/[rbid]';
  $handler->display->display_options['fields']['updated']['date_format'] = 'short';
  /* Field: Reportback: User uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'views_entity_reportback';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Uid';
  $handler->display->display_options['fields']['uid']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['uid']['display'] = 'id';
  $handler->display->display_options['fields']['uid']['view_mode'] = 'full';
  $handler->display->display_options['fields']['uid']['bypass_access'] = 0;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: Reportback: Created Date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'dosomething_reportback';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Reportback: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'dosomething_reportback';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'fid';
  $handler->display->display_options['fields']['uri']['label'] = 'Pic';
  $handler->display->display_options['fields']['uri']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uri']['alter']['text'] = '<img src="[uri]" width="200" height="200"/>';
  $handler->display->display_options['fields']['uri']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uri']['alter']['path'] = 'reportback/[rbid]';
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'fid';
  $handler->display->display_options['fields']['fid']['label'] = 'Fid';
  $handler->display->display_options['fields']['fid']['link_to_file'] = TRUE;
  /* Sort criterion: Reportback: Created Date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'dosomething_reportback';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Reportback: Node nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'dosomething_reportback';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Reportbacks: %1';
  $handler->display->display_options['arguments']['nid']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['breadcrumb'] = 'Reportbacks';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'campaign' => 'campaign',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access_op'] = 'update';
  /* Filter criterion: Reportback: User uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'dosomething_reportback';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Uid';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/reportbacks';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Reportbacks';
  $handler->display->display_options['menu']['weight'] = '100';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['node_reportbacks'] = array(
    t('Master'),
    t('Reportbacks'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Copy'),
    t('No reportbacks found.'),
    t('User'),
    t('Image'),
    t('Rbid'),
    t('.'),
    t('Updated'),
    t('Uid'),
    t('E-mail'),
    t('Created'),
    t('Quantity'),
    t(','),
    t('Pic'),
    t('<img src="[uri]" width="200" height="200"/>'),
    t('Fid'),
    t('All'),
    t('Reportbacks: %1'),
    t('Page'),
  );
  $export['node_reportbacks'] = $view;

  return $export;
}
