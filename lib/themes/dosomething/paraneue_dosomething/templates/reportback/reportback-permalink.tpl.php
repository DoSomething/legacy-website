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
<article class="reportback__permalink">
  <header role="banner" class="header ">
    <div class="wrapper">
      <h1 class="header__title"><?php print check_plain($copy_vars['owners_title']); ?></h1>
      <p class="header__subtitle"><?php print check_plain($copy_vars['owners_rb_subtitle']); ?></p>
    </div>
  </header>

  <div class="container -padded -purple">
    <div class="wrapper">
      <div class="container -white">
        <div class="container__block -half">
          <div><?php print $rb_image ?></div>
          <!-- <div class="caption"><?php print check_plain($reportback->caption) ?></div> -->
          <div class="caption">Squad up to stomp down bullying - Leah</div>
        </div>
        <div class="container__block -half">
          <h1><?php print $node->title ?></h1>
          <p class="heading -gamma"><?php print check_plain($reportback->quantity) ?> <?php print $reportback->quantity_label ?></p>
          <h2><?php print $copy_vars['owners_rb_important'] ?></h2>
          <p><?php print check_plain($reportback->why_participated) ?></p>
        </div>
      </div>
    </div>
  </div>
</article>
