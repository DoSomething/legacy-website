<?php

/**
 * Registration form & modal markup.
 */
if ( $form_id == "user_register_form" ) {
  $form['#attributes']['class'] = 'auth--register';

  $form['message'] = array(
    '#type' => 'item',
    '#markup' => '<h2 class="auth--header">Create a DoSomething.org account to get started!</h2>',
    '#weight' => -199
  );

  $form['create-account-link'] = array(
    '#type' => 'item',
    '#markup' => '<p class="auth--toggle-link"><a href="/user/login" data-cached-modal="#modal--login" class="js-modal-link">Login to an existing account</a></p>',
    '#weight' => 500
  );

  // After build form changes.
  $form['#after_build'][] = 'paraneue_dosomething_register_after_build';
}

?>
