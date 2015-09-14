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
  public $flagged;
  public $reportback_items;
  public $campaign;
  public $user;

  // @TODO: add the following?
  // public $flagged_reason; // Should be nested in flagged property?
  // public $promoted;
  // public $promoted_reason; // Should be nested in promoted property?

  // @TODO: Properties to potentially deprecate
  // public $fids;


  /**
   * Overrides construct to set calculated properties.
   *
   * @param array $values
   * @throws Exception
   */
  public function __construct(array $values = []) {
    parent::__construct($values, 'reportback');

    // @TODO: Temporary hack to avoid code below executing on new class instance in specific scenarios.
    if (!isset($values['ignore'])) {
      // It allows the Reportback form and prior submitted data to load properly.
      $this->fids = array();
      // If this is a new entity, rbid may not be set.
      if (isset($this->rbid)) {
        $this->fids = $this->getFids();
      }

      // If a reportback nid exists:
      if (isset($this->nid)) {
        // Set properties found on the reportback's node nid.
        $this->node_title = $this->getNodeTitle();

        if (module_exists('dosomething_campaign_run')) {
          // Check if this reportback is associated with Campaign Run node.
          if ($parent_nid = dosomething_campaign_run_get_parent_nid($this->nid)) {
            // Use the Campaign node nid instead of the Run nid.
            $this->nid = $parent_nid;
          }
        }

        $this->noun = $this->getNodeSingleTextValue('field_reportback_noun');
        $this->verb = $this->getNodeSingleTextValue('field_reportback_verb');
        $this->quantity_label = $this->noun . ' ' . $this->verb;
      }
    }

    unset($values['ignore']);
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
   * @throws Exception
   */
  public static function get($ids) {
    $reportbacks = [];
    $results = dosomething_reportback_get_reportbacks_query_result(['rbid' => $ids]);

    if (!$results) {
      throw new Exception('No reportback data found.');
    }

    foreach($results as $item) {
      // @TODO: remove need for passing variable for constructor check.
      $reportback = new static(['ignore' => TRUE]);
      $reportback->build($item);

      $reportbacks[] = $reportback;
    }

    return $reportbacks;
  }


  /**
   * Convenience method to retrieve reportbacks based on supplied filters.
   *
   * @param array $filters
   * @return array
   * @throws Exception
   */
  public static function find(array $filters = []) {
    $reportbacks = [];

    $results = dosomething_reportback_get_reportbacks_query($filters);

    if (!$results) {
      throw new Exception('No reportback data found.');
    }

    foreach($results as $item) {
      // @TODO: remove need for passing variable for constructor check.
      $reportback = new static(['ignore' => TRUE]);
      $reportback->build($item);

      $reportbacks[] = $reportback;
    }

    return $reportbacks;
  }


  /**
   * Build out the instantiated Reportback class object with supplied data.
   *
   * @param object $data
   */
  private function build($data) {
    $this->id = $data->rbid;
    $this->created_at = $data->created;
    $this->updated_at = $data->updated;
    $this->quantity = (int) $data->quantity;
    $this->why_participated = $data->why_participated;
    $this->flagged = (bool) $data->flagged;
    $this->reportback_items = dosomething_helpers_format_data($data->items);
    $this->campaign = [
      'id' => $data->nid,
      'title' => $data->title,
      'reportback_info' => [
        'noun' => $data->noun,
        'verb' => $data->verb,
      ],
    ];

    $northstar_user = dosomething_northstar_get_northstar_user($data->uid);
    $northstar_user = json_decode($northstar_user->data, true);
    $northstar_user = (object) $northstar_user['data'][0];

    $this->user = [
      'drupal_id' => $data->uid,
      'id' => $northstar_user->_id,
      'first_name' => $northstar_user->first_name,
      'last_name' => $northstar_user->last_name,
      'photo' => $northstar_user->photo,
      'country' => $northstar_user->country,
    ];
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
      $reasons = '';
      $flagged_reason = $this->flagged_reason;
      $promoted_reason = $this->promoted_reason;
      if (isset($flagged_reason)) {
        $reasons .= $flagged_reason . ', ';
      }
      if (isset($promoted_reason)) {
        $reasons .= $promoted_reason;
      }
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
          'reason' => $reasons,
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
    $items = ReportbackItem::get($this->getFids());

    // Determine all of the reportback statuses
    $flagged_reportbacks = FALSE;
    $promoted_reportbacks = FALSE;

    foreach ($items as $item) {
      if ($item->status === "flagged") {
        $flagged_reportbacks = TRUE;

      }
      else if($item->status === "promoted") {
        $promoted_reportbacks = TRUE;
      }
    }

    // Verifies that reportbacks get the correct status and boolean
    // regardless of the order they are reviewed or how many there is
    if ($flagged_reportbacks || $status === "flagged") {
      $status = "flagged";
    }
    // Promoted must be after flagged as it has second priority
    else if($promoted_reportbacks || $status === "promoted") {
      $status = "promoted";
    }

    // Based on the logic decided above, modify the review values
    if ($status === 'flagged') {
      $this->flagged = 1;
      $this->promoted = 0;

      // If the user doesn't select a reason for a reportback item,
      // an array is sent instead of a string.
      if (is_string($values['flagged_reason'])) {
        // Ensure that the string isn't empty (Occurs when you press save without changing anything)
        if (empty($values['flagged_reason'])) {
          // If the string is empty use the existing reason
          $values['flagged_reason'] = $this->flagged_reason;
        }
        $this->flagged_reason = $values['flagged_reason'];
      }

      // Set the other status reason to NULL if there isn't any left
      if (!$promoted_reportbacks) {
        $this->promoted_reason = NULL;
      }
    }
    elseif ($status === 'promoted') {
      $this->promoted = 1;
      $this->flagged = 0;

      // If the user doesn't select a reason for a reportback item,
      // an array is sent instead of a string.
      if (is_string($values['promoted_reason'])) {
        // Ensure that the string isn't empty (Occurs when you press save without changing anything)
        if (empty($values['promoted_reason'])) {
          // If the string is empty use the existing reason
          $values['promoted_reason'] = $this->promoted_reason;
        }
        $this->promoted_reason = $values['promoted_reason'];
      }

      // There should never be a flagged reason when promoted is the reportback status
      $this->flagged_reason = NULL;
    }
    else {
      $this->flagged = 0;
      $this->promoted = 0;
      $this->flagged_reason = NULL;
      $this->promoted_reason = NULL;
    }

    return entity_save('reportback', $this);
  }

}
