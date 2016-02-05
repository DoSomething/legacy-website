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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grouping_limit';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'entity_id',
      'rendered' => 0,
      'rendered_strip' => 1,
      'grouping-limit' => array(
        'grouping-limit' => '1',
        'grouping-offset' => '0',
      ),
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '###Make the world suck less. Choose a campaign below to get started.';
  $handler->display->display_options['header']['area']['format'] = 'markdown';
  /* Field: Entity ID for grouping */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['ui_name'] = 'Entity ID for grouping';
  $handler->display->display_options['fields']['entity_id']['label'] = '';
  $handler->display->display_options['fields']['entity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['entity_id']['element_type'] = '0';
  $handler->display->display_options['fields']['entity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['entity_id']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['entity_id']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: path_alias */
  $handler->display->display_options['fields']['path_alias']['id'] = 'path_alias';
  $handler->display->display_options['fields']['path_alias']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['path_alias']['field'] = 'path_alias';
  $handler->display->display_options['fields']['path_alias']['label'] = '';
  $handler->display->display_options['fields']['path_alias']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path_alias']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: ss_field_search_image_300x300 */
  $handler->display->display_options['fields']['ss_field_search_image_300x300']['id'] = 'ss_field_search_image_300x300';
  $handler->display->display_options['fields']['ss_field_search_image_300x300']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_field_search_image_300x300']['field'] = 'ss_field_search_image_300x300';
  $handler->display->display_options['fields']['ss_field_search_image_300x300']['label'] = '';
  $handler->display->display_options['fields']['ss_field_search_image_300x300']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ss_field_search_image_300x300']['alter']['text'] = '<img src="[ss_field_search_image_300x300]"/>';
  $handler->display->display_options['fields']['ss_field_search_image_300x300']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['ss_field_search_image_300x300']['alter']['path'] = '[path_alias]?source=campaigns';
  $handler->display->display_options['fields']['ss_field_search_image_300x300']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['path'] = '[path_alias]?source=campaigns';
  $handler->display->display_options['fields']['label']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['alt'] = '[label]';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_call_to_action */
  $handler->display->display_options['fields']['sm_field_call_to_action']['id'] = 'sm_field_call_to_action';
  $handler->display->display_options['fields']['sm_field_call_to_action']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_call_to_action']['field'] = 'sm_field_call_to_action';
  $handler->display->display_options['fields']['sm_field_call_to_action']['label'] = '';
  $handler->display->display_options['fields']['sm_field_call_to_action']['element_label_colon'] = FALSE;
  /* Filter criterion: Apache Solr: ss_field_search_image_300x300 */
  $handler->display->display_options['filters']['ss_field_search_image_300x300']['id'] = 'ss_field_search_image_300x300';
  $handler->display->display_options['filters']['ss_field_search_image_300x300']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['ss_field_search_image_300x300']['field'] = 'ss_field_search_image_300x300';
  $handler->display->display_options['filters']['ss_field_search_image_300x300']['value'] = '[* TO *]';
  /* Filter criterion: Apache Solr: sm_field_campaign_status */
  $handler->display->display_options['filters']['sm_field_campaign_status']['id'] = 'sm_field_campaign_status';
  $handler->display->display_options['filters']['sm_field_campaign_status']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['sm_field_campaign_status']['field'] = 'sm_field_campaign_status';
  $handler->display->display_options['filters']['sm_field_campaign_status']['operator'] = '!=';
  $handler->display->display_options['filters']['sm_field_campaign_status']['value'] = 'closed';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['metatags'] = array(
    'und' => array(
      'title' => array(
        'value' => 'Social Change Volunteer Opportunities with DoSomething.org',
        'default' => '[view:title] | [site:name]',
      ),
      'description' => array(
        'value' => 'Over 200 social change volunteer and community service opportunities.',
        'default' => '[view:description]',
      ),
      'abstract' => array(
        'value' => 'Over 200 social change volunteer and community service opportunities.',
        'default' => 'Largest organization for social change volunteers and community service, with [site:member-count] members and counting.',
      ),
      'keywords' => array(
        'value' => '',
        'default' => '',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
        'default' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
        'default' => '',
      ),
      'standout' => array(
        'value' => '',
        'default' => '',
      ),
      'rights' => array(
        'value' => '',
        'default' => '',
      ),
      'image_src' => array(
        'value' => '',
        'default' => '',
      ),
      'canonical' => array(
        'value' => '[view:url]',
        'default' => '[view:url]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
        'default' => '[current-page:url:unaliased]',
      ),
      'publisher' => array(
        'value' => '',
        'default' => '',
      ),
      'author' => array(
        'value' => '',
        'default' => '',
      ),
      'original-source' => array(
        'value' => '',
        'default' => '',
      ),
      'revisit-after' => array(
        'value' => '',
        'period' => '',
        'default' => '',
      ),
      'content-language' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:card' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:creator' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:creator:id' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:url' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:title' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:description' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:image:src' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:image:width' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:image:height' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:image0' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:image1' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:image2' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:image3' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:player' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:player:width' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:player:height' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:player:stream' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:player:stream:content_type' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:app:country' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:app:name:iphone' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:app:id:iphone' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:app:url:iphone' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:app:name:ipad' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:app:id:ipad' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:app:url:ipad' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:app:name:googleplay' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:app:id:googleplay' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:app:url:googleplay' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:label1' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:data1' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:label2' => array(
        'value' => '',
        'default' => '',
      ),
      'twitter:data2' => array(
        'value' => '',
        'default' => '',
      ),
    ),
  );
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
    t('###Make the world suck less. Choose a campaign below to get started.'),
    t('<img src="[ss_field_search_image_300x300]"/>'),
    t('[label]'),
    t('Page'),
  );
  $export['explore_campaigns'] = $view;

  return $export;
}
