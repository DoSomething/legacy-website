<?php
/**
 * @file
 * Reportback confirmation/permalink page when Rogue sending fails.
 *
 * Available variables:
 * - $node->title                        : Title of the campaign
 * - $is_owner                           : Used to determine if the curernt logged in user is the user who submitted the rb.
 * - $title                              : Title of the permalink/confirmation page.
 * - $subtitle                           : Subtitle of the permalink/confirmation page.
 * - $copy_vars['owners_rb_scholarship'] : Subtitle of the reportback confirmation page.
 * - $copy_vars['owners_rb_important']   : Title of the why I participated section
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

  <div class="container -padded -dark">
    <div class="wrapper">
      <div class="card">
        <div class="card__column">
          <?php print $fail_image; ?>
        </div>
        <div class="card__column">
          <div class="wrapper">
          <!--Show user the reportback confirmation page -->
            <div class="card__copy">
              <h1><?php print $node->title; ?></h1>
              <?php print $failure_copy; ?>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</article>
