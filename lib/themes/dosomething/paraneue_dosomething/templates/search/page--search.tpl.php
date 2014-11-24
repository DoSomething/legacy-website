<?php

/**
 * Generates site-wide page chrome.
 * @see https://drupal.org/node/1728148
 **/

?>

<?php if (!empty($tabs['#primary'])): ?><nav class="admin--tabs"><?php print render($tabs); ?></nav><?php endif; ?>
<?php print $messages; ?>

<div class="chrome--wrapper">
  <?php print $variables['navigation']; ?>
  <?php print $variables['header']; ?>

  <main role="main" class="container">
    <div class="wrapper">
      <?php print render($page['content']); ?>
    </div>
  </main>

  <?php print $variables['footer']; ?>
</div>

