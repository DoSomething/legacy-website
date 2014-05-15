<?php
/**
 * Returns the HTML for a Campaign SMS Game.
 *
 * Available Variables
 * - $fact_problem:
 * - $end_date: End date for the campaign (string).
 * - $scholarship: Scholarship amount (string).
 * - $classes: Additional classes passed for output (string).
 */
?>

<section class="campaign--wrapper action">
  <header role="banner" class="-hero <?php print $classes; ?>">
    <div class="wrapper">
      <h1 class="__title"><?php print $title; ?></h1>
      <h2 class="__subtitle"><?php print $cta; ?></h2>

      <?php if (isset($end_date)): ?><p class="__date"><?php print $end_date; ?></p><?php endif; ?>

      <?php if (isset($sponsors[0]['display'])): ?>
      <div class="sponsor">
        <p class="__copy">Powered by</p>
        <?php foreach ($sponsors as $key => $sponsor) :?>
          <?php if (isset($sponsor['display'])): print $sponsor['display']; endif; ?>
        <?php endforeach; ?>
      </div>
      <?php endif; ?>

      <?php if (isset($scholarship)): ?>
      <div class="scholarship-callout -action -above">
        <p class="copy"><?php print $scholarship; ?></p>
      </div>
      <?php endif; ?>
    </div>
  </header>

  <div class="content-wrapper">

    <h2 id="know" class="banner"><span>Step 1: Know It</span></h2>
    <section class="know step">

      <div class="col first">
        <h4 class="inline--alt-color">The Problem</h4>

        <?php if (isset($fact_problem)): ?>
        <div class="fact-problem"><?php print $fact_problem['fact']; ?><sup><?php print $fact_problem['footnotes']; ?></sup></div>
        <?php endif; ?>

        <?php if (isset($psa)): ?>
          <div class="psa-wrapper"><?php print $psa; ?></div>
        <?php endif; ?>

        <?php if (!isset($psa)): ?>
          <?php print $modals; ?>
        <?php endif; ?>
      </div>

      <div class="col second">
        <h4 class="inline--alt-color">The Solution</h4>

        <?php if (isset($fact_solution)): ?>
          <div class="fact-solution"><?php print $fact_solution['fact']; ?><sup><?php print $fact_solution['footnotes']; ?></sup></div>
        <?php elseif (isset($solution_copy)): ?>
          <div class="solution-copy"><?php print $solution_copy['safe_value']; ?></div>
        <?php endif; ?>

        <?php if (isset($solution_support)): ?>
        <div class="solution-supporting-copy"><?php print $solution_support; ?></div>
        <?php endif; ?>

        <?php if (isset($psa)): ?>
          <?php print $modals; ?>
        <?php endif; ?>
      </div>

      <?php if (isset($fact_sources)): ?>
      <div class="col sources-wrapper">
        <a href="#" class="js-toggle-sources secondary">Sources</a>
        <div class="sources">
          <div class="legal">
            <?php foreach ($fact_sources as $key => $source): ?>
              <div><sup><?php print ($key + 1); ?></sup> <?php print $source; ?></div>
            <?php endforeach; ?>
          </div>
        </div>
      </div>
      <?php endif; ?>
    </section>

    <h2 id="plan" class="banner"><span>Step 2: Share It</span></h2>
    <section>
      <div>
        <?php print render($signup_form); ?>
      </div>
    </section>

      <footer class="help <?php isset($sponsors) ? print 'sponsors' : '' ; ?>">
        <div class="footer-content">
          <div class="help-wrapper">Have a question? <a href="#modal-help" class="js-modal-link secondary">Contact us</a></div>

          <?php if (isset($sponsors)): ?>
          <div class="sponsor-wrapper">
            In partnership with
              <?php print $formatted_partners; ?>
          </div>
          <?php endif; ?>
        </div>
      </footer>

      <?php if (isset($zendesk_form)): ?>
      <script id="modal-help" type="text/cached-modal" data-modal-close="true" data-modal-close-class="white">
        <h2 class="banner">Contact Us</h2>
        <p>Enter your question below. Please be as specific as possible.</p>

        <?php print render($zendesk_form); ?>
      </script>
      <?php endif; ?>
    </section>
  </div>
</section>
