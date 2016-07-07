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
 * - $kudos                              : Kudos data
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

  <div class="container -padded -dark">
    <div class="wrapper">
      <div class="card">
        <div class="card__column">
          <?php print $rb['image']; ?>
          <?php if ($rb['caption']): ?>
            <div class="caption">
              <?php print filter_xss($rb['caption']); ?> - <?php print check_plain($user->first_name); ?>
            </div>
          <?php endif; ?>
          <?php if (isset($kudos) && isset($kudos['fid'])): ?>
            <ul class="form-actions -inline kudos" <?php print $kudos['fid'] ? 'data-reportback-item-id="' . $kudos['fid'] . '"' : ''; ?>>
              <li>
                <button class="js-kudos-button kudos__icon <?php print dosomething_kudos_term_is_selected($kudos, 'heart') ? 'is-active' : '' ?>" data-kudos-term-id="<?php print $kudos['allowed_reactions'][0]; ?>" data-kid="<?php print dosomething_helpers_isset($kudos['existing_kids'][$kudos['allowed_reactions'][0]], 'kid') ?>"></button>
                <span class="counter"><?php print $kudos['reaction_totals']['heart']; ?></span>
              </li>
            </ul>
          <?php endif; ?>
        </div>
        <div class="card__column">
          <div class="wrapper">
          <!--Show user the reportback confirmation page -->
          <?php if ($is_owner): ?>
            <?php if ($share_enabled): ?>
              <div class="cta">
                <div class="cta__block">
                  <p class="cta__message"><?php print $copy_vars['owners_rb_social_cta']; ?></p>
                </div>
                <?php print $share_bar; ?>
              </div>
            <?php endif; ?>
            <div class="card__copy">
              <h1><?php print $node->title; ?></h1>
              <p class="heading -gamma"><?php print $reportback->quantity; ?> <?php print $reportback->quantity_label; ?></p>

              <h3><?php print $copy_vars['owners_rb_important']; ?></h3>

              <?php if ($why_participated_short): ?>
                <p class="participate is-shown"><?php print filter_xss($why_participated_short); ?></p>
                <p class="participate"><?php print filter_xss($reportback->why_participated); ?></p>
                <p><a href="#" class="js-permalink-show-more secondary">Show More</a></p>
              <?php else: ?>
                <p><?php print filter_xss($reportback->why_participated); ?></p>
              <?php endif; ?>
            </div>
          <!--Show non-owner the call to action page -->
          <?php else: ?>
            <div class="cta">
              <div class="wrapper">
                <?php if ($node->secondary_call_to_action && $node->status == 'active'): ?>
                  <p class="cta__message"><?php print $node->secondary_call_to_action; ?></p>
                <?php elseif ($node->status == 'closed'): ?>
                  <p class="cta__message"><?php print $copy_vars['non_owners_closed_cta']; ?></p>
                <?php endif; ?>
                <?php print render($signup_button); ?>
              </div>
            </div>
            <div class="card__copy">
              <p class="heading -alpha"><?php print $node->title; ?></p>

              <?php if ($node->fact_problem['fact']): ?>
                <h3><?php print t('The Problem'); ?></h3>
                <p><?php print $node->fact_problem['fact']; ?></p>
              <?php endif; ?>

              <h3><?php print t('The Solution'); ?></h3>
              <?php if ($node->fact_solution['fact']): ?>
                <p><?php print $node->fact_solution['fact']; ?></p>
              <?php elseif ($node->solution_copy): ?>
                <?php print $node->solution_copy; ?>
              <?php endif; ?>
            </div>
          <?php endif; ?>
          </div>
        </div>
      </div>
    </div>
  </div>
</article>
