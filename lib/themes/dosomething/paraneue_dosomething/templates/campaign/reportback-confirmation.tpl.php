<?php
/**
 * Returns the HTML for the Campaign Reportback Confirmation.
 *
 * Available Variables
 * - $copy: Positive note message copy (string).
 * - $more_campaigns_link: Link to find more campaigns (string).
 * - $back_to_campaign_link: Link to head back to originating campagin (string).
 * - $recommended: Array containing recommended campaigns for user.
 *   - [nid]: Node ID for campaign (integer).
 *   - [title]: Title of campaign (string).
 *   - [call_to_action]: Call to action text for campaign. (string).
 *   - [image]: URL path for campaign image (string).
 *   - [path]: URL path for campaign node (string).
 *   - [pretty_path]: Pretty URL path for campaign node (string).
 *   - [staff_pick]: Indicate if this campaign a staff pick (boolean).
 * - $classes: Additional classes passed for output (string).
 */
?>

<section class="confirmation-wrapper">

  <header role="banner" class="-basic">
    <div class="wrapper">
      <h1 class="__title">You Did It!</h1>
      <?php if (isset($copy)): ?>
        <h2 class="__subtitle"><?php print $copy; ?></h2>
      <?php endif; ?>
    </div>
  </header>

  <?php if (isset($recommended)): ?>
    <div class="gallery-wrapper">
      <h2 class="gallery-title">Keep it up! Find your next campaign.</h2>
      <div class="gallery">
        <?php foreach ($recommended as $rec): ?>
          <div class="gallery-item">
            <?php if (isset($rec['image'])): ?>
              <a href="/<?php print $rec['pretty_path']; ?>"><img src="<?php print $rec['image']; ?>"/></a>
            <?php endif; ?>

            <?php if (isset($rec['title'])): ?>
              <h3 class="title"><?php print l($rec['title'], $rec['path']); ?></h3>
            <?php endif; ?>

            <?php if (isset($rec['call_to_action'])): ?>
              <div class="gallery-description"><?php print $rec['call_to_action']; ?></div>
            <?php endif; ?>
          </div>
        <?php endforeach; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($more_campaigns_link)): ?>
    <div class="cta">
      <div class="wrapper">
        <?php //@TODO: Address styles for this slightly different CTA content. ?>
        <div class="cta-more-campaigns"><?php print $more_campaigns_link; ?></div>
        <div class="cta-back-to-campaign"><?php if (isset($back_to_campaign_link)): ?><?php print $back_to_campaign_link; ?><?php endif; ?></div>
      </div>
    </div>
  <?php endif; ?>
</section>
