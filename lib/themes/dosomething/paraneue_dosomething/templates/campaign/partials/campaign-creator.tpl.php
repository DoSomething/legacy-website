<?php
/**
 * Snippet for displaying a Campaign's creator property, which is an array.
 *
 * For available variables:
 * @see dosomething_campaign_load().
 */
?>

<div class="promotion promotion--creator">
  <a class="wrapper" href="#" data-modal-href="#modal--creator">
    <p class="__copy"><?php print t('Created by'); ?></p>
    <div class="__image">
      <img src="<?php print $picture['src_square']; ?>" />
    </div>
  </a>

  <div data-modal id="modal--creator" class="modal--creator" role="dialog">
    <a href="#" class="js-close-modal modal-close-button">×</a>
    <h2 class="heading -banner">The Creator</h2>
    <div class="wrapper">
      <div class="__member">
        <img src="<?php print $picture['src_square']; ?>" />
      </div>
      <div class="__body">
        <h4 class="__title heading -delta"><?php print $first_name; ?> <?php print $last_initial; ?></h4>
        <p class="__location"><?php print $city; ?>, <?php print $state; ?></p>
        <div class="copy"><?php print $copy; ?></div>
        <div class="form-actions">
          <a href="#" class="js-close-modal">Back to main page</a>
        </div>
      </div>
    </div>
  </div>
</div>
