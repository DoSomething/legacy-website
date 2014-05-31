<?php
/**
 * Returns the HTML for the Campaign Closed page.
 *
 * Available Variables
 * - $title: Title for the pitch page (string).
 * - $cta: Call To Action for the pitch page (string).
 * - $classes: Additional classes passed for output (string).
 * - $scholarship: Scholarship amount (string).
 */
?>

<section class="campaign--wrapper closed">

  <header role="banner" class="-hero <?php print $classes; ?>">
    <div class="wrapper">
      <h1 class="__title"><?php print $title; ?></h1>
      <h2 class="__subtitle"><?php print $cta; ?></h2>

      <?php if (isset($end_date)): ?><p class="__date"><?php print $end_date; ?></p><?php endif; ?>


      <?php if (isset($signup_button)): ?>
        <div class="__signup">
          <?php print render($signup_button); ?>

          <?php if (isset($scholarship)): ?>
          <div class="scholarship-callout -below -pitch">
            <p class="copy"><?php print $scholarship; ?></p>
          </div>
          <?php endif; ?>
        </div>
      <?php endif; ?>

      <?php if (isset($sponsors[0]['display'])): ?>
      <div class="sponsor">
        <p class="__copy">Powered by</p>
        <?php foreach ($sponsors as $key => $sponsor) :?>
          <?php if (isset($sponsor['display'])): print $sponsor['display']; endif; ?>
        <?php endforeach; ?>
      </div>
      <?php endif; ?>
    </div>
  </header>

  <div class="content-wrapper">
    <p><?php print $total_participants; ?> members participated</p>
  </div>

  <footer class="boilerplate">
    <span>A DoSomething.org Campaign. Join over 2.5 million young people taking action. Any cause, anytime, anywhere. *Mic drop</span>
  </footer>
</section>
