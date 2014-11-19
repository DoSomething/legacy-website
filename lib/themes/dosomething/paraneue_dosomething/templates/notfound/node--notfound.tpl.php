<?php
/**
 * Returns the HTML for a 404 page.
 *
 * Available Variables
 * - $header: The page header (string).
 * - $subtitle: The page subtitle (string).
 * - $campaign_results: List of campaign recommends (array).
 * - $search_results: List of search results (array).
 * - $results_info: Quick description about the results shown (string).
 * - $disable_results: Indicates if there should be something below header (bool).
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

  <?php if ($disable_results == FALSE): ?>
    <div class="container notfound-search-results <?php if (!empty($notfound_page_type)) { print $notfound_page_type; } ?>">
      <div class="wrapper notfound-results">
        <?php if (isset($results_copy)): ?>
          <h3 class="search-results-header">
            <?php print $results_copy; ?>
          </h3>
        <?php endif; ?>
        <?php if (!empty($search_form)): ?>
          <?php print $search_form; ?>
        <?php endif; ?>
        <?php if (!empty($suggestions_header)): ?>
          <h3 class="search-results-header">
            <?php print $suggestions_header; ?>
          </h3>
        <?php endif; ?>
        <?php if (isset($campaign_results)): ?>
          <?php print $campaign_results; ?>
        <?php endif; ?>
        <?php if (isset($search_results)): ?>
          <?php print $search_results; ?>
        <?php endif; ?>
      </div>
    </div>
  <?php endif; ?>

</article>
