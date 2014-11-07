<?php
/**
 * @file
 * Generates the HTML for the Neue Gallery Triad pattern.
 *
 * Available variables:
 * - $items: An array of themed items or tiles to put in the gallery.
 *
 * @see paraneue_get_gallery()
 */
?>
<ul class="gallery -triad">
  <?php if (!empty($items)): ?>
    <?php foreach ($items as $delta => $item): ?>
      <?php // @todo: This is kinda nasty. Preprocess it? ?>
      <li class="<?php print paraneue_dosomething_get_gallery_item_order_class($delta); ?>">
        <?php print $item; ?>
      </li>
    <?php endforeach; ?>
  <?php endif; ?>
</ul>
