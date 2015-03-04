<?php
/**
 * @file
 * Reportback confirmation/permalink page.
 *
 * Available variables:
 * - $rb_image    : Reportback image.
 * - $node->title : Title of the campaign
 * - $is_current  : Used to determine if the curernt logged in user is the user who submitted the rb.
 * - $copy_vars['owners_rb_subtitle']    : Title of the reportback confirmation page
 * - $copy_vars['owners_rb_scholarship'] : Subtitle of the reportback confirmation page.
 * - $copy_vars['owners_rb_important']   : Title of the why I participated section
 * - $reportback->why_participated       : Why I participated copy of the reportback
 * - $reportback->quantity               : Reportback quanitity
 * - $reportback->quantity_label         : Quantity lable
 * - $node->fact_problem['fact']
 * - $node->fact_solution['fact']
 * - $reportback->caption
 * - $user->first_name
 *
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
        <div class="container__block -half -border">
          <?php print $rb_image ?>
          <div class="caption"><?php print check_plain($reportback->caption) ?></div>
        </div>
        <div class="container__block -half">
          <h1><?php print $node->title ?></h1>
          <p class="heading -gamma"><?php print check_plain($reportback->quantity) ?> <?php print $reportback->quantity_label ?></p>
          <h3><?php print $copy_vars['owners_rb_important'] ?></h3>
          <p><?php print check_plain($reportback->why_participated) ?></p>
        </div>
      </div>
    </div>
  </div>
</article>
