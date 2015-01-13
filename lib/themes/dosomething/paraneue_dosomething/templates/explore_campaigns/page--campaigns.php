<?php

/**
 * Generates minimal site-wide page chrome.
 * @see https://drupal.org/node/1728148
 **/

?>

<div class="wrapper">
  <?php print $variables['navigation']; ?>
  <?php print $variables['header']; ?>

  <main role="main">
    <?php print render($page['content']); ?>
  </main>

  <?php print $variables['footer']; ?>
</div>

