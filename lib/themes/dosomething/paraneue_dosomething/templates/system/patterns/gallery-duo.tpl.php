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
<?php $row_count = 0; ?>

<ul class="gallery -duo">
  <?php foreach ($items as $item): ?>
    <?php if ($row_count == 0): ?>
      <li class="-first">
        <?php print $item; ?>
      </li>
      <?php $row_count++; ?>
    <?php elseif ($row_count == 1): ?>
      <li class="-second">
        <?php print $item; ?>
      </li>      
      <?php $row_count = 0; ?>
    <?php endif; ?>
  <?php endforeach; ?>
</ul>
