<?php
/**
 * Snippet for displaying a Campaign's creator property, which is an array.
 *
 * For available variables:
 * @see dosomething_campaign_load().
 */
?>

<a href="#" data-modal-href="#modal-creator">
  Created by: <img src="<?php print $picture['src']; ?>" />
</a>

<div data-modal id="modal-creator" role="dialog">
  <a href="#" class="js-close-modal modal-close-button white">×</a>
  <h2 class="banner">The Creator</h2>
  <img src="<?php print $picture['src']; ?>" />
  <h4><?php print $first_name; ?> <?php print $last_initial; ?></h4>
  <p><?php print $city; ?>, <?php print $state; ?></p>
  <div class="copy"><?php print $copy; ?></div>
  <a href="#" class="js-close-modal">Back to main page</a>
</div>
