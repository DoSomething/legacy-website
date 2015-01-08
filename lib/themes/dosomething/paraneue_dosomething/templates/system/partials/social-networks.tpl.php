<?php
/**
 * @file
 * Displays a social networks menu.
 *
 * Available variables:
 * - $social: An array of social networks avaliable. Indexed by network's id.
 *   Each $network in $social contains:
 *   - $network['id']: Designated id of the network (string).
 *   - $network['name']: The name of the network, translated.
 *   - $network['url']: The URL to link to this network profile.
 *   - $network['alt']: The title text is displayed when the image
 *     is hovered, translated.
 *
 * @see _paraneue_dosomething_theme_settings_footer()
 * @see paraneue_dosomething_preprocess_page()
 * @see paraneue_dosomething_theme()
 *
 * @ingroup themeable
 */

?>
<ul>
  <?php foreach ($social as $id => $network): ?>
    <li>
      <?php print l('<span>' . $network['alt'] . '</span>', $network['url'], array(
        'external'   => TRUE,
        'html'       => TRUE,
        'attributes' => array(
          'class' => 'social-icon -' . $network['id'],
          'title' => $network['alt'],
        ),
      ));
      ?>
    </li>
  <?php endforeach ?>
</ul>

