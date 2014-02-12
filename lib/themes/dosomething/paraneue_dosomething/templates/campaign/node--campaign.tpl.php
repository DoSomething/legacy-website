<section class="c--wrapper">
  <header class="header <?php print $classes; ?>" style="background-image: url(<?php print $hero_image_l_url; ?>);">
    <div class="meta">
      <h1 class="title"><?php print $title; ?></h1>
      <p class="cta"><?php print $cta; ?></p>

      <?php print render($signup_form); ?>

      <img class="arrow" src="https://trello-attachments.s3.amazonaws.com/52de9089aa3032b85e9b0962/52e1724e23eeb26f4e9fc427/7e9e3ef8974d815230449b9829e98ac0/arrow.png" alt="Click the button!" />
      <p class="scholarship"><span class="highlight"><?php print $scholarship; ?></span></p>

      <div class="sponsor">
        <?php if (isset($sponsors)): ?>
          <?php foreach ($sponsors as $key => $sponsor) :?>
            <?php print $sponsor['name']; ?>
            <?php // print $sponsor['img']; ?>
          <?php endforeach; ?>
        <?php endif; ?>
      </div>
    </div>
  </header>

  <div class="content">
    <div id="js-pin-to-top-anchor" class="js-pin-to-top-anchor">&nbsp;</div>
    <nav class="navigation sticky"> 
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
      <?php foreach ($step_pre as $item): ?>
        <p class="tip-header"><a href="#"><?php print $item['header']; ?></a><span class="bullet">&nbsp;&#149;&nbsp;</span></p>
      <?php endforeach; ?>

      <div class="tip-wrapper">
      <?php foreach ($step_pre as $item): ?>
        <div class="tip-body"><?php print $item['copy'] ?></div>
      <?php endforeach; ?>
      </div>
      <?php endif; ?>

      <h3>Snap a Pic</h3>
      <?php print $pic_step['safe_value']; ?>
      <h4><?php print $post_step_header; ?></h4>
      <div><?php print $post_step_header['safe_value']; ?></div>

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
      <h4> Pics or It Didn't Happen </h4>
      <div><?php print $reportback_copy; ?></div>
      <a class="btn large"><?php print $reportback_link_label; ?></a>

      <div class="cached-modal"><?php print render($reportback_form); ?></div>
    </section>
  </div>
</section>
