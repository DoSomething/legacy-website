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
    }
    else {
      throw new Exception('Campaign does not exist!');
    }
  }


  protected function getStatus() {
    // @TODO: consider repurposing code from below called function and using inside this method.
    return dosomething_campaign_get_campaign_status($this->node);
  }

}