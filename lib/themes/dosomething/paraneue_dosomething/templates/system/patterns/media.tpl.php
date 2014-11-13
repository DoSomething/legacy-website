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
 * @see paraneue_get_gallery_item()
 */
?>
<article class="media">
  <div class="wrapper">
    <?php if (!empty($content['image'])): ?>
      <?php print $content['image']; ?>
    <?php elseif ($use_default): ?>
      <img src='/profiles/dosomething/themes/dosomething/paraneue_dosomething/bower_components/neue/dist/assets/images/apple-touch-icon-precomposed.png' />
    <?php endif; ?>
  </div>

  <div class="__body">
    <?php if (!empty($content['title'])): ?>
      <h3 class="__title">
        <?php if (!empty($content['link'])): ?>
          <a href="<?php print $content['link']; ?>">
            <?php print $content['title']; ?>
          </a>
        <?php endif; ?>
      </h3>
    <?php endif; ?>
    <div class="__description">
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
