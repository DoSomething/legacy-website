<?php
/**
 * @file
 * dosomething_image.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_image_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_image_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function dosomething_image_image_default_styles() {
  $styles = array();

  // Exported image style: 100x100.
  $styles['100x100'] = array(
    'label' => '100x100',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 1440x810.
  $styles['1440x810'] = array(
    'label' => '1440x810',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1440,
          'height' => 810,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'coloractions_convert',
        'data' => array(
          'format' => 'image/jpeg',
          'quality' => 55,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 1920x1280.
  $styles['1920x1280'] = array(
    'label' => '1920x1280',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1920,
          'height' => 1280,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 300x300.
  $styles['300x300'] = array(
    'label' => '300x300',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 310x310.
  $styles['310x310'] = array(
    'label' => '310x310',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 310,
          'height' => 310,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 400x400.
  $styles['400x400'] = array(
    'label' => '400x400',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 400,
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'coloractions_convert',
        'data' => array(
          'format' => 'image/jpeg',
          'quality' => 65,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 480x480.
  $styles['480x480'] = array(
    'label' => '480x480',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 480,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 50x50.
  $styles['50x50'] = array(
    'label' => '50x50',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 550x300.
  $styles['550x300'] = array(
    'label' => '550x300',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 550,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 640x800.
  $styles['640x800'] = array(
    'label' => '640x800',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 800,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 720x310.
  $styles['720x310'] = array(
    'label' => '720x310',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 720,
          'height' => 310,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 720x720.
  $styles['720x720'] = array(
    'label' => '720x720',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 720,
          'height' => 720,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 740x480.
  $styles['740x480'] = array(
    'label' => '740x480',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 740,
          'height' => 480,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 768x768.
  $styles['768x768'] = array(
    'label' => '768x768',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 768,
          'height' => 768,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 800x300.
  $styles['800x300'] = array(
    'label' => '800x300',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: partner_homepage_image.
  $styles['partner_homepage_image'] = array(
    'label' => 'Partner Homepage Image',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => 80,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_desaturate',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: wmax-300-hmax-75.
  $styles['wmax-300-hmax-75'] = array(
    'label' => 'wmax-300-hmax-75',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => 75,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: wmax-423px.
  $styles['wmax-423px'] = array(
    'label' => 'wmax-423px',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 423,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function dosomething_image_node_info() {
  $items = array(
    'image' => array(
      'name' => t('Image'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
