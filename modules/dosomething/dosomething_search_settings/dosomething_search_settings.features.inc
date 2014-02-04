<?php
/**
 * @file
 * dosomething_search_settings.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function dosomething_search_settings_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : { "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] } },
      "processors" : {
        "search_api_case_ignore" : { "status" : 1, "weight" : "0", "settings" : { "strings" : 0 } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\nh2 = 3\\nh3 = 2\\nstrong = 2\\nb = 2\\nem = 1.5\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : { "spaces" : "[^\\\\p{L}\\\\p{N}]", "ignorable" : "[-]" }
        }
      },
      "fields" : {
        "nid" : { "type" : "integer" },
        "vid" : { "type" : "integer" },
        "type" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "url" : { "type" : "uri" },
        "status" : { "type" : "integer" },
        "promote" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "source" : { "type" : "integer", "entity_type" : "node" },
        "log" : { "type" : "text" },
        "revision" : { "type" : "boolean" },
        "uuid" : { "type" : "text" },
        "vuuid" : { "type" : "text" },
        "field_action_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_cause" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_sponsor" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_active_hours" : { "type" : "decimal" },
        "field_call_to_action" : { "type" : "text" },
        "field_display_end_date" : { "type" : "boolean" },
        "field_fact_problem" : { "type" : "integer", "entity_type" : "fact" },
        "field_fact_solution" : { "type" : "integer", "entity_type" : "fact" },
        "field_facts" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "fact" },
        "field_image_campaign_cover" : { "type" : "integer", "entity_type" : "node" },
        "field_image_campaign_gallery" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_location_finder" : { "type" : "boolean" },
        "field_report_back_noun" : { "type" : "text" },
        "field_report_back_verb" : { "type" : "text" },
        "field_staff_pick" : { "type" : "boolean" },
        "field_step_photo" : { "type" : "text" },
        "field_gallery" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_hero_image" : { "type" : "integer", "entity_type" : "node" },
        "field_intro_title" : { "type" : "text" },
        "field_intro_image" : { "type" : "integer", "entity_type" : "node" },
        "field_intro" : { "type" : "text" },
        "field_subtitle" : { "type" : "text" },
        "field_additional_text_title" : { "type" : "text" },
        "field_additional_text" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" },
        "body:format" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function dosomething_search_settings_default_search_api_server() {
  $items = array();
  $items['solr'] = entity_import('search_api_server', '{
    "name" : "Solr",
    "machine_name" : "solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/collection1",
      "http_user" : "admin",
      "http_pass" : "password",
      "excerpt" : 0,
      "retrieve_data" : 1,
      "highlight_data" : 0,
      "http_method" : "AUTO"
    },
    "enabled" : "1"
  }');
  return $items;
}
