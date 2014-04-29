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
 *   - [path]: URL path for campaign node (string).
 */
?>

<article class="tile tile--campaign" id="campaign-<?php print $vars['nid']; ?>">
  <a class="wrapper" href="<?php print $vars['path']; ?>">
    <div class="tile--meta">
      <h1 class="__title"><?php print $vars['title']; ?></h1>
      <p class="__tagline"><?php print $vars['call_to_action']; ?></p>
    </div>
    <img alt="<?php print $vars['title']; ?>" src="<?php print $vars['image']; ?>" />
  </a>
</article>
