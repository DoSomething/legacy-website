<?php

/**
 * Configures defaults for all forms.
 *
 * Implements hook_form_alter().
 */
function paraneue_dosomething_form_alter_base(&$form, &$form_state, $form_id) {
  // Add `.button` to all form submit buttons.
  if(isset($form['actions']['submit'])) {
    $form['actions']['submit']['#attributes']['class'][] = 'button';
  }
}

/**
 * Implements theme_form_element().
 */
function paraneue_dosomething_form_element($variables) {
  $element = &$variables['element'];

  // Before we start to render the output,
  // hold any description in a new variable
  // so we can customize the output later.
  if (!empty($element['#description'])) {
    $description = $element['#description'];
    unset($element['#description']);
  }

  $output = theme_form_element($variables);


  // If rendering a radio button or checkbox, create rendered element for label
  if($element['#type'] === 'radio' || $element['#type'] === 'checkbox') {
    // If not set to 'attribute' display setting, add an option indicator
    if($element['#title_display'] !== 'attribute') {
      $variables['rendered_element'] = $element['#children'] . '<span class="option__indicator"></span>' . "\n";
    }
    else {
      $variables['rendered_element'] = $element['#children'] . "\n";
    }

    $output = theme('form_element_label', $variables);
  }

  // Custom HTML for field description.
  if(isset($description)) {
    $output .= ' <div class="footnote">' . $description ."</div> \n";
  }

  return $output;
}

/**
 * Implements theme_form_element_label().
 */
function paraneue_dosomething_form_element_label($variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();

  // Use `.option` class if returning the label for a checkbox.
  if ($element['#type'] === 'checkbox' && $element['#title_display'] !== 'attribute') {
    $attributes['class'] = 'option -checkbox';
  }
  elseif ($element['#type'] === 'radio' && $element['#title_display'] !== 'attribute') {
    $attributes['class'] = 'option -radio';
  }
  else {
    // If displaying with an attribute, use element's class
    if ($element['#title_display'] === 'attribute' && !empty($element['#custom_label_class'])) {
      $attributes['class'] = $element['#custom_label_class'];
    }
    // Style the label as class option to display inline with the element.
    elseif ($element['#title_display'] === 'after') {
      $attributes['class'] = 'element-label-after';
    }
    // Show label only to screen readers to avoid disruption in visual flows.
    elseif ($element['#title_display'] === 'invisible') {
      $attributes['class'] = 'element-invisible';
    }
    else {
      $attributes['class'] = 'field-label';
    }
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }


  // Return with rendered element if it exists
  if (!empty($variables['rendered_element'])) {
    return ' <label' . drupal_attributes($attributes) . '>' . $variables['rendered_element'] . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</label>\n";
  }
  else {
    // The leading whitespace helps visually separate fields from inline labels.
    return ' <label' . drupal_attributes($attributes) . '>' . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</label>\n";
  }
}

/**
 * Implements theme_textfield().
 */
function paraneue_dosomething_textfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'text';
  element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength'));
  _form_set_class($element, array('text-field'));

  $extra = '';

  $output = '<input ' . drupal_attributes($element['#attributes']) . ' />';

  return $output . $extra;
}

/**
 * Implements theme_password().
 */
function paraneue_dosomething_password($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'password';
  element_set_attributes($element, array('id', 'name', 'size', 'maxlength'));
  _form_set_class($element, array('text-field'));

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

/**
 * Implements theme_textarea().
 */
function paraneue_dosomething_textarea($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'cols', 'rows'));
  _form_set_class($element, array('text-field'));

  return '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
}

/**
 * Implements theme_select().
 */
function paraneue_dosomething_select($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'size'));

  return '<div class="select"><select' . drupal_attributes($element['#attributes']) . '>' . form_select_options($element) . '</select></div>';
}

/**
 * Implements theme_file().
 */
function paraneue_dosomething_file($variables) {
  $element = $variables['element'];
  $id = NULL;
  $label = $element['#children'];

  if (isset($element['#id'])) {
    $id = $element['#id'];
  }

  $element['#attributes']['type'] = 'file';
  $element['#attributes']['aria-label'] = 'file browser';
  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-file'));
  // Need to include the <input> within <label> to universalize style for file input.
  if ($element['#attributes']['is_supersized']) {
    $message = '<div class="message-callout -below"><div class="message-callout__copy"><p>' . $label . '</p></div></div>';
    return '<label class="gigantor" id="' . $id . '">' . $message . '<input' . drupal_attributes($element['#attributes']) . ' /></label>';
  }
}

/**
 * Sets customs alterations to the dosomething_payment form.
 */
function paraneue_dosomething_form_dosomething_payment_form_alter(&$form, &$form_state, $form_id) {
  // Customize field elements.
  $form['cvv']['#prefix'] = '<div class="donate__cvv">';
  $form['cvv']['#suffix'] = '</div>';
  $form['exp_month']['#prefix'] = '<div class="donate__expmonth">';
  $form['exp_month']['#suffix'] = '</div>';
  $form['exp_year']['#prefix'] = '<div class="donate__expyear">';
  $form['exp_year']['#suffix'] = '</div>';
  $form['amount']['#prefix'] = '<div class="donate__amount">';
  $form['amount']['#suffix'] = '</div>';
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Preprocesses the User Profile Form.
 */
function paraneue_dosomething_form_user_profile_form_alter(&$form, &$form_state, $form_id) {
  $is_resetting_password = $form['account']['current_pass']['#access'] === false;

  // Unless the user is resetting their password, send them to Northstar's profile form.
  if (! $is_resetting_password) {
    drupal_goto(NORTHSTAR_URL . '/users/' . dosomething_user_get_northstar_id($form['account']['uid']) . '/edit', ['absolute' => TRUE]);
  }

  // Remove all extra fields besides password.
  unset($form['field_birthdate']);
  unset($form['field_address']);
  unset($form['field_first_name']);
  unset($form['field_last_name']);
  unset($form['locale']);
  unset($form['timezone']);

  $form['#submit'][] = 'paraneue_dosomething_user_profile_submit_handler';
  $form['#after_build'][] = 'paraneue_dosomething_form_user_profile_after_build';
}

function paraneue_dosomething_form_user_profile_after_build($form, &$form_state) {
  // These fields are needed for form processing, but should not be visible/editable.
  $form['account']['name']['#access'] = FALSE;
  $form['account']['mail']['#access'] = FALSE;
  $form['field_mobile']['#access'] = FALSE;

  return $form;
}

/**
 * Preprocesses a given password_confirm form element.
 *
 * @see paraneue_dosomething_form_user_profile_form_alter.
 */
function paraneue_dosomething_process_password_confirm($element) {
  unset($element['#description']);
  $element['#prefix'] = '<h4>' . t('Change Password') . '</h4>';
  $element['pass1']['#title'] = t('New Password');
  $element['pass2']['#title'] = t('Confirm Password');
  return $element;
}
