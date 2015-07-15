<?php

class Reportback extends Entity {

  protected $files_table = 'dosomething_reportback_file';
  protected $log_table = 'dosomething_reportback_log';
  protected $entity;

  public $id;
  public $created_at;
  public $updated_at;
  public $quantity;
  public $why_participated;
  public $total_participants;
  public $flagged;
  public $reportback_items;
  public $campaign;
  public $user;

  // @TODO: add the following?
  // public $noun;
  // public $verb;
  // public $flagged_reason; // Should be nested in flagged property?
  // public $promoted;
  // public $promoted_reason; // Should be nested in promoted property?

  // @TODO: Properties to deprecate
  // public $fids;


  /**
   * Overrides construct to set calculated properties.
   */
  public function __construct(array $values = []) {
    parent::__construct($values, 'reportback');

//    die(print_r(debug_backtrace()));
//    die(print_r($this));

    // @TODO: currently setting the fids is required for action page prove it section to load properly
//    $this->fids = array();
//    // If this is a new entity, rbid may not be set.
//    if (isset($this->rbid)) {
//      $this->fids = $this->getFids();
//    }

//    // If a reportback nid exists:
//    if (isset($this->nid)) {
//      // Set properties found on the reportback's node nid.
//      $this->node_title = $this->getNodeTitle();
//
//      if (module_exists('dosomething_campaign_run')) {
//        // Check if this reportback is associated with Campaign Run node.
//        if ($parent_nid = dosomething_campaign_run_get_parent_nid($this->nid)) {
//          // Use the Campaign node nid instead of the Run nid.
//          $this->nid = $parent_nid;
//        }
//      }
//
//      $this->noun = $this->getNodeSingleTextValue('field_reportback_noun');
//      $this->verb = $this->getNodeSingleTextValue('field_reportback_verb');
//      $this->quantity_label = $this->noun . ' ' . $this->verb;
//    }
  }


  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return [
      'path' => 'reportback/' . $this->identifier()
    ];
  }


  /**
   * Convenience method to retrieve a single or multiple reportbacks from supplied id(s).
   *
   * @param string|array $ids Single id or array of ids of Reportbacks to load.
   * @return array
   */
  public static function get($ids) {
    $reportbacks = [];

    if (!is_array($ids)) {
      $ids = [$ids];
    }

    $entities = entity_load('reportback', $ids);

    foreach($entities as $entity) {
      $reportback = new static();
      $reportback->build($entity);

      $reportbacks[] = $reportback;
    }

    return $reportbacks;
  }


  /**
   * Build out the instantiated Reportback class object with supplied entity data.
   *
   * @param string|array $ids Single id or array of ids.
   */
  public function build($entity) {
    $method = 'beta';  // beta

//    if ($method === 'alpha') {
//      if (!is_array($ids)) {
//        $ids = dosomething_helpers_format_data($ids);
//      }
//      $result = dosomething_reportback_get_reportbacks_query_result(['rbid' => $ids]);
//      $result = array_pop($result);
//      // @TODO: Above returns object with null properties if no results, should return null or false.
//
//      if (!$result->rbid) {
//        throw new Exception('No reportback data found.');
//      }
//
//      $this->id = $result->rbid;
//      $this->created_at = $result->created;
//      $this->updated_at = $result->updated;
//      $this->quantity = (int)$result->quantity;
//      $this->why_participated = $result->why_participated;
//      $this->flagged = $result->flagged;
//      $this->noun = $result->noun;
//      $this->verb = $result->verb;
//      $this->reportback_items = dosomething_helpers_format_data($result->items); //$this->getReportbackItems();
//      $this->campaign = [
//        'id' => $result->nid,
//        'title' => $result->title,
//      ];
//      $this->user = [
//        'id' => $result->uid,
//      ];
//    }

    if ($method === 'beta') {
      $this->id = $entity->rbid;
      $this->created_at = $entity->created;
      $this->updated_at = $entity->updated;
      $this->quantity = (int) $entity->quantity;
      $this->why_participated = $entity->why_participated;
      $this->total_participants = (int) $entity->num_participants;
      $this->flagged = (bool) $entity->flagged;
//      $this->reportback_items = ReportbackItem::get($this->id);
      $this->campaign = [
        'id' => $entity->nid,
      ];
      $this->user = [
        'id' => $entity->uid,
      ];
    }
  }


  /**
   * Return all fids from dosomething_reportback_files table for this entity.
   */
  public function getFids() {
    return db_select($this->files_table, 'f')
      ->fields('f', array('fid'))
      ->condition('rbid', $this->rbid)
      ->execute()
      ->fetchCol();
  }


  /**
   * Return all data from dosomething_reportback_log table for this entity.
   */
  public function getReportbackLog() {
    return db_select($this->log_table, 'l')
      ->fields('l')
      ->condition('rbid', $this->rbid)
      ->execute()
      ->fetchAll();
  }


  /**
   * Returns the node title of the $entity->nid.
   */
  public function getNodeTitle() {
    $result = db_select('node', 'n')
      ->fields('n', array('title'))
      ->condition('nid', $this->nid)
      ->execute()
      ->fetchCol();
    if ($result) {
      return $result[0];
    }
    return NULL;
  }


  /**
   * Returns a single text value for a given $field_name for the $entity->nid.
   */
  public function getNodeSingleTextValue($field_name) {
    $result = db_select('field_data_' . $field_name, 'f')
      ->fields('f', array($field_name . '_value'))
      ->condition('entity_id', $this->nid)
      ->condition('entity_type', 'node')
      ->execute()
      ->fetchCol();
    if ($result) {
      return $result[0];
    }
    return NULL;
  }


  /**
   * Inserts given fid into dosomething_reportback_files table for this entity.
   *
   * @param object $values
   *   Values to write to a dosomething_reportback_file record.
   */
  public function createReportbackFile($values) {
    if (!isset($values->caption)) {
      $values->caption = NULL;
    }
    // Default status should be pending:
    $status = 'pending';
    // If this reportback has been flagged already:
    if ($this->flagged) {
      $status = 'flagged';
    }
    $reportback_file = entity_create('reportback_item', array(
      'rbid' => $this->rbid,
      'fid' => $values->fid,
      'caption' => $values->caption,
      'remote_addr' => dosomething_helpers_ip_address(),
      'status' => $status,
    ));
    return $reportback_file->save();
  }


  /**
   * Logs current entity values with given $op string.
   */
  public function insertLog($op) {
    global $user;
    // Store global uid, in rare case this is staff editing a reportback record.
    $uid = $user->uid;
    // If there is no uid, it's because this is a mobile submission.
    if ($uid == 0) {
      // Use the uid on the reportback entity instead.
      $uid = $this->uid;
    }
    // If deleting, store current time.
    if ($op == 'delete') {
      $timestamp = REQUEST_TIME;
    }
    // Else use the entity's updated property.
    else {
      $timestamp = $this->updated;
    }
    try {
      // Grab file fids to keep as a record.
      $fids = $this->getFids();
      // Log the entity values into the log table.
      $id = db_insert($this->log_table)
        ->fields(array(
          'rbid' => $this->rbid,
          'uid' => $uid,
          'op' => $op,
          'timestamp' => $timestamp,
          'quantity' => $this->quantity,
          'why_participated' => $this->why_participated,
          'files' => implode(',', $fids),
          'num_files' => count($fids),
          'remote_addr' => dosomething_helpers_ip_address(),
        ))
        ->execute();
    }
    catch (Exception $e) {
      watchdog('dosomething_reportback', $e, array(), WATCHDOG_ERROR);
    }
  }


  /**
   * Returns array of themed images for this Reportback.
   *
   * @return array
   */
  public function getThemedImages($style) {
    $images = array();
    if (!module_exists('dosomething_image')) return $images;

    foreach ($this->fids as $fid) {
      $images[] = dosomething_image_get_themed_image_by_fid($fid, $style);
    }
    return $images;
  }


  /**
   * Deletes the Reportback files.
   */
  public function deleteFiles() {
    // Loop through the reportback files:
    foreach ($this->getFids() as $fid) {
      $rbf = reportback_file_load($fid);
      $rbf->delete();
    }
  }


  /**
   * Flags or promotes the reportback, and adds reasons.
   *
   * @param string $status
   *   The status of the reprotback file (approved, flagged, excluded, promoted)
   * @param array $values
   *   Array storing values for flagged/promoted reasons.
   */
  public function setFlaggedPromoted($status = NULL, $values = NULL) {
    if ($status === 'flagged') {
      $this->flagged = 1;
      $this->flagged_reason = $values['flagged_reason'] ?: NULL;
      $this->promoted = 0;
    }
    elseif ($status === 'promoted') {
      $this->promoted = 1;
      $this->promoted_reason = $values['promoted_reason'] ?: NULL;
      $this->flagged = 0;
    }
    else {
      $this->flagged = 0;
      $this->promoted = 0;
    }
    return entity_save('reportback', $this);
  }

}
