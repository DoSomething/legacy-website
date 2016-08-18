
<?php
/**
 * @file
 * Preprocess functions for the dosomething_campaign module.
 */

/**
 * Implements hook_preprocess_node().
 */
function dosomething_campaign_preprocess_node(&$vars) {
  if ($vars['type'] != 'campaign' || $vars['view_mode'] != 'full') return;

  $node = $vars['node'];
  $vars['campaign'] = dosomething_campaign_load($node);

  $wrapper = dosomething_helpers_node_metadata_wrapper($node);

  $current_path = current_path();

  // Hero Images.
  dosomething_helpers_preprocess_hero_images($vars);

  if (!empty($vars['field_partners'])) {
    // Sets partners, sponsors, and partner_info arrays if present.
    dosomething_helpers_preprocess_partners_vars($vars);
  }

  // Add inline css based on vars.
  dosomething_helpers_add_inline_css($vars);

  // Add internal js script with campaign and user data for frontend.
  dosomething_helpers_add_js_campaign_and_user_data($vars);

  // Preprocess common vars between all campaign types for non-pitch templates.
  dosomething_campaign_preprocess_common_vars($vars, $wrapper);

  $pitch_path = 'node/' . $node->nid . '/pitch';
  if ($pitch_path == $current_path || dosomething_campaign_is_pitch_page($node)) {
    // Gather vars for pitch page.
    $vars['is_pitch_page'] = TRUE;
    dosomething_campaign_preprocess_pitch_page($vars, $wrapper);
    return;
  }

  // Check if current path is active path.
  // @see dosomething_campaign_menu().
  $active_path = 'node/' . $node->nid . '/active';
  if ($current_path == $active_path) {
    if (dosomething_campaign_get_campaign_type($node) === 'sms_game') {
      dosomething_campaign_preprocess_sms_game($vars, $wrapper);
      return;
    }

    // Preprocess the vars for the campaign action page.
    dosomething_campaign_preprocess_action_page($vars, $wrapper);
    return;
  }

  // Check if current path is closed path.
  // @see dosomething_campaign_menu().
  $closed_path = 'node/' . $node->nid . '/closed';
  // If the campaign node is closed or we're on the closed path:
  if (dosomething_campaign_is_closed($node) || $current_path == $closed_path) {
    dosomething_campaign_run_preprocess_closed($vars);
    return;
  }

  if (dosomething_campaign_get_campaign_type($node) == 'sms_game') {
    dosomething_campaign_preprocess_sms_game($vars, $wrapper);
    return;
  }

  // Include the JS for Onboarding.
  dosomething_helpers_add_js_onboarding($node->nid);

  // Preprocess the vars for the campaign action page.
  dosomething_campaign_preprocess_action_page($vars, $wrapper);
}

/**
 * Preprocesses variables common between campaign action page and sms_game.
 */
