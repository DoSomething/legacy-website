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
 * @see paraneue_dosomething_get_gallery_item()
 */
?>

<article class="tile <?php print $classes; ?>">

  <?php if ($content['status']): ?>
  <a class="wrapper" href="/<?php print $content['link']; ?>">
  <?php else: ?>
  <div class="wrapper">
  <?php endif; ?>

    <?php if ($content['is_staff_pick']): ?>
      <div class="tile__flag -staff-pick"><?php print t('Staff Pick'); ?></div>
    <?php endif; ?>

    <div class="tile__meta">
      <h1 class="tile__title"><?php print $content['title']; ?></h1>
      <p class="tile__tagline"><?php print $content['tagline']; ?></p>
    </div>

    <?php
      if (isset($content['video'])) {
        print $content['video'];
      }
      elseif (isset($content['image'])) {
        print $content['image'];
      }
    ?>

  <?php if ($content['status']): ?>
  </a>
  <?php else: ?>
  </div>
  <?php endif;?>

</article>
