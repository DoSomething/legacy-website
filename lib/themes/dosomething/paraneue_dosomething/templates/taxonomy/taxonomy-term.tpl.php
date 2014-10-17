<div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes; ?>">

  <div class="content">
    <?php print render($content); ?>
    <?php if (!empty($campaign_gallery)): ?>
      <?php print $campaign_gallery; ?>
    <?php endif; ?>
  </div>

</div>
