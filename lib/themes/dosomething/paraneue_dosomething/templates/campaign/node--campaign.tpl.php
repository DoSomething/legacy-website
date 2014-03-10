<section class="campaign--wrapper">

  <?php foreach ($hero_image as $key => $image_url ) :?>
    <header class="header <?php print $key . ' ' . $classes; ?>" <?php print (isset($image_url) ? 'style="background-image: url(' . $image_url . ');"' : ''); ?>>
      <div class="meta">
        <h1 class="title"><?php print $title; ?></h1>
        <p class="cta"><?php print $cta; ?></p>

        <?php if (isset($end_date)): ?><p class="date"><?php print $end_date; ?></p><?php endif; ?>

        <?php if (isset($sponsors)): ?>
        <div class="sponsor">
          Powered by
          <?php foreach ($sponsors as $key => $sponsor) :?>
            <?php print $sponsor['name']; ?>
            <?php if (isset($sponsor['img'])): print $sponsor['img']; endif; ?>
          <?php endforeach; ?>
        </div>
        <?php endif; ?>
      </div>
    </header>
  <?php endforeach; ?>

  <nav id="nav" class="navigation">
    <ul>
      <li><a class="plain js-jump-scroll" href="#know">know</a></li>
      <li><a class="plain js-jump-scroll" href="#do">do</a></li>
      <li><a class="plain js-jump-scroll" href="#plan">plan</a></li>
      <li><a class="primary js-jump-scroll" href="#prove">prove it</a></li>
    </ul>
  </nav>

  <h2 id="know" class="step-header"><span class="shift">Step 1: Know It</span></h2>
  <section class="know step">

    <div class="col first">
      <h4 style="color: <?php isset($alt_color) ? print '#' . $alt_color : ''; ?>;">The Problem</h4>

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
      <h4 style="color: <?php isset($alt_color) ? print '#' . $alt_color : ''; ?>;">The Solution</h4>

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
      <a href="#" class="js-close-modal modal-close-button">×</a>
      <?php foreach ($faq as $item): ?>
        <h4 class="faq-header"><?php print $item['header']; ?></h4>
        <div class="faq-copy"><?php print $item['copy'] ?></div>
      <?php endforeach; ?>
    </script>
    <?php endif; ?>

    <?php if (isset($more_facts)): ?>
    <script id="modal-facts" type="text/cached-modal">
      <a href="#" class="js-close-modal modal-close-button">×</a>
      <?php foreach ($more_facts['facts'] as $key => $fact): ?>
        <div class="fact-more"><?php print $fact['fact']; ?><sup><?php print $fact['footnotes']; ?></sup></div>
      <?php endforeach; ?>
      Sources:
      <?php foreach ($more_facts['sources'] as $key => $source): ?>
        <div class="legal"><sup><?php print ($key + 1); ?></sup><?php print $source; ?></div>
      <?php endforeach; ?>
    </script>
    <?php endif; ?>

    <?php if (isset($partner_info)): ?>
    <?php foreach ($partner_info as $delta => $partner): ?>
    <script id="modal-partner-<?php print $delta; ?>" type="text/cached-modal">
      <a href="#" class="js-close-modal modal-close-button">×</a>
      <?php print $partner['copy']; ?>
      <?php if (isset($partner['image'])): print $partner['image']; endif; ?>
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
        <h4 style="color: <?php isset($alt_color) ? print '#' . $alt_color : ''; ?>;">Stuff You Need</h4>
        <div><?php print $items_needed['safe_value']; ?></div>
      <?php endif; ?>

      <?php if (isset($action_guides)) : ?>
        <ul>
        <?php foreach ($action_guides as $action_guide): ?>
          <li><?php print $action_guide; ?></li>
        <?php endforeach; ?>
        </ul>
      <?php endif; ?>

      <?php if (isset($time)) : ?>
        <h4 style="color: <?php isset($alt_color) ? print '#' . $alt_color : ''; ?>;">Time and Place</h4>
        <div><?php print $time['safe_value']; ?></div>
      <?php endif; ?>
    </div>

    <div class="col second">
      <?php if (isset($hype)) : ?>
        <h4 style="color: <?php isset($alt_color) ? print '#' . $alt_color : ''; ?>;">Hype</h4>
        <div><?php print $hype['safe_value']; ?></div>
      <?php endif; ?>

      <?php if (isset($vips)) : ?>
        <h4 style="color: <?php isset($alt_color) ? print '#' . $alt_color : ''; ?>;">VIPs</h4>
        <div><?php print $vips['safe_value']; ?></div>
      <?php endif; ?>
    </div>

    <?php if (isset($location_finder_url)) : ?>
      <div class="location-finder">
        <h4 style="color: <?php isset($alt_color) ? print '#' . $alt_color : ''; ?>;">Find a Location</h4>
        <div class="border">
          <?php if (isset($location_finder_copy)) : ?>
            <div><?php print $location_finder_copy['safe_value']; ?></div>
          <?php endif; ?>

          <a class="btn secondary" href="<?php print $location_finder_url['url']; ?>" target="_blank">Locate</a>
        </div>
      </div>
    <?php endif; ?>
  </section>

  <h2 id="do" class="step-header"><span class="shift">Step 3: Do It</span></h2>
  <section class="do step">
    <div class="content">
      <div class="pre">
        <?php if (isset($pre_step_header)): ?><h3 style="color: <?php isset($alt_color) ? print '#' . $alt_color : ''; ?>;"><?php print $pre_step_header; ?></h3><?php endif; ?>
        <?php if (isset($pre_step_copy['safe_value'])): ?><div><?php print $pre_step_copy['safe_value']; ?></div><?php endif; ?>

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

      <div class="step-image-wrapper mobile">
        <?php if (isset($step_image_landscape)): ?>
          <figure class="step-image"><?php print $step_image_landscape; ?></figure>
        <?php endif; ?>
      </div>

      <div class="during">
        <h3 style="color: <?php isset($alt_color) ? print '#' . $alt_color : ''; ?>;">Snap a Pic</h3>
        <?php if (isset($pic_step['safe_value'])): ?><div><?php print $pic_step['safe_value']; ?></div><?php endif; ?>
      </div>

      <div class="post">
        <?php if (isset($post_step_header)): ?><h3 style="color: <?php isset($alt_color) ? print '#' . $alt_color : ''; ?>;"><?php print $post_step_header; ?></h3><?php endif; ?>
        <?php if (isset($post_step_copy)): ?><div><?php print $post_step_copy; ?></div><?php endif; ?>
      </div>
    </div>

    <div class="step-image-wrapper desktop">
      <?php if (isset($step_image_square)): ?>
        <figure class="step-image"><?php print $step_image_square; ?></figure>
      <?php endif; ?>
    </div>

    <?php if (isset($step_post)) : ?>
    <script type="text/cached-modal">
    <?php foreach ($step_post as $item): ?>
    <h4 style="color: <?php isset($alt_color) ? print '#' . $alt_color : ''; ?>;"><?php print $item['header']; ?></h4>
    <div><?php print $item['copy'] ?></div>
    <?php endforeach; ?>
    </script>
    <?php endif; ?>
  </section>

  <h2 id="prove" class="step-header"><span class="shift">Step 4: Prove It</span></h2>
  <section class="prove step" style="background-image: <?php isset($alt_bg_src) ? print 'url(' . $alt_bg_src . ')' : ''; ?>;">
    <div class="content">
      <h3 class="title">Pics or It Didn't Happen</h3>
      <?php if (isset($reportback_copy)): ?><div class="copy"><?php print $reportback_copy; ?></div><?php endif; ?>

      <?php if (isset($reportback_link_label)): ?><a href="#modal-report-back" class="js-modal-link btn large"><?php print $reportback_link_label; ?></a><?php endif; ?>
      <?php if (isset($official_rules_src)): ?><a href="<?php print $official_rules_src; ?>">Official Rules</a><?php endif; ?>

      <?php if (isset($reportback_form)): ?>
      <script id="modal-report-back" type="text/cached-modal">
        <a href="#" class="js-close-modal modal-close-button">×</a>
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
      <?php //@TODO: Remove Trello-hosted placeholder ?>
      <figure class="slide visible"><img src="https://trello-attachments.s3.amazonaws.com/53037337ba957ad54dc80486/53063914418de170762c28c0/62291511fcc8d763184a04a99db007b7/placeholder.jpg" alt="This could be you!" /></figure>
      </div>
    <?php endif; ?>
    </div>

    <footer class="help sponsors">
      <?php if (isset($sponsors)): ?>
      <div class="sponsor">
        In partnership with
        <?php foreach ($partners as $key => $partner) :?>
          <?php print $partner['name']; ?>
        <?php endforeach; ?>
      </div>
      <?php endif; ?>

      <p>Have a Question?</p>
      <a href="#modal-help" class="js-modal-link">Email Us</a>
    </footer>

    <?php if (isset($zendesk_form)): ?>
    <script id="modal-help" type="text/cached-modal">
      <a href="#" class="js-close-modal modal-close-button">×</a>
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

</section>
