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
    global $language;

    parent::__construct($values, 'reportback');

    // @TODO: Temporary hack to avoid code below executing on new class instance in specific scenarios.
    if (!isset($values['ignore'])) {
      // It allows the Reportback form and prior submitted data to load properly.
      $this->fids = [];
      // If this is a new entity, rbid may not be set.
      if (isset($this->rbid)) {
        $this->fids = $this->getFids();
      }

      // If a reportback nid exists:
      if (isset($this->nid)) {
        // Set properties found on the reportback's node nid.
        $this->node_title = $this->getNodeSingleTextValue('title_field', $language);

        if (module_exists('dosomething_campaign_run')) {
          // Check if this reportback is associated with Campaign Run node.
          if ($parent_nid = dosomething_campaign_run_get_parent_nid($this->nid)) {
            // Use the Campaign node nid instead of the Run nid.
            $this->nid = $parent_nid;
          }
        }

        $this->noun = $this->getNodeSingleTextValue('field_reportback_noun', $language);
        $this->verb = $this->getNodeSingleTextValue('field_reportback_verb', $language);
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
   * @param  string|array  $ids Single id or array of ids of Reportbacks to load.
   * @return array
   * @throws Exception
   */
  public static function get($ids) {
    $single_reportback = FALSE;
    $reportbacks = [];

    if (!is_array($ids)) {
      $single_reportback = TRUE;
    }

    $results = dosomething_reportback_get_reportbacks_query(['rbid' => $ids]);


    if (!user_access('administer modules') && !$results) {
      $results = dosomething_reportback_get_reportbacks_query(['rbid' => $ids], TRUE);
      
      if ($results) {
        throw new Exception('Access denied.');
      }
    }
   
   if (!$results) {
      throw new Exception('No reportback data found.');
    }

    foreach($results as $item) {
      // @TODO: remove need for passing variable for constructor check.
      $reportback = new static(['ignore' => TRUE]);
      $reportback->build($item, TRUE);

      $reportbacks[] = $reportback;
    }

    if ($single_reportback) {
      return array_pop($reportbacks);
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

    // What if there are results that are returned but not all results are returned since flagged will not be included. Is this mis-leading? 
    $results = dosomething_reportback_get_reportbacks_query($filters);

    if (!user_access('administer modules') && !$results) {
      $results = dosomething_reportback_get_reportbacks_query($filters, TRUE);
      
      if ($results) {
        http_response_code(403);
        throw new Exception('Access denied.');
      }
    }
    else if (!$results) {
      throw new Exception('No reportback data found.');
    }

    foreach($results as $item) {
      // @TODO: remove need for passing variable for constructor check.
      $reportback = new static(['ignore' => true]);
      $reportback->build($item, $filters['load_user']);

      $reportbacks[] = $reportback;
    }

    return $reportbacks;
  }

  /**
   * Build out the instantiated Reportback class object with supplied data.
   *
   * @param object $data
   * @param bool  $full Boolean to decide whether to fetch full user data.
   */
  private function build($data, $full = false) {
    global $user;
    $northstar_user = (object) [];

    $this->id = $data->rbid;
    $this->created_at = $data->created;
    $this->updated_at = $data->updated;
    $this->quantity = (int) $data->quantity;
    $this->why_participated = dosomething_helpers_isset($data, 'why_participated');
    $this->flagged = $this->getFlag($data->flagged);
    $this->reportback_items = dosomething_helpers_format_data($data->items);
    // @TODO: need to potentially remove this and include language from NS user object instead of global $user
    $this->language = dosomething_helpers_isset($user, 'language', 'en-global');
    $this->campaign = Campaign::get($data->nid);

    if ($full) {
      $northstar_response = dosomething_northstar_get_northstar_user($data->uid);
      $northstar_response = json_decode($northstar_response);

      if (!empty($northstar_response->data) && !isset($northstar_response->error)) {
        $northstar_user = $northstar_response->data;
      }
    }

    $this->user = [
      'drupal_id' => $data->uid,
      'id' => dosomething_helpers_isset($northstar_user, 'id'),
      'first_name' => dosomething_helpers_isset($northstar_user, 'first_name'),
      'last_initial' => dosomething_helpers_isset($northstar_user, 'last_initial'),
      'photo' => dosomething_helpers_isset($northstar_user, 'photo'),
      'country' => dosomething_helpers_isset($northstar_user, 'country'),
    ];
  }

  /**
   * Get the flagging status for Reportback.
   *
   * @param  $flag
   * @return mixed|null
   */
  protected function getFlag($flag) {
    if (is_null($flag)) {
      return NULL;
    }
    else {
      return dosomething_helpers_convert_string_to_boolean($flag);
    }
  }

  /**
   * Return all fids from dosomething_reportback_files table for this entity.
   */
  public function getFids() {
    return db_select($this->files_table, 'f')
      ->fields('f', ['fid'])
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
   * Returns a single text value for a given $field_name for the $entity->nid.
   */
  public function getNodeSingleTextValue($field_name, $language) {
    $result = db_select('field_data_' . $field_name, 'f')
      ->fields('f', [$field_name . '_value'])
      ->condition('entity_id', $this->nid)
      ->condition('entity_type', 'node')
      ->condition('language', $language->language)
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
    $reportback_file = entity_create('reportback_item', [
      'rbid' => $this->rbid,
      'fid' => $values->fid,
      'caption' => $values->caption,
      'remote_addr' => dosomething_helpers_ip_address(),
      'status' => $status,
    ]);
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
        ->fields([
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
        ])
        ->execute();
    }
    catch (Exception $e) {
      watchdog('dosomething_reportback', $e, [], WATCHDOG_ERROR);
    }
  }

  /**
   * Returns array of themed images for this Reportback.
   *
   * @return array
   */
  public function getThemedImages($style) {
    $images = [];
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
      if ($item->status === 'flagged') {
        $flagged_reportbacks = TRUE;

      }
      elseif($item->status === 'promoted') {
        $promoted_reportbacks = TRUE;
      }
    }

    // Verifies that reportbacks get the correct status and boolean
    // regardless of the order they are reviewed or how many there is
    if ($flagged_reportbacks || $status === 'flagged') {
      $status = 'flagged';
    }
    // Promoted must be after flagged as it has second priority
    elseif($promoted_reportbacks || $status === 'promoted') {
      $status = 'promoted';
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
