<?php

/**
 * Page template for search results.
 **/

?>

<?php if (!empty($tabs['#primary'])): ?><nav class="admin--tabs"><?php print render($tabs); ?></nav><?php endif; ?>
<?php print $messages; ?>

<div class="chrome--wrapper">
  <?php print $variables['navigation']; ?>
  <?php print $variables['header']; ?>

  <main role="main" class="container">
    <div class="wrapper">
      <?php if (!empty($noresults_copy)): ?>
        <h3><?php print $noresults_copy; ?></h3>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php if (!empty($recommended_campaigns_gallery)): ?>
        <?php print $recommended_campaigns_gallery; ?>
      <?php endif; ?>
    </div>
  </main>

  <?php print $variables['footer']; ?>
</div>

