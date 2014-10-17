<?php
/**
 * Returns the HTML for a Campaign Gallery.
 *
 * Available Variables
 * - $items: The Campaign gallery items to display.
 */
?>
<div>
  <ul>
  <?php foreach($items as $item): ?>
    <li><?php print $item; ?></li>
  <?php endforeach; ?>
  </ul>
</div>
