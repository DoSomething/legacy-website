<?php 

function dosomething_notfound_admin_config_form($form, &$form_state){
	
	$form['image_example_image_fid'] = array(
		'#title' => t('Header photo'),
		'#type' => 'managed_file',
		'#default_value' => variable_get('image_example_image_fid', ''),
		);
	$form['notfound_copy_header'] = array(
		'#type' => 'textfield',
		'#title' => t('Header copy'),	
		);
	$form['notfound_copy_subheader'] = array(
		'#type' => 'textfield',
		'#title' => t('Sub-Header copy'),	
		);
	$form['notfound_status'] = array(
		'#type' => 'checkboxes',
		'#options' => drupal_map_assoc(array(t('Search'), t('Specific Content'))),
		'#title' => t('Disable relevant results'),
		);

	return system_settings_form($form);
}
