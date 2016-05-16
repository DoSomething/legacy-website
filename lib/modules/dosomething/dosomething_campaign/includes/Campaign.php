<?php

class Campaign {

  protected $node;
  protected $variables;

  /**
   * Properties exposed in teaser Campaign view.
   */
  public $id;
  public $title;
  public $display;
  public $tagline;
  public $campaign_runs;
  public $status;
  public $type;
  public $language;
  public $translations;

  /**
   * Properties exposed in full Campaign view.
   */
  public $created_at;
  public $updated_at;
  public $time_commitment;
  public $cover_image;
  public $scholarship;
  public $staff_pick;
  public $facts;
  public $solutions;
  public $pre_step;
  public $latest_news;
  public $causes;
  public $action_types;
  public $action_guides;
  public $attachments;
  public $issue;
  public $tags;
  public $timing;
  public $reportback_info;
  public $affiliates;
  public $services;

  /**
   * Convenience method to retrieve a single campaign from supplied id.
   *
   * @param  string|array  $ids  Single id or array of ids of Campaigns to retrieve.
   * @param  string        $display
   * @return array|mixed
   * @throws Exception
   */
  public static function get($ids, $display = 'teaser') {
    $single_campaign = FALSE;
    $campaigns = [];

    if (!is_array($ids)) {
      $single_campaign = TRUE;
      $ids = [$ids];
    }
    // Only load campaign types in this class.
    $results = node_load_multiple($ids, ['type' => 'campaign']);

    if (!$results) {
      throw new Exception('No campaign data found.');
    }

    foreach($results as $item) {
      $campaign = new static();
      $campaign->build($item, $display);

      $campaigns[] = $campaign;
    }

    if ($single_campaign) {
      return array_pop($campaigns);
    }

    return $campaigns;
  }

  /**
   * Convenience method to retrieve campaigns based on supplied filters.
   *
   * @param  array  $filters
   * - nid (string|array)
   * - type (string)
   * - staff_pick (bool)
   * - term_id (string|array)
   * - count (int)
   * - random (bool)
   * - page (int)
   * @param  string  $display
   * @return array
   * @throws Exception
   */
  public static function find(array $filters = [], $display = 'teaser') {
    $campaigns = [];

    $results = dosomething_campaign_get_campaigns_query($filters);

    if (!$results) {
      throw new Exception('No campaign data found.');
    }

    $results = array_map('dosomething_helpers_extract_id', $results);
    $results = node_load_multiple($results);

    foreach($results as $item) {
      $campaign = new static;
      $campaign->build($item, $display);

      $campaigns[] = $campaign;
    }

    return $campaigns;
  }

  /**
   * Return node data for this campaign instance.
   *
   * @return mixed
   */
  public function getNodeData() {
    return $this->node;
  }

  /**
   * Return variables data for this campaign instance.
   *
   * @return mixed
   */
  public function getVariablesData() {
    return $this->variables;
  }

  /**
   * Build out the instantiated Campaign class object with supplied data.
   *
   * @param  $data
   * @param  $display
   * @throws Exception
   */
  private function build($data, $display = 'teaser') {
    $this->node = $data;
    $this->id = $data->nid;

    if ($data->type === 'campaign') {
      $this->variables = dosomething_helpers_get_variables('node', $this->id);
      $this->title = $data->title;
      $this->display = $display;
      $this->campaign_runs = $this->getCampaignRuns($this->id);
      $this->language = $this->getLanguage();
      $this->translations = $this->getTranslations();
      $this->tagline = $this->getTagline();
      $this->status = $this->getStatus();
      $this->type = $this->getType();

      if ($display === 'full') {
        $this->created_at = $data->created;
        $this->updated_at = $data->changed;
        $this->time_commitment = $this->getTimeCommitment();

        $this->cover_image = [
          'default' => $this->getCoverImage(),
          'alternate' => $this->getCoverImageAlt(),
        ];

        $this->scholarship = $this->getScholarship();
        $this->staff_pick = $this->getStaffPickStatus();

        $this->competition =  dosomething_helpers_convert_string_to_boolean(dosomething_campaign_is_competition($this->id));

        $fact_data = $this->getFactData();
        $this->facts = [
          'problem' => $fact_data['fact_problem'],
          'solution' => $fact_data['fact_solution'],
          'sources' => $fact_data['sources'],
        ];

        $solution_data = $this->getSolutionData();
        $this->solutions = $solution_data;

        $this->pre_step = $this->getPreStepInfo();
        $this->latest_news = $this->getLatestNews();

        $this->causes = $this->getCauses();

        $this->action_types = $this->getActionTypes();

        $this->action_types = $this->getActionGuides();

        $this->attachments = $this->getAttachments();

        $this->issue = $this->getIssue();
        $this->tags = $this->getTags();

        $timing = $this->getTiming();
        $this->timing = $timing;

        $this->affiliates = $this->getAffiliates();

        $this->services = $this->getServices();
      }

      $this->reportback_info = $this->getReportbackInfo();
    }
  }

