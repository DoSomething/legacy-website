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

    // Customize field elements.
    $form['field_first_name']['#weight'] = '-20';
    $form['field_first_name'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('What do we call you?');
    $form['field_first_name'][LANGUAGE_NONE][0]['value']['#attributes']['class'] = array('js-validate');
    $form['field_first_name'][LANGUAGE_NONE][0]['value']['#attributes']['data-validate'] = 'name';
    $form['field_first_name'][LANGUAGE_NONE][0]['value']['#attributes']['data-validate-required'] = '';
     
    $form['account']['mail']['#title'] = t('Email');
    $form['account']['mail']['#attributes']['placeholder'] = t('your_email@example.com');
    $form['account']['mail']['#attributes']['class'] = array('js-validate');
    $form['account']['mail']['#attributes']['data-validate'] = 'email';
    $form['account']['mail']['#attributes']['data-validate-required'] = '';
    unset($form['account']['mail']['#description']);

    $form['field_mobile']['#weight'] = -11;
    $form['field_mobile'][LANGUAGE_NONE][0]['value']['#title'] = 'Cell Number <span class="field-label-optional">(optional)</span>'; 
    $form['field_mobile'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('(555) 555-5555');
    $form['field_mobile'][LANGUAGE_NONE][0]['value']['#attributes']['class'] = array('js-validate');
    $form['field_mobile'][LANGUAGE_NONE][0]['value']['#attributes']['data-validate'] = 'phone';

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
  $form['field_birthdate']['#weight'] = '-19';
  $form['field_birthdate'][LANGUAGE_NONE][0]['#theme_wrappers'] = array('form_element');
  $form['field_birthdate'][LANGUAGE_NONE][0]['value']['date']['#attributes']['placeholder'] = t('MM/DD/YYYY');
  $form['field_birthdate'][LANGUAGE_NONE][0]['value']['date']['#attributes']['class'] = array('js-validate');
  $form['field_birthdate'][LANGUAGE_NONE][0]['value']['date']['#attributes']['data-validate'] = 'birthday';
  $form['field_birthdate'][LANGUAGE_NONE][0]['value']['date']['#attributes']['data-validate-required'] = '';
  $form['field_birthdate'][LANGUAGE_NONE][0]['value']['date']['#title_display'] = 'before';
  $form['field_birthdate'][LANGUAGE_NONE][0]['value']['date']['#title'] = 'Birthday';
  unset($form['field_birthdate'][LANGUAGE_NONE][0]['#title']);
  unset($form['field_birthdate'][LANGUAGE_NONE][0]['value']['date']['#description']);

  $form['account']['pass']['pass1']['#attributes']['placeholder'] = t('Top secret!');
  $form['account']['pass']['pass1']['pass1']['#attributes']['class'] = array('js-validate');
  $form['account']['pass']['pass1']['pass1']['#attributes']['data-validate'] = 'password';
  $form['account']['pass']['pass1']['#attributes']['data-validate-required'] = '';
  $form['account']['pass']['pass1']['#attributes']['data-validate-trigger'] = '#edit-pass-pass2';

  $form['account']['pass']['pass2']['#attributes']['placeholder'] = t('Just double checking!');
  $form['account']['pass']['pass2']['#attributes']['class'] = array('js-validate');
  $form['account']['pass']['pass2']['#attributes']['data-validate'] = 'match';
  $form['account']['pass']['pass2']['#attributes']['data-validate-required'] = '';
  $form['account']['pass']['pass2']['#attributes']['data-validate-match'] = '#edit-pass-pass1';

  unset($form['account']['pass']['#description']);

  return $form;
}

