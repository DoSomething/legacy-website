
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
 *   (optional) If TRUE, get the presignup form, else regular signup form.
 * @param string $id
 *   (optional) The identifier of the signup form, if multiple forms are rendered.
 */
function dosomething_signup_preprocess_signup_button(&$vars, $label = "Sign Up", $presignup = FALSE, $id = NULL) {
  // In case we were passed a NULL value for $label:
  if ($label == NULL) {
    $label = "Sign Up";
  }
  $label = t($label);
  $var_name = 'signup_button';
  $form_id = 'dosomething_signup_form';
  if ($id) {
    $var_name .= '_' . $id;
    $form_id .= '_' . $id;
  }
  // If this is a presignup form:
  if ($presignup) {
    $form_id = 'dosomething_signup_presignup_form';
  }
  // If user is logged in:
  if (user_is_logged_in()) {
    // Render button as sign up form.
    $vars[$var_name] = drupal_get_form($form_id, $vars['nid'], $label);
  }
  // Otherwise, for anonymous user:
  else {
    // Render button as link to open up the login modal.
    $vars[$var_name] = array(
      '#markup' => dosomething_user_get_login_modal_link_markup($label),
    );
  }
}
