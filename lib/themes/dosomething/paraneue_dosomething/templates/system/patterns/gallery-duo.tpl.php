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
  <?php if (!empty($items)): ?>
    <?php foreach ($items as $item): ?>
        <li class="<?php ($row_count == 0) ? print '-first' : print '-second' ?>">
          <?php print $item; ?>
        </li>
        <?php ($row_count == 0) ? $row_count++ : $row_count = 0 ?>
    <?php endforeach; ?>
  <?php endif; ?>
</ul>
