<?php
/**
 * Returns the HTML for a Campaign Gallery.
 *
 * Available Variables
 * - $items: The Campaign gallery items to display.
 */
?>
<section class="container container--campaigns">
  <ul class="gallery -mosaic -featured">
  <?php foreach($items as $item): ?>
    <li class="campaign -published"><?php print $item; ?></li>
  <?php endforeach; ?>
  </li>
</div>
