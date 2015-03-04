<?php
/**
 * @file
 * Reportback confirmation/permalink page.
 *
 * Available variables:
 * - $node->title : Title of the campaign
 * - $is_current  : Used to determine if the curernt logged in user is the user who submitted the rb.
 * - $node->fact_problem['fact']
 * - $node->fact_solution['fact']
 * - $rb_image
 * - $copy_vars['owners_rb_subtitle']
 * - $copy_vars['owners_rb_scholarship']
 * - $reportback->caption
 * - $user->first_name
 * - $copy_vars['owners_rb_important']
 * - $reportback->why_participated
 * - $reportback->quantity
 * - $reportback->quantity_label
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>

<div class="container">
  <div class="container__block -half">
    <div><?php print $rb_image ?></div>
    <!-- <div class="caption"><?php print check_plain($reportback->caption) ?></div> -->
    <div class="caption">Squad up to stomp down bullying - Leah</div>
  </div>
  <div class="container__block -half">
    <div class="reportback-info-block">
      <h1><?php print $node->title ?></h1>
      <h3><?php print check_plain($reportback->quantity) ?> <?php print $reportback->quantity_label ?></h3>
    </div>
    <div class="reportback-info-block">
      <h2><?php print $copy_vars['owners_rb_important'] ?></h2>
      <p><?php print check_plain($reportback->why_participated) ?></p>
    </div>
  </div>
</div>

<!-- <h2> <?php echo $node->title ?> </h2>

<?php if (!$is_current): ?>
  <?php echo $node->call_to_action ?>

  <h3> <?php t('The Problem') ?> </h3>
  <?php echo $node->fact_problem['fact'] ?>

  <h3> <?php t('The Solution') ?> </h3>
  <?php echo $node->fact_solution['fact'] ?>

<?php endif ?>

<?php echo $rb_image ?>

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



<?php endif ?> -->
