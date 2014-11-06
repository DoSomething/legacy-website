<?php
/**
 * @file
 * Generates the HTML for the Neue Gallery Duo pattern.
 *
 * Available variables:
 * - $items: An array of themed items or tiles to put in the gallery.
 *
 * @see paraneue_get_gallery()
 */
?>
<ul class="gallery -duo">
  <?php if (!empty($items)): ?>
    <?php foreach ($items as $delta => $item): ?>
        <li class="<?php ($delta % 2) ? print '-second' : print '-first' ?>">
          <?php print $item; ?>
        </li>
        <?php ($delta % 2) ? $row_count = 0 : $row_count++ ?>
    <?php endforeach; ?>
  <?php endif; ?>
</ul>
