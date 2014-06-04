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

  <section id="know" class="container container--know">
    <h2 class="container__title banner"><span>Step 1: Know It</span></h2>

    <div class="wrapper">

      <div class="container__body">
        <div class="-columned">
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

        <div class="-columned -col-last">
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



  <section id="plan" class="container container--plan">
    <h2 class="container__title banner"><span>Step 2: Plan It</span></h2>

    <div class="wrapper">

      <div class="container__body">
      <?php if (isset($starter)) : ?>
        <div class="intro"><?php print $starter['safe_value']; ?></div>
      <?php endif; ?>

      <div class="-columned">
        <?php if (isset($items_needed)) : ?>
          <h4 class="inline--alt-color">Stuff You Need</h4>
          <div><?php print $items_needed['safe_value']; ?></div>
        <?php endif; ?>

        <?php if (isset($action_guides)) : ?>
          <ul>
          <?php foreach ($action_guides as $delta => $action_guide): ?>
            <li><a href="#modal-action-guide-<?php print $delta; ?>" class="js-modal-link"><?php print $action_guide['desc']; ?></a></li>
          <?php endforeach; ?>
          </ul>
        <?php endif; ?>

        <?php if (isset($signup_data_form_link)): ?>
          <ul>
            <li><a href="#modal-signup-data-form" class="js-modal-link"><?php print $signup_data_form_link; ?></a></li>
          </ul>
        <?php endif; ?>

        <?php if (isset($time)) : ?>
          <h4 class="inline--alt-color">Time and Place</h4>
          <div><?php print $time['safe_value']; ?></div>
        <?php endif; ?>
      </div>

      <div class="-columned -col-last">
        <?php if (isset($hype)) : ?>
          <h4 class="inline--alt-color">Hype</h4>
          <div><?php print $hype['safe_value']; ?></div>
        <?php endif; ?>

        <?php if (isset($vips)) : ?>
          <h4 class="inline--alt-color">VIPs</h4>
          <div><?php print $vips['safe_value']; ?></div>
        <?php endif; ?>
      </div>

      <?php if (isset($location_finder_url)) : ?>
        <div class="location-finder">
          <h4 class="inline--alt-color">Find a Location</h4>
          <?php if (isset($location_finder_copy)) : ?>
            <div><?php print $location_finder_copy['safe_value']; ?></div>
          <?php endif; ?>

          <a class="btn small secondary" href="<?php print $location_finder_url['url']; ?>" target="_blank">Locate</a>
        </div>
      <?php endif; ?>

      <!-- "Plan It" Section Modals -->
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







  <section id="do" class="container container--do">
    <h2 class="container__title banner"><span>Step 3: Do It</span></h2>

    <div class="wrapper">

      <div class="pre">
        <?php if (isset($pre_step_header)): ?><h4 class="inline--alt-color"><?php print $pre_step_header; ?></h4><?php endif; ?>
        <?php if (isset($pre_step_copy['safe_value'])): ?><div><?php print $pre_step_copy['safe_value']; ?></div><?php endif; ?>

        <?php if (isset($step_pre)) : ?>
        <a href="#modal-tips-pre" class="js-modal-link more-tips">View tips</a>
        <?php endif; ?>

        <div class="tips--wrapper">
          <?php if (isset($step_pre)) : ?>
          <div class="tip-header-wrapper">
          <?php foreach ($step_pre as $key=>$item): ?>
            <a href="#tip<?php print $key; ?>" class="js-show-tip tip-header <?php $key == 0 ? print ' active' : '' ?>"><?php print $item['header']; ?></a><span class="bullet">&#149;&nbsp;</span>
          <?php endforeach; ?>
          </div>

          <div class="tip-body-wrapper">
          <?php foreach ($step_pre as $key=>$item): ?>
            <div class="tip-body tip<?php print $key; ?>"><?php print $item['copy'] ?></div>
          <?php endforeach; ?>
          </div>
          <?php endif; ?>
        </div>
      </div>

      <!-- "More tips" modal for mobile viewports -->
      <script id="modal-tips-pre" class="modal--tips" type="text/cached-modal" data-modal-close="true" data-modal-close-class="white">
        <h2 class="banner">Tips</h2>
        <?php if (is_array($step_pre)): ?>
          <?php foreach ($step_pre as $item): ?>
            <h4 class="inline--alt-color"><?php print $item['header']; ?></h4>
            <div><?php print $item['copy']; ?></div>
          <?php endforeach; ?>
        <?php endif; ?>

        <a href="#" class="js-close-modal">Back to main page</a>
      </script>

      <div class="step-image-wrapper mobile">
        <?php if (isset($step_image_landscape)): ?>
          <figure class="step-image"><?php print $step_image_landscape; ?></figure>
        <?php endif; ?>
      </div>

      <div class="during">
        <h4 class="inline--alt-color"><?php print $pic_step_header; ?></h4>
        <?php if (isset($pic_step_copy['safe_value'])): ?><div><?php print $pic_step_copy['safe_value']; ?></div><?php endif; ?>
      </div>

      <div class="post">
        <?php if (isset($post_step_header)): ?><h4 class="inline--alt-color"><?php print $post_step_header; ?></h4><?php endif; ?>
        <?php if (isset($post_step_copy)): ?><p><?php print $post_step_copy; ?></p><?php endif; ?>

        <div class="tips--wrapper">
          <?php if (isset($step_post)) : ?>
          <div class="tip-header-wrapper">
          <?php foreach ($step_post as $key=>$item): ?>
            <a href="#tip<?php print $key; ?>" class="js-show-tip tip-header <?php $key == 0 ? print ' active' : '' ?>"><?php print $item['header']; ?></a><span class="bullet">&#149;&nbsp;</span>
          <?php endforeach; ?>
          </div>

          <div class="tip-body-wrapper">
          <?php foreach ($step_post as $key=>$item): ?>
            <div class="tip-body tip<?php print $key; ?>"><?php print $item['copy'] ?></div>
          <?php endforeach; ?>
          </div>
          <?php endif; ?>
        </div>

        <?php if (isset($step_post)) : ?>
          <a href="#modal-tips-post" class="js-modal-link more-tips">View tips</a>
        <?php endif; ?>
      </div>

      <!-- "More tips" modal for mobile viewports  -->
      <script id="modal-tips-post" class="modal--tips2" type="text/cached-modal" data-modal-close="true" data-modal-close-class="white">
        <h2 class="banner">Tips</h2>
        <?php if (is_array($step_post)): ?>
          <?php foreach ($step_post as $item): ?>
            <h4 class="inline--alt-color"><?php print $item['header']; ?></h4>
            <div><?php print $item['copy']; ?></div>
          <?php endforeach; ?>
        <?php endif; ?>

        <a href="#" class="js-close-modal">Back to main page</a>
      </script>
    </div>

    <div class="step-image-wrapper desktop">
      <?php if (isset($step_image_square)): ?>
        <figure class="step-image"><?php print $step_image_square; ?></figure>
      <?php endif; ?>
    </div>

    <?php if (is_array($step_post)) : ?>
    <script type="text/cached-modal" id="modal-post-tips" class="modal--tips" data-modal-close="true" data-modal-close-class="white">
      <h2 class="banner">Tips</h2>
      <?php foreach ($step_post as $item): ?>
      <h4 class="inline--alt-color"><?php print $item['header']; ?></h4>
      <div><?php print $item['copy'] ?></div>
      <?php endforeach; ?>
      <a href="#" class="js-close-modal">Back to main page</a>
    </script>
    <?php endif; ?>
  </section>






  <section id="prove" class="container container--prove inline--alt-bg">
    <h2 class="container__title banner"><span>Step 4: Prove It</span></h2>

    <div class="wrapper">
      <h3 class="title">Pics or It Didn't Happen</h3>
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

    <div class="carousel-wrapper gallery">
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
    </div>



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
  </section>

</article>
