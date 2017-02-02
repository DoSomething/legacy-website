
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
 * @param array $ids
 *   (optional) Array of each signup form id, if multiple forms are rendered.
 */
function dosomething_signup_preprocess_signup_button(&$vars, $label = "Sign Up", $presignup = FALSE, $ids = array()) {
  // In case we were passed a NULL value for $label:
  if ($label == NULL) {
    $label = "Sign Up";
  }

  $label = t($label);
  $var_name = 'signup_button';
  $form_id = 'dosomething_signup_form';

  // If this is a presignup form:
  if ($presignup) {
    $form_id = 'dosomething_signup_presignup_form';
  }

  // If we have an array of signup forms to render:
  if (!empty($ids)) {
    // Loop through each id:
    foreach ($ids as $id) {
      // Append the $id to the end of the variable and form_id.
      $multi_var_name = $var_name . '_' . $id;
      $multi_form_id = $form_id . '_' . $id;
      // Add signup_button_$id as a variable to $vars.
      $vars[$multi_var_name] = dosomething_signup_get_signup_button($label, $vars['nid'], $multi_form_id);
    }
  }
  // else if no multiples:
  else {
    // Just add the 'signup_button' variable to $vars.
    $vars[$var_name] = dosomething_signup_get_signup_button($label, $vars['nid'], $form_id);
  }
}

/**
 * Returns signup button array to be rendered within a template file.
 */
function dosomething_signup_get_signup_button($label, $nid, $form_id) {
  // If user is logged in:
  if (user_is_logged_in()) {
    // Return signup form array to be rendered.
    return drupal_get_form($form_id, $nid, $label);
  }

  // Otherwise, for anonymous user, return a #markup array to be rendered.
  $node = node_load($nid);

  return drupal_get_form('dosomething_signup_unauthenticated_form', $nid, $label);
}
