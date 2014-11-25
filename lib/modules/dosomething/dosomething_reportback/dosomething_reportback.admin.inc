<?php
/**
 * @file
 * Code for dosomething_reportback admin functionality.
 */

/**
 * Form constructor for Reportback admin config form.
 *
 * @see dosomething_reportback_menu()
 */
function dosomething_reportback_admin_config_form($form, &$form_state) {
  $form['dosomething_reportback_is_crop_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Reportback Cropping.'),
    '#default_value' => variable_get('dosomething_reportback_is_crop_enabled', FALSE),
    '#description' => t("Allows users to crop their own Reportback images."),
  );
  return system_settings_form($form);
}

/**
 * Page callback for Admin Gallery table.
 */
function dosomething_reportback_admin_gallery_page() {
  $header = array(
    t('Submitted'),
    NULL,
    t('Quantity'),
    t('Email'),
    t('Campaign'),
  );

  $result = dosomething_reportback_get_gallery_results();
  $rows = array();

  foreach ($result as $record) {
    $img = dosomething_image_get_themed_image_by_fid($record->fid, '300x300');
    $info = $img . '<p><strong>' . $record->caption . '</strong></p>';
    $info .= '<hr />' . $record->why_participated;
    $date = format_date($record->updated, 'short');

    $rows[] = array(
      l($date, 'reportback/' . $record->rbid),
      $info,
      $record->quantity,
      l($record->mail, 'user/'. $record->uid),
      l($record->title, 'node/'. $record->nid),
    );

  }

  return theme('table', array(
    'header' => $header,
    'rows' => $rows,
  ));
}

function dosomething_reportback_admin_gallery_row_form() {

}
