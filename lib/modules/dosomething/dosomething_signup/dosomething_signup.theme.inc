
<?php
/**
 * @file
 * Preprocess functions for the dosomething_signup module.
 */

/**
 * Preprocesses variables for a signup button.
 *
 * Adds a $signup_button variable into $vars, which is set to either a signup form, 
 * or a link to open the login/registration modal.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.  Must contain $vars['nid'].
 * @param string $label
 *   The label to display fon the button.
 * @param string $presignup
 *   Optional - If TRUE, get the presignup form, else regular signup form.
 */
function dosomething_signup_preprocess_signup_button(&$vars, $label = "Sign Up", $presignup = FALSE) {
  $label = t($label);
  // If user is logged in:
  if (user_is_logged_in()) {
    $form_id = 'dosomething_signup_form';
    if ($presignup) {
      $form_id = 'dosomething_signup_presignup_form';
    }
    // Render button as sign up form.
    $vars['signup_button'] = drupal_get_form($form_id, $vars['nid'], $label);
  }
  // Otherwise, for anonymous user:
  else {
    // Render button as link to open up the login modal.
    $vars['signup_button'] = array(
      '#markup' => dosomething_user_get_login_modal_link_markup($label),
    );
  }
}