function dosomething_campaign_preprocess_common_vars(&$vars, &$wrapper) {
  if (isset($wrapper->field_issue)) {
    $issue = $wrapper->field_issue->value();

    if ($issue) {
      $vars['issue'] = $issue->name;
    }
  }
  dosomething_campaign_preprocess_facts_vars($vars, $wrapper);
  dosomething_campaign_preprocess_media_vars($vars, $wrapper);
  $vars['starter'] = $wrapper->field_starter_statement->value();
  $vars['official_rules'] = $wrapper->field_official_rules->value();
  $vars['official_rules_src'] = file_create_url($vars['official_rules']['uri']);
  // Check for modals.
  $modal_links = array();
  if (isset($vars['campaign']->faq)) {
    $modal_links['faq'] = $vars['campaign']->faq;
  }
  if (isset($vars['more_facts'])) {
    $modal_links['more_facts'] = $vars['more_facts'];
    if (isset($vars['issue'])) {
      $modal_links['issue'] = $vars['issue'];
    }
  }
  if (isset($vars['partner_info'])) {
    $modal_links['partner_info'] = $vars['partner_info'];
  }
  if (!empty($modal_links)) {
    $vars['modals'] = theme('modal_links', array('modals' => $modal_links));
  }
  // Zendesk Support Ticket form.
  if (isset($vars['content']['zendesk_form'])) {
    $vars['zendesk_form'] = $vars['content']['zendesk_form'];
  }

  // Problem shares
  $vars['show_problem_shares'] = theme_get_setting('show_problem_shares');
  $campaign = $vars['campaign'];

  if ($vars['show_problem_shares']) {
    $problem_share_prompt = t(variable_get('dosomething_campaign_problem_share_prompt'));
    if ($problem_share_prompt) {
      $vars['problem_share_prompt'] = $problem_share_prompt;
    }

    $base_url = url(base_path(), ['absolute'=> TRUE, 'language' => dosomething_global_get_language_by_language_code('en-global')]);
    $campaign_path = url(current_path(), array('absolute' => TRUE));

    // Create the image path to the problem fact statement image generated for the node.
    $country_prefix = (dosomething_global_get_current_prefix()) ? strtoupper(dosomething_global_get_current_prefix()) : 'global';
    $problem_share_image = $base_url . 'sites/default/files/images/problem-' . $vars['nid'] . '-' . $country_prefix . '.png';

    $share_types = array(
      'facebook' => array(
        'type' => 'feed_dialog',
        'parameters' => array(
          'picture' => $problem_share_image,
        ),
      ),
      'twitter' => array(
        'tweet' => (isset($campaign->fact_problem)) ? $campaign->fact_problem['fact'] : NULL,
      ),
      'tumblr' => array(
        'posttype' => 'photo',
        'content' => $problem_share_image,
        'caption' => t("This is REAL, do something about this with me: "),
      ),
    );

    $vars['share_bar'] = dosomething_helpers_share_bar($campaign_path, $share_types, 'problem_shares', 'social-menu -with-callout');
  }
}


/**
 * Preprocesses variables for facts fields.
 */
function dosomething_campaign_preprocess_facts_vars(&$vars, &$wrapper) {
  // Check for additional facts in field_facts.
  if ($wrapper->field_facts->count() > 0) {
    $vars['more_facts'] = dosomething_fact_get_fact_field_vars($wrapper->field_facts);
  }
}

/**
 * Preprocesses variables for facts fields.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.
 * @param object $wrapper
 *   The corresponding entity wrapper for the node in $vars.
 */
