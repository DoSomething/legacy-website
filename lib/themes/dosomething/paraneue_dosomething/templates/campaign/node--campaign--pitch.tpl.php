<?php
/**
 * Returns the HTML for the Campaign Pitch page.
 *
 * Available Variables
 * - $campaign: A campaign object. @see dosomething_campaign_load()
 * - $classes: Additional classes passed for output (string).
 * - $scholarship: Scholarship amount (string).
 */
?>

<section class="campaign campaign--pitch pitch">

  <header role="banner" class="-hero <?php print $classes; ?>">
    <div class="wrapper">
      <?php print $campaign_headings; ?>

      <?php if (isset($signup_button)): ?>
        <div class="__signup">
          <?php print render($signup_button); ?>
          <?php print $campaign_scholarship; ?>
        </div>
      <?php endif; ?>

      <?php print $sponsor_logos; ?>
    </div>
  </header>

  <div class="wrapper">

    <div class="container container--tagline">
      <div class="wrapper">
        <p class="__tagline">
          <?php print t('A DoSomething.org Campaign. Join over 2.5 million young people taking action. Any cause, anytime, anywhere.'); ?>
          <em><?php print t('*Mic drop'); ?></em>
        </p>
      </div>
    </div>

  </div>

</section>
