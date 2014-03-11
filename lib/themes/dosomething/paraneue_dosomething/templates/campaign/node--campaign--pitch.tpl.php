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

      <?php if (isset($sponsors)): ?>
      <div class="sponsor-wrapper">
        <p class="copy">Powered by:</p>
        <?php foreach ($sponsors as $key => $sponsor) :?>
          <?php if (isset($sponsor['img'])): print $sponsor['img']; endif; ?>
        <?php endforeach; ?>
      </div>
      <?php endif; ?>
    </div>
  </header>

  <footer class="boilerplate">
    <strong>A DoSomething.org Campaign</strong>
    <span>Join over 2.4 million young people taking action. Any Cause. Anytime. Anywhere.</span>
  </footer>
</section>
