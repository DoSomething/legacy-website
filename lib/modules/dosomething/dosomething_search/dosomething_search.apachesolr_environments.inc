<?php
/**
 * @file
 * dosomething_search.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function dosomething_search_apachesolr_environments() {
  $export = array();
  
  $host = variable_get('apachesolr_host', '192.168.1.169');
  $port = variable_get('apachesolr_port', '8080');
  $path = variable_get('apachesolr_path', 'solr/collection1');

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'Solr Server';
  $environment->url = "http://{$host}:{$port}/{$path}";
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_index_last' => array(
      'node' => array(
        'last_changed' => '1394134209',
        'last_entity_id' => '919',
      ),
    ),
    'apachesolr_index_updated' => 1394134286,
    'apachesolr_last_optimize' => 1394126904,
    'apachesolr_search_changed_boost' => '0:0',
    'apachesolr_search_comment_boost' => '0:0',
    'apachesolr_search_date_boost' => '0:0',
    'apachesolr_search_promote_boost' => '0',
    'apachesolr_search_sticky_boost' => '0',
    'apachesolr_search_type_boosts' => array(
      'action_guide' => '0',
      'campaign' => '21.0',
      'campaign_group' => '21.0',
      'fact' => '0',
      'fact_page' => '0',
      'image' => '0',
      'static_content' => '0.1',
    ),
    'field_bias' => array(
      '_version_' => '0',
      'bm_field_display_end_date' => '0',
      'bm_field_location_finder' => '0',
      'bm_field_staff_pick' => '0',
      'bs_field_display_end_date' => '0',
      'bs_field_location_finder' => '0',
      'bs_field_staff_pick' => '0',
      'bs_promote' => '0',
      'bs_status' => '0',
      'bs_sticky' => '0',
      'bs_translate' => '0',
      'bundle' => '0',
      'bundle_name' => '0',
      'content' => '1.0',
      'dm_field_high_season' => '0',
      'dm_field_high_season_end' => '0',
      'dm_field_low_season' => '0',
      'dm_field_low_season_end' => '0',
      'ds_changed' => '0',
      'ds_created' => '0',
      'ds_last_comment_or_change' => '0',
      'entity_id' => '0',
      'entity_type' => '0',
      'fm_field_active_hours' => '0',
      'fs_field_active_hours' => '0',
      'hash' => '0',
      'id' => '0',
      'im_field_action_type' => '0',
      'im_field_cause' => '0',
      'im_field_issue' => '0',
      'im_field_primary_action_type' => '0',
      'im_field_primary_cause' => '0',
      'im_field_tags' => '0',
      'im_vid_1' => '0',
      'im_vid_2' => '0',
      'im_vid_3' => '0',
      'im_vid_5' => '0',
      'is_tnid' => '0',
      'is_uid' => '0',
      'itm_field_scholarship_amount' => '0',
      'its_field_scholarship_amount' => '0',
      'label' => '5.0',
      'path' => '0',
      'path_alias' => '0',
      'site' => '0',
      'sm_field_action_guide' => '0',
      'sm_field_additional_text_title' => '0',
      'sm_field_call_to_action' => '0',
      'sm_field_cta_button_text' => '0',
      'sm_field_fact_problem' => '0',
      'sm_field_fact_solution' => '0',
      'sm_field_facts' => '0',
      'sm_field_intro_image' => '0',
      'sm_field_intro_title' => '0',
      'sm_field_post_step_header' => '0',
      'sm_field_pre_step_header' => '0',
      'sm_field_reportback_noun' => '0',
      'sm_field_reportback_verb' => '0',
      'sm_field_subtitle' => '0',
      'sm_vid_Action_Type' => '0',
      'sm_vid_Cause' => '0',
      'sm_vid_Issue' => '0',
      'sm_vid_Tags' => '0',
      'sort_label' => '0',
      'sort_language' => '0',
      'sort_name' => '0',
      'sort_name_formatted' => '0',
      'spell' => '0',
      'ss_language' => '0',
      'ss_name' => '0',
      'ss_name_formatted' => '0',
      'tags_a' => '0',
      'tags_h1' => '5.0',
      'tags_h2_h3' => '3.0',
      'tags_h4_h5_h6' => '2.0',
      'tags_inline' => '1.0',
      'taxonomy_names' => '2.0',
      'tid' => '0',
      'timestamp' => '0',
      'tm_vid_1_names' => '0',
      'tm_vid_2_names' => '3.0',
      'tm_vid_3_names' => '3.0',
      'tm_vid_5_names' => '0',
      'tos_content_extra' => '0.1',
      'tos_name' => '0',
      'tos_name_formatted' => '0',
      'ts_comments' => '0',
      'url' => '0',
    ),
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'fact_page',
      1 => 'static_content',
      2 => 'campaign',
      3 => 'campaign_group',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
