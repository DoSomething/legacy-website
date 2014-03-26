<section class="campaign--wrapper">
  <header class="header <?php print $classes; ?>">
    <div class="meta">
      <h1 class="title"><?php print $title; ?></h1>
      <p class="cta"><?php print $cta; ?></p>

      <?php if (isset($end_date)): ?><p class="date"><?php print $end_date; ?></p><?php endif; ?>

      <?php if (isset($signup_button)): ?><?php print render($signup_button); ?><?php endif; ?>

      <?php if (isset($scholarship)): ?>
      <div class="scholarship-wrapper">
        <p class="copy"><?php print $scholarship; ?></p>
      </div>
      <?php endif; ?>

      <?php if (isset($sponsors[0]['display'])): ?>
      <div class="sponsor-wrapper">
        <p class="copy">Powered by</p>
        <?php foreach ($sponsors as $key => $sponsor) :?>
          <?php if (isset($sponsor['display'])): print $sponsor['display']; endif; ?>
        <?php endforeach; ?>
      </div>
      <?php endif; ?>
    </div>
  </header>

  <footer class="boilerplate">
    <span>A DoSomething.org Campaign. Join over 2.5 million young people taking action. Any cause, anytime, anywhere. *Mic drop</span>
  </footer>
</section>