  protected function getActionGuides() {
    $data = [];
    
    $action_guide_ids = dosomething_helpers_extract_field_data($this->node->field_action_guide);

    if (! $action_guide_ids) {
      return $data;
    }

    if (! is_array($action_guide_ids)) {
      $action_guide_ids = [$action_guide_ids];
    }

    $items = node_load_multiple($action_guide_ids);

    foreach ($items as $item) {
      $action_guide = [];

      $action_guide['id'] = $item->nid;
      $action_guide['title'] = $item->title;
      $action_guide['subtitle'] = dosomething_helpers_extract_field_data($item->field_subtitle);
      $action_guide['description'] = dosomething_helpers_extract_field_data($item->field_description);

      $action_guide['intro']['title'] = dosomething_helpers_extract_field_data($item->field_intro_title);
      $action_guide['intro']['copy'] = dosomething_helpers_extract_field_data($item->field_intro);

      $action_guide['additional_text']['title'] = dosomething_helpers_extract_field_data($item->field_additional_text_title);
      $action_guide['additional_text']['copy'] = dosomething_helpers_extract_field_data($item->field_additional_text);

      $action_guide['created_at'] = $item->created;
      $action_guide['updated_at'] = $item->changed;

      $data[] = $action_guide;
    }
  }

  /**
   * Get both primary and secondary Action Types for campaign if available.
   *
   * @return array
   */
  protected function getActionTypes() {
    // @TODO: Potentially (or very likely can) combine this with getCauses() to DRY up code.
    $data = [];
    $data['primary'] = NULL;
    $data['secondary'] = NULL;

    $primary_action_type_id = dosomething_helpers_extract_field_data($this->node->field_primary_action_type);
    $secondary_action_type_ids = dosomething_helpers_extract_field_data($this->node->field_action_type);

    if ($primary_action_type_id) {
      $data['primary'] = $this->getTaxonomyTerm($primary_action_type_id);
    }

    if ($secondary_action_type_ids) {
      $secondary_action_types = [];

      foreach((array) $secondary_action_type_ids as $tid) {
        $secondary_action_types[] = $this->getTaxonomyTerm($tid);
      }

      $data['secondary'] = $secondary_action_types;
    }

    return $data;
  }

  /**
   * Get all affiliates (partners, etc) for the campaign.
   *
   * @return array
   */
  protected function getAffiliates() {
    // @TODO: Only grabs partners for now. Update with further affiliates as needed.
    return [
      'partners' => $this->getPartners(),
    ];
  }

  /**
   * Get all downloadable attachments for the campaign.
   *
   * @return array
   */
  protected function getAttachments() {
    $data = [];

    $items = dosomething_helpers_extract_field_data($this->node->field_downloads);

    if (!$items) {
      return $data;
    }

    if (dosomething_helpers_array_is_associative($items)) {
      $items = [$items];
    }

    foreach ($items as $item) {
      $attachment = [];

      $attachment['title'] = $item['title'];
      $attachment['description'] = $item['description'];
      $attachment['uri'] = file_create_url($item['uri']);
      $attachment['type'] = $item['type'];

      $data[] = $attachment;
    }

    return $data;
  }

  /**
   * Get all Campaign Run for this Campaign.
   */
  protected function getCampaignRuns($id) {
    if (!$this->node->field_current_run) {
      return NULL;
    }

    $runs = [
      'current' => [],
      'past' => [],
    ];

    foreach ($this->node->field_current_run as $key => $value) {
      $runs['current'][$key]['id'] = dosomething_helpers_extract_field_data($this->node->field_current_run, $key);
    }

    // @TODO: Figure out how to grab past runs

    return $runs;
  }

