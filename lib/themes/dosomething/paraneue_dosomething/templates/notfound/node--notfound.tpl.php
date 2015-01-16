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
  <header role="banner" class="-centered header-notfound">
    <div class="wrapper">
      <h1 class="__title"><?php print $title ?></h1>
      <div class="__subtitle"><?php print $subtitle ?></div>
    </div>
    <?php if (isset($video)): ?>
      <video src=<?php print $video ?> autoplay loop <?php if(isset($video_poster)){ echo "poster='",  $video_poster, "'"; } ?> ></video>
    <?php endif; ?>
  </header>

  <?php if ($disable_results == FALSE): ?>
    <div class="container -padded">
      <div class="wrapper">
        <div class="container__body -narrow">
          <?php if (isset($results_copy) && !empty($is_path_specific_page)): ?>
            <?php print $results_copy; ?>
          <?php elseif (isset($results_copy)): ?>
            <h3><?php print $results_copy; ?></h3>
          <?php endif; ?>

          <?php if (!empty($search_form)): ?>
            <?php print $search_form; ?>
          <?php endif; ?>
        </div>

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
