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
    <li class="campaign -<?php print $item['class'] ?>">
      <?php print $item['campaign']; ?>
    </li>
  <?php endforeach; ?>
  </ul>
</section>
