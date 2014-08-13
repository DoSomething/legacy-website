<?php
/**
 * @file
 * dosomething_shipment.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_shipment_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'user_shipments';
  $view->description = 'List of Shipment entities.';
  $view->tag = 'default';
  $view->base_table = 'dosomething_shipment';
  $view->human_name = 'User Shipments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Shipments';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'created' => 'created',
    'shirt_size2' => 'shirt_size2',
    'entity_id' => 'entity_id',
    'entity_type' => 'entity_type',
    'id_1' => 'id_1',
    'shirt_size1' => 'shirt_size1',
    'shipment_type' => 'shipment_type',
    'uid' => 'uid',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'shirt_size2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'shirt_size1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'shipment_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start - @end of @total Shipments';
  /* Relationship: Shipments: Uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'dosomething_shipment';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Shipments: Shipment id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'dosomething_shipment';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Shipments: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'dosomething_shipment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Shipments: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'dosomething_shipment';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['separator'] = '';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['label'] = 'Email';
  /* Field: Shipments: Shipment Entity type */
  $handler->display->display_options['fields']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['fields']['entity_type']['table'] = 'dosomething_shipment';
  $handler->display->display_options['fields']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['fields']['entity_type']['label'] = 'Entity type';
  $handler->display->display_options['fields']['entity_type']['exclude'] = TRUE;
  /* Field: Shipments: Shipment Entity id */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'dosomething_shipment';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = 'Entity';
  $handler->display->display_options['fields']['entity_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['entity_id']['alter']['text'] = '[entity_type]/[entity_id] ';
  $handler->display->display_options['fields']['entity_id']['separator'] = '';
  /* Field: Shipments: Shipment item */
  $handler->display->display_options['fields']['item']['id'] = 'item';
  $handler->display->display_options['fields']['item']['table'] = 'dosomething_shipment';
  $handler->display->display_options['fields']['item']['field'] = 'item';
  $handler->display->display_options['fields']['item']['label'] = 'Item';
  /* Field: Shipments: Shipment item option */
  $handler->display->display_options['fields']['item_option']['id'] = 'item_option';
  $handler->display->display_options['fields']['item_option']['table'] = 'dosomething_shipment';
  $handler->display->display_options['fields']['item_option']['field'] = 'item_option';
  $handler->display->display_options['fields']['item_option']['label'] = 'Item option';
  /* Field: Shipments: Shipment additional item */
  $handler->display->display_options['fields']['item_additional']['id'] = 'item_additional';
  $handler->display->display_options['fields']['item_additional']['table'] = 'dosomething_shipment';
  $handler->display->display_options['fields']['item_additional']['field'] = 'item_additional';
  $handler->display->display_options['fields']['item_additional']['label'] = 'Additional item';
  /* Field: Shipments: Shipment item option */
  $handler->display->display_options['fields']['item_additional_option']['id'] = 'item_additional_option';
  $handler->display->display_options['fields']['item_additional_option']['table'] = 'dosomething_shipment';
  $handler->display->display_options['fields']['item_additional_option']['field'] = 'item_additional_option';
  $handler->display->display_options['fields']['item_additional_option']['label'] = 'Additional item option';
  /* Filter criterion: Shipments: Uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'dosomething_shipment';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['group'] = 1;
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
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['relationship'] = 'uid';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'Email';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/users/shipments';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Shipments';
  $handler->display->display_options['menu']['description'] = 'List of all User Shipments.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['user_shipments'] = array(
    t('Master'),
    t('Shipments'),
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
    t('Displaying @start - @end of @total Shipments'),
    t('Shipment User'),
    t('Shipment id'),
    t('.'),
    t(','),
    t('Date created'),
    t('Uid'),
    t('Email'),
    t('Entity type'),
    t('Entity'),
    t('[entity_type]/[entity_id] '),
    t('Item'),
    t('Item option'),
    t('Additional item'),
    t('Additional item option'),
    t('Page'),
  );
  $export['user_shipments'] = $view;

  return $export;
}
