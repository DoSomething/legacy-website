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

    $header = t("Log in to get started!");
    $form['header'] = array(
      '#type' => 'item',
      '#markup' => '<h2 class="auth--header">' . $header . '</h2>',
      '#weight' => -199,
    );

    // Check if the Login Form copy variable has been set.
    $subheader = variable_get('dosomething_user_login_form_copy', '');
    if (!empty($subheader)) {
      $form['subheader'] = array(
        '#type' => 'item',
        '#markup' => '<p class="auth--subheader">' . $subheader . '</p>',
        '#weight' => -189,
      );
    }

    $copy_create = t("Create a DoSomething.org account");
    $link_create = '<a href="/user/register" id="link--register" data-modal-href="#modal--register">' . $copy_create . '</a>';
    $copy_forgot = t("Forgot password?");
    $link_forgot = l($copy_forgot, 'user/password');
    $form['create-account-link'] = array(
      '#type' => 'item',
      '#markup' => '<p class="auth--toggle-link">' . $link_create . '<br/>' . $link_forgot . '</p>',
      '#weight' => 500,
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
  $form['name']['#title'] = t('Email address');
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
  $msg = t('An email has been sent to @email to reset your password.', array(
    '@email' => check_plain($email),
  ));
  drupal_set_message($msg);
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
  $form['name']['#title'] = t('Email address or cell number');
  unset($form['name']['#description']);

  unset($form['pass']['#description']);

  return $form;
}
