<?php
/**
 * @file
 * dosomething_image.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_image_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'search_images';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Search images';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search Images';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Square Crop */
  $handler->display->display_options['fields']['field_image_square']['id'] = 'field_image_square';
  $handler->display->display_options['fields']['field_image_square']['table'] = 'field_data_field_image_square';
  $handler->display->display_options['fields']['field_image_square']['field'] = 'field_image_square';
  $handler->display->display_options['fields']['field_image_square']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_square']['settings'] = array(
    'image_style' => '50x50',
    'image_link' => '',
  );
  /* Field: Content: Landscape Crop */
  $handler->display->display_options['fields']['field_image_landscape']['id'] = 'field_image_landscape';
  $handler->display->display_options['fields']['field_image_landscape']['table'] = 'field_data_field_image_landscape';
  $handler->display->display_options['fields']['field_image_landscape']['field'] = 'field_image_landscape';
  $handler->display->display_options['fields']['field_image_landscape']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_landscape']['settings'] = array(
    'image_style' => '50x50',
    'image_link' => '',
  );
  /* Field: Content: Portrait Crop */
  $handler->display->display_options['fields']['field_image_portrait']['id'] = 'field_image_portrait';
  $handler->display->display_options['fields']['field_image_portrait']['table'] = 'field_data_field_image_portrait';
  $handler->display->display_options['fields']['field_image_portrait']['field'] = 'field_image_portrait';
  $handler->display->display_options['fields']['field_image_portrait']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_portrait']['settings'] = array(
    'image_style' => '50x50',
    'image_link' => '',
  );
  /* Field: Content: Cause */
  $handler->display->display_options['fields']['field_cause']['id'] = 'field_cause';
  $handler->display->display_options['fields']['field_cause']['table'] = 'field_data_field_cause';
  $handler->display->display_options['fields']['field_cause']['field'] = 'field_cause';
  $handler->display->display_options['fields']['field_cause']['delta_offset'] = '0';
  /* Field: Content: Image Tags */
  $handler->display->display_options['fields']['field_image_tags']['id'] = 'field_image_tags';
  $handler->display->display_options['fields']['field_image_tags']['table'] = 'field_data_field_image_tags';
  $handler->display->display_options['fields']['field_image_tags']['field'] = 'field_image_tags';
  $handler->display->display_options['fields']['field_image_tags']['label'] = 'Tags';
  $handler->display->display_options['fields']['field_image_tags']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'image' => 'image',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Image Tags (field_image_tags) */
  $handler->display->display_options['filters']['field_image_tags_tid']['id'] = 'field_image_tags_tid';
  $handler->display->display_options['filters']['field_image_tags_tid']['table'] = 'field_data_field_image_tags';
  $handler->display->display_options['filters']['field_image_tags_tid']['field'] = 'field_image_tags_tid';
  $handler->display->display_options['filters']['field_image_tags_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_image_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_image_tags_tid']['expose']['operator_id'] = 'field_image_tags_tid_op';
  $handler->display->display_options['filters']['field_image_tags_tid']['expose']['label'] = 'Image Tags';
  $handler->display->display_options['filters']['field_image_tags_tid']['expose']['operator'] = 'field_image_tags_tid_op';
  $handler->display->display_options['filters']['field_image_tags_tid']['expose']['identifier'] = 'field_image_tags_tid';
  $handler->display->display_options['filters']['field_image_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_image_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_image_tags_tid']['group_info']['label'] = 'Image Tags (field_image_tags)';
  $handler->display->display_options['filters']['field_image_tags_tid']['group_info']['identifier'] = 'field_image_tags_tid';
  $handler->display->display_options['filters']['field_image_tags_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_image_tags_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_image_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_image_tags_tid']['vocabulary'] = 'image_tags';
  /* Filter criterion: Content: Cause (field_cause) */
  $handler->display->display_options['filters']['field_cause_tid']['id'] = 'field_cause_tid';
  $handler->display->display_options['filters']['field_cause_tid']['table'] = 'field_data_field_cause';
  $handler->display->display_options['filters']['field_cause_tid']['field'] = 'field_cause_tid';
  $handler->display->display_options['filters']['field_cause_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_cause_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cause_tid']['expose']['operator_id'] = 'field_cause_tid_op';
  $handler->display->display_options['filters']['field_cause_tid']['expose']['label'] = 'Cause';
  $handler->display->display_options['filters']['field_cause_tid']['expose']['operator'] = 'field_cause_tid_op';
  $handler->display->display_options['filters']['field_cause_tid']['expose']['identifier'] = 'field_cause_tid';
  $handler->display->display_options['filters']['field_cause_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_cause_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_cause_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_cause_tid']['vocabulary'] = 'cause';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/images/search';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Search Images';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_image_square' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '([nid])';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Square Crop */
  $handler->display->display_options['fields']['field_image_square']['id'] = 'field_image_square';
  $handler->display->display_options['fields']['field_image_square']['table'] = 'field_data_field_image_square';
  $handler->display->display_options['fields']['field_image_square']['field'] = 'field_image_square';
  $handler->display->display_options['fields']['field_image_square']['label'] = '';
  $handler->display->display_options['fields']['field_image_square']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_square']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_square']['settings'] = array(
    'image_style' => '50x50',
    'image_link' => '',
  );
  $translatables['search_images'] = array(
    t('Master'),
    t('Search Images'),
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
    t('Title'),
    t('Edit link'),
    t('Nid'),
    t('Square Crop'),
    t('Landscape Crop'),
    t('Portrait Crop'),
    t('Cause'),
    t('Tags'),
    t('Image Tags'),
    t('Image Tags (field_image_tags)'),
    t('Page'),
    t('Entity Reference'),
    t('([nid])'),
  );
  $export['search_images'] = $view;

  return $export;
}
