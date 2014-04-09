
<?php
/**
 * @file
 * Preprocess functions for the dosomething_campaign module.
 */

/**
 * Implements hook_preprocess_node().
 */
function dosomething_campaign_preprocess_node(&$vars) {
  if ($vars['type'] != 'campaign') { return; }

  // Are we on a the action/pitch page?
  if ($vars['view_mode'] == 'pitch' || $vars['view_mode'] == 'full') {

    $node = menu_get_object();
    $wrapper = entity_metadata_wrapper('node', $node);

    $scholarship = $wrapper->field_scholarship_amount->value();
    if (isset($scholarship)) {
      $vars['scholarship'] = '$' . number_format($scholarship, 0, '', ',') . ' Scholarship';
    }

    $vars['cta'] = $wrapper->field_call_to_action->value();

    // Timing.
    $display_date = $wrapper->field_display_end_date->value();
    // Check if there is a value in the date field.
    $high_season = $wrapper->field_high_season->value();
    if ($display_date == 1 && isset($high_season)) {
      $end_date = date('F d', $wrapper->field_high_season->value2->value());
      $vars['end_date'] = 'Ends ' . $end_date;
    }

    // Hero Images.
    if (isset($vars['field_image_campaign_cover'][0])) {
      $hero_nid = $vars['field_image_campaign_cover'][0]['entity']->nid;
      $vars['hero_image_l'] = dosomething_image_get_themed_image($hero_nid, 'landscape', '1440x810');
      $vars['hero_image_m'] = dosomething_image_get_themed_image($hero_nid, 'square', '768x768');
      $vars['hero_image_l_url'] = dosomething_image_get_themed_image_url($hero_nid, 'landscape', '1440x810');
      $vars['hero_image_m_url'] = dosomething_image_get_themed_image_url($hero_nid, 'square', '768x768');
    }

    isset($vars['hero_image_m_url']) ? $vars['hero_image']['mobile'] = $vars['hero_image_m_url'] : NULL ;
    isset($vars['hero_image_l_url']) ? $vars['hero_image']['desktop'] = $vars['hero_image_l_url'] : NULL ;

    if (!empty($vars['field_partners'])) {
      // Sets partners, sponsors, and partner_info arrays if present.
      dosomething_campaign_preprocess_partners_vars($vars);
      dosomething_campaign_format_partnerts_list($vars);
    }

    // Preprocess any custom campaign variables.
    dosomething_campaign_preprocess_custom_vars($vars);

    // Add inline css based on vars.
    dosomething_campaign_add_inline_css($vars);

    if ($vars['view_mode'] == 'pitch') {
      // Use the pitch page template to theme.
      $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__pitch';
      // Gather vars for pitch page.
      dosomething_campaign_preprocess_pitch_page($vars, $wrapper);
    }
    elseif ($vars['view_mode'] == 'full'){
      // Gather the vars for the action page.
      dosomething_campaign_preprocess_action_page($vars, $wrapper);
    }
  }
}
/**
 * Returns a list of partners formatted correctly
 *
 * If there are two partners, seperate them with "and"
 * If there are three or more partners a comma seperating each and "and" before the last.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.
 */
function dosomething_campaign_format_partnerts_list(&$vars) {
  $partners = $vars['partners'];
  $formatted_partners = '';
  foreach ($partners as $key => $partner) {
    $formatted_partners .= $partner['name'];
    if (count($partners) > 2 && $key == (count($partners) -2)) {
      $formatted_partners .= ' and ';
    }
    elseif (count($partners) > 2 && $key < (count($partners) -1)) {
      $formatted_partners .= ', ';
    }
    elseif ($key < (count($partners) -1)) {
      $formatted_partners .= ' and ';
    }
  }
  $vars['formatted_partners'] = $formatted_partners;
}

/**
 * Adds inline css into HEAD based on current state of vars.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.
 */
function dosomething_campaign_add_inline_css(&$vars) {
  // Check for alt_color variable.
  if (isset($vars['alt_color'])) {
    $alt_color = 'color: #' .  $vars['alt_color'] . ' !important;';
    $style_alt_color = '.inline--alt-color { ' . $alt_color . ' }';
    drupal_add_css($style_alt_color, $option['type'] = 'inline');
  }

  // Add hero background images if set
  if (isset($vars['hero_image']['mobile']) && isset($vars['hero_image']['desktop'])) {
    $style_hero_image = '.campaign--wrapper header.header {
        background-image: url("' . $vars['hero_image']['mobile'] . '");
      }

      @media only screen and (min-width: 768px) {
        .campaign--wrapper header.header {
          background-image: url("' . $vars['hero_image']['desktop'] . '");
        }
      }';
    drupal_add_css($style_hero_image, $option['type'] = 'inline');
  }

  // Set alt sponsor bg for modals
  if (isset($vars['alt_bg_src'])) {
    $alt_bg = 'background-image: url("' . $vars['alt_bg_src'] . '") !important;';
    $style_alt_background = '.inline--alt-bg { ' . $alt_bg . ' }';

    drupal_add_css($style_alt_background, $option['type'] = 'inline');
  }

}

