<?php

/**
 * Login form & modal markup.
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
      '#markup' => '<p class="auth--toggle-link"><a href="/user/registration" data-cached-modal="#modal--register" class="js-modal-link">Create a DoSomething.org Account</a><br/><a href="/user/password">Forgot password?</a></p>',
      '#weight' => 500
    );

    unset($form['links']);

    // After build form changes.
    $form['#after_build'][] = 'paraneue_dosomething_login_after_build';
  }
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
  $form['name']['#attributes']['placeholder'] = 'Email address or cell number';
  unset($form['name']['#description']);
 
  $form['pass']['#attributes']['placeholder'] = 'Password';
  unset($form['pass']['#description']);

  return $form; 
}

