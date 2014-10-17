<div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes; ?>">

  <header role="banner" class="-hero <?php print $classes; ?>">
    <div class="wrapper">
      <h1 class="__title"><?php print $term->name; ?></h1>
      <?php if (isset($subtitle)): ?>
        <h2 class="__subtitle"><?php print $subtitle; ?></h2>
      <?php endif; ?>
    </div>
  </header>

  <?php if (isset($intro)): ?>
    <section class="container container--intro">
      <div class="wrapper">
        <?php print $intro; ?>
      </div>
    </section>
  <?php endif; ?>

  <?php if (!empty($campaign_gallery)): ?>
    <?php print $campaign_gallery; ?>
  <?php endif; ?>

</div>
