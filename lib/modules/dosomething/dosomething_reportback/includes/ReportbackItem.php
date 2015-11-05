<?php

class ReportbackItem extends Entity {

  public $id;
  public $status;
  public $caption;
  public $created_at;
  public $media;
  public $kudos;
  public $reportback;
  public $campaign;
  public $user;


  /**
   * Overrides construct for parent Entity class.
   *
   * @param array $values
   * @throws Exception
   */
  public function __construct(array $values = []) {
    parent::__construct($values, 'reportback_item');
  }


  /**
   * Overrides to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'reportback/' . $this->rbid . '?fid=' . $this->identifier());
  }


  /**
   * Convenience method to retrieve a single or multiple reportback-items from supplied id(s).
   *
   * @param string|array $ids Single id or array of ids of Reportback Items to load.
   * @return array
   * @throws Exception
   */
  public static function get($ids) {
    $reportbackItems = [];

    $results = dosomething_reportback_get_reportback_files_query_result(['fid' => $ids]);

    if (!$results) {
      throw new Exception('No reportback items data found.');
    }

    foreach($results as $item) {
      $reportbackItem = new static;
      $reportbackItem->build($item);

      $reportbackItems[] = $reportbackItem;
    }

    return $reportbackItems;
  }


  /**
   * Convenience method to retrieve reportback-items based on supplied filters.
   *
   * @param array $filters
   * @return array
   * @throws Exception
   */
  public static function find(array $filters = []) {
    $reportbackItems = [];

    $results = dosomething_reportback_get_reportback_items_query($filters);

    if (!$results) {
      throw new Exception('No reportback items data found.');
    }

    foreach($results as $item) {
      $load_user = dosomething_helpers_isset($filters['load_user'], NULL, FALSE);
      $reportbackItem = new static();
      $reportbackItem->build($item, $load_user);

      $reportbackItems[] = $reportbackItem;
    }

    return $reportbackItems;
  }


  /**
   * Build out the instantiated Reportback Item class object with supplied data.
   *
   * @param object $data
   * @param bool  $full Boolean to decide whether to fetch full user data.
   */
  private function build($data, $full = false) {
    $northstar_user = (object) [];

    $this->id = $data->fid;
    $this->status = $data->status;
    $this->caption = !empty($data->caption) ? $data->caption : t('DoSomething? Just did!');
    $this->created_at = $data->timestamp;
    $this->media = [
      'uri' => dosomething_image_get_themed_image_url_by_fid($data->fid, '480x480'),
      'type' => 'image',
    ];
    $this->kudos = dosomething_helpers_format_data($data->kids);
    $this->reportback = [
      'id' => $data->rbid,
      'created_at' => $data->created,
      'updated_at' => $data->updated,
      'quantity' => (int) $data->quantity,
    ];
    $this->campaign = [
      'id' => $data->nid,
      'title' => $data->title,
      'reportback_info' => [
        'noun' => $data->noun,
        'verb' => $data->verb,
      ],
    ];

    if ($full) {
      // $northstar_response = dosomething_northstar_get_northstar_user($data->uid);
      $error_response = '{"error":{"code":404,"message":"The resource does not exist."},"debug":{"file":"\/home\/vagrant\/DoSomething.org\/northstar\/app\/Http\/Controllers\/UserController.php","line":146}}';
      $success_response = '{"data":[{"_id":"5430e850dt8hbc541c37tt3d","email":"test@dosomething.org","mobile":"5555550100","drupal_id":"100001","addr_street1":"123","addr_street2":"456","addr_city":"Paris","addr_state":"Florida","addr_zip":"555555","country":"US","birthdate":"12/17/91","first_name":"First","last_name":"Last","updated_at":"2015-11-03 19:52:51","created_at":"2015-11-03 19:52:51","photo":null,"interests":null,"race":null,"religion":null,"school_id":null,"college_name":null,"degree_type":null,"major_name":null,"hs_gradyear":null,"hs_name":null,"sat_math":null,"sat_verbal":null,"sat_writing":null,"cgg_id":null,"agg_id":null,"source":null,"parse_installation_ids":null}]}';
      $northstar_response = json_decode($success_response); //change back to $northstar_response

      if ($northstar_response && !isset($northstar_response->error)) {
        $northstar_user = array_shift($northstar_response->data);
      }

    }

    $this->user = [
      'drupal_id' => $data->uid,
      'id' => dosomething_helpers_isset($northstar_user, '_id'),
      'first_name' => dosomething_helpers_isset($northstar_user, 'first_name'),
      'last_name' => dosomething_helpers_isset($northstar_user, 'last_name'),
      'photo' => dosomething_helpers_isset($northstar_user, 'photo'),
      'country' => dosomething_helpers_isset($northstar_user, 'country'),
    ];
  }


  /**
   * @param string $file_size
   * @return array|null|string
   */
  public function getImage($file_size = '300x300') {
    $image = dosomething_image_get_themed_image_by_fid($this->fid, $file_size);
    if (!$image) {
      return t("File removed.");
    }
    return $image;
  }


  /**
   * @param string $file_size
   * @return null|string
   */
  public function getImageURL($file_size = '300x300') {
    $image = dosomething_image_get_themed_image_url_by_fid($this->fid, $file_size);
    if (!$image) {
      return t("File removed.");
    }
    return $image;
  }


  /**
   * Sets the Reportback File status and Reviewer details.
   *
   * @param array $values
   *   An associative array containing:
   *   - status (string).  Required.
   *   - source (string). The page or device the Review has been submitted from.
   *   - flagged_reason (string).
   *   - delete (integer).  If set to 1, delete the corresponding File entity.
   * @return bool
   */
  public function review($values) {
    global $user;
    if (!isset($values['status'])) {
      return FALSE;
    }
    $this->status = $values['status'];
    $this->reviewer = $user->uid;
    $this->reviewed = REQUEST_TIME;
    // Default source as the current URL path of page being viewed.
    $this->review_source = current_path();
    // If source was passed:
    if (isset($values['source'])) {
      // Store that instead.
      $this->review_source = $values['source'];
    }
    $reportback = reportback_load($this->rbid);
    $reason = NULL;

    if (isset($values['flagged_reason'])) {
      $flagged_reason = $values['flagged_reason'];
    }
    if (isset($values['promoted_reason'])) {
      $promoted_reason = $values['promoted_reason'];
    }

    // Must be saved before calling setFlaggedPromoted
    $updated_reportback_item = entity_save('reportback_item', $this);

    $reportback->setFlaggedPromoted($this->status, $values);

    if (!empty($values['delete'])) {
      $this->deleteFile();
    }

    // Save the reviewed properties.
    return $updated_reportback_item;
  }


  /**
   * Deletes the File associated with this Reportback File.
   */
  public function deleteFile() {
    $file = file_load($this->fid);
    if ($file) {
      return file_delete($file);
    }
  }
}
