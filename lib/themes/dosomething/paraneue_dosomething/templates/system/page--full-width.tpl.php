<?php

/**
 * Generates minimal site-wide page chrome.
 * @see https://drupal.org/node/1728148
 **/

?>

<!--[if lt IE 8 ]><div class="messages error">You're using an unsupported browser. Please <a href="http://browsehappy.com/">upgrade your browser</a> to make sure everything works nicely!</div><![endif]-->

<?php if (!empty($tabs['#primary'])): ?><nav class="admin-tabs"><?php print render($tabs); ?></nav><?php endif; ?>
<?php print $messages; ?>

<div class="wrapper">
  <?php print $variables['navigation']; ?>
  <?php if(isset($variables['header'])) print $variables['header']; ?>

  <main role="main">
    <?php print render($page['content']); ?>
  </main>

  <?php print $variables['footer']; ?>
</div>
