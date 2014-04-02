<?php

/**
 * Generates site-wide page chrome.
 * @see https://drupal.org/node/1728148
 **/

?>

<?php if (!empty($tabs['#primary'])): ?><nav class="admin--tabs"><?php print render($tabs); ?></nav><?php endif; ?>
<?php print $messages; ?>

<main class="wrapper">
  <?php print $variables['navigation']; ?>

  <?php print render($page['content']); ?>
</main>

<?php print $variables['footer']; ?>
