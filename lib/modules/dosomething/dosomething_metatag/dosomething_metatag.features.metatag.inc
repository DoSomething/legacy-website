<?php
/**
 * @file
 * dosomething_metatag.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function dosomething_metatag_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'config' => array(
      'title' => array(
        'value' => '[current-page:title] | [site:name]',
      ),
      'description' => array(
        'value' => '',
      ),
      'abstract' => array(
        'value' => '',
      ),
      'keywords' => array(
        'value' => '',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'standout' => array(
        'value' => '',
      ),
      'generator' => array(
        'value' => '',
      ),
      'copyright' => array(
        'value' => '',
      ),
      'image_src' => array(
        'value' => '',
      ),
      'canonical' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
      ),
      'publisher' => array(
        'value' => '',
      ),
      'author' => array(
        'value' => '',
      ),
      'original-source' => array(
        'value' => '',
      ),
      'revisit-after' => array(
        'value' => '',
        'period' => '',
      ),
    ),
  );

  // Exported Metatag config instance: node:campaign.
  $config['node:campaign'] = array(
    'instance' => 'node:campaign',
    'config' => array(
      'description' => array(
        'value' => '[node:field_call_to_action] Find all the tips you need here.',
      ),
      'abstract' => array(
        'value' => '[node:field_call_to_action] Find all the tips you need here.',
      ),
      'keywords' => array(
        'value' => '[node:field_tags]',
      ),
      'news_keywords' => array(
        'value' => '[node:field_tags]',
      ),
      'twitter:creator' => array(
        'value' => '@dosomething',
      ),
      'twitter:url' => array(
        'value' => '[node:url]',
      ),
      'twitter:description' => array(
        'value' => '[node:field_call_to_action]',
      ),
    ),
  );

  // Exported Metatag config instance: node:fact_page.
  $config['node:fact_page'] = array(
    'instance' => 'node:fact_page',
    'config' => array(
      'keywords' => array(
        'value' => '[node:title], [node:field_cause]',
      ),
    ),
  );

  // Exported Metatag config instance: user.
  $config['user'] = array(
    'instance' => 'user',
    'disabled' => TRUE,
    'config' => array(
      'title' => array(
        'value' => '[user:name] | [site:name]',
      ),
    ),
  );

  return $config;
}