  /**
   * Get both primary and secondary Causes for campaign if available.
   *
   * @return array
   */
  protected function getCauses() {
    // @TODO: Potentially combine this with getActionTypes() to DRY up code.
    $data = [];
    $data['primary'] = NULL;
    $data['secondary'] = NULL;

    $primary_cause_id = dosomething_helpers_extract_field_data($this->node->field_primary_cause);
    $secondary_cause_ids = dosomething_helpers_extract_field_data($this->node->field_cause);

    if ($primary_cause_id) {
      $data['primary'] = $this->getTaxonomyTerm($primary_cause_id);
    }

    if ($secondary_cause_ids) {
      if (is_array($secondary_cause_ids)) {
        $secondary_causes = [];

        foreach($secondary_cause_ids as $tid) {
          $secondary_causes[] = $this->getTaxonomyTerm($tid);
        }
      }
      else {
        $secondary_causes[] = $this->getTaxonomyTerm($secondary_cause_ids);
      }

      $data['secondary'] = $secondary_causes;
    }

    return $data;
  }

  /**
   * Get the cover image data for campaign if available.
   *
   * @param  string|null  $id Image node id.
   * @return array|null
   */
  protected function getCoverImage($id = NULL) {
    if (is_null($id)) {
      $id = dosomething_helpers_extract_field_data($this->node->field_image_campaign_cover);
    }

    // @TODO: This could potentially be turned into an Image class, and load the data by including and then instantiating the class $image = new Image($id);
    // This would help cleanup some of the code, and keep things DRYer.
    if ($id) {
      $image = node_load($id);
    }
    else {
      return NULL;
    }

    $data = [];

    $data['id'] = $image->nid;
    $data['type'] = $image->type;
    $data['title'] = $image->title;
    $data['created_at'] = $image->created;
    $data['updated_at'] = $image->changed;
    $data['dark_background'] = (bool) dosomething_helpers_extract_field_data($image->field_dark_image);

    // @TODO: consider reworking following function to return data instead of assigning it by reference to variable. Kind of confusing.
    dosomething_campaign_load_image_url($data['sizes'], $image);
    if ($data['sizes']['landscape']) {
      $data['sizes']['landscape']['uri'] = dosomething_image_get_themed_image_url($image->nid, 'landscape', '1440x810');
    }

    if ($data['sizes']['square']) {
      $data['sizes']['square']['uri'] = dosomething_image_get_themed_image_url($image->nid, 'square', '300x300');
    }

    return $data;
  }

  /**
   * Get alternative cover image for campaign if available.
   *
   * @return array|null
   */
  protected function getCoverImageAlt() {
    $image_id = $this->variables['alt_image_campaign_cover_nid'];

    if ($image_id) {
      return $this->getCoverImage($image_id);
    }
    else {
      return NULL;
    }
  }

  /**
   * Get Facts data for campaign if available; collects both fact problem
   * and fact solution as well as the sources for both.
   *
   * @return array|null
   */
  protected function getFactData() {
    $data = [];
    $data['fact_problem'] = NULL;
    $data['fact_solution'] = NULL;
    $data['sources'] = NULL;

    $fact_fields = ['field_fact_problem', 'field_fact_solution'];
    $fact_vars = dosomething_fact_get_mutiple_fact_field_vars($this->node, $fact_fields);

    if (!empty($fact_vars)) {
      foreach ($fact_vars['facts'] as $index => $fact_data) {
        $index = str_replace('field_', '', $index);

        $data[$index]['fact'] = dosomething_helpers_isset($fact_data['fact']);
        $data[$index]['id'] = dosomething_helpers_isset($fact_data['nid']);
        $data[$index]['footnote'] = (int) dosomething_helpers_isset($fact_data['footnotes']);
        $data[$index]['source'] = dosomething_helpers_isset($fact_data['sources']);

      }

      $sources = dosomething_helpers_isset($fact_vars['sources']);
      foreach ($sources as $index => $source) {
        $data['sources'][$index]['formatted'] = $source;
      }

      return $data;
    }

    return NULL;

  }

