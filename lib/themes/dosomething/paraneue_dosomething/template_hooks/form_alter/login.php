<?php

/**
 * Login form & modal markup.
 */
if( $form_id == "user_login_block" || $form_id == 'user_login' ) {
  $form['#attributes']['class'] = 'auth--login';

  $form['message'] = array(
    '#type' => 'item',
    '#markup' => '<h2 class="auth--header">Log in to get started!</h2>',
    '#weight' => -199
  );

  unset($form['links']);

  $form['create-account-link'] = array(
    '#type' => 'item',
    '#markup' => '<p class="auth--toggle-link"><a href="/user/registration" data-cached-modal="#modal--register" class="js-modal-link">Create a DoSomething.org Account</a><br/><a href="/user/password">Forgot password?</a></p>',
    '#weight' => 500
  );

  // After build form changes.
  $form['#after_build'][] = 'paraneue_dosomething_login_after_build';
}


?>
