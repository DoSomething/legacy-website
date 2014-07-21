<?php
/**
 * @file
 * Displays a social networks menu.
 *
 * Available variables:
 * - $social: An array of social networks avaliable. Indexed by network's id.
 *   Each $network in $social contains:
 *   - $network['id']: Designaed id of the network (string).
 *   - $network['name']: The name of the network, translated.
 *   - $network['url']: The URL to link to this network profile.
 *   - $network['alt']: The title text is displayed when the image
 *     is hovered, translated.
 *   - $network['glyph']: The character representing network's icon
 *     in DS glyph font
 * - $container_classes: Container classes, optional (string)
 *
 * @see _paraneue_dosomething_theme_settings_footer()
 * @see paraneue_dosomething_preprocess_page()
 * @see paraneue_dosomething_theme()
 *
 * @ingroup themeable
 */

?>
<div class="social <?php print empty($container_classes) ?: $container_classes; ?>">
  <ul>
    <?php foreach ($social as $id => $network): ?>
    <li><?php
      print l($network['glyph'], $network['url'], array(
        'external'   => TRUE,
        'html'       => TRUE,
        'attributes' => array(
          'class' => 'social-link',
          'alt'   => $network['alt'],
          'title' => $network['alt'],
        ),
      ));
    ?></li>
    <?php endforeach ?>
  </ul>
</div>