  /**
   * Get the Issue for campaign if available.
   *
   * @return array|null
   */
  protected function getIssue() {
    // @TODO: Need to find out if this is allowed to be a field with multiple values...?
    $issue_id = dosomething_helpers_extract_field_data($this->node->field_issue);

    if ($issue_id) {
      $issue = $this->getTaxonomyTerm($issue_id);

      return $issue;
    }

    return NULL;
  }

  /**
   * Get language data.
   *
   * @return array
   */
  protected function getLanguage() {
    $language = dosomething_helpers_isset($this->node->language);
    $prefix = dosomething_global_get_prefix_for_language($language);

    return [
      'language_code' => dosomething_global_convert_country_to_language($prefix),
      'prefix' => !empty($prefix) ? $prefix : NULL,
    ];
  }

  /**
   * Get campaign's latest news.
   *
   * @return array
   */
  protected function getLatestNews() {
    return [
      'latest_news' => dosomething_helpers_extract_field_data($this->node->field_latest_news_copy),
    ];
  }

  /**
   * Get MailChimp data.
   *
   * @return array
   */
  protected function getMailChimpData() {
    return [
      'grouping_id' => dosomething_helpers_isset($this->variables, 'mailchimp_grouping_id'),
      'group_name' => dosomething_helpers_isset($this->variables, 'mailchimp_group_name'),
    ];
  }

  /**
   * Get Mobile Commons data.
   *
   * @return array
   */
  protected function getMobileCommonsData() {
    return [
      'opt_in_path_id' => dosomething_helpers_isset($this->variables, 'mobilecommons_opt_in_path'),
      'friends_opt_in_path_id' => dosomething_helpers_isset($this->variables, 'mobilecommons_friends_opt_in_path'),
    ];
  }

  protected function getPartners() {
    $data = [];

    // @TODO: only accounts for single partner at the moment.
    // Update extract function to grab array of partners instead of just first id.
    // @see https://github.com/DoSomething/phoenix/issues/6396
    $partner_data_collection_ids = dosomething_helpers_extract_field_data($this->node->field_partners);

    if (! $partner_data_collection_ids) {
      return $data;
    }

    if (! is_array($partner_data_collection_ids)) {
      $partner_data_collection_ids = [$partner_data_collection_ids];
    }

    foreach ($partner_data_collection_ids as $id) {
      $partner = [];

      $data_collection = field_collection_item_load($id);
      $data_taxonomy = taxonomy_term_load(dosomething_helpers_extract_field_data($data_collection->field_partner));

      $partner['name'] = $data_taxonomy->name;
      $partner['sponsor'] = (bool) dosomething_helpers_extract_field_data($data_collection->field_is_sponsor);
      $partner['copy'] = dosomething_helpers_extract_field_data($data_collection->field_partner_copy);
      $partner['uri'] = dosomething_helpers_extract_field_data($data_collection->field_partner_url);

      $logo = dosomething_helpers_extract_field_data($data_taxonomy->field_partner_logo);

      if ($logo) {
        $partner['media'] = [
          'uri' => image_style_url('wmax-423px', $logo['uri']),
          'type' => $logo['type'],
        ];
      } else {
        $partner['media'] = NULL;
      }

      $data[] = $partner;
    }

    return $data;
  }

  /**
   * Get campaign's pre-step header and caption.
   *
   * @return array
   */
  protected function getPreStepInfo() {
    $pre_step = [];
    $pre_step['header'] = (dosomething_helpers_extract_field_data($this->node->field_pre_step_header));
    $pre_step['copy'] = (dosomething_helpers_extract_field_data($this->node->field_pre_step_copy));

    return $pre_step;
  }

  /**
   * Get Reportback content info used in the campaign.
   *
   * @return array
   */
  protected function getReportbackInfo() {
    $data = [];
    $data['copy'] = NULL;
    $data['confirmation_message'] = NULL;
    $data['noun'] = NULL;
    $data['verb'] = NULL;

    $copy = dosomething_helpers_extract_field_data($this->node->field_reportback_copy);
    $confirmation_message = dosomething_helpers_extract_field_data($this->node->field_reportback_confirm_msg);
    $noun = dosomething_helpers_extract_field_data($this->node->field_reportback_noun);
    $verb = dosomething_helpers_extract_field_data($this->node->field_reportback_verb);

    if ($copy) {
      $data['copy'] = $copy;
    }

    if ($confirmation_message) {
      $data['confirmation_message'] = $confirmation_message;
    }

    if ($noun) {
      $data['noun'] = $noun;
    }

    if ($verb) {
      $data['verb'] = $verb;
    }

    return $data;
  }

