<?php

/**
 * Login form markup (see `dosomething_user` module). 
 */
if( $form_id == "user_login_block" ) {
  $form['#attributes']['class'] = 'auth--login';

  $form['modal-close-button'] = array(
    '#type' => 'item',
    '#markup' => '<a href="#" class="js-close-modal modal-close-button">×</a>',
    '#weight' => -200
  );

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
}

?>
