<?php
/**
 * Snippet for displaying a Campaign's creator property, which is an array.
 *
 * For available variables:
 * @see dosomething_campaign_load().
 */

dpm($variables);
?>

<<<<<<< HEAD
<a href="#" data-modal-href="#modal-creator">
  <?php print t('Created by:'); ?> <img src="<?php print $picture['src']; ?>" />
</a>
=======
<div class="promotion promotion--creator">
  <a href="#" data-modal-href="#modal--promotion--creator">
    <p class="__copy">Created by</p>
    <img src="<?php print $picture['src_square']; ?>" />
  </a>

  <div data-modal id="modal--promotion--creator" class="modal--promotion--creator" role="dialog">
    <a href="#" class="js-close-modal modal-close-button white">×</a>
    <h2 class="banner">The Creator</h2>
    <img src="<?php print $picture['src_square']; ?>" />
    <div class="wrapper">
      <h4><?php print $first_name; ?> <?php print $last_initial; ?></h4>
      <p><?php print $city; ?>, <?php print $state; ?></p>
      <div class="copy"><?php print $copy; ?></div>
      <a href="#" class="js-close-modal">Back to main page</a>
    </div>
  </div>
</div>



<?php /*
<ul class="modal-links">
      <li><a href="#" data-modal-href="#modal-faq">Check out our FAQs</a></li>

      <li><a href="#" data-modal-href="#modal-facts">Learn more about </a></li>
>>>>>>> Initial work on campaign creator faming.

  </ul>

<div data-modal id="modal-faq" role="dialog">
  <a href="#" class="js-close-modal modal-close-button white">×</a>
<<<<<<< HEAD
  <h2 class="banner"><?php print t('The Creator'); ?></h2>
  <img src="<?php print $picture['src']; ?>" />
  <h4><?php print $first_name; ?> <?php print $last_initial; ?></h4>
  <p><?php print $city; ?>, <?php print $state; ?></p>
  <div class="copy"><?php print $copy; ?></div>
  <a href="#" class="js-close-modal"><?php print t('Back to main page'); ?></a>
=======
  <h2 class="banner">FAQs</h2>
      <h4 class="faq-header">What is the question?</h4>
    <div class="faq-copy"><p>What was the answer.
* I dunno
* Is markdown printing?</p>
</div>
      <h4 class="faq-header">Hey let's try a link</h4>
    <div class="faq-copy"><p>Ok let's see how <a href="http://www.google.com">Google</a> works.</p>
</div>
    <a href="#" class="js-close-modal">Back to main page</a>
</div>

<div data-modal id="modal-facts" role="dialog">
  <a href="#" class="js-close-modal modal-close-button white">×</a>
  <h2 class="banner">Facts</h2>
  <ul>
      <li>Showing your school board that music programs are important will apply pressure on them to maintain funding for the programs you love.<sup></sup></li>
      <li>Students at risk of not successfully completing their high school educations cite their participation in the arts as reasons for staying in school.<sup>1</sup></li>
      <li>Every year, 1 in every 3 senior adults falls, which is the leading cause of fatal and nonfatal injuries among that age group.<sup>2 3</sup></li>
    </ul>

  <section class="sources">
    <h3 class="__title js-toggle-sources">Sources</h3>
    <ul class="__body legal">
          <li><sup>1</sup> <p>Barry, N., J. Taylor, K. Walls, "The Role of the Fine and Performing Arts in High School Dropout Prevention", Center for Music Research, 2002. Web Accessed February 2014.</p>
</li>
          <li><sup>2</sup> <p>Tromp AM, Pluijm SMF, Smit JH, et al. Fall-risk screening test: a prospective study on predictors for falls in community-dwelling elderly. J Clin Epidemiol 2001;54(8):837–844.</p>
</li>
          <li><sup>3</sup> <p>Centers for Disease Control and Prevention, National Center for Injury Prevention and Control. Web–based Injury Statistics Query and Reporting System (WISQARS) [online]. Accessed August 15, 2013.</p>
</li>
        </ul>
  </section>
  <a href="#" class="js-close-modal">Back to main page</a>
>>>>>>> Initial work on campaign creator faming.
</div>
*/ ?>
