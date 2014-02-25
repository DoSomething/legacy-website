<section class="c--wrapper">
  <header class="header <?php print $classes; ?>" <?php print (isset($hero_img_l_url) ? 'style="background:url(' . $hero_img_l_url . ');"' : ''); ?>>
    <div class="meta">
      <h1 class="title"><?php print $title; ?></h1>
      <p class="cta"><?php print $cta; ?></p>
      <p class="date"> <?php print $end_date; ?> </p>

      <?php if (isset($sponsors)): ?>
      <div class="sponsor">
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

  <h2 id="know" class="step-header"><span class="shift">Know It</span></h2>
  <section class="know step">
    <div class="col first">
      <h4>The Problem</h4>
      <?php if (isset($fact_problem)): ?>
      <p><?php print $fact_problem['fact']; ?></p>
      <?php foreach ($fact_problem['sources'] as $source): ?>
        <p class="legal">Source: <?php print $source; ?></p>
      <?php endforeach; ?>
      <?php endif; ?>

      <?php if (isset($psa)): ?>
        <?php print $psa; ?>
      <?php endif; ?>
    </div>

    <div class="col second">
      <h4>The Solution</h4>
      <?php if (isset($fact_solution)): ?>
      <p><?php print $fact_solution['fact']; ?></p>
      <?php foreach ($fact_solution['sources'] as $source): ?>
        <p class="legal">Source: <?php print $source; ?></p>
      <?php endforeach; ?>
      <?php endif; ?>

      <?php if (isset($solution_copy)): ?>
      <div class="solution-copy"><?php print $solution_copy['safe_value']; ?></div>
      <?php endif; ?>

      <?php if (isset($solution_support)): ?>
      <div class="solution-supporting-copy"><?php print $solution_support['safe_value']; ?></div>
      <?php endif; ?>

      <?php if (isset($more_facts)): ?>
      <?php foreach ($more_facts as $fact): ?>
        <div>
          <p><?php print $fact['fact']; ?></p>
          <?php foreach ($fact['sources'] as $source): ?>
            <p class="legal">Source: <?php print $source; ?></p>
          <?php endforeach; ?>
        </div>
      <?php endforeach; ?>
      <?php endif; ?>
    </div>

    <aside class="cached-modal">
      <?php if (isset($faq)): ?>
      <h4>FAQ</h4>
      <?php foreach ($faq as $item): ?>
      <h4 class="faq-header"><?php print $item['header']; ?></h4>
      <div class="faq-copy"><?php print $item['copy'] ?></div>
      <?php endforeach; ?>
      <?php endif; ?>
    </aside>
  </section>

  <h2 id="plan" class="step-header"><span class="shift">Plan It</span></h2>
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

  <h2 id="do" class="step-header"><span class="shift">Do It</span></h2>
  <section class="do step">
    <h3><?php print $pre_step_header; ?></h3>
    <div><?php print $pre_step_copy['safe_value']; ?></div>

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

    <h3>Snap a Pic</h3>
    <?php print $pic_step['safe_value']; ?>
    <h4><?php print $post_step_header; ?></h4>
    <div><?php print $post_step_copy; ?></div>

    <!-- MODAL -->
    <?php if (isset($step_post)) : ?>
    <div class="cached-modal">
    <?php foreach ($step_post as $item): ?>
    <h3><?php print $item['header']; ?></h3>
    <div><?php print $item['copy'] ?></div>
    <?php endforeach; ?>
    </div>
    <?php endif; ?>
  </section>

  <h2 id="prove" class="step-header"><span class="shift">Prove It</span></h2>
  <section class="prove step">
    <div class="content">
      <h2 class="title">Pics or It Didn't Happen</h2>
      <div class="copy"><?php print $reportback_copy; ?></div>

      <a href="#modal-report-back" class="js-modal-link btn large"><?php print $reportback_link_label; ?></a>
      <div id="modal-report-back" class="cached-modal"><?php print render($reportback_form); ?></div>
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
  </section>

  <?php if (isset($zendesk_form)): ?>
  <?php //@todo: Modalize and link to me. ?>
  <?php print render($zendesk_form); ?>
  <?php endif; ?>
</section>
