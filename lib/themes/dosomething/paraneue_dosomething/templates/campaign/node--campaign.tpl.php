<section class="campaign--wrapper">
  <header class="header <?php print $classes; ?>">
    <div class="meta">
      <h1 class="title"><?php print $title; ?></h1>
      <p class="cta"><?php print $cta; ?></p>

      <?php if (isset($end_date)): ?><p class="date"><?php print $end_date; ?></p><?php endif; ?>

      <?php if (isset($sponsors)): ?>
      <div class="sponsor-wrapper">
        <p class="copy">Powered by:</p>
        <?php foreach ($sponsors as $key => $sponsor) :?>
          <?php if (isset($sponsor['display'])): print $sponsor['display']; endif; ?>
        <?php endforeach; ?>
      </div>
      <?php endif; ?>
    </div>
  </header>

  <div class="content-wrapper">
    <div class="navigation--wrapper">
      <nav id="nav" class="navigation js-sticky">
        <ul>
          <li><a class="plain js-jump-scroll js-scroll-indicator" href="#know">know</a></li>
          <li><a class="plain js-jump-scroll js-scroll-indicator" href="#plan">plan</a></li>
          <li><a class="plain js-jump-scroll js-scroll-indicator" href="#do">do</a></li>
          <li><a class="primary js-jump-scroll js-scroll-indicator" href="#prove">prove it</a></li>
        </ul>
      </nav>
    </div>

    <h2 id="know" class="step-header"><span class="shift">Step 1: Know It</span></h2>
    <section class="know step">

      <div class="col first">
        <h4 class="inline--alt-color">The Problem</h4>

        <?php if (isset($fact_problem)): ?>
        <div class="fact-problem"><?php print $fact_problem['fact']; ?><sup><?php print $fact_problem['footnotes']; ?></sup></div>
        <?php endif; ?>

        <ul class="modal-links">
          <?php if (isset($faq)): ?>
            <li><a href="#modal-faq" class="js-modal-link">Check out our FAQs</a></li>
          <?php endif; ?>

          <?php if (isset($more_facts)): ?>
            <li><a href="#modal-facts" class="js-modal-link">Learn more about <?php print $issue; ?></a></li>
          <?php endif; ?>

          <?php if (isset($partner_info)): ?>
          <?php foreach ($partner_info as $delta => $partner): ?>
            <li><a href="#modal-partner-<?php print $delta; ?>" class="js-modal-link">Why we &lt;3 <?php print $partner['name']; ?></a>
          <?php endforeach; ?>
          <?php endif; ?>
        </ul>
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
      </div>

      <?php if (isset($fact_sources)): ?>
      <div class="col sources">
        <div class="legal">
          <strong>Sources:</strong>
          <?php foreach ($fact_sources as $key => $source): ?>
            <div><sup><?php print ($key + 1); ?></sup> <?php print $source; ?></div>
          <?php endforeach; ?>
        </div>
      </div>
      <?php endif; ?>

      <!-- "Know It" Section Modals -->
      <?php if (isset($faq)): ?>
      <script id="modal-faq" type="text/cached-modal">
        <a href="#" class="js-close-modal modal-close-button white">×</a>
        <h2 class="banner">FAQs</h2>
        <?php foreach ($faq as $item): ?>
          <h4 class="faq-header"><?php print $item['header']; ?></h4>
          <div class="faq-copy"><?php print $item['copy'] ?></div>
        <?php endforeach; ?>
        <a href="#" class="js-close-modal">Back to main page</a>
      </script>
      <?php endif; ?>

      <?php if (isset($more_facts)): ?>
      <script id="modal-facts" type="text/cached-modal">
        <a href="#" class="js-close-modal modal-close-button white">×</a>
        <h2 class="banner">Facts</h2>
        <?php foreach ($more_facts['facts'] as $key => $fact): ?>
          <div class="fact-more"><?php print $fact['fact']; ?><sup><?php print $fact['footnotes']; ?></sup></div>
        <?php endforeach; ?>
        Sources:
        <?php foreach ($more_facts['sources'] as $key => $source): ?>
          <div class="legal"><sup><?php print ($key + 1); ?></sup><?php print $source; ?></div>
        <?php endforeach; ?>
        <a href="#" class="js-close-modal">Back to main page</a>
      </script>
      <?php endif; ?>

      <?php if (isset($partner_info)): ?>
      <?php foreach ($partner_info as $delta => $partner): ?>
      <script id="modal-partner-<?php print $delta; ?>" type="text/cached-modal">
        <a href="#" class="js-close-modal modal-close-button white">×</a>
        <h2 class="banner">We &lt;3 <?php print $partner['name']; ?></h2>
        <?php print $partner['copy']; ?>
        <?php if (isset($partner['image'])): print $partner['image']; endif; ?>
        <a href="#" class="js-close-modal">Back to main page</a>
      </script>
      <?php endforeach; ?>
      <?php endif; ?>
    </section>
    <!-- /KNOW -->

    <h2 id="plan" class="step-header"><span class="shift">Step 2: Plan It</span></h2>
    <section class="plan step">
      <?php if (isset($starter)) : ?>
        <div class="intro"><?php print $starter['safe_value']; ?></div>
      <?php endif; ?>

      <div class="col first">
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

        <?php if (isset($time)) : ?>
          <h4 class="inline--alt-color">Time and Place</h4>
          <div><?php print $time['safe_value']; ?></div>
        <?php endif; ?>
      </div>

      <div class="col second">
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

          <a class="btn secondary" href="<?php print $location_finder_url['url']; ?>" target="_blank">Locate</a>
        </div>
      <?php endif; ?>

      <!-- "Plan It" Section Modals -->
      <?php if (isset($action_guides)): ?>
      <?php foreach ($action_guides as $delta => $action_guide): ?>
      <script id="modal-action-guide-<?php print $delta; ?>" type="text/cached-modal">
        <a href="#" class="js-close-modal modal-close-button white">×</a>
        <h2 class="banner"></h2>
          <div><?php print $action_guide['content']; ?></div>
        <a href="#" class="js-close-modal">Back to main page</a>
      </script>
      <?php endforeach; ?>
      <?php endif; ?>

    </section>

    <h2 id="do" class="step-header"><span class="shift">Step 3: Do It</span></h2>
    <section class="do step">
      <div class="content">
        <div class="pre">
          <?php if (isset($pre_step_header)): ?><h3 class="inline--alt-color"><?php print $pre_step_header; ?></h3><?php endif; ?>
          <?php if (isset($pre_step_copy['safe_value'])): ?><div><?php print $pre_step_copy['safe_value']; ?></div><?php endif; ?>

          <?php if (isset($step_pre)) : ?>
          <a href="#modal-tips-pre" class="js-modal-link more-tips">View tips</a>
          <?php endif; ?>

          <div class="tips">
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
        <script id="modal-tips-pre" class="modal--tips" type="text/cached-modal">
          <a href="#" class="js-close-modal modal-close-button white">×</a>

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
          <h3 class="inline--alt-color"><?php print $pic_step_header; ?></h3>
          <?php if (isset($pic_step_copy['safe_value'])): ?><div><?php print $pic_step_copy['safe_value']; ?></div><?php endif; ?>
        </div>

        <div class="post">
          <?php if (isset($post_step_header)): ?><h3 class="inline--alt-color"><?php print $post_step_header; ?></h3><?php endif; ?>
          <?php if (isset($post_step_copy)): ?><div><?php print $post_step_copy; ?></div><?php endif; ?>

          <?php if (isset($step_post)) : ?>
            <a href="#modal-post-tips" class="js-modal-link more-tips">View tips</a>
          <?php endif; ?>

          <div class="tips">
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

          <div class="tips">
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
        </div>

        <!-- "More tips" modal for mobile viewports  -->
        <script id="modal-tips-post" class="modal--tips2" type="text/cached-modal">
          <a href="#" class="js-close-modal modal-close-button white">×</a>

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
      <script type="text/cached-modal" id="modal-post-tips" class="modal--tips">
      <a href="#" class="js-close-modal modal-close-button white">×</a>
      <h2 class="banner">Tips</h2>
      <?php foreach ($step_post as $item): ?>
      <h4 class="inline--alt-color"><?php print $item['header']; ?></h4>
      <div><?php print $item['copy'] ?></div>
      <?php endforeach; ?>
      <a href="#" class="js-close-modal">Back to main page</a>
      </script>
      <?php endif; ?>
    </section>

    <h2 id="prove" class="step-header"><span class="shift">Step 4: Prove It</span></h2>
    <section class="prove step inline--alt-bg">
      <div class="content">
        <h3 class="title">Pics or It Didn't Happen</h3>
        <?php if (isset($reportback_copy)): ?><div class="copy"><?php print $reportback_copy; ?></div><?php endif; ?>

        <?php if (isset($reportback_link_label)): ?><a href="#modal-report-back" class="js-modal-link btn large"><?php print $reportback_link_label; ?></a><?php endif; ?>
        <?php if (isset($official_rules)): ?><a class="official-rules" href="<?php print $official_rules_src; ?>">Official Rules</a><?php endif; ?>

        <?php if (isset($reportback_form)): ?>
        <script id="modal-report-back" class="modal--reportback inline--alt-bg" type="text/cached-modal">
          <a href="#" class="js-close-modal modal-close-button white">×</a>
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

      <footer class="help <?php isset($sponsors) ? print 'sponsors' : '' ; ?>">
        <div class="footer-content">
          <?php if (isset($sponsors)): ?>
          <div class="sponsor-wrapper">
            In partnership with
            <?php foreach ($partners as $key => $partner) :?>
              <?php print $partner['name']; ?>
            <?php endforeach; ?>
          </div>
          <?php endif; ?>

          <div class="help-wrapper">Have a question? <a href="#modal-help" class="js-modal-link secondary">Give us a shout</a></div>
        </div>
      </footer>

      <?php if (isset($zendesk_form)): ?>
      <script id="modal-help" type="text/cached-modal">
        <a href="#" class="js-close-modal modal-close-button white">×</a>
        <h2 class="banner">Contact Us</h2>
        <p>Enter your question below. Please be as specific as possible.</p>

        <?php print render($zendesk_form); ?>
      </script>
      <?php endif; ?>

      <?php if (isset($fact_sources)): ?>
      <footer class="sources">
        <div class="legal">
          <strong>Sources:</strong>
          <?php foreach ($fact_sources as $key => $source): ?>
            <div><sup><?php print ($key + 1); ?></sup> <?php print $source; ?></div>
          <?php endforeach; ?>
        </div>
      </footer>
      <?php endif; ?>
    </section>
  </div>
</section>
