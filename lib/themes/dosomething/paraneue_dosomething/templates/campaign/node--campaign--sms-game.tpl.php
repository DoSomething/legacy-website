<?php
/**
 * Returns the HTML for the Campaign SMS Game page.
 *
 * Available Variables
 * - $fact_problem:
 * - $end_date: End date for the campaign (string).
 * - $scholarship: Scholarship amount (string).
 * - $classes: Additional classes passed for output (string).
 */
?>

<article id="node-<?php print $node->nid; ?>" class="campaign campaign--sms <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <header role="banner" class="-hero <?php print $classes; ?>">
    <div class="wrapper">
      <h1 class="__title"><?php print $title; ?></h1>
      <h2 class="__subtitle"><?php print $campaign->call_to_action; ?></h2>

      <?php if (isset($end_date)): ?><p class="__date"><?php print $end_date; ?></p><?php endif; ?>

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

  <div class="wrapper">

    <section id="know" class="container know">
      <h2 class="container__title banner"><span>Step 1: Know It</span></h2>

      <div class="wrapper">

        <div class="container__body">
          <div class="-columned">
            <?php if (isset($campaign->fact_problem)): ?>
            <h3 class="inline--alt-color">The Problem</h3>
            <p><?php print $campaign->fact_problem['fact']; ?><sup><?php print $campaign->fact_problem['footnotes']; ?></sup></p>
            <?php endif; ?>

            <?php if (isset($psa)): ?>
              <aside <?php if ($is_video_psa) echo 'class="video"'; ?>>
                <?php print $psa; ?>
              </aside>
            <?php else: ?>
              <?php if (isset($modals)): ?>
                <?php print $modals; ?>
              <?php endif; ?>
            <?php endif; ?>
          </div>

          <div class="-columned -col-last">
            <?php if (isset($campaign->fact_solution) || isset($campaign->solution_copy)): ?>
                <h3 class="inline--alt-color">The Solution</h3>

              <?php if (isset($campaign->fact_solution)): ?>
                <p><?php print $campaign->fact_solution['fact']; ?><sup><?php print $campaign->fact_solution['footnotes']; ?></sup></p>
              <?php elseif (isset($campaign->solution_copy)): ?>
                <?php print $campaign->solution_copy; ?>
              <?php endif; ?>

              <?php if (isset($campaign->solution_support)): ?>
                <?php print $campaign->solution_support; ?>
              <?php endif; ?>

            <?php endif; ?>

            <?php if (isset($psa)): ?>
              <?php if (isset($modals)): ?>
                <?php print $modals; ?>
              <?php endif; ?>
            <?php endif; ?>
          </div>
        </div>


        <?php if (isset($campaign->fact_sources)): ?>
        <section class="sources">
          <h3 class="__title js-toggle-sources">Sources</h3>
          <ul class="__body legal">
            <?php foreach ($campaign->fact_sources as $key => $source): ?>
              <li><sup><?php print ($key + 1); ?></sup> <?php print $source; ?></li>
            <?php endforeach; ?>
          </ul>
        </section>
        <?php endif; ?>
      </div>
    </section>


    <section id="do" class="container container--do inline--alt-bg">
      <h2 class="container__title banner"><span>Step 2: Do It</span></h2>

      <div class="wrapper">
        <div class="container__body">
          <?php if (isset($starter_header)) : ?>
            <h3 class="inline--alt-color"><?php print $starter_header; ?></h3>
          <?php endif; ?>
          <?php if (isset($starter)) : ?>
            <div><?php print $starter['safe_value']; ?></div>
          <?php endif; ?>

          <?php if (isset($signup_form)) : ?>
            <?php print render($signup_form); ?>
          <?php endif; ?>

          <?php if (isset($scholarship)): ?>
          <div class="message-callout -right">
            <div class="__copy">
              <p><?php print $scholarship; ?></p>
            </div>
          </div>
          <?php endif; ?>
        </div>

        <div class="disclaimer legal">
          <p>Taking part in this experience means you agree to our <a href="https://www.dosomething.org/about/terms-service">Terms of Service</a> &amp; to receive our weekly update. Message & data rates may apply. Text STOP to opt-out, HELP for help.</p>
        </div>
      </div>
    </section>


    <?php if (isset($zendesk_form) || isset($sponsors)): ?>
    <footer class="info-bar">
      <div class="wrapper">

        <?php if (isset($zendesk_form)): ?>
        <div class="help">
          Questions? <a href="#modal-contact-form" class="js-modal-link">Contact Us</a>
          <script id="modal-contact-form" class="modal--contact" type="text/cached-modal" data-modal-close="true" data-modal-close-class="white">
            <h2 class="banner">Contact Us</h2>
            <p>Enter your question below. Please be as specific as possible.</p>
            <?php print render($zendesk_form); ?>
          </script>
        </div>
        <?php endif; ?>

        <?php if (isset($sponsors)): ?>
          <div class="sponsor">
            In partnership with <?php print $formatted_partners; ?>
          </div>
        <?php endif; ?>
      </div>
    </footer>
    <?php endif; ?>

  </div>

</article>
