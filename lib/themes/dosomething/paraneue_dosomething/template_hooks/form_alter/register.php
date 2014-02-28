<?php

/**
 * Registration form & modal markup.
 *
 * Implements hook_form_alter().
 */
function paraneue_dosomething_form_alter_register(&$form, &$form_state, $form_id) {
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
}

/**
 * Custom afterbuild on registration form.
 *
 * @param array - $form
 *  A drupal form array.
 * @param array - $form_state
 *  A drupal form_state array.
 *
 * @return - array - $form
 *  Modified drupal form.
 */
function paraneue_dosomething_register_after_build($form, &$form_state) {
  // Field references
  $field_first_name = &$form['field_first_name'][LANGUAGE_NONE][0]['value'];
  $field_birthdate = &$form['field_birthdate'][LANGUAGE_NONE][0]['value']['date'];
  $field_mail = &$form['account']['mail'];
  $field_mobile = &$form['field_mobile'][LANGUAGE_NONE][0]['value'];
  $field_pass = &$form['account']['pass']['pass1'];
  $field_pass_confirmation = &$form['account']['pass']['pass2'];
  
  // Re-arrange and clean up form and containers.
  $form['field_first_name']['#weight'] = '-20';
  $form['field_birthdate']['#weight'] = '-19';
  $form['field_birthdate'][LANGUAGE_NONE][0]['#theme_wrappers'] = array('form_element');
  unset($form['field_birthdate'][LANGUAGE_NONE][0]['#title']);

  // Customize field elements.
  $field_first_name['#attributes']['placeholder'] = t('What do we call you?');
  $field_first_name['#attributes']['class'] = array('js-validate');
  $field_first_name['#attributes']['data-validate'] = 'name';
  $field_first_name['#attributes']['data-validate-required'] = '';
  
  $field_birthdate['#attributes']['placeholder'] = t('MM/DD/YYYY');
  $field_birthdate['#attributes']['class'] = array('js-validate');
  $field_birthdate['#attributes']['data-validate'] = 'birthday';
  $field_birthdate['#attributes']['data-validate-required'] = '';
  $field_birthdate['#title_display'] = 'before';
  $field_birthdate['#title'] = 'Birthday';
  unset($field_birthdate['#description']);

  $field_mail['#title'] = t('Email');
  $field_mail['#attributes']['placeholder'] = t('your_email@example.com');
  $field_mail['#attributes']['class'] = array('js-validate');
  $field_mail['#attributes']['data-validate'] = 'email';
  $field_mail['#attributes']['data-validate-required'] = '';
  unset($field_mail['#description']);

  $form['field_mobile']['#weight'] = -11;
  $field_mobile['#title'] = 'Cell Number <span class="field-label-optional">(optional)</span>'; 
  $field_mobile['#attributes']['placeholder'] = t('(555) 555-5555');
  $field_mobile['#attributes']['class'] = array('js-validate');
  $field_mobile['#attributes']['data-validate'] = 'phone';

  $field_pass['#attributes']['placeholder'] = t('Top secret!');
  $field_pass['pass1']['#attributes']['class'] = array('js-validate');
  $field_pass['pass1']['#attributes']['data-validate'] = 'password';
  $field_pass['#attributes']['data-validate-required'] = '';
  $field_pass['#attributes']['data-validate-trigger'] = '#edit-pass-pass2';
  unset($form['account']['pass']['#description']);

  $field_pass_confirmation['#attributes']['placeholder'] = t('Just double checking!');
  $field_pass_confirmation['#attributes']['class'] = array('js-validate');
  $field_pass_confirmation['#attributes']['data-validate'] = 'match';
  $field_pass_confirmation['#attributes']['data-validate-required'] = '';
  $field_pass_confirmation['#attributes']['data-validate-match'] = '#edit-pass-pass1';

  return $form;
}

