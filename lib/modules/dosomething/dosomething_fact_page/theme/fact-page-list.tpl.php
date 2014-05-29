<?php
/**
 * Returns the HTML for Fact Page list.
 *
 * Available Variables
 * - $links: Array of links, keyed by the cause name.
 */
?>
<div>
<?php foreach ($links as $cause => $fact_pages): ?>
  <h2><?php print $cause; ?></h2>
  <ul>
    <?php foreach ($fact_pages as $link): ?>
    <li><?php print $link; ?></li>
    <?php endforeach ; ?>
  </ul>
<?php endforeach; ?>
</div>
