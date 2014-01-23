<div class="content clearfix <?php print $classes; ?>">

<?php print $cta; ?>
  <h2> Know It </h2>
  <?php if (isset($fact_problem)): ?>
  <div>
    <p><?php print $fact_problem['fact']; ?></p>
    <p class="legal">Source: <?php print $fact_problem['source']; ?></p>
  </div>
  <?php endif; ?>

  <?php if (isset($fact_solution)): ?>
  <div>
    <p><?php print $fact_solution['fact']; ?></p>
    <p class="legal">Source: <?php print $fact_solution['source']; ?></p>
  </div>
  <?php endif; ?>

  <?php if (isset($solution_support)): ?>
  <p><?php print $solution_support; ?></p>
  <?php endif; ?>

  <?php if (isset($more_facts)): ?>
  <?php foreach ($more_facts as $fact): ?>
  <div>
    <p><?php print $fact['fact']; ?></p>
    <p class="legal">Source: <?php print $fact['source']; ?></p>
  </div>
  <?php endforeach; ?>
  <?php endif; ?>

  <?php if (isset($faq)): ?>
  <h3>FAQ</h3>
  <?php foreach ($faq as $item): ?>
  <h4><?php print $item['header']; ?></h4>
  <p><?php print $item['copy'] ?></p>
  <?php endforeach; ?>
  <?php endif; ?>

  <h2> Plan It </h2>
  <?php if (isset($starter)) : ?>
    <?php print $starter['safe_value']; ?>
  <?php endif; ?>
  <?php if (isset($time)) : ?>
    <?php print $time['safe_value']; ?>
  <?php endif; ?>
  <?php if (isset($hype)) : ?>
    <?php print $hype['safe_value']; ?>
  <?php endif; ?>
  <?php if (isset($vips)) : ?>
    <?php print $vips['safe_value']; ?>
  <?php endif; ?>
  <?php if (isset($items_needed)) : ?>
    <?php print $items_needed['safe_value']; ?>
  <?php endif; ?>

  <h2> Do It </h2>
  <h4> <?php print $pre_step_header; ?> </h4>
  <?php print $pre_step_copy['safe_value']; ?>

  <?php if (isset($step_pre)) : ?>
  <h3>Pre Steps</h3>
  <?php foreach ($step_pre as $item): ?>
  <h4><?php print $item['header']; ?></h4>
  <p><?php print $item['copy'] ?></p>
  <?php endforeach; ?>
  <?php endif; ?>

  <?php if (isset($step_post)) : ?>
  <h3>Post Steps</h3>
  <?php foreach ($step_post as $item): ?>
  <h4><?php print $item['header']; ?></h4>
  <p><?php print $item['copy'] ?></p>
  <?php endforeach; ?>
  <?php endif; ?>

  <h4> Snap a Pic </h4>
  <?php print $pic_step['safe_value']; ?>
  <h4> <?php print $post_step_header; ?> </h4>
  <?php print $post_step_header['safe_value']; ?>

  <h2> Prove It </h2>
  <h4> Pics or It Didn't Happen </h4>
  <?php print $reportback_copy; ?>

  <?php print render($reportback_form); ?>

</div>
