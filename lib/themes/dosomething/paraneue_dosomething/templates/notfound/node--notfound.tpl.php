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
          <p class="center-text"><strong><?php print $results_info ?></strong></p>
        <?php endif; ?>
        <?php if ($suggestions): ?>
          <!-- Suggestions go here -->
        <?php endif; ?>
        <?php if ($search): ?>
          <!-- TEMP solution for debugging, actual will be implemented later -->
          <?php
            foreach ($results as $result) {
              print $result['title'];
              print '<br>';
            }
          ?>
        <?php endif; ?>
      </div>
    </div>
  <?php endif; ?>

</article>
