<?php

/**
 * @file
 * Provides classes for the Signup Entity.
 */

/**
 * Our Signup entity class.
 */
class SignupEntity extends Entity {

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'signup/' . $this->identifier());
  }
}

/**
 * Our custom controller for the dosomething_signup type.
 */
class SignupEntityController extends EntityAPIController {
  /**
   * Overrides buildContent() method.
   *
   * Adds Signup properties into Signup entity's render.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    // Load user to get username.
    $account = user_load($entity->uid);
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);
    $build['nid'] = array(
      '#type' => 'markup',
      '#markup' => '<p>Nid: ' . l($entity->nid, 'node/' . $entity->nid . '/signups') . '</p>',
    );
    $build['username'] = array(
      '#type' => 'markup',
      '#markup' => '<p>User: ' . l($account->name, 'user/' . $account->uid) . '</p>',
    );
    $build['timestamp'] = array(
      '#type' => 'markup',
      '#markup' => '<p>Signed up: ' . format_date($entity->timestamp, 'short') . '</p>',
    );
    if ($entity->signup_data_form_timestamp) {
      $build['signup_data_form_submitted'] = array(
        '#type' => 'markup',
        '#markup' => '<p>Signup Data Form Submitted: ' . format_date($entity->signup_data_form_timestamp, 'short') . '</p>',
      );
      if ($entity->signup_data_form_response != NULL) {
        $build['signup_data_form_response'] = array(
          '#type' => 'markup',
          '#markup' => '<p>Signup Data Form Response: ' . $entity->signup_data_form_response . '</p>',
        );
      }
      $reset_form = drupal_get_form('dosomething_signup_reset_signup_data_form', $entity->sid);
      $build['reset_form'] = $reset_form;
    }
    if ($entity->why_signedup) {
      $build['why_signedup'] = array(
        '#type' => 'markup',
        '#markup' => '<p>Signup Reason: ' . check_plain($entity->why_signedup) . '</p>',
      );    
    }
    if ($entity->source) {
      $build['source'] = array(
        '#type' => 'markup',
        '#markup' => '<p>Source: ' . check_plain($entity->source) . '</p>',
      );
    }
    return $build;
  }

  /**
   * Overrides save() method.
   *
   * Populates timestamp and uid automatically.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    if (isset($entity->is_new)) {
      if (!isset($entity->timestamp)) {
        $entity->timestamp = REQUEST_TIME;
      }
      if (!isset($entity->uid)) {
        global $user;
        $entity->uid = $user->uid;
      }
    }
    parent::save($entity, $transaction);
    if (DOSOMETHING_SIGNUP_LOG_SIGNUPS) {
      watchdog('dosomething_signup', json_encode($entity));
    }
  }
}
