<?php

/**
 * Generates site-wide page chrome.
 * @see https://drupal.org/node/1728148
 **/

?>

<?php print $variables['navigation']; ?>
<?php print $variables['header']; ?>

<main role="main" class="container">
  <div class="wrapper">
    <?php print render($page['content']); ?>
  </div>
</main>

<?php print $variables['footer']; ?>
