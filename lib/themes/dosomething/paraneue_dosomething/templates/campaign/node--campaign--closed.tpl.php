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
    <?php print $psa; ?>

    <h2 class="banner"><span>What You Did</span></h2>
    <section class="plan step">
      <div class="intro">

        <?php if (isset($total_participants)): ?>
        <div><?php print $total_participants; ?></div>
        <div>members participated</div>
        <?php endif; ?>

        <?php if (isset($total_quantity)): ?>
        <div><?php print $total_quantity; ?></div>
        <div><?php print $total_quantity_label; ?></div>
        <?php endif; ?>

        <?php if (isset($intro)): ?>
        <?php print $intro['safe_value']; ?>
        <?php endif; ?>

      </div>
    </section>

<?php print_r($klout_gallery); ?>
    <h2 class="banner"><span>Love From Celebs</span></h2>
    <section class="plan step">
      <div class="intro">

        <?php if (isset($additional_text_title)): ?>
        <h4><?php print $additional_text_title; ?></h4>
        <?php endif; ?>

        <?php if (isset($additional_text)): ?>
        <div><?php print $additional_text['safe_value']; ?></div>
        <?php endif; ?>

      </div>
    </section>

    <h2 class="banner"><span>Congratulations to...</span></h2>
    <section class="plan step">
      <div class="intro">

        <p>Winners go here.. HALP.</p>
        <?php print_r($winners); ?>

      </div>
    </section>

  </div>

  <footer class="boilerplate">
    <span>A DoSomething.org Campaign. Join over 2.5 million young people taking action. Any cause, anytime, anywhere. <em>*Mic drop</em></span>
  </footer>
</section>
