<?php
/**
 * @file
 * Reportback confirmation/permalink page when Rogue sending fails.
 *
 * Available variables:
 * - $node->title                        : Title of the campaign
 * - $fail_image                         : Image to use in place of reportback photo
 * - $title                              : Title of the permalink/confirmation page.
 * - $subtitle                           : Subtitle of the permalink/confirmation page.
 * - $failure_copy                       : Text to use next to the image (in place of the user's Why Participated)
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