  /**
   * Collect data for third party services.
   *
   * @return array
   */
  protected function getServices() {
    return [
      'mobile_commons' => $this->getMobileCommonsData(),
      'mailchimp' => $this->getMailChimpData(),
    ];
  }

  /**
   * Get the Scholarship amount for campaign if available.
   *
   * @return array|null
   */
  protected function getScholarship() {
    return dosomething_helpers_extract_field_data($this->node->field_scholarship_amount);
  }

  /**
   * Get the Solutions data for campaign if available; collects both the main solution copy
   * and the solution support copy.
   *
   * @return array
   */
  protected function getSolutionData() {
    $data['copy'] = dosomething_helpers_extract_field_data($this->node->field_solution_copy);
    $data['support_copy'] = dosomething_helpers_extract_field_data($this->node->field_solution_support);

    return $data;
  }

  /**
   * Get status whether this campaign is a Staff Pick or not.
   *
   * @return bool
   */
  protected function getStaffPickStatus() {
    return (bool) dosomething_helpers_extract_field_data($this->node->field_staff_pick);
  }

  /**
   * Get Status of campaign.
   *
   * @return string|null
   */
  protected function getStatus() {
    return dosomething_helpers_extract_field_data($this->node->field_campaign_status);
  }

  /**
   * Get Tags assigned to campaign if available.
   *
   * @return array|null
   */
  protected function getTags() {
    $data = [];

    $tag_ids = dosomething_helpers_extract_field_data($this->node->field_tags);

    if ($tag_ids) {
      foreach ((array) $tag_ids as $id) {
        $data[] = $this->getTaxonomyTerm($id);
      }

      return $data;
    }

    return NULL;
  }

  /**
   * Get taxonomy term node data from provided id.
   *
   * @param  $id
   * @return array
   */
  protected function getTaxonomyTerm($id) {
    $data = [];

    $taxonomy = taxonomy_term_load($id);

    $data['id'] = $taxonomy->tid;
    $data['name'] = strtolower($taxonomy->name);

    return $data;
  }

  /**
   * Get the Tagline for campaign.
   *
   * @return array|null
   */
  protected function getTagline() {
    return dosomething_helpers_extract_field_data($this->node->field_call_to_action);
  }

  /**
   * Get the specified Time Commitment for campaign.
   *
   * @return float
   */
  protected function getTimeCommitment() {
    // @TODO: I've renamed "active_hours" to "time_commitment" because it sounds more straightforward; but appreciate feedback.
    return (float) dosomething_helpers_extract_field_data($this->node->field_active_hours);
  }

  /**
   * Get the timing for high and low seasons for campaign if available.
   * Dates formatted as ISO-8601 datetime.
   *
   * @return array
   */
  protected function getTiming() {
    $timing = [];
    $timing['high_season'] = dosomething_helpers_extract_field_data($this->node->field_high_season);
    $timing['low_season'] = dosomething_helpers_extract_field_data($this->node->field_low_season);

    foreach ($timing as $season => $dates) {
      if ($timing[$season]) {
        foreach ($timing[$season] as $key => $date) {
          $timing[$season][$key] = dosomething_helpers_convert_date($date);
        }
      }
    }

    return $timing;
  }

  /**
   * Get translations data for this Campaign.
   *
   * @return array
   * @TODO: potentially add extra useful info for each translation (full country name, etc?)
   */
  protected function getTranslations() {
    $translationData = $this->node->translations;
    $translations = [
      'original' => dosomething_helpers_isset($translationData->original),
    ];

    if (isset($translationData->data)) {
      foreach ($translationData->data as $key => $value) {
        $prefix = dosomething_global_get_prefix_for_language($key);

        $translations[$key] = [
          'language_code' => $key,
          'prefix' => !empty($prefix) ? $prefix : NULL,
        ];
      }
    }

    return $translations;
  }

  /**
   * Get Type of campaign.
   *
   * @return string|null
   */
  protected function getType() {
    return dosomething_helpers_extract_field_data($this->node->field_campaign_type);
  }

}
