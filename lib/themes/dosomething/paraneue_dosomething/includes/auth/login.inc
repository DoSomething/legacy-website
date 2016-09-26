<?php

/**
 * Adds login modal to page markup.
 *
 * Implements hook_page_alter().
 */
function paraneue_dosomething_page_alter_login(&$page) {
  if (!user_is_logged_in()){
    if (module_exists('dosomething_northstar') && variable_get('dosomething_user_openid_oauth_login_enabled')) {
      $page['page_bottom']['login'] = [
        '#type' => 'item',
        '#prefix' => '<div data-modal id="modal--login" role="dialog" hidden>',
        '#suffix' => '</div>',
        '#markup' => dosomething_northstar_openid_login_view(),
      ];
    }
    else {
      $page['page_bottom']['login'] = array(
        '#prefix' => '<div data-modal id="modal--login" role="dialog" hidden><div class="modal__block">',
        '#suffix' => '</div></div>',
        'login' => drupal_get_form('user_login_block')
      );
    }
  }
}

/**
 * Configures login form.
 *
 * Implements hook_form_alter().
 */
function paraneue_dosomething_form_alter_login(&$form, &$form_state, $form_id) {
  if( $form_id == "user_login_block" || $form_id == 'user_login' ) {
    $header = t("Log in to get started!");
    $form['header'] = array(
      '#type' => 'item',
      '#markup' => '<h2 class="auth-heading">' . $header . '</h2>',
      '#weight' => -199,
    );

    $form['actions']['submit']['#value'] = t('Log In');

    // Check if the Login Form copy variable has been set.
    $subheader = t(variable_get('dosomething_user_login_form_copy', ''));
    if (!empty($subheader)) {
      $form['subheader'] = array(
        '#type' => 'item',
        '#markup' => '<p class="auth-heading">' . $subheader . '</p>',
        '#weight' => -189,
      );
    }

    $copy_create = t("Create a DoSomething.org account");
    $link_create = '<a href="/user/register" id="link--register" data-modal-href="#modal--register">' . $copy_create . '</a>';

    $link_forgot = NULL;
    // Check if the password link should be displayed.
    $display_pw = variable_get('dosomething_user_login_form_display_password_link', TRUE);
    if ($display_pw) {
      $copy_forgot = t("Forgot password?");
      $link_forgot = '<br/>' . l($copy_forgot, 'user/password');
    }
    $form['create-account-link'] = array(
      '#type' => 'item',
      '#markup' => '<p class="auth-toggle-link">' . $link_create . $link_forgot . '</p>',
      '#weight' => 500,
    );

    $form['actions']['submit']['#attributes']['class'] = array('button');

    unset($form['links']);

    // After build form changes.
    $form['#after_build'][] = 'paraneue_dosomething_login_after_build';
  }
  // Add some changes for the reset password form.
  if ( $form_id ==  'user_pass' ) {
    // After build form changes.
    $form['#after_build'][] = 'paraneue_dosomething_pass_reset_after_build';
    $form['#submit'][] = 'paraneue_dosomething_pass_submit';
    $form['#validate'][] = 'paraneue_dosomething_pass_validate';
  }

  return $form;
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
 * Custom validation handler on the password reset form.
 *
 * Sets the neutral message when user is not found.
 *
 * @see paraneue_dosomething_pass_set_message()
 */
function paraneue_dosomething_pass_validate($form, &$form_state) {
  if (!empty($form_state['values']['name']) && form_get_error($form['name'])) {
    // Hide previous errors.
    form_clear_error();
    drupal_get_messages('error');

    // Set the neutral message.
    paraneue_dosomething_pass_set_message();

    // Behave same as in the submit callback.
    drupal_goto('user');
  }
}

/**
 * Custom submit handler on the password reset form.
 *
 * Sets the neutral message after the form submission.
 *
 * @see paraneue_dosomething_pass_set_message()
 */
function paraneue_dosomething_pass_submit($form, &$form_state) {
  paraneue_dosomething_pass_set_message();
}

/**
 * Helper function for the password reset form.
 *
 * Designed to set the neutral message that would not expose whether the
 * email is registered in our DB.
 *
 * @see https://www.owasp.org/index.php/Authentication_Cheat_Sheet#Authentication_and_Error_Messages
 */
function paraneue_dosomething_pass_set_message() {
  $default_msg = 'If your email address exists in our database, you will receive a password recovery link at your email address in a few minutes.';
  $msg = variable_get('dosomething_user_reset_password_copy', $default_msg);

  drupal_set_message(t($msg));
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
