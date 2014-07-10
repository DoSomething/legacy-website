<?php

/**
 * Adds login modal to page markup.
 *
 * Implements hook_page_alter().
 */
function paraneue_dosomething_page_alter_login(&$page) {
  if (!user_is_logged_in()){
    $page['page_bottom']['login'] = array(
      '#prefix' => '<div data-modal id="modal--login" role="dialog" hidden>',
      '#suffix' => '</div>',
      'login' => drupal_get_form('user_login_block')
    );
  }
}

/**
 * Configures login form.
 *
 * Implements hook_form_alter().
 */
function paraneue_dosomething_form_alter_login(&$form, &$form_state, $form_id) {
  if( $form_id == "user_login_block" || $form_id == 'user_login' ) {
    $form['#attributes']['class'] = 'auth--login';

    $form['message'] = array(
      '#type' => 'item',
      '#markup' => '<h2 class="auth--header">Log in to get started!</h2>',
      '#weight' => -199
    );

    $form['create-account-link'] = array(
      '#type' => 'item',
      '#markup' => '<p class="auth--toggle-link"><a href="/user/register" id="link--register" data-modal-href="#modal--register">Create a DoSomething.org account</a><br/><a href="/user/password">Forgot password?</a></p>',
      '#weight' => 500
    );

    $form['actions']['submit']['#attributes']['class'] = array('btn');

    unset($form['links']);

    // After build form changes.
    $form['#after_build'][] = 'paraneue_dosomething_login_after_build';
  }
  // Add some changes for the reset password form.
  if ( $form_id ==  'user_pass' ) {
    // After build form changes.
    $form['#after_build'][] = 'paraneue_dosomething_pass_reset_after_build';
    $form['#submit'][] = 'paraneue_dosomething_pass_submit';
   }
}

/**
 * Custom afterbuild on password reset form.
 *
 * @param array - $form
 *  A drupal form array.
 * @param array - $form_state
 *  A drupal form_state array.
 *
 * @return - array - $form
 *  Modified drupal form.
 */
function paraneue_dosomething_pass_reset_after_build($form, &$form_state) {
  $form['name']['#title'] = 'Email address';
  return $form;
}

/**
 * Custom submit handler on password reset form.
 *
 * Sets a message after form submission.
 *
 * @param array - $form
 *  A drupal form array.
 * @param array - $form_state
 *  A drupal form_state array.
 */
function paraneue_dosomething_pass_submit($form, &$form_state) {
  $email = $form_state['values']['name'];
  drupal_set_message(t('An email has been sent to '. $email . ' to reset your password.'));
}

/**
 * Custom afterbuild on login form.
 *
 * @param array - $form
 *  A drupal form array.
 * @param array - $form_state
 *  A drupal form_state array.
 *
 * @return - array - $form
 *  Modified drupal form.
 */
function paraneue_dosomething_login_after_build($form, &$form_state) {
  // Customize field elements.
  $form['name']['#title'] = 'Email address or cell number';
  unset($form['name']['#description']);

  unset($form['pass']['#description']);

  return $form;
}