function dosomething_campaign_preprocess_media_vars(&$vars, &$wrapper) {
  $vars['is_video_psa'] = false;
  // Before printing the video, make sure the video field has a video id.
  if (!empty($vars['field_video']) && !empty($wrapper->field_video->value()->field_video_id)) {
    $vars['psa'] = theme('dosomething_video_embed', array(
      'field' => $wrapper->field_video->value(),
      'width' => 550,
      'height' => 300,
    ));
    $vars['is_video_psa'] = true;
  }
  else {
    if (isset($vars['field_image_psa_replacement'][0])) {
      $psa_nid = $vars['field_image_psa_replacement'][0]['entity']->nid;
      $vars['psa'] = dosomething_image_get_themed_image($psa_nid, 'landscape', '550x300');
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
  $campaign = $vars['campaign'];

  // Progress
  $vars['campaign_progress'] = dosomething_reportback_get_reportback_total_plus_override($vars['nid']);

  // Know It.

  // Plan.

  // 1) Materials

  // Build the unique share link.
  $share_path = 'user/' . dosomething_user_get_field('field_northstar_id');
  $custom_social_share_link = dosomething_global_url(current_path(), array('absolute' => TRUE,'query' => array('source' => $share_path)));

  if (isset($campaign->items_needed)) {
    $materials['category'] = 'materials';
    $materials['title'] = t('Stuff You Need');
    $materials['content'] = $campaign->items_needed;
    // If the campaign is setup to create a custom social share link, get that all setup
    if (dosomething_campaign_feature_on($campaign, 'social_share_unique_link')) {
      $copy = $campaign->variables['social_share_custom_text'] ?: t("Share your link!");
      $materials['content'] .= '<ul><li><a href="#" data-modal-href="#modal-share"> ' . $copy . '</li></ul>';
      drupal_add_js(
        array('dosomethingUser' =>
          array('userInfo' =>
            array(
            'email' => $vars['user']->mail,
            'first_name' => dosomething_user_get_field('field_first_name'),
            'last_name' => dosomething_user_get_field('field_last_name'),
            'birthdate' => dosomething_user_get_field('field_birthdate', NULL, 'm/d/Y'),
            'street_address' => dosomething_user_get_field('field_address')['thoroughfare'],
            'street_address_2' => dosomething_user_get_field('field_address')['premise'],
            'city' => dosomething_user_get_field('field_address')['locality'],
            'state' => dosomething_user_get_field('field_address')['administrative_area'],
            'uid' => $vars['user']->uid,
            ),
          ),
        ),
        'setting'
      );
    }
    $vars['plan'][] = $materials;
  }

  // 2) Time
  if (isset($campaign->time_and_place)) {
    $time['category'] = 'time';
    $time['title'] = t('Time and Place');
    $time['content'] = $campaign->time_and_place;
    $vars['plan'][] = $time;
  }

  // 3) VIPs
  if (isset($campaign->vips)) {
    $vips['category'] = 'vips';
    $vips['title'] = t('VIPs');
    $vips['content'] = $campaign->vips;
    $vars['plan'][] = $vips;
  }

  // 4) Hype
  if (isset($campaign->promoting_tips)) {
    $hype['category'] = 'hype';
    $hype['title'] = t('Hype');
    $hype['content'] = $campaign->promoting_tips;
    $vars['plan'][] = $hype;
  }

  if (isset($vars['plan'])) {
    // Total Content Items in Plan
    $vars['plan_count'] = count($vars['plan']);
  }


  $location_copy = $wrapper->field_location_finder_copy->value();
  if (!empty($location_copy)) {
    $vars['location_finder']['copy'] = $location_copy['safe_value'];
  }

  $location_url = $wrapper->field_location_finder_url->value();
  if (!empty($location_url)) {
    $vars['location_finder']['url'] = $location_url['url'];
  }


  $action_guides = $vars['field_action_guide'];
  // LANGUAGE_NONE is being added to action guide references with #global see #5585
  if (array_key_exists(LANGUAGE_NONE, $action_guides)) {
    $action_guides = $action_guides[LANGUAGE_NONE];
  }
  if (!empty($action_guides)) {
    foreach ($action_guides as $delta => $target) {
      if (! isset($target['entity'])) {
        break;
      }
      $action_guide = $target['entity'];
      $action_guide_wrapper = entity_metadata_wrapper('node', $action_guide);
      $action_guide_desc = $action_guide_wrapper->field_description->value();
      $action_guide_content = node_view($action_guide);
      $vars['action_guides'][$delta]['desc'] = $action_guide_desc;
      $vars['action_guides'][$delta]['content'] = render($action_guide_content);
    }
  }
  // Preprocess signup data form.
  dosomething_campaign_preprocess_signup_data_form($vars);

  // Preprocess shipment form.
  dosomething_campaign_preprocess_shipment_form($vars);

  // Do.

  // 1) During
  $pre_step_header = $wrapper->field_pre_step_header->value();
  if (!empty($pre_step_header)) {
    $vars['do']['during']['header'] = $pre_step_header;
  }
  $pre_step_copy = $wrapper->field_pre_step_copy->value();
  if (!empty($pre_step_copy)) {
    $vars['do']['during']['copy'] = $pre_step_copy['safe_value'];
  }
  if (!empty($vars['campaign']->step_pre)) {
    $vars['do']['during']['tips'] = $vars['campaign']->step_pre;
  }


  // 2) Snap Photo
  $vars['do']['snap_photo']['header'] = t(DOSOMETHING_CAMPAIGN_PIC_STEP_HEADER);
  $pic_step_copy = $wrapper->field_photo_step->value();
  if (!empty($pic_step_copy)) {
    $vars['do']['snap_photo']['copy'] = $pic_step_copy['safe_value'];
  }

  // 3) After
  $post_step_header = $wrapper->field_post_step_header->value();
  if (!empty($post_step_header)) {
    $vars['do']['after']['header'] = $post_step_header;
  }
  $post_step_copy = $wrapper->field_post_step_copy->value();
  if (!empty($post_step_copy)) {
    $vars['do']['after']['copy'] = $post_step_copy['safe_value'];
  }
  if (!empty($vars['campaign']->step_post)) {
    $vars['do']['after']['tips'] = $vars['campaign']->step_post;
  }


  // Gallery
  if ($do_gallery = $wrapper->field_image_step_gallery->value()) {
    $do_images = array();
    foreach ($do_gallery as $key => $do_image) {
      $do_images[$key]['nid'] = $do_image->nid;
    }
    // We only need one image for tpl for now, so get the image for key 0.
    $vars['do']['snap_photo']['image'] = dosomething_image_get_themed_image($do_images[0]['nid'], 'square', '310x310');
  }


  // Prove.
  $vars['reportback_copy'] = $wrapper->field_reportback_copy->value();

  $reportback_placeholder = drupal_get_path('theme', 'paraneue_dosomething') . '/images/this-could-be-you.jpg';
  $vars['reportback_placeholder'] = theme('image', array(
      'path' => $reportback_placeholder,
      'alt' => 'This could be you!',
      'attributes' => array(
        'class' => 'carousel__slide bordered is-visible'
      ),
  ));

  // Reportback form.
  $vars['reportback_link']['label'] = t("Submit Your Pic");

  if (isset($vars['user'])) {
    $uid = $vars['user']->uid;
  }
  else {
    $uid = NULL;
  }

  // If logged in user's reportback exists for this node,
  if ($rbid = dosomething_reportback_exists($vars['nid'], NULL, $uid)) {
    $vars['reportback_link']['label'] = t("Update Submission");
  }
  $vars['reportback_form'] = $vars['content']['reportback_form'];

  // Add analytics custom event on action page.
  dosomething_helpers_add_analytics_event("Action Page View", $vars['title']);

  $optimizely_js = 'window["optimizely"] = window["optimizely"] || []; window.optimizely.push(["trackEvent", "Action Page View"]);';
  drupal_add_js($optimizely_js, 'inline');

  // Pass the signup id to the front end.
  if (module_exists('dosomething_signup')) {
    if ($sid = dosomething_signup_exists($vars['nid'])) {
      // Get competition data
      $signup = signup_load($sid);
      $competition = ['joined' => $signup->competition];
      if ($competition['joined']) {
        $signup_form = dosomething_signup_get_signup_data_form_info($signup->nid);
        $competition['messages']['confirmation'] = $signup_form['confirm_msg'];
      }

      drupal_add_js(
        ['dosomethingSignup' =>
          [
            'sid' => $sid,
            'competition' => $competition
          ],
        ],
        'setting'
      );
    }
  }

  // Pass custom share links to the front end. Unique by UID.
  $base_url = url(base_path(), array('absolute'=> TRUE, 'language' => 'en-global'));
  $country_prefix_for_share = (dosomething_global_get_current_prefix()) ? strtoupper(dosomething_global_get_current_prefix()) : 'global';
  $share_image = $base_url . 'sites/default/files/images/problem-' . $campaign->nid . '-' . $country_prefix_for_share . '.png';

  // Add social share bar.
  $social_share_types = array(
    'facebook' => array(
      'type' => 'feed_dialog',
      'parameters' => array(
      'picture' => $share_image,
    ),
  ),
    'twitter' => array(
      'tweet' => (isset($campaign->fact_problem)) ? $campaign->fact_problem['fact'] : NULL,
    ),
    'tumblr' => array(
      'posttype' => 'photo',
      'content' => $share_image,
      'caption' => t("This is REAL, do something about this with me: "),
    ),
  );

  $share_button_markup = dosomething_helpers_share_bar($custom_social_share_link, $social_share_types, $campaign->nid . '_referral', 'social-menu');

  $vars['social_share_bar'] = $share_button_markup;
  $vars['custom_social_share_link'] = $custom_social_share_link;

  // Pass along whether or not voter registration is enabled
  $vars['register_voters'] = dosomething_campaign_feature_on($campaign, 'enable_voter_registration', TRUE) ? true : false;

  // If we are registering voters check to see if the user will be 18 by the election
  if ($vars['register_voters']) {
    // Calculate the user's age on election day
    $election_day_age = dosomething_user_age_on_date('Nov 8 2016');
    $vars['can_vote'] = (!($election_day_age < 18)) ? true : false;
    $vars['voter_reg_form'] = '<iframe src="https://register2.rockthevote.com/registrants/map/?source=iframe&partner=35164" width="100%" height="1000" marginheight="0" frameborder="0"></iframe>';
  }
}

/**
 * Preprocesses variables for the link to a signup data form.
 */
function dosomething_campaign_preprocess_signup_data_form(&$vars) {
  if (isset($vars['content']['signup_data_form'])) {
      $vars['signup_data_form'] = $vars['content']['signup_data_form'];
  }

  // If the signup data form link is present:
  if (isset($vars['content']['signup_data_form_link'])) {
    $vars['signup_data_form_link'] = $vars['content']['signup_data_form_link'];
  }
  // If the skip form is present:
  if (isset($vars['content']['skip_signup_data_form'])) {
    // Store as a variable.
    $vars['skip_signup_data_form'] = $vars['content']['skip_signup_data_form'];
  }
}

/**
 * Preprocesses variables for the link to a Shipment form.
 */
function dosomething_campaign_preprocess_shipment_form(&$vars) {
  // If the signup data form link is present:
  if (isset($vars['content']['shipment_form_link'])) {
    $vars['shipment_form_link'] = $vars['content']['shipment_form_link'];
    $vars['shipment_form'] = $vars['content']['shipment_form'];
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
  // Use the pitch page template to theme.
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__pitch';

  // Track that we're viewing a pitch page.
  $vars['campaign']->is_pitch_page = TRUE;

  // Check for a signup button copy override.
  $label = $vars['campaign']->variables['signup_form_submit_label'];

  // Adds signup_button_primary and signup_button_secondary variables.
  $ids = array('primary', 'secondary');
  dosomething_signup_preprocess_signup_button($vars, $label, NULL, $ids);

  // Render the form array now, so we can print it multiple times on the page.
  $vars['signup_button_secondary'] = render($vars['signup_button_secondary']);

  // Begin $tagline variable:
  $vars['tagline'] = t('A DoSomething.org campaign.') . ' ';

  // If Member Count variable is set:
  if ($count = dosomething_user_get_member_count(TRUE)) {
    // Add it into the $tagline.
    $vars['tagline'] .= t('Join over @count members taking action.', [
      '@count' => $count,
    ]);

    $vars['tagline'] .= ' ';
  }

  // Moar $tagline.
  $vars['tagline'] .= t('Any cause, anytime, anywhere.');
}

/**
 * Preprocesses variables for a SMS Game.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.
 * @param object $wrapper
 *   The corresponding entity wrapper for the node in $vars.
 */
function dosomething_campaign_preprocess_sms_game(&$vars, &$wrapper) {
  // Use the SMS Game template to theme.
  $vars['theme_hook_suggestions'][] = 'node__campaign__sms_game';
  $vars['signup_form'] = $vars['content']['signup_form'];
  $vars['starter_header'] = $wrapper->field_starter_statement_header->value();
  drupal_add_js('//cdn.optimizely.com/js/1158700146.js', 'external');
}

/**
 * Preprocesses variables for a Reportback Gallery.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.
 * @param string $style
 *   The image style to render the images in.
 * @param int $num_items
 *   Optional. The number of reportback files to return.
 *   If not set, will return variables for all promoted files.
 */
function dosomething_campaign_preprocess_closed_reportback_gallery(&$vars, $style = '300x300', $num_items = 3) {

  if (!isset($vars['nid'])) {
    return;
  }

  $params = array(
    'nid' => $vars['nid'],
    'status' => 'promoted',
    'count' => $num_items,
  );
  $result = dosomething_reportback_get_reportback_items_query($params);

  // Loop through gallery_vars to only output what we need for theming:
  foreach ($result as $delta => $item) {
    $vars['reportback_gallery'][$delta]['image'] = dosomething_image_get_themed_image_by_fid($item->fid, $style);

    if (isset($item->caption)) {
      $vars['reportback_gallery'][$delta]['caption'] = filter_xss($item->caption, array());
    }
    $account = user_load($item->uid);
    $vars['reportback_gallery'][$delta]['first_name'] = dosomething_user_get_field('field_first_name', $account);
  }
}
