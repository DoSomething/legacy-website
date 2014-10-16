<?php
/**
 * Returns the HTML for a Campaign Gallery.
 *
 * Available Variables
 * - $items: The Campaign gallery items to display.
 */
?>
<div>
  <li>
  <?php foreach($items as $item): ?>
    <ul><?php print $item; ?></ul>
  <?php endforeach; ?>
  </li>
</div>
