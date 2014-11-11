<?php
/**
 * Returns the HTML for a 404 page.
 *
 * Available Variables
 * - $header: The page header (string).
 * - $subtitle: The page subtitle (string). 
 * - $results: List of related results to display (array).
 * - $search: Indicate if this is specific content or search (boolean).
 * PLANNED
 * - $results_info: Quick description about the results shown (string).
 */
?>
<article>

  <header role="banner" class="-centered notfound">
    <div class="wrapper">
      <h1 class="__title"><?php print $title ?></h1>    
      <?php print $subtitle ?>
    </div>
    <video src=<?php print $video ?> autoplay="" loop=""></video>
  </header>

  <?php if (isset($results)): ?>
    <div class="container notfound-search-results">
      <div class="wrapper">
        <?php if (isset($results_info)): ?>
          <p class="center-text"><strong><?php print $results_info ?></strong></p>
        <?php endif; ?>
        <?php if ($search): ?>

        <?php endif; ?>
      </div>
    </div>
  <?php endif; ?>

</article>