/**
 * Preprocesses variables for any custom settings.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.
 */
function dosomething_campaign_preprocess_custom_vars(&$vars) {
  // Get prefix to check for custom campaign variables.
  $prefix = dosomething_campaign_get_custom_var_prefix($vars['nid']);
  // Check for custom alt color.
  $alt_color = variable_get($prefix . 'alt_color');
  if (!empty($alt_color)) {
    // Sanitize value for sanity's sake.
    $vars['alt_color'] = strip_tags($alt_color);
  }
  // Check for alt background File fid.
  $fid = variable_get($prefix . 'alt_bg_fid');
  if (!empty($fid)) {
    $file = file_load($fid);
    $vars['alt_bg_src'] = file_create_url($file->uri);
  }
}

/**
 * Preprocesses variables for a campaign sponsors, partners, and partner info.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.
 */
function dosomething_campaign_preprocess_partners_vars(&$vars) {
  // Returns partners, sponsors, and partner_info arrays.
  $partners_vars = dosomething_taxonomy_get_partners_vars($vars['nid']);
  // Gather any returned arrays.
  foreach ($partners_vars as $key => $values) {
    $vars[$key] = $values;
  }
  // Preprocess sponsor logos.
  if (isset($vars['sponsors'])) {
    foreach ($vars['sponsors'] as $delta => $sponsor) {
      $vars['sponsors'][$delta]['name'] = $sponsor['name'];
      // If there is a file present for sponsor logo:
      if (isset($sponsor['fid'])) {
        $img = dosomething_image_get_themed_image_by_fid($sponsor['fid'], 'wmax-423px', $sponsor['name']);
        $vars['sponsors'][$delta]['img'] = $img;
        // Set the display variable as the image.  This is outputted to tpl.
        $vars['sponsors'][$delta]['display'] = $img;
      }
      // Else if no file:
      else {
        // Return null so we won't display anything
        $vars['sponsors'][$delta]['display'] = NULL;
      }
    }
  }
  // Preprocess partner info modals.
  if (isset($vars['partner_info'])) {
    foreach ($vars['partner_info'] as $delta => $info) {
      // If image landscape field is set:
      $image_node = $info['image'];
      if (!empty($image_node->field_image_landscape)) {
        $img = dosomething_image_get_themed_image($image_node->nid, 'landscape', '550x300');
        $vars['partner_info'][$delta]['image'] = $img;
      }
    }
  }
}

/**
 * Preprocesses variables for a campaign action page.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.
 * @param object $wrapper
 *   The corresponding entity wrapper for the node in $vars.
 */
