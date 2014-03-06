<?php
/**
 * @file
 * dosomething_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'explore_campaigns';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'Explore Campaigns';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Explore Campaigns';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '###Make the world suck less.  Check out one of these super easy, kickass campaigns.';
  $handler->display->display_options['header']['area']['format'] = 'markdown';
  /* Field: Apache Solr: ss_field_search_image */
  $handler->display->display_options['fields']['ss_field_search_image']['id'] = 'ss_field_search_image';
  $handler->display->display_options['fields']['ss_field_search_image']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_field_search_image']['field'] = 'ss_field_search_image';
  $handler->display->display_options['fields']['ss_field_search_image']['label'] = '';
  $handler->display->display_options['fields']['ss_field_search_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ss_field_search_image']['alter']['text'] = '<img src="[ss_field_search_image]"/>';
  $handler->display->display_options['fields']['ss_field_search_image']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_call_to_action */
  $handler->display->display_options['fields']['sm_field_call_to_action']['id'] = 'sm_field_call_to_action';
  $handler->display->display_options['fields']['sm_field_call_to_action']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_call_to_action']['field'] = 'sm_field_call_to_action';
  $handler->display->display_options['fields']['sm_field_call_to_action']['label'] = '';
  $handler->display->display_options['fields']['sm_field_call_to_action']['element_label_colon'] = FALSE;
  /* Filter criterion: Apache Solr: ss_field_search_image */
  $handler->display->display_options['filters']['ss_field_search_image']['id'] = 'ss_field_search_image';
  $handler->display->display_options['filters']['ss_field_search_image']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['ss_field_search_image']['field'] = 'ss_field_search_image';
  $handler->display->display_options['filters']['ss_field_search_image']['value'] = '[* TO *]';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'campaigns';
  $translatables['explore_campaigns'] = array(
    t('Master'),
    t('Explore Campaigns'),
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
    t('###Make the world suck less.  Check out one of these super easy, kickass campaigns.'),
    t('<img src="[ss_field_search_image]"/>'),
    t('Page'),
  );
  $export['explore_campaigns'] = $view;

  return $export;
}
