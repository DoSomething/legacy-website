<?php
/**
 * @file
 * Reportback confirmation/permalink page.
 *
 * Available variables:
 * - $rb_image                           : Reportback image.
 * - $node->title                        : Title of the campaign
 * - $is_owner                           : Used to determine if the curernt logged in user is the user who submitted the rb.
 * - $title                              : Title of the permalink/confirmation page.
 * - $subtitle                           : Subtitle of the permalin/confirmation page.
 * - $copy_vars['owners_rb_scholarship'] : Subtitle of the reportback confirmation page.
 * - $copy_vars['owners_rb_important']   : Title of the why I participated section
 * - $reportback->why_participated       : Why I participated copy of the reportback
 * - $reportback->quantity               : Reportback quanitity
 * - $reportback->quantity_label         : Quantity lable
 * - $reportback->caption                : Caption associated with the image.
 * - $user->first_name                   : User's first name
 * - $node->fact_problem['fact']
 * - $node->fact_solution['fact']
 *
 */
?>

<article class="reportback__permalink">
  <header role="banner" class="header ">
    <div class="wrapper">
      <h1 class="header__title"><?php print $title; ?></h1>
      <p class="header__subtitle"><?php print $subtitle; ?></p>
    </div>
  </header>

  <div class="container -padded -purple">
    <div class="wrapper">
      <div class="card">
        <div class="card__column">
          <?php print $rb['image']; ?>
          <?php if ($rb['caption']): ?>
            <div class="caption">
              <?php print $rb['caption']; ?> - <?php print $user->first_name; ?>
            </div>
          <?php endif; ?>
        </div>
        <div class="card__column -right">
          <!--Show user the reportback confirmation page -->
          <?php if ($is_owner): ?>
            <div class="card__copy">
              <h1><?php print $node->title; ?></h1>
              <p class="heading -gamma"><?php print $reportback->quantity; ?> <?php print $reportback->quantity_label; ?></p>
  
              <h3><?php print $copy_vars['owners_rb_important']; ?></h3>
              <p><?php print $reportback->why_participated; ?></p>
            </div>
          <!--Show non-owner the call to action page -->
          <?php else: ?>
            <div class="card__copy">
              <p class="heading -alpha"><?php print $node->title; ?></p>

              <h3><?php print t('The Problem'); ?></h3>
              <p><?php print $node->fact_problem['fact']; ?></p>

              <h3><?php print t('The Solution'); ?></h3>
              <p><?php print $node->fact_solution['fact']; ?></p>
            </div>
            <div class="cta">
              <div class="wrapper">
                <p class="cta__message"><?php print $node->call_to_action; ?></p>
                <a href="<?php print $link ?>" class="button">do it</a>
              </div>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  </div>
</article>