function dosomething_campaign_preprocess_action_page(&$vars, &$wrapper) {
  // Know.
  $vars['solution_copy'] = $wrapper->field_solution_copy->value();
  $vars['solution_support'] = $wrapper->field_solution_support->value();
  $vars['issue'] = $wrapper->field_issue->value()->name;

  // Collect multiple fact fields values as fact and sources variables.
  $fact_fields = array('field_fact_problem', 'field_fact_solution');
  $fact_vars = dosomething_fact_get_mutiple_fact_field_vars($wrapper->nid->value(), $fact_fields);
  if (!empty($fact_vars)) {
    if (isset($fact_vars['facts']['field_fact_problem'])) {
      $vars['fact_problem'] = $fact_vars['facts']['field_fact_problem'];
    }
    if (isset($fact_vars['facts']['field_fact_solution'])) {
      $vars['fact_solution'] = $fact_vars['facts']['field_fact_solution'];
    }
    // Store all sources from fields as a sources array.
    $vars['fact_sources'] = $fact_vars['sources'];
  }

  // Check for additional facts in field_facts.
  if ($wrapper->field_facts->count() > 0) {
    $vars['more_facts'] = dosomething_fact_get_fact_field_vars($wrapper->field_facts);
  }

  // Collect all field_collection values as vars.
  $field_collections = array('faq', 'step_pre', 'step_post');
  foreach ($field_collections as $fc) {
    $vars[$fc] = dosomething_campaign_get_field_collection_values($wrapper, 'field_' . $fc);
  }

  if (!empty($vars['field_video'])) {
    $vars['psa'] = theme('dosomething_video_embed', array(
      'field' => $wrapper->field_video->value(),
      'width' => 550,
      'height' => 300,
    ));
  }
  else {
    if (isset($vars['field_image_psa_replacement'][0])) {
      $psa_nid = $vars['field_image_psa_replacement'][0]['entity']->nid;
      $vars['psa'] = dosomething_image_get_themed_image($psa_nid, 'landscape', '550x300');
    }
  }

  // Plan.
  $vars['starter'] = $wrapper->field_starter_statement->value();
  $vars['time'] = $wrapper->field_time_and_place->value();
  $vars['vips'] = $wrapper->field_vips->value();
  $vars['hype'] = $wrapper->field_promoting_tips->value();
  $vars['items_needed'] = $wrapper->field_items_needed->value();
  $vars['location_finder_copy'] = $wrapper->field_location_finder_copy->value();
  $vars['location_finder_url'] = $wrapper->field_location_finder_url->value();
  $action_guides = $vars['field_action_guide'];
  if (!empty($action_guides)) {
    foreach ($action_guides as $delta => $target) {
      $action_guide = $target['entity'];
      $action_guide_wrapper = entity_metadata_wrapper('node', $action_guide);
      $action_guide_desc = $action_guide_wrapper->field_description->value();
      $vars['action_guides'][$delta]['desc'] = $action_guide_desc;
      $vars['action_guides'][$delta]['content'] = render(node_view($action_guide));
    }
  }
  // Preprocess signup data form link.
  dosomething_campaign_preprocess_signup_data_form($vars);

  // Do.
  $vars['pre_step_header'] = $wrapper->field_pre_step_header->value();
  $vars['pre_step_copy'] = $wrapper->field_pre_step_copy->value();
  $vars['pic_step_header'] = t(DOSOMETHING_CAMPAIGN_PIC_STEP_HEADER);
  $vars['pic_step_copy'] = $wrapper->field_photo_step->value();
  $vars['post_step_header'] = $wrapper->field_post_step_header->value();
  $vars['post_step_copy'] = $wrapper->field_post_step_copy->value();
  // Step gallery.
  if ($step_gallery = $wrapper->field_image_step_gallery->value()) {
    $step_images = array();
    foreach ($step_gallery as $key => $step_image) {
      $step_images[$key]['nid'] = $step_image->nid;
    }
    // We only need one image for tpl for now, so get the image for key 0.
    $vars['step_image_square'] = dosomething_image_get_themed_image($step_images[0]['nid'], 'square', '310x310');
    $vars['step_image_landscape'] = dosomething_image_get_themed_image($step_images[0]['nid'], 'landscape', '550x300');
  }

  // Prove.
  $vars['reportback_copy'] = $wrapper->field_reportback_copy->value();
  $vars['official_rules'] = $wrapper->field_official_rules->value();
  $vars['official_rules_src'] = file_create_url($vars['official_rules']['uri']);

  $reportback_placeholder = drupal_get_path('theme', 'paraneue_dosomething') . '/images/this-could-be-you.jpg';
  $vars['reportback_placeholder'] = theme('image', array('path'=>$reportback_placeholder, 'alt'=> 'This could be you!'));

  // Reportback gallery.
  if ($reportback_gallery = $wrapper->field_image_reportback_gallery->value()) {
    foreach ($reportback_gallery as $key => $rb_image) {
      $vars['reportback_image'][$key] = dosomething_image_get_themed_image_url($rb_image->nid, 'landscape', '740x480');
    }
  }

  // Reportback form.
  $vars['reportback_link']['label'] = t("Submit Your Pic");
  $vars['reportback_link']['size'] = "medium";
  // If logged in user's reportback exists for this node,
  if ($rbid = dosomething_reportback_exists($vars['nid'])) {
    $vars['reportback_link']['label'] = t("Update Submission");
    $vars['reportback_link']['size'] = "small";
  }
  $vars['reportback_form'] = $vars['content']['reportback_form'];

  // Zendesk Support Ticket form.
  if (isset($vars['content']['reportback_form'])) {
    $vars['zendesk_form'] = $vars['content']['zendesk_form'];
  }
}

/**
 * Preprocesses variables for the link to a signup data form.
 */
function dosomething_campaign_preprocess_signup_data_form(&$vars) {
  if (isset($vars['content']['signup_data_form_link'])) {
    $vars['signup_data_form_link'] = $vars['content']['signup_data_form_link'];
    $vars['signup_data_form'] = $vars['content']['signup_data_form'];
  }
}

/**
 * Preprocesses variables for a campaign pitch page.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.
 * @param object $wrapper
 *   The corresponding entity wrapper for the node in $vars.
 */
function dosomething_campaign_preprocess_pitch_page(&$vars, &$wrapper) {
  // Define label for signup button.
  $label = t("Sign Up");
  // If user is logged in:
  if (user_is_logged_in()) {
    // Render button as sign up form.
    $vars['signup_button'] = drupal_get_form('dosomething_signup_form', $vars['nid'], $label);
  }
  // Otherwise, for anonymous user:
  else {
    // Render button as link to open up the login modal.
    $vars['signup_button'] = array(
      '#markup' => '<a href="#modal--login" class="js-modal-link btn medium">' . $label . '</a>',
    );
  }
}
