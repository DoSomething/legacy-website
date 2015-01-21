<?php
/**
 * Returns the HTML for the Campaign SMS Game page.
 *
 * Available Variables
 * - $campaign: A campaign object. @see dosomething_campaign_load()
 * - $scholarship: Scholarship amount (string).
 * - $classes: Additional classes passed for output (string).
 */
?>

<article id="node-<?php print $node->nid; ?>" class="campaign campaign--sms <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <header role="banner" class="-hero <?php print $classes; ?>">
    <div class="wrapper">
      <?php print $campaign_headings; ?>

      <?php print $promotions; ?>
    </div>
  </header>

  <div class="wrapper">

    <section id="know" class="container">
      <h2 class="heading -banner"><span><?php print t('Step 1: Know It'); ?></span></h2>
      <div class="wrapper">

        <div class="container__body -half">
          <?php if (isset($campaign->fact_problem)): ?>
          <h3 class="inline--alt-color"><?php print t('The Problem'); ?></h3>
          <p><?php print $campaign->fact_problem['fact']; ?><sup><?php print $campaign->fact_problem['footnotes']; ?></sup></p>
          <?php endif; ?>

          <?php if (isset($psa)): ?>
            <aside <?php if ($is_video_psa) echo 'class="media-video"'; ?>>
              <?php print $psa; ?>
            </aside>
          <?php else: ?>
            <?php if (isset($modals)): ?>
              <?php print $modals; ?>
            <?php endif; ?>
          <?php endif; ?>
        </div>

        <div class="container__body -half">
          <?php if (isset($campaign->fact_solution) || isset($campaign->solution_copy)): ?>
              <h3 class="inline--alt-color"><?php print t('The Solution'); ?></h3>

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

        <div class="container__body -narrow">
          <?php if (isset($campaign->fact_sources)): ?>
          <section class="sources">
            <h3 class="__title js-toggle-sources"><?php print t('Sources'); ?></h3>
            <ul class="__body legal">
              <?php foreach ($campaign->fact_sources as $key => $source): ?>
                <li><sup><?php print ($key + 1); ?></sup> <?php print $source; ?></li>
              <?php endforeach; ?>
            </ul>
          </section>
          <?php endif; ?>
        </div>
      </div>
    </section>


    <section id="do" class="container container--do inline--alt-bg">
      <h2 class="heading -banner"><span><?php print t('Step 2: Do It'); ?></span></h2>
      <div class="wrapper">

        <div class="container__body -narrow">
          <?php if (isset($starter_header)) : ?>
            <h3 class="inline--alt-color"><?php print $starter_header; ?></h3>
          <?php endif; ?>
          <?php if (isset($starter)) : ?>
            <div><?php print $starter['safe_value']; ?></div>
          <?php endif; ?>
        </div>

        <?php if (isset($signup_form)) : ?>
          <?php print render($signup_form); ?>
        <?php endif; ?>

        <?php print $campaign_scholarship; ?>

        <div class="container__body -narrow">
          <p class="legal">
            <?php
            print t("Taking part in this experience means you agree to our !terms_link &amp; to receive our weekly update. Message &amp; data rates may apply. Text STOP to opt-out, HELP for help.",
              array("!terms_link" => l(t('Terms of Service'), 'about/terms-service'))); ?>
          </p>
        </div>

      </div>

      <?php if ($info_bar): ?>
        <?php print $info_bar; ?>
      <?php endif; ?>

    </section>


  </div>

</article>
