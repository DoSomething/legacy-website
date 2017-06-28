<?php
/**
 * @file
 * Reportback confirmation/permalink page for Rogue.
 */
?>
<article class="reportback__permalink">
  <header role="banner" class="header ">
    <div class="wrapper">
      <h1 class="header__title">Awesome! We got your photo.</h1>
      <p class="header__subtitle">You've entered into the scholarship and your photo will show up in the gallery soon!</p>
    </div>
  </header>

  <div class="container -padded -dark">
    <div class="wrapper">
      <div class="card">
        <div class="card__column">
          <?php print $image; ?>
        </div>
        <div class="card__column">
          <div class="wrapper">
          <!--Show user the reportback confirmation page -->
            <div class="card__copy">
              <h1>What's next?</h1>
              <p>The fun doesn't have to stop now. You can upload more photos, continue working on the campaign, or share it with your friends on social media.</p>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</article>
