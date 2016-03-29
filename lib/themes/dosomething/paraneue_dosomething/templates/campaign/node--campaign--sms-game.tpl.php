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

  <header role="banner" class="header -hero <?php print $classes; ?>">
    <div class="wrapper">
      <?php print $campaign_headings; ?>

      <?php print $promotions; ?>
    </div>
  </header>

  <div class="wrapper">

    <section id="know" class="container">
      <h2 class="heading -banner"><span><?php print t('Step 1: Know It'); ?></span></h2>
      <div class="wrapper">

        <div class="container__block -half">
          <?php if (isset($campaign->fact_problem)): ?>
            <h3 class="inline-sponsor-color"><?php print t('The Problem'); ?></h3>
            <p><?php print $campaign->fact_problem['fact']; ?><sup><?php print $campaign->fact_problem['footnotes']; ?></sup></p>

            <?php if ($show_problem_shares): ?>
              <div class="message-callout -above-horizontal -blue">
                <div class="message-callout__copy">
                  <p><?php print $problem_share_prompt; ?></p>
                </div>
              </div>
              <?php print $share_bar; ?>
            <?php endif; ?>
          <?php endif; ?>

          <?php if ($show_problem_shares): ?>
            <?php // If there's a PSA image or video, output it in this column. ?>
            <?php if (isset($psa)): ?>
              <p <?php if ($is_video_psa) echo 'class="media-video"'; ?>>
                <?php print $psa; ?>
              </p>
            <?php endif; ?>
          <?php else: ?>
            <?php // If there's a PSA image or video, output it in this column, otherwise output the modals list if it exists. ?>
            <?php if (isset($psa)): ?>
              <p <?php if ($is_video_psa) echo 'class="media-video"'; ?>>
                <?php print $psa; ?>
              </p>
            <?php else: ?>
              <?php if (isset($modals)): ?>
                <?php print $modals; ?>
              <?php endif; ?>
            <?php endif; ?>
          <?php endif; ?>
        </div>

        <div class="container__block -half">
          <?php if (isset($campaign->fact_solution) || isset($campaign->solution_copy)): ?>
              <h3 class="inline-sponsor-color"><?php print t('The Solution'); ?></h3>

            <?php if (isset($campaign->fact_solution)): ?>
              <p><?php print $campaign->fact_solution['fact']; ?><sup><?php print $campaign->fact_solution['footnotes']; ?></sup></p>
            <?php elseif (isset($campaign->solution_copy)): ?>
              <?php print $campaign->solution_copy; ?>
            <?php endif; ?>

            <?php if (isset($campaign->solution_support)): ?>
              <?php print $campaign->solution_support; ?>
            <?php endif; ?>

          <?php endif; ?>

          <?php if ($show_problem_shares): ?>
            <?php // Alway output modals in the second column. ?>
            <?php if (isset($modals)): ?>
             <?php print $modals; ?>
            <?php endif; ?>
          <?php else: ?>
            <?php // If there's a PSA image or video, then it was output in the first column above and thus need to output the modals in this second column instead. ?>
            <?php if (isset($psa)): ?>
              <?php if (isset($modals)): ?>
                <?php print $modals; ?>
              <?php endif; ?>
            <?php endif; ?>
          <?php endif; ?>
        </div>

        <div class="container__block -narrow">
          <?php if (isset($campaign->fact_sources)): ?>
          <section class="footnote">
            <h4 class="js-footnote-toggle"><?php print t('Sources'); ?></h4>
            <ul class="js-footnote-hidden">
              <?php foreach ($campaign->fact_sources as $key => $source): ?>
                <li><sup><?php print($key + 1); ?></sup> <?php print $source; ?></li>
              <?php endforeach; ?>
            </ul>
          </section>
          <?php endif; ?>
        </div>
      </div>
    </section>


    <section id="do" class="container container--do inline-alt-background-color">
      <div class="wrapper">
        <div class="container__block -narrow">
          <h2 class="heading -emphasized -inverse"><span><?php print t('Step 2: Do It'); ?></span></h2>
          <?php if (isset($starter_header)) : ?>
            <h3 class="inline-alt-text-color"><?php print $starter_header; ?></h3>
          <?php endif; ?>
          <?php if (isset($starter)) : ?>
            <div><?php print $starter['safe_value']; ?></div>
          <?php endif; ?>
        </div>

        <?php if (isset($signup_form)) : ?>
          <?php print render($signup_form); ?>
        <?php endif; ?>

        <div class="container__block -narrow">
          <?php if (isset($official_rules)): ?>
            <p class="footnote">
              <a class="official-rules" href="<?php print $official_rules_src; ?>"><?php print t('Official Rules'); ?></a>
            </p>
          <?php endif; ?>

          <p class="footnote">
            <?php
            print t('Taking part in this experience means you agree to our !terms_link &amp; to receive our weekly update. Message &amp; data rates may apply. Text STOP to opt-out, HELP for help.',
              ['!terms_link' => l(t('Terms of Service'), 'about/terms-service')]); ?>
          </p>
        </div>
      </div>


      <?php if ($info_bar): ?>
        <?php print $info_bar; ?>
      <?php endif; ?>

    </section>


  </div>

</article>
