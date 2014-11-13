<?php
/**
 * Returns the HTML for a 404 page.
 *
 * Available Variables
 * - $header: The page header (string).
 * - $subtitle: The page subtitle (string).
 * - $results: List of results to display (array).
 * - $search: Indicate if results is a search (boolean).
 * - $suggestions: Indicate if results is a recomendation (boolean).
 * - $results_info: Quick description about the results shown (string).
 */
?>
<article>
  <header role="banner" class="-centered notfound">
    <div class="wrapper">
      <h1 class="__title"><?php print $title ?></h1>
      <?php print $subtitle ?>
    </div>
    <?php if (isset($video)): ?>
      <video src=<?php print $video ?> autoplay="" loop=""></video>
    <?php endif; ?>
  </header>

  <?php if ($search == TRUE || $suggestions == TRUE): ?>
    <div class="container notfound-search-results">
      <div class="wrapper">
        <?php if (isset($results_info)): ?>
          <p class="results-info-copy"><?php print $results_info ?></p>
        <?php endif; ?>
        <?php if (!empty($search_form)): ?>
          <?php print $search_form; ?>
        <?php endif; ?>
        <?php if ($suggestions){ print $results; }?>
        <?php if ($search): ?>
          <?php print $search_results_gallery; ?>
        <?php endif; ?>
      </div>
    </div>
  <?php endif; ?>

</article>
