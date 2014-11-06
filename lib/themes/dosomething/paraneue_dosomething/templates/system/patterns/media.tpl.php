<?php
/**
 * @file
 * Generates the HTML for the Neue Media pattern.
 *
 * Available variables:
 * - $content: An array containing - 
 *    - title
 *    - description
 *    - impact
 *    - image
 *    - url
 *
 * @see paraneue_get_gallery_item()
 */
?>
<article class="media">
  <div class="wrapper">
    <?php if ($content['image']): ?>
      <?php print $content['image']; ?>
    <?php endif; ?>
  </div>

  <div class="__body">
    <?php if ($content['title']): ?>
      <h3 class="__title">
        <?php print $content['title']; ?>
      </h3>
    <?php endif; ?>
    <div class="__description">
      <?php if ($content['impact']): ?>
        <p><?php print t('My impact:'); ?>
        <p><?php print $content['impact']; ?></p>
      <?php endif; ?>        
      <?php if ($content['description']): ?>
        <?php print $content['description']; ?>
      <?php endif; ?>
    </div>
  </div>
</article>
