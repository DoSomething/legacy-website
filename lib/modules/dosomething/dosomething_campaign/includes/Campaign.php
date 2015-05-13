<?php

class Campaign {

  public $nid;
  protected $node;

  public function __construct($id) {
    $this->nid = $id;
    $this->node = node_load($id);

    if ($this->node->type === 'campaign') {
      $this->title = $this->node->title;
      $this->created = $this->node->created;
      $this->updated = $this->node->changed;
      $this->status = $this->getStatus();
      $this->type = $this->getType();
      $this->scholarship = $this->getScholarship();
    }
    else {
      throw new Exception('Campaign does not exist!');
    }
  }


  protected function getTagline() {

  }

  protected function getScholarship() {
    return $this->extractValue($this->node->field_scholarship_amount);
  }


  protected function getStatus() {
    return $this->extractValue($this->node->field_campaign_status);
  }


  protected function getType() {
    return $this->extractValue($this->node->field_campaign_type);
  }


  protected function extractValue($field) {
    $field = $field[LANGUAGE_NONE][0];

    if ($field['value']) {
      if (isset($field['safe_value'])) {
        return $field['safe_value'];
      }
      return $field['value'];
    }

    return NULL;
  }
}