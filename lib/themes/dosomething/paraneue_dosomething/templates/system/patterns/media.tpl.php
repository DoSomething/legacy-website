<?php
/**
 * @file
 * Generates the HTML for the Neue Media pattern.
 *
 * Available variables:
 * - $content: An associative array that can contain:
 *    - $title: Title of the item.
 *    - $description: Description or subtitle.
 *    - $impact: Impact number.
 *    - $image: Thumbnail image.
 *    - $link: Link to the item.
 *
 * @see paraneue_dosomething_get_gallery_item()
 */
?>
<article class="media <?php print $classes; ?>">
  <div class="media__image">
    <?php if (!empty($content['image'])): ?>
      <?php print $content['image']; ?>
    <?php endif; ?>
  </div>

  <div class="media__body">
    <?php if (!empty($content['title'])): ?>
      <h3 class="media__title">
        <?php if (!empty($content['link'])): ?>
          <a href="<?php print $content['link']; ?>">
            <?php print $content['title']; ?>
          </a>
        <?php else: ?>
          <?php print $content['title']; ?>
        <?php endif; ?>
      </h3>
    <?php endif; ?>
    <div class="media__description">
      <?php if (!empty($content['impact'])): ?>
        <p><?php print t('My impact:'); ?>
        <p><?php print $content['impact']; ?></p>
      <?php endif; ?>
      <?php if (!empty($content['description'])): ?>
        <?php print $content['description']; ?>
      <?php endif; ?>
    </div>
  </div>
</article>
