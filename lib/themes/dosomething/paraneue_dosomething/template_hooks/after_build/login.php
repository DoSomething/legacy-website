<?php

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
  $form['name']['#title'] = 'Email address or cell number';
  $form['name']['#attributes']['placeholder'] = 'Email address or cell number';
  $form['pass']['#attributes']['placeholder'] = 'Password';

  unset($form['name']['#description']);
  unset($form['pass']['#description']);

  return $form; 
}

?>
