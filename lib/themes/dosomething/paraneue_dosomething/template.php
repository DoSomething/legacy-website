<?php

/**
 * Implements hook_js_alter().
 */
function paraneue_dosomething_preprocess_page(&$vars, $hook) {
  include('template_hooks/preprocess_page/html5shiv.php');

}

/**
 * Implements hook_form_alter();
 */
function paraneue_dosomething_form_alter(&$form, &$form_state, $form_id) {
  include('template_hooks/form_alter/login.php');
  include('template_hooks/form_alter/register.php');
}

/**
 * Custom '#after_build' functions on form elements.
 */
include('template_hooks/after_build/login.php');
include('template_hooks/after_build/register.php');

?>
