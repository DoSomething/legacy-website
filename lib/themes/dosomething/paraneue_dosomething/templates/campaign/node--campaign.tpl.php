<?php
/**
 * Returns the HTML for the Campaign Action page.
 *
 * Available Variables
 * - $fact_problem:
 * - $end_date: End date for the campaign (string).
 * - $scholarship: Scholarship amount (string).
 * - $classes: Additional classes passed for output (string).
 */

krumo('spacer');
krumo('spacer');
krumo($variables);
// krumo($plan_count);
?>

<article class="campaign action"><?php // @TODO: need to deal w/ "action" class. ?>

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


  <nav id="nav" class="navigation js-sticky">
    <ul>
      <li><a class="js-jump-scroll js-scroll-indicator" href="#know">know</a></li>
      <li><a class="js-jump-scroll js-scroll-indicator" href="#plan">plan</a></li>
      <li><a class="js-jump-scroll js-scroll-indicator" href="#do">do</a></li>
      <li><a class="primary js-jump-scroll js-scroll-indicator" href="#prove">prove it</a></li>
    </ul>
  </nav>


  <?php // KNOW IT ////////////////////////////////////////////////////// ?>
  <section id="know" class="container container--know">
    <h2 class="container__title banner"><span>Step 1: Know It</span></h2>

    <div class="wrapper">

      <div class="container__body">
        <div class="-columned -odd">
          <?php if (isset($fact_problem)): ?>
          <h3 class="inline--alt-color">The Problem</h3>
          <p><?php print $fact_problem['fact']; ?><sup><?php print $fact_problem['footnotes']; ?></sup></p>
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

        <div class="-columned -even -col-last">
          <?php if (isset($fact_solution) || isset($solution_copy)): ?>
            <h3 class="inline--alt-color">The Solution</h3>

            <?php if (isset($fact_solution)): ?>
              <p><?php print $fact_solution['fact']; ?><sup><?php print $fact_solution['footnotes']; ?></sup></p>

            <?php elseif (isset($solution_copy)): ?>
              <?php print $solution_copy['safe_value']; ?>

              <?php if (isset($solution_support)): ?>
                <p><?php print $solution_support; ?></p>
              <?php endif; ?>
            <?php endif; ?>

          <?php endif; ?>

          <?php if (isset($psa)): ?>
            <?php if (isset($modals)): ?>
              <?php print $modals; ?>
            <?php endif; ?>
          <?php endif; ?>
        </div>
      </div>

      <?php if (isset($fact_sources)): ?>
      <section class="sources">
        <h3 class="__title js-toggle-sources">Sources</h3>
        <ul class="__body legal">
          <?php foreach ($fact_sources as $key => $source): ?>
            <li><sup><?php print ($key + 1); ?></sup> <?php print $source; ?></li>
          <?php endforeach; ?>
        </ul>
      </section>
      <?php endif; ?>

    </div>
  </section>


  <?php // PLAN IT ////////////////////////////////////////////////////// ?>
  <section id="plan" class="container container--plan">
    <h2 class="container__title banner"><span>Step 2: Plan It</span></h2>

    <div class="wrapper">

      <div class="container__body">
      <?php if (isset($starter)) : ?>
        <?php print $starter['safe_value']; ?>
      <?php endif; ?>

      <?php if ($plan): ?>
        <?php foreach ($plan as $delta => $content): ?>

          <?php if ($delta%2 === 0) print '<div class="__row">'; ?>
          <div class="-columned <?php print $delta%2 ? '-even' : '-odd'; ?>">
            <h3 class="inline--alt-color"><?php print $content['title']; ?></h3>
            <?php print $content['content']; ?>

            <?php // Content specifically for Materials content section. ?>
            <?php if ($content['category'] === 'materials' && isset($action_guides)) : ?>
              <ul>
              <?php foreach ($action_guides as $delta => $action_guide): ?>
                <li><a href="#modal-action-guide-<?php print $delta; ?>" class="js-modal-link"><?php print $action_guide['desc']; ?></a></li>
              <?php endforeach; ?>
              </ul>
            <?php endif; ?>

            <?php if ($content['category'] === 'materials' && isset($signup_data_form_link)): ?>
              <ul>
                <li><a href="#modal-signup-data-form" class="js-modal-link"><?php print $signup_data_form_link; ?></a></li>
              </ul>
            <?php endif; ?>
          </div>
          <?php if ($delta%2 === 1 || $delta + 1 === $plan_count) print '</div>'; ?>

        <?php endforeach; ?>
      <?php endif; ?>


      <?php if (isset($location_finder['url'])) : ?>
        <div class="__row">
          <h3 class="inline--alt-color">Find a Location</h3>
          <?php if (isset($location_finder['copy'])) : ?>
            <?php print $location_finder['copy']; ?>
          <?php endif; ?>

          <a class="btn small secondary" href="<?php print $location_finder['url']; ?>" target="_blank">Locate</a>
        </div>
      <?php endif; ?>




      <?php // "Plan It" Section Modals ?>
      <?php if (isset($action_guides)): ?>
      <?php foreach ($action_guides as $delta => $action_guide): ?>
      <script id="modal-action-guide-<?php print $delta; ?>" type="text/cached-modal" data-modal-close="true" data-modal-close-class="white">
        <div><?php print $action_guide['content']; ?></div>
        <a href="#" class="js-close-modal">Back to main page</a>
      </script>
      <?php endforeach; ?>
      <?php endif; ?>

      <?php if (isset($signup_data_form)): ?>
      <script id="modal-signup-data-form" class="modal--signup-data" type="text/cached-modal" data-modal-close="true" data-modal-close-class="white">
        <div><?php print render($signup_data_form); ?></div>
        <?php if (isset($skip_signup_data_form)): ?>
        <div><?php print render($skip_signup_data_form); ?></div>
        <?php endif; ?>
      </script>
      <?php endif; ?>

    </div>
  </section>






  <?php // DO IT ////////////////////////////////////////////////////// ?>
  <section id="do" class="container container--do">
    <h2 class="container__title banner"><span>Step 3: Do It</span></h2>

    <div class="wrapper">

      <div class="container__body -compact">

        <?php foreach ($do as $key => $content): ?>
          <div class="__row">
            <?php if (isset($content['header'])): ?>
              <h3 class="inline--alt-color"><?php print $content['header']; ?></h3>
            <?php endif; ?>

            <?php if (isset($content['image'])): ?>
              <figure class="polaroid">
                <?php print $content['image']; ?>
              </figure>
            <?php endif; ?>

            <?php if (isset($content['copy'])): ?>
              <?php print $content['copy']; ?>
            <?php endif; ?>

            <?php if (isset($content['tips'])): ?>
              <section class="tabbed">
                <h4 class="visually-hidden">Tips</h4>
                <nav class="tabs__menu waypoints">
                  <ul class="menu">
                    <?php foreach ($content['tips'] as $delta => $tip): ?>
                      <?php $delta++; ?>
                      <li class="<?php if ($delta === 1) print ' -active'?>">
                        <a href="#tip-<?php print $delta; ?>"><?php print $tip['header']; ?></a>
                      </li>
                    <?php endforeach; ?>
                  </ul>
                </nav>

                <ul class="tabs__body">
                  <?php foreach ($content['tips'] as $delta => $tip): ?>
                    <?php $delta++; ?>
                    <li id="tip-<?php print $delta; ?>" class="tab">
                      <h5 class="__title"><?php print $tip['header']; ?></h5>
                      <?php print $tip['copy']; ?>
                    </li>
                  <?php endforeach; ?>
                </ul>
              </section>
            <?php endif; ?>
          </div>
        <?php endforeach; ?>

      </div>

    </div>
  </section>





  <?php // PROVE IT ////////////////////////////////////////////////////// ?>
  <section id="prove" class="container container--prove inline--alt-bg">
    <h2 class="container__title banner"><span>Step 4: Prove It</span></h2>

    <div class="wrapper">
      <div class="container__body">
        <div class="-columned">
          <h3>Pics or It Didn't Happen</h3>
          <?php if (isset($reportback_copy)): ?><div class="copy"><?php print $reportback_copy; ?></div><?php endif; ?>

          <?php if (isset($reportback_link)): ?><a href="#modal-report-back" class="js-modal-link btn <?php print $reportback_link['size']; ?>"><?php print $reportback_link['label']; ?></a><?php endif; ?>

          <?php if (isset($scholarship)): ?>
          <div class="scholarship-callout -action -below">
            <p class="copy"><?php print $scholarship; ?></p>
          </div>
          <?php endif; ?>

          <?php if (isset($official_rules)): ?><a class="official-rules" href="<?php print $official_rules_src; ?>">Official Rules</a><?php endif; ?>

          <?php if (isset($reportback_form)): ?>
          <script id="modal-report-back" class="modal--reportback inline--alt-bg" type="text/cached-modal" data-modal-close="true" data-modal-close-class="white">
            <h2 class="banner">Prove It</h2>
            <?php print render($reportback_form); ?>
          </script>
          <?php endif; ?>
        </div>

        <aside class="carousel-wrapper gallery -columned">
          <?php if (isset($reportback_image)): ?>
            <div id="prev" class="prev-wrapper">
              <div class="prev-button"><span class="arrow">&#xe605;</span></div>
            </div>

            <div class="slide-wrapper">
              <?php foreach ($reportback_image as $key=>$image): ?>
              <figure id="slide<?php print $key ?>" class="slide"><img src="<?php print $image ?>" /></figure>
              <?php endforeach; ?>
            </div>

            <div id="next" class="next-wrapper">
              <div class="next-button"><span class="arrow">&#xe60a;</span></div>
            </div>
          <?php else: ?>
          <div class="carousel-wrapper">
            <figure class="slide visible"><?php print $reportback_placeholder; ?></figure>
            </div>
          <?php endif; ?>
        </aside>
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



  <?php /*
  <?php // Add the new footer info-bar stuff. ?>
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
  */ ?>

</article>
