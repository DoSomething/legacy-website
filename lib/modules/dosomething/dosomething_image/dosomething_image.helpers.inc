<?php
/**
 * @file
 * Helper functions for dosomething_image functionality.
 */

/**
 * Create an image node from a JSON string.
 */
function dosomething_image_create_node_from_json($string) {
  $data = json_decode($string);
  $image = new stdClass();

  $node->type = 'image';
  $node->title = $data->title;
  $node->active = 1;

  if(isset($data->src->portrait)) {
    $node->field_image_portrait[LANGUAGE_NONE][0] = dosomething_image_create_image_field_from_path($data->src->portrait);
  }

  if(isset($data->src->landscape)) {
    $node->field_image_landscape[LANGUAGE_NONE][0] = dosomething_image_create_image_field_from_path($data->src->landscape);
  }

  if(isset($data->src->square)) {
    $node->field_image_square[LANGUAGE_NONE][0] = dosomething_image_create_image_field_from_path($data->src->square);
  }

  if(isset($data->is_dark_image)) {
    $node->field_dark_image[LANGUAGE_NONE][0]['value'] = 1;
  }

  node_save($node);

  return $node;
}

/**
 * Create an image field from a file path.
 */
function dosomething_image_create_image_field_from_path($path) {
  $file_src = file_get_contents($path);
  $filename = basename($path);
  $file = file_save_data($file_src, 'public://' . $filename, FILE_EXISTS_RENAME);
  $image_field = (array)$file;

  return $image_field;
}

