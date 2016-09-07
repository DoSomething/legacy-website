<?php

class SignupsController extends EntityAPIController {

  protected $ignore_global_user = FALSE;

  // @TODO: dosomething_signup.inc didn't have this call to the parent construct
  // and not sure if it's an issue if added.
  public function __construct() {
    parent::__construct('signup');
  }

  /**
   * Overrides buildContent() method.
   *
   * Adds Signup properties into Signup entity's render.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = []) {
    // Load user to get username.
    $account = user_load($entity->uid);
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);
    $build['nid'] = [
      '#type' => 'markup',
      '#markup' => '<p>Nid: ' . l($entity->nid, 'node/' . $entity->nid . '/signups') . '</p>',
    ];
    $build['username'] = [
      '#type' => 'markup',
      '#markup' => '<p>User: ' . l($account->name, 'user/' . $account->uid) . '</p>',
    ];
    $build['timestamp'] = [
      '#type' => 'markup',
      '#markup' => '<p>Signed up: ' . format_date($entity->timestamp, 'short') . '</p>',
    ];
    if ($entity->signup_data_form_timestamp) {
      $build['signup_data_form_submitted'] = [
        '#type' => 'markup',
        '#markup' => '<p>Signup Data Form Submitted: ' . format_date($entity->signup_data_form_timestamp, 'short') . '</p>',
      ];
      if ($entity->signup_data_form_response != NULL) {
        $build['signup_data_form_response'] = [
          '#type' => 'markup',
          '#markup' => '<p>Signup Data Form Response: ' . $entity->signup_data_form_response . '</p>',
        ];
      }
      $reset_form = drupal_get_form('dosomething_signup_reset_signup_data_form', $entity->sid);
      $build['reset_form'] = $reset_form;
    }
    if ($entity->why_signedup) {
      $build['why_signedup'] = [
        '#type' => 'markup',
        '#markup' => '<p>Signup Reason: ' . check_plain($entity->why_signedup) . '</p>',
      ];
    }
    if ($entity->source) {
      $build['source'] = [
        '#type' => 'markup',
        '#markup' => '<p>Source: ' . check_plain($entity->source) . '</p>',
      ];
    }
    return $build;
  }

  /**
   * Automagically create a new record.
   *
   * @param  array   $values
   * @return bool|Exception
   *
   * @todo   Eventually change this into just a create() method that overrides
   * the parent EntityAPIController method, and doesn't break dosomething_signup_create()
   * which does not instantiate the SignupController object, so it has no access to
   * the $this->save() method below.
   */
  public function magick_create(array $values = []) {
    $signup = parent::create($values);

    // The $this->save() overriden method depends on the use of the
    // global $user, and then does a check against this user with the user
    // on the newly created Signup entity. If they don't match then the
    // signup fails. The ignore_global_user property is set to true so the
    // afformentioned conditional check on global $user does not happen.
    $this->ignore_global_user = TRUE;

    try {
      $record = $this->save($signup);

      // @TODO: eventually return the actual signup record. S'okay for now.
      return TRUE;
    } catch (Exception $error) {
      throw new Exception('There is already an existing signup for this user on this campaign/campaign run combination.');
    }
  }

  /**
   * Overrides save() method.
   *
   * Populates timestamp and uid automatically.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    global $user;

    if (isset($entity->is_new)) {
      if (!isset($entity->timestamp)) {
        $entity->timestamp = REQUEST_TIME;
      }
      if (!isset($entity->uid)) {
        global $user;
        $entity->uid = $user->uid;
      }
    }

    // Make sure a uid exists.
    if (!isset($entity->uid)) {
      return FALSE;
    }

    // @TODO: We should probably clean this up a bit...
    if (!$this->ignore_global_user) {
      // If the entity uid doesnt belong to current user:
      if ($entity->uid != $user->uid) {
        // And current user can't edit any reportback:
        if (!user_access('edit any signup') && !drupal_is_cli()) {
          watchdog('dosomething_signup', 'Attempted uid override for @entity by User @uid',
            [
              '@entity' => json_encode($entity),
              '@uid' => $user->uid,
            ], WATCHDOG_WARNING);
          return FALSE;
        }
      }
    }

    try {
      $signup_record = parent::save($entity, $transaction);

      if ($signup_record && DOSOMETHING_SIGNUP_LOG_SIGNUPS) {
        watchdog('dosomething_signup', json_encode($entity));
      }

      return $signup_record;
    } catch (Exception $error) {
      throw $error;
    }
  }

}
