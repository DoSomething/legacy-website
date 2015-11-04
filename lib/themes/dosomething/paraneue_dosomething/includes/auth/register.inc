<?php

/**
 * Adds registration modal to page markup.
 *
 * Implements hook_page_alter().
 */
function paraneue_dosomething_page_alter_register(&$page) {
  if (!user_is_logged_in()){
    $page['page_bottom']['register'] = array(
      '#prefix' => '<div data-modal id="modal--register" role="dialog" hidden><div class="modal__block">',
      '#suffix' => '</div></div>',
      'register' => drupal_get_form('user_register_form')
    );
  }
}

/**
 * Configures registration form.
 *
 * Implements hook_form_alter().
 */
function paraneue_dosomething_form_alter_register(&$form, &$form_state, $form_id) {
  if ( $form_id == "user_register_form" ) {
    $copy = t("Create a DoSomething.org account to get started!");
    $form['message'] = array(
      '#type' => 'item',
      '#markup' => '<h2 class="auth-heading">' . $copy . '</h2>',
      '#weight' => -199,
    );

    $form['actions']['submit']['#attributes']['class'] = array('button');
    $form['actions']['submit']['#value'] = t('Create new account');

    $copy = t("Log in to an existing account");
    $form['create-account-link'] = array(
      '#type' => 'item',
      '#markup' => '<p class="auth-toggle-link"><a href="/user/login" data-modal-href="#modal--login">' . $copy . '</a></p>',
      '#weight' => 500,
    );

    $copy = t("Creating an account means you agree to our !terms & !privacy and to receive our weekly update. Message & data rates may apply. Text STOP to opt-out, HELP for help", [
      '!terms' => dosomething_user_get_link_terms_service(),
      '!privacy' => dosomething_user_get_link_privacy_policy(),
    ]);

    $form['legal-text'] = array(
      '#type' => 'item',
      '#markup' => '<p class="footnote">' . $copy . '</p>',
      '#weight' => 501,
    );

    // Customize field elements.
    $form['field_first_name']['#weight'] = '-20';
    $form['field_first_name']['#attributes']['class'] = array('auth-twocol');
    $form['field_first_name'][LANGUAGE_NONE][0]['value']['#title'] = t('First Name');
    $form['field_first_name'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('What do we call you?');
    $form['field_first_name'][LANGUAGE_NONE][0]['value']['#attributes']['class'] = array('js-validate');
    $form['field_first_name'][LANGUAGE_NONE][0]['value']['#attributes']['data-validate'] = 'name';
    $form['field_first_name'][LANGUAGE_NONE][0]['value']['#attributes']['data-validate-required'] = '';

    // If last name is shown, make first name full width
    if (isset($form['field_last_name'])) {
      $form['field_first_name']['#attributes']['class'] = array();
    }

    // If the last name field is present:
    // @see _dosomething_user_register_display_fields().
    if (isset($form['field_last_name'])) {
      $form['field_last_name']['#weight'] = '-19';
      $form['field_last_name'][LANGUAGE_NONE][0]['value']['#title'] = t('Last Name');
      $form['field_last_name'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('What\'s your P.E. teacher call you?');
      $form['field_last_name'][LANGUAGE_NONE][0]['value']['#attributes']['class'] = array('js-validate');
      $form['field_last_name'][LANGUAGE_NONE][0]['value']['#attributes']['data-validate'] = 'last_name';
      $form['field_last_name'][LANGUAGE_NONE][0]['value']['#attributes']['data-validate-required'] = '';
    }

    $form['account']['mail']['#weight'] = 10;
    $form['account']['mail']['#title'] = t('Email');
    $form['account']['mail']['#attributes']['placeholder'] = t('your_email@example.com');
    $form['account']['mail']['#attributes']['class'] = array('js-validate');
    $form['account']['mail']['#attributes']['data-validate'] = 'email';
    $form['account']['mail']['#attributes']['data-validate-required'] = '';
    unset($form['account']['mail']['#description']);


    $country_code = dosomething_settings_get_geo_country_code();
    $show_help_text = FALSE;

    if (in_array($country_code, dosomething_global_get_countries())) {
      if ($country_code == 'BR' || $country_code == 'MX') {
        $show_help_text = TRUE;
        $country_name = dosomething_global_get_country_name($country_code);
      }

      $form['account']['field_mobile'] = $form['field_mobile'];
      $form['account']['field_mobile']['#weight'] = 20;
      $form['account']['field_mobile'][LANGUAGE_NONE][0]['value']['#title'] = t('Cell Number') . ' <em>' . t("(optional)") . '</em>';
      $form['account']['field_mobile'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('(555) 555-5555');
      $form['account']['field_mobile'][LANGUAGE_NONE][0]['value']['#attributes']['class'] = array('js-validate');
      $form['account']['field_mobile'][LANGUAGE_NONE][0]['value']['#attributes']['data-validate'] = 'phone';
      if ($show_help_text) {
        $form['account']['field_mobile'][LANGUAGE_NONE][0]['value']['#description'] = t("Get volunteer opportunities on your phone! Texting available in @country soon", array('@country' => $country_name));
      }
    }

    $form['field_mobile']['#access'] = FALSE;

    $form['account']['pass']['#weight'] = 30;

    // Perform remaining form changes after build is complete.
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
  $form['field_birthdate'][LANGUAGE_NONE][0] = paraneue_dosomething_form_user_profile_after_build($form['field_birthdate'][LANGUAGE_NONE][0], $form_state);
  $form['field_birthdate']['#weight'] = '-18';
  $form['field_birthdate']['#theme_wrappers'] = array('form_element');

  // If last name is shown, make first name full width
  if (isset($form['field_last_name'])) {
    $form['field_birthdate']['#attributes']['class'] = array();
  }

  $form['account']['pass']['pass1']['#attributes']['placeholder'] = t('6+ characters... make it tricky!');
  $form['account']['pass']['pass1']['#attributes']['class'] = array('js-validate');
  $form['account']['pass']['pass1']['#attributes']['data-validate'] = 'password';
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
