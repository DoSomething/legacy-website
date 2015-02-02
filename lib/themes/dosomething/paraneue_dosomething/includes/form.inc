<?php

/**
 * Configures defaults for all forms.
 *
 * Implements hook_form_alter().
 */
function paraneue_dosomething_form_alter_base(&$form, &$form_state, $form_id) {
  // Add `.button` to all form submit buttons.
  $form['actions']['submit']['#attributes']['class'][] = 'button';
  // Check if this form needs Shirt Styles applied.
  paraneue_dosomething_form_alter_shirt_options($form, $form_state, $form_id);
}

/**
 * Implements theme_form_element().
 */
function paraneue_dosomething_form_element($variables) {
  $element = &$variables['element'];
  $output = theme_form_element($variables);

  // If rendering a checkbox, create rendered element for label
  if($element['#type'] == 'radio') {
    $variables['rendered_element'] = ' ' . $prefix . $element['#children'] . '<span class="option__indicator"></span>' . $suffix . "\n";
    $output = theme('form_element_label', $variables);
  }

  // If rendering a checkbox, create rendered element for label
  if($element['#type'] == 'checkbox') {
    $variables['rendered_element'] = ' ' . $prefix . $element['#children'] . '<span class="option__indicator"></span>' . $suffix . "\n";
    $output = theme('form_element_label', $variables);
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
  if ($element['#type'] == 'checkbox') {
    $attributes['class'] = 'option -checkbox';
  }
  elseif ($element['#type'] == 'radio') {
    $attributes['class'] = 'option -radio';
  }
  else {
    // Style the label as class option to display inline with the element.
    if ($element['#title_display'] == 'after') {
      $attributes['class'] = 'element-label-after';
    }
    // Show label only to screen readers to avoid disruption in visual flows.
    elseif ($element['#title_display'] == 'invisible') {
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
  // @TODO_RBv2: temporary variable to add feature flag logix. Remove once Reportback v2 launched to Prod.
  $show_new_reportback = theme_get_setting('show_new_reportback');

  if ($show_new_reportback) {
    $element = $variables['element'];
    $id = NULL;

    if (isset($element['#id'])) {
      $id = $element['#id'];
    }

    $element['#attributes']['type'] = 'file';
    $element['#attributes']['aria-label'] = 'file browser';
    element_set_attributes($element, array('id', 'name', 'size'));
    _form_set_class($element, array('form-file'));

    // Need to include the <input> within <label> to universalize style for file input.
    if ($element['#attributes']['is_supersized']) {
      return '<label class="gigantor" id="' . $id . '"><span>' . t('Upload a pic') . '</span><input' . drupal_attributes($element['#attributes']) . ' /></label>';
    }
    else {
      return '<label class="button button--file -tertiary" id="' . $id . '"><span>' . t('Add another photo') . '</span><input' . drupal_attributes($element['#attributes']) . ' /></label>';
    }
  }
  else {
    return theme_file($variables);
  }
}

/**
 * Checks if given $form needs Shirt Styles applied based on its $form_id.
 */
function paraneue_dosomething_form_alter_shirt_options(&$form, &$form_state, $form_id) {
  // Form IDs which need Shirt styles.
  $form_ids = array(
    'dosomething_reward_redeem_form',
    'dosomething_signup_user_signup_data_form'
  );
  // If this form is not one of the Shirt Style forms.
  if (!in_array($form_id, $form_ids)) {
    // Exit out.
    return;
  }
  // If this is the User Signup Data Form:
  if ($form_id == 'dosomething_signup_user_signup_data_form') {
    // If we aren't collecting shipment info:
    // @see dosomething_signup_user_signup_data_form().
    if (!isset($form['shipment_item'])) {
      // Don't need to preprocess anything.
      return;
    }
    // If we aren't collecting a shirt, we don't need to preprocess anything.
    if ($form['shipment_item']['#value'] != 'shirt') {
      // Exit out.
      return;
    }
    // If the form has been submitted already:
    if (isset($form['submitted_copy'])) {
      // We don't need to preprocess anything, exit.
      return;
    }
  }
  $form['item_header']['#markup'] = '<h4>' . t('Your Shirt') . '</h4>';
  // Attributes to be applied to the Shirt Size options.
  $shirt_size_attributes = array(
    'data-validate' => 'shirt_size',
    'data-validate-required' => '',
  );
  foreach ($form['item']['#options'] as $key => $option) {
    $form['item'][$key]['#prefix'] = '<div class="media-options__item -radio">';
    $form['item'][$key]['#suffix'] = '</div>';
  }
  $shirt_style_prefix = '<div data-validate="shirt_style" data-validate-required class="js-media-options">';
  $shirt_style_suffix = '</div>';
  $form['item']['#prefix'] = $shirt_style_prefix;
  $form['item']['#suffix'] = $shirt_style_suffix;
  $form['item']['#title'] = '<div class="label">' . t("Your Shirt Style") . '</div>';
  $form['item_option']['#attributes'] = $shirt_size_attributes;
  if (isset($form['item_additional'])) {
    foreach ($form['item_additional']['#options'] as $key => $option) {
      $form['item_additional'][$key]['#prefix'] = '<div class="media-options__item -radio">';
      $form['item_additional'][$key]['#suffix'] = '</div>';
    }
    $form['item_additional_header']['#markup'] = '<h4>' . t("Your Friend's Shirt") . '</h4>';
    $form['item_additional']['#prefix'] = $shirt_style_prefix;
    $form['item_additional']['#suffix'] = $shirt_style_suffix;
    $form['item_additional']['#title'] = '<div class="label">' . t("Your Friend's Shirt Style") . '</div>';
    $form['item_additional_option']['#attributes'] = $shirt_size_attributes;
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
