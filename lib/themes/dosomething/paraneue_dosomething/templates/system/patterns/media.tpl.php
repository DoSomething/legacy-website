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
    <?php print $content['image']; ?>
  </div>

  <div class="__body">
    <h3 class="__title"><?php print $content['title']; ?></h3>
    <div class="__description">
      <?php print $content['description']; ?>
    </div>
  </div>
</article>
