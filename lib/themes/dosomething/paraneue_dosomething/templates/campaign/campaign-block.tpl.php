<?php
/**
 * Returns the HTML for a single Campaign Block.
 *
 * Available Variables
 * - $vars: An array of campaign variables.
 *   - [nid]: Node ID for campaign (integer).
 *   - [title]: Title of campaign (string).
 *   - [call_to_action]: Call to action text for campaign. (string).
 *   - [image]: URL path for campaign image (string).
 *   - [src]: URL path for campaign node (string).
 */
?>

<article class="campaign -teaser" id="campaign-<?php print $vars['nid']; ?>">
  <h1><?php print l($vars['title'], $vars['src']); ?></h1>
  <p><?php print $vars['call_to_action']; ?></p>
  <img alt="<?php print $vars['title']; ?>" src="<?php print $vars['image']; ?>" />
</article>
