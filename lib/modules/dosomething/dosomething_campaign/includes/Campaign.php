<?php

class Campaign {

  public $nid;
  protected $node;
  protected $variables;

  public function __construct($id) {
    $this->nid = $id;
    $this->node = node_load($id);

    if ($this->node && $this->node->type === 'campaign') {
      $this->variables = dosomething_helpers_get_variables('node', $this->nid);
      $this->title = $this->node->title;
      $this->tagline = $this->getTagline();
      $this->created = $this->node->created;
      $this->updated = $this->node->changed;
      $this->status = $this->getStatus();
      $this->type = $this->getType();
      $this->active_hours = $this->getActiveHours();
      $this->cover_image = $this->getCoverImage();
      $this->cover_image_alt = $this->getCoverImageAlt();
      $this->scholarship = $this->getScholarship();
      $this->is_staff_pick = $this->getStaffPickStatus();

      $fact_data = $this->getFactData();
      $this->fact_problem = $fact_data['fact_problem'];
      $this->fact_solution = $fact_data['fact_solution'];
      $this->fact_sources = $fact_data['sources'];

      $solution_data = $this->getSolutionData();
      $this->solution = $solution_data;

      $cause_data = $this->getCauses();
      $this->primary_cause = $cause_data['primary'];
      $this->secondary_causes = $cause_data['secondary'];

      $action_types_data = $this->getActionTypes();
      $this->primary_action_type = $action_types_data['primary'];
      $this->secondary_action_types = $action_types_data['secondary'];

      $this->issue = $this->getIssue();
      $this->tags = $this->getTags();
    }
    else {
      throw new Exception('Campaign does not exist!');
    }
  }


  // @TODO: potentially move this function to dosomething_helpers module for access in other modules.
  protected function extractValue($field) {
    if (isset($field) && !empty($field)) {
      // @TODO: start by checking for existence of a key.
      $data = $field[LANGUAGE_NONE];

      if (count($data) === 1) {
        $data = $data[0];

        if (isset($data['value'])) {
          if (isset($data['safe_value'])) {
            return $data['safe_value'];
          }
          return $data['value'];
        }

        // @TODO: potentially use an array_keys() solution here like below, so don't need to specify exact key name.
        if (isset($data['target_id'])) {
          return $data['target_id'];
        }

        if (isset($data['tid'])) {
          return $data['tid'];
        }
      } elseif (count($data) > 1) {
        $values = array();

        foreach ($data as $item => $array) {
          $keys = array_keys($array);
          $values[] = $array[$keys[0]];
        }

        return $values;
      }
    }

    return NULL;
  }


  // @TODO: Potentially combine this with getCauses() to DRY up code.
  protected function getActionTypes() {
    $data = array();
    $data['primary'] = NULL;
    $data['secondary'] = NULL;

    $primary_action_type_id = $this->extractValue($this->node->field_primary_action_type);
    $secondary_action_type_ids = $this->extractValue($this->node->field_action_type);

    if ($primary_action_type_id) {
      $data['primary'] = $this->getTaxonomyTerm($primary_action_type_id);
    }

    if ($secondary_action_type_ids) {
      $secondary_action_types = array();

      foreach($secondary_action_type_ids as $tid) {
        $secondary_action_types[] = $this->getTaxonomyTerm($tid);
      }

      $data['secondary'] = $secondary_action_types;
    }

    return $data;
  }


  /**
   * @return string
   */
  protected function getActiveHours() {
    // @TODO: Suggestion to potential rename this field from "active_hours" to "time_commitment".
    return $this->extractValue($this->node->field_active_hours);
  }


  // @TODO: Potentially combine this with getActionTypes() to DRY up code.
  protected function getCauses() {
    $data = array();
    $data['primary'] = NULL;
    $data['secondary'] = NULL;

    $primary_cause_id = $this->extractValue($this->node->field_primary_cause);
    $secondary_cause_ids = $this->extractValue($this->node->field_cause);

    if ($primary_cause_id) {
      $data['primary'] = $this->getTaxonomyTerm($primary_cause_id);
    }

    if ($secondary_cause_ids) {
      $secondary_causes = array();

      foreach($secondary_cause_ids as $tid) {
        $secondary_causes[] = $this->getTaxonomyTerm($tid);
      }

      $data['secondary'] = $secondary_causes;
    }

    return $data;
  }


  protected function getCoverImage($id = NULL) {
    if ($id) {
      $image_id = $id;
    }
    else {
      $image_id = $this->extractValue($this->node->field_image_campaign_cover);
    }

    // @TODO: This could potentially be turned into an Image class, and load the data by including and then instantiating the class $image = new Image($id);
    // This would help cleanup some of the code, and keep things DRYer.
    if ($image_id) {
      $image = node_load($image_id);
    }
    else {
      return NULL;
    }

    $data = array();

    $data['nid'] = $image->nid;
    $data['type'] = $image->type;
    $data['title'] = $image->title;
    $data['created'] = $image->created;
    $data['updated'] = $image->changed;
    $data['is_dark'] = (bool) $this->extractValue($image->field_dark_image);

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


  protected function getCoverImageAlt() {
    $image_id = $this->variables['alt_image_campaign_cover_nid'];

    if ($image_id) {
      return $this->getCoverImage($image_id);
    }
    else {
      return NULL;
    }
  }


  protected function getFactData() {
    $data = array();

    $fact_fields = array('field_fact_problem', 'field_fact_solution');
    $fact_vars = dosomething_fact_get_mutiple_fact_field_vars($this->node, $fact_fields);

    if (!empty($fact_vars)) {
      $data['fact_problem'] = dosomething_helpers_issetor($fact_vars['facts']['field_fact_problem']);
      $data['fact_solution'] = dosomething_helpers_issetor($fact_vars['facts']['field_fact_solution']);
      $data['sources'] = dosomething_helpers_issetor($fact_vars['sources']);
    }

    return $data;
  }


  protected function getIssue() {
    // @TODO: Need to find out if this is allowed to be a field with multiple values...?
    $issue_id = $this->extractValue($this->node->field_issue);

    if ($issue_id) {
      $issue = $this->getTaxonomyTerm($issue_id);

      return $issue;
    }

    return NULL;
  }


  protected function getPrimaryCause() {
    $cause_id = $this->extractValue($this->node->field_primary_cause);

    if ($cause_id) {
      $cause = $this->getTaxonomyTerm($cause_id);

      return $cause;
    }

    return NULL;
  }


  protected function getTags() {
    $data = array();

    $tag_ids = $this->extractValue($this->node->field_tags);

    foreach ($tag_ids as $tid) {
      $data[] = $this->getTaxonomyTerm($tid);
    }

    return $data;
  }


  protected function getTaxonomyTerm($tid) {
    $data = array();

    $taxonomy = taxonomy_term_load($tid);

    $data['tid'] = $taxonomy->tid;
    $data['name'] = strtolower($taxonomy->name);

    return $data;
  }


  protected function getTagline() {
    return $this->extractValue($this->node->field_call_to_action);
  }


  protected function getScholarship() {
    return $this->extractValue($this->node->field_scholarship_amount);
  }


  protected function getSolutionData() {
    $data['copy'] = $this->extractValue($this->node->field_solution_copy);
    $data['support_copy'] = $this->extractValue($this->node->field_solution_support);

    return $data;
  }


  protected function getStaffPickStatus() {
    return (bool) $this->extractValue($this->node->field_staff_pick);
  }


  protected function getStatus() {
    return $this->extractValue($this->node->field_campaign_status);
  }


  protected function getType() {
    return $this->extractValue($this->node->field_campaign_type);
  }

}