<?php
/**
 * @file
 * dosomething_fact.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_fact_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'fact_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dosomething_fact';
  $view->human_name = 'Fact Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Fact Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'fact' => 'fact',
    'source' => 'source',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'fact' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'source' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Fact: Fact ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'dosomething_fact';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Fact: Fact */
  $handler->display->display_options['fields']['fact']['id'] = 'fact';
  $handler->display->display_options['fields']['fact']['table'] = 'dosomething_fact';
  $handler->display->display_options['fields']['fact']['field'] = 'fact';
  $handler->display->display_options['fields']['fact']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['fact']['alter']['path'] = 'fact/[id]';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/fact/manage/[id]';
  /* Field: Fact: Source */
  $handler->display->display_options['fields']['source']['id'] = 'source';
  $handler->display->display_options['fields']['source']['table'] = 'dosomething_fact';
  $handler->display->display_options['fields']['source']['field'] = 'source';
  /* Field: Fact: Updated Date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'dosomething_fact';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'raw time ago';
  /* Field: Fact: Created Date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'dosomething_fact';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Filter criterion: Fact: Fact */
  $handler->display->display_options['filters']['fact']['id'] = 'fact';
  $handler->display->display_options['filters']['fact']['table'] = 'dosomething_fact';
  $handler->display->display_options['filters']['fact']['field'] = 'fact';
  $handler->display->display_options['filters']['fact']['operator'] = 'contains';
  $handler->display->display_options['filters']['fact']['exposed'] = TRUE;
  $handler->display->display_options['filters']['fact']['expose']['operator_id'] = 'fact_op';
  $handler->display->display_options['filters']['fact']['expose']['label'] = 'Label';
  $handler->display->display_options['filters']['fact']['expose']['operator'] = 'fact_op';
  $handler->display->display_options['filters']['fact']['expose']['identifier'] = 'fact';
  $handler->display->display_options['filters']['fact']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Fact: Source */
  $handler->display->display_options['filters']['source']['id'] = 'source';
  $handler->display->display_options['filters']['source']['table'] = 'dosomething_fact';
  $handler->display->display_options['filters']['source']['field'] = 'source';
  $handler->display->display_options['filters']['source']['operator'] = 'contains';
  $handler->display->display_options['filters']['source']['exposed'] = TRUE;
  $handler->display->display_options['filters']['source']['expose']['operator_id'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['label'] = 'Source';
  $handler->display->display_options['filters']['source']['expose']['operator'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['identifier'] = 'source';
  $handler->display->display_options['filters']['source']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/fact';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Facts';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['fact_search'] = $view;

  return $export;
}
