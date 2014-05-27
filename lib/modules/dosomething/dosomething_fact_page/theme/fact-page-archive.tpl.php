<?php
/**
 * Returns the HTML for the Fact Page archive.
 *
 * Available Variables
 * - $links: Array of Fact Page titles, linked to corresponding node. (array)
 */
?>
<ul>
<?php foreach ($links as $link): ?>
  <li><?php print $link; ?></li>
<?php endforeach; ?>
</ul>
