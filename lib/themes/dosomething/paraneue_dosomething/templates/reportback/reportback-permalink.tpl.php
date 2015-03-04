<h2> <?php echo $node->title ?> </h2>

<?php if (!$is_current): ?>
  <?php echo $node->call_to_action ?>

  <h3> <?php t('The Problem') ?> </h3>
  <?php echo $node->fact_problem['fact'] ?>

  <h3> <?php t('The Solution') ?> </h3>
  <?php echo $node->fact_solution['fact'] ?>

<?php endif ?>

<?php echo $rb['image'] ?>
<?php echo $rb['caption'] ?>

<?php // Used to determine if the curernt logged in user is the user who submitted the rb. ?>
<?php if ($is_current): ?>
  <?php echo $copy_vars['owners_rb_subtitle'] ?>
  <?php echo $copy_vars['owners_rb_scholarship'] ?>
  <?php echo check_plain($reportback->caption) ?>
  <?php echo check_plain($user->first_name) ?>

  <h3>
  <?php echo $copy_vars['owners_rb_important'] ?>
 </h3>
  <?php echo check_plain($reportback->why_participated) ?>

  <?php echo check_plain($reportback->quantity) ?>&nbsp;
  <?php echo $reportback->quantity_label ?>



<?php endif ?>
