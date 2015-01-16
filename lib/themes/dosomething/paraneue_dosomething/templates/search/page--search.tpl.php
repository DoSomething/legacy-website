<?php

/**
 * Page template for search results.
 **/

?>

<!--[if lt IE 8 ]><div class="messages error">You're using an unsupported browser. Please <a href="http://browsehappy.com/">upgrade your browser</a> to make sure everything works nicely!</div><![endif]-->

<?php if (!empty($tabs['#primary'])): ?><nav class="admin-tabs"><?php print render($tabs); ?></nav><?php endif; ?>
<?php print $messages; ?>

<div class="wrapper">
  <?php print $variables['navigation']; ?>
  <?php print $variables['header']; ?>

  <main role="main" class="container -padded">
    <div class="wrapper">
      <?php if (!empty($noresults_copy)): ?>
        <div class="container__body">
          <h3><?php print $noresults_copy; ?></h3>
        </div>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php if (!empty($recommended_campaigns_gallery)): ?>
        <?php print $recommended_campaigns_gallery; ?>
      <?php endif; ?>
    </div>
  </main>

  <?php print $variables['footer']; ?>
</div>
