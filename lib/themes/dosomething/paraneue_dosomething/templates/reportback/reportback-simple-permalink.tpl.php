<?php
/**
 * @file
 * Reportback confirmation/permalink page for Rogue.
 */
?>
<article class="reportback__permalink">
  <header role="banner" class="header ">
    <div class="wrapper">
      <h1 class="header__title">Thanks for proving your impact!</h1>
      <p class="header__subtitle">A DoSomething staffer will review your photo shortly. Hang tight!</p>
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
              <p>Once a staffer approves your photo, it’ll appear in the gallery in the Prove It section of the campaign page. Remember, you can continue working on the campaign and update your photo and impact # as many times as you want. Let’s Do This!</p>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</article>
