<?php
/**
 * @file
 * Generates the HTML for the Neue Tile pattern.
 *
 * Available variables:
 * - $classes: Classes to apply to the <article> (string).
 * - $content: An associative array that can contain:
 *    - $title: Title of the item.
 *    - $status: If the content is published, TRUE. (boolean).
 *    - $is_staff_pick: If Staff Pick block should display (boolean).
 *    - $tagline: (string).
 *    - $image: Rendered image (string).
 *    - $link: Link to the item.
 *
 * @see paraneue_get_gallery_item()
 */
?>

<article class="tile <?php print $classes; ?>">
  <?php if ($status): ?>
  <a class="wrapper" href="/<?php print $link; ?>">
  <?php else: ?>
  <div class="wrapper">
  <?php endif; ?>
    <?php if ($is_staff_pick): ?>
      <div class="__flag -staff-pick"><?php print t('Staff Pick'); ?></div>
    <?php endif; ?>

    <div class="tile--meta">
      <h1 class="__title"><?php print $title; ?></h1>
      <p class="__tagline"><?php print $call_to_action; ?></p>
    </div>
    <img alt="<?php print $title; ?>" src="<?php print $image; ?>" />
  <?php if ($status): ?>
  </a>
  <?php else: ?>
  </div>
  <?php endif;?>
</article>
