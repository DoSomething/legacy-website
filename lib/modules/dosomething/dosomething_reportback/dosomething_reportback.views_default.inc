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
  $view->name = 'reportback_files';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dosomething_reportback_file';
  $view->human_name = 'Reportback Files';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Reviewed';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any reportback';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'fid' => 'fid',
    'rbid_1' => 'rbid_1',
    'rendered_entity' => 'rendered_entity',
    'status' => 'status',
    'quantity' => 'quantity',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'fid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rbid_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rendered_entity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
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
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start - @end of @total Reportback Images';
  /* Relationship: Reportback Item: Reportback File rbid */
  $handler->display->display_options['relationships']['rbid']['id'] = 'rbid';
  $handler->display->display_options['relationships']['rbid']['table'] = 'dosomething_reportback_file';
  $handler->display->display_options['relationships']['rbid']['field'] = 'rbid';
  $handler->display->display_options['relationships']['rbid']['required'] = TRUE;
  /* Relationship: Reportback: Node nid */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'dosomething_reportback';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['relationship'] = 'rbid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Field: Reportback Item: Reportback file fid */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'views_entity_reportback_item';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['fid']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['fid']['bypass_access'] = 0;
  /* Field: Reportback Item: Reportback File rbid */
  $handler->display->display_options['fields']['rbid_1']['id'] = 'rbid_1';
  $handler->display->display_options['fields']['rbid_1']['table'] = 'dosomething_reportback_file';
  $handler->display->display_options['fields']['rbid_1']['field'] = 'rbid';
  $handler->display->display_options['fields']['rbid_1']['label'] = 'RBID';
  $handler->display->display_options['fields']['rbid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['rbid_1']['alter']['path'] = 'admin/reportback/[rbid_1]';
  $handler->display->display_options['fields']['rbid_1']['separator'] = '';
  /* Field: Reportback: Node nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'views_entity_reportback';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'rbid';
  $handler->display->display_options['fields']['nid']['label'] = 'Campaign';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['nid']['view_mode'] = 'full';
  $handler->display->display_options['fields']['nid']['bypass_access'] = 0;
  /* Field: Reportback Item: Rendered Reportback Item */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_reportback_item';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = 'Image';
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 1;
  /* Field: Reportback Item: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'dosomething_reportback_file';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Item Status';
  /* Field: Reportback: Flagged status */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'dosomething_reportback';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'rbid';
  $handler->display->display_options['fields']['flagged']['label'] = 'Reportback flagged status';
  /* Field: Reportback: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'dosomething_reportback';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['relationship'] = 'rbid';
  /* Sort criterion: Reportback Item: Reportback file fid */
  $handler->display->display_options['sorts']['fid']['id'] = 'fid';
  $handler->display->display_options['sorts']['fid']['table'] = 'dosomething_reportback_file';
  $handler->display->display_options['sorts']['fid']['field'] = 'fid';
  $handler->display->display_options['sorts']['fid']['order'] = 'DESC';
  /* Filter criterion: Reportback Item: Status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'dosomething_reportback_file';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['operator'] = '!=';
  $handler->display->display_options['filters']['status_1']['value'] = 'pending';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  /* Filter criterion: Reportback Item: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'dosomething_reportback_file';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['status']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['group_info']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Approved',
      'operator' => '=',
      'value' => 'approved',
    ),
    2 => array(
      'title' => 'Promoted',
      'operator' => '=',
      'value' => 'promoted',
    ),
    3 => array(
      'title' => 'Excluded',
      'operator' => '=',
      'value' => 'excluded',
    ),
    4 => array(
      'title' => 'Flagged',
      'operator' => '=',
      'value' => 'flagged',
    ),
  );
  /* Filter criterion: Reportback: Flagged Reason */
  $handler->display->display_options['filters']['flagged_reason']['id'] = 'flagged_reason';
  $handler->display->display_options['filters']['flagged_reason']['table'] = 'dosomething_reportback';
  $handler->display->display_options['filters']['flagged_reason']['field'] = 'flagged_reason';
  $handler->display->display_options['filters']['flagged_reason']['relationship'] = 'rbid';
  $handler->display->display_options['filters']['flagged_reason']['exposed'] = TRUE;
  $handler->display->display_options['filters']['flagged_reason']['expose']['operator_id'] = 'flagged_reason_op';
  $handler->display->display_options['filters']['flagged_reason']['expose']['label'] = 'Flagged Reason';
  $handler->display->display_options['filters']['flagged_reason']['expose']['operator'] = 'flagged_reason_op';
  $handler->display->display_options['filters']['flagged_reason']['expose']['identifier'] = 'flagged_reason';
  $handler->display->display_options['filters']['flagged_reason']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['flagged_reason']['group_info']['label'] = 'Flagged Reason';
  $handler->display->display_options['filters']['flagged_reason']['group_info']['identifier'] = 'flagged_reason';
  $handler->display->display_options['filters']['flagged_reason']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'inappropriate',
      'operator' => 'contains',
      'value' => 'inappropriate',
    ),
    2 => array(
      'title' => 'irrelevant',
      'operator' => 'contains',
      'value' => 'irrelevant',
    ),
    3 => array(
      'title' => 'unrealistic quantity',
      'operator' => 'contains',
      'value' => 'unrealistic',
    ),
  );
  /* Filter criterion: Reportback: Promoted Reason */
  $handler->display->display_options['filters']['promoted_reason']['id'] = 'promoted_reason';
  $handler->display->display_options['filters']['promoted_reason']['table'] = 'dosomething_reportback';
  $handler->display->display_options['filters']['promoted_reason']['field'] = 'promoted_reason';
  $handler->display->display_options['filters']['promoted_reason']['relationship'] = 'rbid';
  $handler->display->display_options['filters']['promoted_reason']['exposed'] = TRUE;
  $handler->display->display_options['filters']['promoted_reason']['expose']['operator_id'] = 'promoted_reason_op';
  $handler->display->display_options['filters']['promoted_reason']['expose']['label'] = 'Promoted Reason';
  $handler->display->display_options['filters']['promoted_reason']['expose']['operator'] = 'promoted_reason_op';
  $handler->display->display_options['filters']['promoted_reason']['expose']['identifier'] = 'promoted_reason';
  $handler->display->display_options['filters']['promoted_reason']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['promoted_reason']['group_info']['label'] = 'Promoted Reason';
  $handler->display->display_options['filters']['promoted_reason']['group_info']['identifier'] = 'promoted_reason';
  $handler->display->display_options['filters']['promoted_reason']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Good Photo',
      'operator' => 'contains',
      'value' => 'photo',
    ),
    2 => array(
      'title' => 'Good Quote',
      'operator' => 'contains',
      'value' => 'quote',
    ),
    3 => array(
      'title' => 'Good for Sponsor',
      'operator' => 'contains',
      'value' => 'sponsor',
    ),
    4 => array(
      'title' => 'High Impact',
      'operator' => 'contains',
      'value' => 'impact',
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'admin/users/rb/reviewed';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Reviewed';
  $handler->display->display_options['menu']['description'] = 'All Reviewed Reportbacks';
  $handler->display->display_options['menu']['weight'] = '20';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'reviewed_reportbacks');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Reportback Item: Reportback File rbid */
  $handler->display->display_options['relationships']['rbid']['id'] = 'rbid';
  $handler->display->display_options['relationships']['rbid']['table'] = 'dosomething_reportback_file';
  $handler->display->display_options['relationships']['rbid']['field'] = 'rbid';
  $handler->display->display_options['relationships']['rbid']['required'] = TRUE;
  /* Relationship: Reportback: Node nid */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'dosomething_reportback';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['relationship'] = 'rbid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reportback Item: Reportback file fid */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'views_entity_reportback_item';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['fid']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['fid']['bypass_access'] = 0;
  /* Field: Reportback Item: Reportback File rbid */
  $handler->display->display_options['fields']['rbid_1']['id'] = 'rbid_1';
  $handler->display->display_options['fields']['rbid_1']['table'] = 'dosomething_reportback_file';
  $handler->display->display_options['fields']['rbid_1']['field'] = 'rbid';
  $handler->display->display_options['fields']['rbid_1']['label'] = 'RBID';
  $handler->display->display_options['fields']['rbid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['rbid_1']['alter']['path'] = 'admin/reportback/[rbid_1]';
  $handler->display->display_options['fields']['rbid_1']['separator'] = '';
  /* Field: Reportback: Node nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'views_entity_reportback';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'rbid';
  $handler->display->display_options['fields']['nid']['label'] = 'Campaign';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['nid']['view_mode'] = 'full';
  $handler->display->display_options['fields']['nid']['bypass_access'] = 0;
  /* Field: Reportback: Run NID */
  $handler->display->display_options['fields']['run_nid']['id'] = 'run_nid';
  $handler->display->display_options['fields']['run_nid']['table'] = 'dosomething_reportback';
  $handler->display->display_options['fields']['run_nid']['field'] = 'run_nid';
  $handler->display->display_options['fields']['run_nid']['relationship'] = 'rbid';
  $handler->display->display_options['fields']['run_nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['run_nid']['alter']['path'] = '/node/[run_nid]';
  $handler->display->display_options['fields']['run_nid']['separator'] = '';
  /* Field: Reportback Item: Rendered Reportback Item */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_reportback_item';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = 'Image';
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 1;
  /* Field: Reportback Item: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'dosomething_reportback_file';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Item Status';
  /* Field: Reportback: Flagged status */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'dosomething_reportback';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'rbid';
  $handler->display->display_options['fields']['flagged']['label'] = 'Reportback flagged status';
  /* Field: Reportback: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'dosomething_reportback';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['relationship'] = 'rbid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Reportback: Node nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'dosomething_reportback';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'rbid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'campaign' => 'campaign',
    'campaign_run' => 'campaign_run',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Reportback Item: Status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'dosomething_reportback_file';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['operator'] = '!=';
  $handler->display->display_options['filters']['status_1']['value'] = 'pending';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  /* Filter criterion: Reportback Item: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'dosomething_reportback_file';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['status']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['group_info']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Approved',
      'operator' => '=',
      'value' => 'approved',
    ),
    2 => array(
      'title' => 'Promoted',
      'operator' => '=',
      'value' => 'promoted',
    ),
    3 => array(
      'title' => 'Excluded',
      'operator' => '=',
      'value' => 'excluded',
    ),
    4 => array(
      'title' => 'Flagged',
      'operator' => '=',
      'value' => 'flagged',
    ),
  );
  /* Filter criterion: Reportback: Flagged Reason */
  $handler->display->display_options['filters']['flagged_reason']['id'] = 'flagged_reason';
  $handler->display->display_options['filters']['flagged_reason']['table'] = 'dosomething_reportback';
  $handler->display->display_options['filters']['flagged_reason']['field'] = 'flagged_reason';
  $handler->display->display_options['filters']['flagged_reason']['relationship'] = 'rbid';
  $handler->display->display_options['filters']['flagged_reason']['exposed'] = TRUE;
  $handler->display->display_options['filters']['flagged_reason']['expose']['operator_id'] = 'flagged_reason_op';
  $handler->display->display_options['filters']['flagged_reason']['expose']['label'] = 'Flagged Reason';
  $handler->display->display_options['filters']['flagged_reason']['expose']['operator'] = 'flagged_reason_op';
  $handler->display->display_options['filters']['flagged_reason']['expose']['identifier'] = 'flagged_reason';
  $handler->display->display_options['filters']['flagged_reason']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['flagged_reason']['group_info']['label'] = 'Flagged Reason';
  $handler->display->display_options['filters']['flagged_reason']['group_info']['identifier'] = 'flagged_reason';
  $handler->display->display_options['filters']['flagged_reason']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'inappropriate',
      'operator' => 'contains',
      'value' => 'inappropriate',
    ),
    2 => array(
      'title' => 'irrelevant',
      'operator' => 'contains',
      'value' => 'irrelevant',
    ),
    3 => array(
      'title' => 'unrealistic quantity',
      'operator' => 'contains',
      'value' => 'unrealistic',
    ),
  );
  /* Filter criterion: Reportback: Promoted Reason */
  $handler->display->display_options['filters']['promoted_reason']['id'] = 'promoted_reason';
  $handler->display->display_options['filters']['promoted_reason']['table'] = 'dosomething_reportback';
  $handler->display->display_options['filters']['promoted_reason']['field'] = 'promoted_reason';
  $handler->display->display_options['filters']['promoted_reason']['relationship'] = 'rbid';
  $handler->display->display_options['filters']['promoted_reason']['exposed'] = TRUE;
  $handler->display->display_options['filters']['promoted_reason']['expose']['operator_id'] = 'promoted_reason_op';
  $handler->display->display_options['filters']['promoted_reason']['expose']['label'] = 'Promoted Reason';
  $handler->display->display_options['filters']['promoted_reason']['expose']['operator'] = 'promoted_reason_op';
  $handler->display->display_options['filters']['promoted_reason']['expose']['identifier'] = 'promoted_reason';
  $handler->display->display_options['filters']['promoted_reason']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['promoted_reason']['group_info']['label'] = 'Promoted Reason';
  $handler->display->display_options['filters']['promoted_reason']['group_info']['identifier'] = 'promoted_reason';
  $handler->display->display_options['filters']['promoted_reason']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Good Photo',
      'operator' => 'contains',
      'value' => 'photo',
    ),
    2 => array(
      'title' => 'Good Quote',
      'operator' => 'contains',
      'value' => 'quote',
    ),
    3 => array(
      'title' => 'Good for Sponsor',
      'operator' => 'contains',
      'value' => 'sponsor',
    ),
    4 => array(
      'title' => 'High Impact',
      'operator' => 'contains',
      'value' => 'impact',
    ),
  );
  /* Filter criterion: Reportback: Run NID */
  $handler->display->display_options['filters']['run_nid']['id'] = 'run_nid';
  $handler->display->display_options['filters']['run_nid']['table'] = 'dosomething_reportback';
  $handler->display->display_options['filters']['run_nid']['field'] = 'run_nid';
  $handler->display->display_options['filters']['run_nid']['relationship'] = 'rbid';
  $handler->display->display_options['filters']['run_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['run_nid']['expose']['operator_id'] = 'run_nid_op';
  $handler->display->display_options['filters']['run_nid']['expose']['label'] = 'Run NID';
  $handler->display->display_options['filters']['run_nid']['expose']['operator'] = 'run_nid_op';
  $handler->display->display_options['filters']['run_nid']['expose']['identifier'] = 'run_nid';
  $handler->display->display_options['filters']['run_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  $handler->display->display_options['path'] = 'node/%/rb/reviewed';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Reviewed';
  $handler->display->display_options['menu']['weight'] = '30';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_2');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'cause' => 'cause',
    'issue' => 'issue',
  );
  $handler->display->display_options['path'] = 'taxonomy/term/%/rb/reviewed';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Reviewed';
  $handler->display->display_options['menu']['weight'] = '30';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['reportback_files'] = array(
    t('Master'),
    t('Reviewed'),
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
    t('Displaying @start - @end of @total Reportback Images'),
    t('Reportback'),
    t('Content'),
    t('Reportback file fid'),
    t('RBID'),
    t('.'),
    t('Campaign'),
    t('Image'),
    t('Item Status'),
    t('Reportback flagged status'),
    t('Quantity'),
    t(','),
    t('Status'),
    t('Flagged Reason'),
    t('Promoted Reason'),
    t('Page'),
    t('Run NID'),
    t('All'),
  );
  $export['reportback_files'] = $view;

  return $export;
}
