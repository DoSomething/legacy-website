<?php
/**
 * @file
 * dosomething_campaign.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dosomething_campaign_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'field_collection_item-field_faq-field_compound_text_copy'
  $field_instances['field_collection_item-field_faq-field_compound_text_copy'] = array(
    'bundle' => 'field_faq',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_compound_text_copy',
    'label' => 'Answer',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_faq-field_compound_text_header'
  $field_instances['field_collection_item-field_faq-field_compound_text_header'] = array(
    'bundle' => 'field_faq',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_compound_text_header',
    'label' => 'Question',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_step_post-field_compound_text_copy'
  $field_instances['field_collection_item-field_step_post-field_compound_text_copy'] = array(
    'bundle' => 'field_step_post',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => ' Any tips for what the user should do after the action is finished. "Thank everyone who helped you put on the drive with a handwritten note."
<br/>
<strong> Limit: 135 characters </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_compound_text_copy',
    'label' => 'Copy',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_step_post-field_compound_text_header'
  $field_instances['field_collection_item-field_step_post-field_compound_text_header'] = array(
    'bundle' => 'field_step_post',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use active verbs. 
</br>
<strong> Limit 20 characters. </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_compound_text_header',
    'label' => 'Header',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_step_pre-field_compound_text_copy'
  $field_instances['field_collection_item-field_step_pre-field_compound_text_copy'] = array(
    'bundle' => 'field_step_pre',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is a tip to help the member during this step of the action. 
<br/>
<strong> Limit: 135 characters </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_compound_text_copy',
    'label' => 'Copy',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_step_pre-field_compound_text_header'
  $field_instances['field_collection_item-field_step_pre-field_compound_text_header'] = array(
    'bundle' => 'field_step_pre',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use active verbs. 
<br/>
<strong> Limit 20 characters. </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_compound_text_header',
    'label' => 'Header',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-campaign-field_action_guide'
  $field_instances['node-campaign-field_action_guide'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 60,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 0,
    'field_name' => 'field_action_guide',
    'label' => 'Action Guide',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-campaign-field_action_type'
  $field_instances['node-campaign-field_action_type'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Limit: 2 per campaign.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_action_type',
    'label' => 'Action Type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-campaign-field_active_hours'
  $field_instances['node-campaign-field_active_hours'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 21,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_active_hours',
    'label' => 'Active Hours',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-campaign-field_call_to_action'
  $field_instances['node-campaign-field_call_to_action'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is one simple, specific action. It tells our members exactly what the action is they are taking during the campaign. i.e. <em>"Create an action plan to protect prescription drugs in your home from young children."</em> or <em>"Send a handmade birthday card to a child experiencing homelessness."</em>
<p>This should always start with a verb and end with a period.</p>
<p><strong> Limit: 65 characters </strong></p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'pitch' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_call_to_action',
    'label' => 'Call to Action',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-campaign-field_cause'
  $field_instances['node-campaign-field_cause'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cause',
    'label' => 'Cause',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-campaign-field_confirmation_doc'
  $field_instances['node-campaign-field_confirmation_doc'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Include the link of the Google doc that proves the impact of the campaign.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 17,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_confirmation_doc',
    'label' => 'Proof of Impact',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-campaign-field_display_end_date'
  $field_instances['node-campaign-field_display_end_date'] = array(
    'bundle' => 'campaign',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 16,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_display_end_date',
    'label' => 'Show End Date on Pitch & Action Page',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-campaign-field_fact_problem'
  $field_instances['node-campaign-field_fact_problem'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Compels people to care about the issue. i.e. <i>1 in 3 homeless people are under the age of 18.</i>
<br/>
<strong> Limit: 135 characters </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 8,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 0,
    'field_name' => 'field_fact_problem',
    'label' => 'Problem Fact',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-campaign-field_fact_solution'
  $field_instances['node-campaign-field_fact_solution'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Information that shows that the call to action is what to do to solve the issue. If using a fact, create a fact and reference it here.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 9,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 0,
    'field_name' => 'field_fact_solution',
    'label' => 'Solution Fact',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-campaign-field_facts'
  $field_instances['node-campaign-field_facts'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This will open up as a separate modal. Only fill this out if you have 3+ stats you want the user to learn about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 13,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 0,
    'field_name' => 'field_facts',
    'label' => 'Facts',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-campaign-field_faq'
  $field_instances['node-campaign-field_faq'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 31,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_faq',
    'label' => 'FAQ',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-campaign-field_high_season'
  $field_instances['node-campaign-field_high_season'] = array(
    'bundle' => 'campaign',
    'deleted' => 0,
    'description' => 'Is there a time when this campaign should be heavily weighted and highly promoted in the campaign finder? If so, include a start date. Includes things like staff pick campaigns, beach cleanups (summer months), campaign ideas for the holidays, etc.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 14,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_high_season',
    'label' => 'High Season',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'blank',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'custom',
        'input_format_custom' => 'M-d-Y',
        'label_position' => 'within',
        'text_parts' => array(),
        'year_range' => '-0:+1',
      ),
      'type' => 'date_select',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-campaign-field_image_campaign_cover'
  $field_instances['node-campaign-field_image_campaign_cover'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 5,
      ),
      'pitch' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(),
        'type' => 'entityreference_entity_id',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image_campaign_cover',
    'label' => 'Cover Image',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-campaign-field_image_psa_replacement'
  $field_instances['node-campaign-field_image_psa_replacement'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If there is no PSA then this image is required.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 38,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image_psa_replacement',
    'label' => 'PSA Replacement Image',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-campaign-field_image_reportback_gallery'
  $field_instances['node-campaign-field_image_reportback_gallery'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 50,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image_reportback_gallery',
    'label' => 'Prove it Gallery',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-campaign-field_image_step_gallery'
  $field_instances['node-campaign-field_image_step_gallery'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 49,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image_step_gallery',
    'label' => 'Do It Gallery',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-campaign-field_issue'
  $field_instances['node-campaign-field_issue'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 53,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_issue',
    'label' => 'Issue',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-campaign-field_items_needed'
  $field_instances['node-campaign-field_items_needed'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is a list of the items you\'ll need to complete the action. This section should just be a set of bullet points (i.e. no sentence introducing the bullets). 
<p>
<li>To create bullet points put "* " in front of the word. For instance <em>"* paper * crayons * smiles"</em> </li>
<li>Capitalize the first letter of the first word in a list (i.e. <em>* Peanuts</em> NOT <em>* peanuts</em>).</li>
<li>Don\'t use articles in a list (i.e. <em>* Car</em> NOT <em>* A Car</em>).</li>
<li>Use periods after the end of a list item if it\'s a sentence or long fragment, but do not use a period if it\'s a single item.</li>
</ul>
</p>
<strong> Limit: 135  </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 27,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_items_needed',
    'label' => 'Stuff You Need',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-campaign-field_location_finder'
  $field_instances['node-campaign-field_location_finder'] = array(
    'bundle' => 'campaign',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 29,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_location_finder',
    'label' => 'Internal Location Finder Needed',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-campaign-field_location_finder_copy'
  $field_instances['node-campaign-field_location_finder_copy'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is to describe what the location should be used for and any notes the user needs when using the finder. i.e. <i>Find a local food bank that accepts donations. Call them to arrange drop off in advance.</i><br>
<strong>Limit 120 characters.</strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 57,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_location_finder_copy',
    'label' => 'Location Finder Copy',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-campaign-field_location_finder_url'
  $field_instances['node-campaign-field_location_finder_url'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 58,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_location_finder_url',
    'label' => 'External Location Finder URL',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-campaign-field_low_season'
  $field_instances['node-campaign-field_low_season'] = array(
    'bundle' => 'campaign',
    'deleted' => 0,
    'description' => 'Is there a time when this campaign should be lightly weighted in the campaign finder? If so include a start date. We don\'t want to be highlighting beach cleanups in the winter or Thanksgiving ideas in the summer.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 15,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_low_season',
    'label' => 'Low Season',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'blank',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'custom',
        'input_format_custom' => 'M-d-Y',
        'label_position' => 'within',
        'text_parts' => array(),
        'year_range' => '-0:+1',
      ),
      'type' => 'date_select',
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'node-campaign-field_official_rules'
  $field_instances['node-campaign-field_official_rules'] = array(
    'bundle' => 'campaign',
    'deleted' => 0,
    'description' => 'If there is a prize to be won, you must include a PDF of the official rules.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 35,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_official_rules',
    'label' => 'Official Rules',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'offical-rules',
      'file_extensions' => 'txt pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-campaign-field_photo_step'
  $field_instances['node-campaign-field_photo_step'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is the step where the user should take a photo confirming that their action took place. i.e. Take a photo of the jeans you collected and everyone who donated. 
<br/>
<strong> Limit: 135 characters </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 43,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_photo_step',
    'label' => 'Snap a Pic',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 46,
    ),
  );

  // Exported field_instance: 'node-campaign-field_post_step_copy'
  $field_instances['node-campaign-field_post_step_copy'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This describes the action the user must take after they take a picture. I.e. "Drop off the food you collected at your local food bank at the time you decided. Then pat yourself on the back like the boss you are."; "Check in with the senior center two weeks later. See if they’ve been acting safer with the tip sheets and condoms - no details needed.".
<br/>
<strong> Limit 135 characters. </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_post_step_copy',
    'label' => 'After Copy',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 48,
    ),
  );

  // Exported field_instance: 'node-campaign-field_post_step_header'
  $field_instances['node-campaign-field_post_step_header'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Must start with a verb. Should not have any punctuation. Encompass what the user should do after taking the picture i.e. Deliver The Food or Follow Up.
<br/>
<strong> Limit 25 characters. </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 47,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_post_step_header',
    'label' => 'After Header',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 47,
    ),
  );

  // Exported field_instance: 'node-campaign-field_pre_step_copy'
  $field_instances['node-campaign-field_pre_step_copy'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This describes the action the user must take before they can take a picture. I.e. "Set up a collection box outside the store. Tell people about your drive before they walk in - see the food pile up when they walk out."; "Head to the senior center or retirement home and hand out condoms to seniors in need (get it). Don’t forget the instructions!". 
<br/>
<strong> Limit 135 characters. </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 46,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pre_step_copy',
    'label' => 'During Copy',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 44,
    ),
  );

  // Exported field_instance: 'node-campaign-field_pre_step_header'
  $field_instances['node-campaign-field_pre_step_header'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Must start with a verb. Must end with a !. Encompass what the user needs to do before taking a picture i.e. Run Your Drive!, Hand Out Condoms!, Hide The Pills!"
<br/>
<strong> Limit 25 characters. </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 45,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pre_step_header',
    'label' => 'During Header',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 43,
    ),
  );

  // Exported field_instance: 'node-campaign-field_primary_action_type'
  $field_instances['node-campaign-field_primary_action_type'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 55,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_primary_action_type',
    'label' => 'Primary Action Type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-campaign-field_primary_cause'
  $field_instances['node-campaign-field_primary_cause'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 54,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_primary_cause',
    'label' => 'Primary Cause',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-campaign-field_promoting_tips'
  $field_instances['node-campaign-field_promoting_tips'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is for tips on promoting the campaign once it\'s live - hanging posters, to social media tips, to getting local press... 
<br/>
<strong> Limit: 135 character </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 28,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_promoting_tips',
    'label' => 'Hype',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-campaign-field_psa'
  $field_instances['node-campaign-field_psa'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The ID of the youtube video <strong> (comes after the ?v=) </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 51,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_psa',
    'label' => 'PSA',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-campaign-field_reportback_confirm_msg'
  $field_instances['node-campaign-field_reportback_confirm_msg'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Sentence user sees after reporting back. I.e. You kicked ass making birthday cards for children in need. 
<br/>
<strong> Limit 60 characters. </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 44,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_reportback_confirm_msg',
    'label' => 'Report Back Confirmation Sentence',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-campaign-field_reportback_copy'
  $field_instances['node-campaign-field_reportback_copy'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 52,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_reportback_copy',
    'label' => 'Report Back Copy',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-campaign-field_reportback_noun'
  $field_instances['node-campaign-field_reportback_noun'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'i.e. JEANS collected, SENIOR CITIZENS educated, FLYERS posted. Your responses should not be in all caps though, instead write - Jeans',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_reportback_noun',
    'label' => 'Report Back Noun',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-campaign-field_reportback_verb'
  $field_instances['node-campaign-field_reportback_verb'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'i.e. jeans COLLECTED, senior citizens EDUCATED, flyers POSTED. Your responses should not be in all caps though, instead write - Collected',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 23,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_reportback_verb',
    'label' => 'Report Back Verb',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-campaign-field_scholarship_amount'
  $field_instances['node-campaign-field_scholarship_amount'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If there is a scholarship, enter the dollar amount here. If there is no scholarship, leave this field blank.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 34,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_scholarship_amount',
    'label' => 'Scholarship Amount',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '$',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-campaign-field_solution_copy'
  $field_instances['node-campaign-field_solution_copy'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If you are not using a fact above, use this field. This is information that shows that the call to action is what to do to solve the issue.
<br />
<strong>Limit: 135 characters</strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 59,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_solution_copy',
    'label' => 'Solution Statement',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-campaign-field_solution_support'
  $field_instances['node-campaign-field_solution_support'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If you need more clarification on the solution statement. (i.e., "Last year, teens who got thumb socks were less likely to text and drive and more likely to ask others to stop.") 
<br/>
<strong> Limit: 135 characters </strong>
',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_solution_support',
    'label' => 'Supporting Statement on the Solution',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-campaign-field_sponsor'
  $field_instances['node-campaign-field_sponsor'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 7,
      ),
      'pitch' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sponsor',
    'label' => 'Sponsor',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-campaign-field_staff_pick'
  $field_instances['node-campaign-field_staff_pick'] = array(
    'bundle' => 'campaign',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 20,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_staff_pick',
    'label' => 'Is Staff Pick',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-campaign-field_starter_statement'
  $field_instances['node-campaign-field_starter_statement'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The first thing they need to know. Could be general advice "start planning two weeks in advance" or pointing out the most important thing to do "as you plan, don\'t forget to get permission!".
<br/>
<strong> Limit: 135 characters </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_starter_statement',
    'label' => 'Campaign Specific Starter Statement',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-campaign-field_step_post'
  $field_instances['node-campaign-field_step_post'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 33,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_step_post',
    'label' => 'After Tips',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 49,
    ),
  );

  // Exported field_instance: 'node-campaign-field_step_pre'
  $field_instances['node-campaign-field_step_pre'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 32,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_step_pre',
    'label' => 'During Tips',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 45,
    ),
  );

  // Exported field_instance: 'node-campaign-field_tags'
  $field_instances['node-campaign-field_tags'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Include any key words or phrases we want to associate for both external and internal search. i.e. Music, Hospital, Children, Kids for the campaign "Put on a concert in a Children\'s Hospital". Also could include celebrity tied to the campaign like Miley Cyrus. 
<br/>
<strong> Please use commas to separate terms. </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 4,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-campaign-field_time_and_place'
  $field_instances['node-campaign-field_time_and_place'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This should include advice about both timing and location. "Put your donation box in a place where lots of people walk by." "Have your drive run for at least a week to give people a chance to donate." 
<br/>
<strong> Limit: 135 characters </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 25,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_time_and_place',
    'label' => 'Time and Place',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-campaign-field_vips'
  $field_instances['node-campaign-field_vips'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This should include info on people you may need to involve. Ranges from getting permission from your principal, to getting your artsy friend involved to make a compelling poster, to how you pick a friend who texts and drives for Thumb Wars. 
<br/>
<strong> Limit: 135 characters </strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 26,
      ),
      'pitch' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_vips',
    'label' => 'VIPs',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 15,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t(' Any tips for what the user should do after the action is finished. "Thank everyone who helped you put on the drive with a handwritten note."
<br/>
<strong> Limit: 135 characters </strong>');
  t('Action Guide');
  t('Action Type');
  t('Active Hours');
  t('After Copy');
  t('After Header');
  t('After Tips');
  t('Answer');
  t('Call to Action');
  t('Campaign Specific Starter Statement');
  t('Cause');
  t('Compels people to care about the issue. i.e. <i>1 in 3 homeless people are under the age of 18.</i>
<br/>
<strong> Limit: 135 characters </strong>');
  t('Copy');
  t('Cover Image');
  t('Do It Gallery');
  t('During Copy');
  t('During Header');
  t('During Tips');
  t('External Location Finder URL');
  t('FAQ');
  t('Facts');
  t('Header');
  t('High Season');
  t('Hype');
  t('If there is a prize to be won, you must include a PDF of the official rules.');
  t('If there is a scholarship, enter the dollar amount here. If there is no scholarship, leave this field blank.');
  t('If there is no PSA then this image is required.');
  t('If you are not using a fact above, use this field. This is information that shows that the call to action is what to do to solve the issue.
<br />
<strong>Limit: 135 characters</strong>');
  t('If you need more clarification on the solution statement. (i.e., "Last year, teens who got thumb socks were less likely to text and drive and more likely to ask others to stop.") 
<br/>
<strong> Limit: 135 characters </strong>
');
  t('Include any key words or phrases we want to associate for both external and internal search. i.e. Music, Hospital, Children, Kids for the campaign "Put on a concert in a Children\'s Hospital". Also could include celebrity tied to the campaign like Miley Cyrus. 
<br/>
<strong> Please use commas to separate terms. </strong>');
  t('Include the link of the Google doc that proves the impact of the campaign.');
  t('Information that shows that the call to action is what to do to solve the issue. If using a fact, create a fact and reference it here.');
  t('Internal Location Finder Needed');
  t('Is Staff Pick');
  t('Is there a time when this campaign should be heavily weighted and highly promoted in the campaign finder? If so, include a start date. Includes things like staff pick campaigns, beach cleanups (summer months), campaign ideas for the holidays, etc.');
  t('Is there a time when this campaign should be lightly weighted in the campaign finder? If so include a start date. We don\'t want to be highlighting beach cleanups in the winter or Thanksgiving ideas in the summer.');
  t('Issue');
  t('Limit: 2 per campaign.');
  t('Location Finder Copy');
  t('Low Season');
  t('Must start with a verb. Must end with a !. Encompass what the user needs to do before taking a picture i.e. Run Your Drive!, Hand Out Condoms!, Hide The Pills!"
<br/>
<strong> Limit 25 characters. </strong>');
  t('Must start with a verb. Should not have any punctuation. Encompass what the user should do after taking the picture i.e. Deliver The Food or Follow Up.
<br/>
<strong> Limit 25 characters. </strong>');
  t('Official Rules');
  t('PSA');
  t('PSA Replacement Image');
  t('Primary Action Type');
  t('Primary Cause');
  t('Problem Fact');
  t('Proof of Impact');
  t('Prove it Gallery');
  t('Question');
  t('Report Back Confirmation Sentence');
  t('Report Back Copy');
  t('Report Back Noun');
  t('Report Back Verb');
  t('Scholarship Amount');
  t('Sentence user sees after reporting back. I.e. You kicked ass making birthday cards for children in need. 
<br/>
<strong> Limit 60 characters. </strong>');
  t('Show End Date on Pitch & Action Page');
  t('Snap a Pic');
  t('Solution Fact');
  t('Solution Statement');
  t('Sponsor');
  t('Stuff You Need');
  t('Supporting Statement on the Solution');
  t('Tags');
  t('The ID of the youtube video <strong> (comes after the ?v=) </strong>');
  t('The first thing they need to know. Could be general advice "start planning two weeks in advance" or pointing out the most important thing to do "as you plan, don\'t forget to get permission!".
<br/>
<strong> Limit: 135 characters </strong>');
  t('This describes the action the user must take after they take a picture. I.e. "Drop off the food you collected at your local food bank at the time you decided. Then pat yourself on the back like the boss you are."; "Check in with the senior center two weeks later. See if they’ve been acting safer with the tip sheets and condoms - no details needed.".
<br/>
<strong> Limit 135 characters. </strong>');
  t('This describes the action the user must take before they can take a picture. I.e. "Set up a collection box outside the store. Tell people about your drive before they walk in - see the food pile up when they walk out."; "Head to the senior center or retirement home and hand out condoms to seniors in need (get it). Don’t forget the instructions!". 
<br/>
<strong> Limit 135 characters. </strong>');
  t('This is a list of the items you\'ll need to complete the action. This section should just be a set of bullet points (i.e. no sentence introducing the bullets). 
<p>
<li>To create bullet points put "* " in front of the word. For instance <em>"* paper * crayons * smiles"</em> </li>
<li>Capitalize the first letter of the first word in a list (i.e. <em>* Peanuts</em> NOT <em>* peanuts</em>).</li>
<li>Don\'t use articles in a list (i.e. <em>* Car</em> NOT <em>* A Car</em>).</li>
<li>Use periods after the end of a list item if it\'s a sentence or long fragment, but do not use a period if it\'s a single item.</li>
</ul>
</p>
<strong> Limit: 135  </strong>');
  t('This is a tip to help the member during this step of the action. 
<br/>
<strong> Limit: 135 characters </strong>');
  t('This is for tips on promoting the campaign once it\'s live - hanging posters, to social media tips, to getting local press... 
<br/>
<strong> Limit: 135 character </strong>');
  t('This is one simple, specific action. It tells our members exactly what the action is they are taking during the campaign. i.e. <em>"Create an action plan to protect prescription drugs in your home from young children."</em> or <em>"Send a handmade birthday card to a child experiencing homelessness."</em>
<p>This should always start with a verb and end with a period.</p>
<p><strong> Limit: 65 characters </strong></p>');
  t('This is the step where the user should take a photo confirming that their action took place. i.e. Take a photo of the jeans you collected and everyone who donated. 
<br/>
<strong> Limit: 135 characters </strong>');
  t('This is to describe what the location should be used for and any notes the user needs when using the finder. i.e. <i>Find a local food bank that accepts donations. Call them to arrange drop off in advance.</i><br>
<strong>Limit 120 characters.</strong>');
  t('This should include advice about both timing and location. "Put your donation box in a place where lots of people walk by." "Have your drive run for at least a week to give people a chance to donate." 
<br/>
<strong> Limit: 135 characters </strong>');
  t('This should include info on people you may need to involve. Ranges from getting permission from your principal, to getting your artsy friend involved to make a compelling poster, to how you pick a friend who texts and drives for Thumb Wars. 
<br/>
<strong> Limit: 135 characters </strong>');
  t('This will open up as a separate modal. Only fill this out if you have 3+ stats you want the user to learn about.');
  t('Time and Place');
  t('Use active verbs. 
</br>
<strong> Limit 20 characters. </strong>');
  t('Use active verbs. 
<br/>
<strong> Limit 20 characters. </strong>');
  t('VIPs');
  t('i.e. JEANS collected, SENIOR CITIZENS educated, FLYERS posted. Your responses should not be in all caps though, instead write - Jeans');
  t('i.e. jeans COLLECTED, senior citizens EDUCATED, flyers POSTED. Your responses should not be in all caps though, instead write - Collected');

  return $field_instances;
}
