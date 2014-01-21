<div class="content clearfix <?php print $classes; ?>">

  <?php print render($reportback_form); ?>

  <div>
    <p><?php print $fact_problem['fact']; ?></p>
    <p class="legal">Source: <?php print $fact_problem['source']; ?></p>
  </div>
  <div>
    <p><?php print $fact_solution['fact']; ?></p>
    <p class="legal">Source: <?php print $fact_solution['source']; ?></p>
  </div>

  <h3>Pre Steps</h3>
  <?php foreach ($step_pre as $item): ?>
  <h4><?php print $item['header']; ?></h4>
  <p><?php print $item['copy'] ?></p>
  <?php endforeach; ?>

  <h3>Post Steps</h3>
  <?php foreach ($step_post as $item): ?>
  <h4><?php print $item['header']; ?></h4>
  <p><?php print $item['copy'] ?></p>
  <?php endforeach; ?>

  <h3>FAQ</h3>
  <?php foreach ($faq as $item): ?>
  <h4><?php print $item['header']; ?></h4>
  <p><?php print $item['copy'] ?></p>
  <?php endforeach; ?>
</div>
