<section class="c--wrapper">
  <header class="header <?php print $classes; ?>" style="background-image: url(<?php print $hero_image_l_url; ?>);">
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
  </header>

  <div class="content">
    <div id="js-pin-to-top-anchor" class="js-pin-to-top-anchor">&nbsp;</div>
    <nav class="navigation js-pin-to-top">
      <ul>
        <li><a class="plain js-jump-scroll" href="#know">know</a></li>
        <li><a class="plain js-jump-scroll" href="#do">do</a></li>
        <li><a class="plain js-jump-scroll" href="#plan">plan</a></li>
        <li><a class="primary js-jump-scroll" href="#prove">prove it</a></li>
      </ul>
    </nav>

    <h2 id="know" class="step-header">Know It</h2>
    <section class="know step">
      <div class="col first">
        <?php if (isset($fact_problem)): ?>
        <h4>The Problem</h4>
        <p><?php print $fact_problem['fact']; ?></p>
        <?php foreach ($fact_solution['sources'] as $source): ?>
        <p class="legal">Source: <?php print $fact_problem['source']; ?></p>
        <?php endforeach; ?>
        <?php endif; ?>
      </div>

      <div class="col second">
        <?php if (isset($fact_solution)): ?>
        <h4>The Solution</h4>
        <p><?php print $fact_solution['fact']; ?></p>
        <?php foreach ($fact_problem['sources'] as $source): ?>
        <p class="legal">Source: <?php print $fact_solution['source']; ?></p>
        <?php endforeach; ?>
      </div>

      <div>
        <p><?php print $fact['fact']; ?></p>
        <?php foreach ($fact['sources'] as $source): ?>
          <p class="legal">Source: <?php print $source; ?></p>
        <?php endforeach; ?>

        <?php if (isset($solution_copy)): ?>
        <p><?php print $solution_copy['safe_value']; ?></p>
        <?php endif; ?>

        <?php if (isset($solution_support)): ?>
        <p><?php print $solution_support['safe_value']; ?></p>
        <?php endif; ?>
   
        <?php if (isset($more_facts)): ?>
        <?php foreach ($more_facts as $fact): ?>
        <p><?php print $fact['fact']; ?></p>
        <p class="legal">Source: <?php print $fact['source']; ?></p>
        <?php endforeach; ?>
        <?php endif; ?>
      </div>

      <aside class="js-modal-link">
        <?php if (isset($faq)): ?>
        <h4>FAQ</h4>
        <?php foreach ($faq as $item): ?>
        <h4><?php print $item['header']; ?></h4>
        <p><?php print $item['copy'] ?></p>
        <?php endforeach; ?>
        <?php endif; ?>
      </aside>
    </section>

    <h2 id="do" class="step-header">Plan It</h2>
    <section class="do step">
      <?php if (isset($starter)) : ?>
        <?php print $starter['safe_value']; ?>
      <?php endif; ?>

      <div class="first col">
        <?php if (isset($items_needed)) : ?>
          <h4>Stuff You Need</h4>
          <?php print $items_needed['safe_value']; ?>
        <?php endif; ?>

        <?php if (isset($time)) : ?>
          <h4>Time and Place</h4>
          <?php print $time['safe_value']; ?>
        <?php endif; ?>
      </div>

      <div class="second col">
        <?php if (isset($hype)) : ?>
          <h4>Hype</h4>
          <?php print $items_needed['safe_value']; ?>
          <?php print $hype['safe_value']; ?>
        <?php endif; ?>

        <?php if (isset($vips)) : ?>
          <h4>VIPs</h4>
          <?php print $vips['safe_value']; ?>
        <?php endif; ?>
      </div>

      <?php if (isset($location_finder_copy)) : ?>
        <h4>Find a Location</h4>
        <?php print $location_finder_copy['safe_value']; ?>
      <?php endif; ?>

      <?php if (isset($location_finder_url)) : ?>
        <a href="<?php print $location_finder_url['url']; ?>" target="_blank">Locate</a>
      <?php endif; ?>
    </section>

    <h2 id="plan" class="step-header">Do It</h2>
    <section class="plan step">
      <h3><?php print $pre_step_header; ?></h3>
      <?php print $pre_step_copy['safe_value']; ?>

      <?php if (isset($step_pre)) : ?>
      <?php foreach ($step_pre as $item): ?>
      <h4><?php print $item['header']; ?></h4>
      <p><?php print $item['copy'] ?></p>
      <?php endforeach; ?>
      <?php endif; ?>

      <?php if (isset($step_post)) : ?>
      <?php foreach ($step_post as $item): ?>
      <h4><?php print $item['header']; ?></h4>
      <p><?php print $item['copy'] ?></p>
      <?php endforeach; ?>
      <?php endif; ?>

      <h4>Snap a Pic</h4>
      <?php print $pic_step['safe_value']; ?>
      <h4><?php print $post_step_header; ?></h4>
      <?php print $post_step_header['safe_value']; ?>
    </section>

    <h2 id="prove" class="step-header">Prove It</h2>
    <section class="prove step">
      <h4> Pics or It Didn't Happen </h4>
      <?php print $reportback_copy; ?>
      <a class="btn large"><?php print $reportback_link_label; ?></a>

      <?php print render($reportback_form); ?>
    </section>
  </div>
</section>
