<section class="campaign--wrapper">
  <header class="header <?php print $classes; ?>" <?php print (isset($hero_img_l_url) ? 'style="background:url(' . $hero_img_l_url . ');"' : ''); ?>>
    <div class="meta">
      <h1 class="title"><?php print $title; ?></h1>
      <p class="cta"><?php print $cta; ?></p>
      <p class="date"> <?php print $end_date; ?> </p>

      <?php if (isset($sponsors)): ?>
      <div class="sponsor">
        Powered by
        <?php foreach ($sponsors as $key => $sponsor) :?>
          <?php print $sponsor['name']; ?>
          <?php // print $sponsor['img']; ?>
        <?php endforeach; ?>
      </div>
      <?php endif; ?>
    </div>
  </header>

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
      <h4>The Problem</h4>

      <?php if (isset($fact_problem)): ?>
      <div class="fact-problem"><?php print $fact_problem['fact']; ?><sup>1</sup></div>
      <?php endif; ?>

      <?php if (isset($faq)): ?>
      <ul>
        <li><a href="#modal-faq" class="js-modal-link">Check out our FAQs</a></li>
      </ul>
      <div id="modal-faq" class="cached-modal">
        <a href="#" class="js-close-modal modal-close-button">×</a>
        <?php foreach ($faq as $item): ?>
          <h4 class="faq-header"><?php print $item['header']; ?></h4>
          <div class="faq-copy"><?php print $item['copy'] ?></div>
        <?php endforeach; ?>
      </div>
      <?php endif; ?>

      <?php if (isset($more_facts)): ?>
      <ul>
        <li><a href="#modal-facts" class="js-modal-link">Learn more about <?php print $issue; ?></a></li>
      </ul>
      <div id="modal-facts" class="cached-modal">
        <a href="#" class="js-close-modal modal-close-button">×</a>
        <?php foreach ($more_facts as $fact): ?>
          <div class="fact-more">
            <div class="fact-more"><?php print $fact['fact']; ?></div>
            <?php // @TODO: Output sources separately.  ?>
            <?php foreach ($fact['sources'] as $source): ?>
              <div class="legal"><p>Source:</p><?php print $source; ?></div>
            <?php endforeach; ?>
          </div>
        <?php endforeach; ?>
      </div>
      <?php endif; ?>

      <?php if (isset($partner_info)): ?>
      <?php foreach ($partner_info as $delta => $partner): ?>
        <a href="#modal-partner-<?php print $delta; ?>" class="js-modal-link">
          Why we <3 <?php print $partner['name']; ?>
        </a>
        <div id="modal-partner-<?php print $delta; ?>" class="cached-modal">
          <a href="#" class="js-close-modal modal-close-button">×</a>
          <?php print $partner['copy']; ?>
        </div>
      <?php endforeach; ?>
      <?php endif; ?>

    </div>

    <div class="col second">
      <h4>The Solution</h4>

      <?php // @TODO - Print only one of these ?>
      <?php if (isset($fact_solution)): ?>
      <div class="fact-solution"><?php print $fact_solution['fact']; ?></div>
      <?php endif; ?>

      <?php if (isset($solution_copy)): ?>
      <div class="solution-copy"><?php print $solution_copy['safe_value']; ?><sup>2</sup></div>
      <?php endif; ?>

      <?php if (isset($solution_support)): ?>
      <div class="solution-supporting-copy"><?php print $solution_support['safe_value']; ?></div>
      <?php endif; ?>
    </div>

    <!-- @TODO - This is a mess. Clean it up after Aaron updates the fact counters -->

    <div class="col sources">
      <?php if (isset($fact_problem)): ?>
      <div class="legal">
        <strong>Sources:</strong>
        <sup>1</sup>

        <?php foreach ($fact_problem['sources'] as $source): ?>
        <?php print $source; ?>
        <?php endforeach; ?>
      </div>
      <?php endif; ?>

      <?php if (isset($fact_solution)): ?>
      <div class="legal">
        <sup>2</sup>

        <?php foreach ($fact_solution['sources'] as $source): ?>
        <?php print $source; ?>
        <?php endforeach; ?>
      <?php endif; ?>
      </div>
    </div>

  </section>

  <h2 id="plan" class="step-header"><span class="shift">Step 2: Plan It</span></h2>
  <section class="plan step">
    <?php if (isset($starter)) : ?>
      <div class="intro"><?php print $starter['safe_value']; ?></div>
    <?php endif; ?>

    <div class="col first">
      <?php if (isset($items_needed)) : ?>
        <h4>Stuff You Need</h4>
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
        <h4>Time and Place</h4>
        <div><?php print $time['safe_value']; ?></div>
      <?php endif; ?>
    </div>

    <div class="col second">
      <?php if (isset($hype)) : ?>
        <h4>Hype</h4>
        <div><?php print $hype['safe_value']; ?></div>
      <?php endif; ?>

      <?php if (isset($vips)) : ?>
        <h4>VIPs</h4>
        <div><?php print $vips['safe_value']; ?></div>
      <?php endif; ?>
    </div>

    <?php if (isset($location_finder_url)) : ?>
      <div class="location-finder">
        <h4>Find a Location</h4>
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
    <div class="pre">
      <h3><?php print $pre_step_header; ?></h3>
      <div><?php print $pre_step_copy['safe_value']; ?></div>
    </div>

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

    <div class="during">
      <h3>Snap a Pic</h3>
      <div><?php print $pic_step['safe_value']; ?></div>
    </div>

    <div class="post">
      <h3><?php print $post_step_header; ?></h3>
      <div><?php print $post_step_copy; ?></div>
    </div>

    <!-- MODAL -->
    <?php if (isset($step_post)) : ?>
    <div class="cached-modal">
    <?php foreach ($step_post as $item): ?>
    <h4><?php print $item['header']; ?></h4>
    <div><?php print $item['copy'] ?></div>
    <?php endforeach; ?>
    </div>
    <?php endif; ?>
  </section>

  <h2 id="prove" class="step-header"><span class="shift">Step 4: Prove It</span></h2>
  <section class="prove step">
    <div class="content">
      <h3 class="title">Pics or It Didn't Happen</h3>
      <div class="copy"><?php print $reportback_copy; ?></div>

      <a href="#modal-report-back" class="js-modal-link btn large"><?php print $reportback_link_label; ?></a>
      <div id="modal-report-back" class="cached-modal">
        <a href="#" class="js-close-modal modal-close-button">×</a>
        <?php print render($reportback_form); ?>
      </div>
    </div>

    <div class="js-carousel gallery">
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
    <div class="slide-wrapper">
      <?php //@TODO: Remove Trello-hosted placeholder ?>
      <figure class="slide visible"><img src="https://trello-attachments.s3.amazonaws.com/53037337ba957ad54dc80486/53063914418de170762c28c0/62291511fcc8d763184a04a99db007b7/placeholder.jpg" alt="This could be you!" /></figure>
      </div>
    <?php endif; ?>
    </div>


    <?php if (isset($sponsors)): ?>
    <div class="sponsor">
      In partnership with
      <?php foreach ($partners as $key => $partner) :?>
        <?php print $partner['name']; ?>
      <?php endforeach; ?>
    </div>
    <?php endif; ?>

    <footer class="help">
      <!-- @TODO - This is a placeholder. Remove once Zen Desk is working. -->
      <p>Have a Question?</p>
      <a href="#">Email Us</a>

      <?php if (isset($zendesk_form)): ?>
      <?php //@todo: Modalize and link to me. ?>
      <?php print render($zendesk_form); ?>
      <?php endif; ?>
    </footer>
  </section>

</section>
