<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="modal__block">
    <h2><?php print $title; ?></h2>
  </div>

  <div class="modal__block">
    <?php if (isset($subtitle)): ?>
      <h3 class="subtitle"><?php print $subtitle; ?></h3>
    <?php endif; ?>

    <?php if (isset($intro_title)): ?>
      <h2><?php print $intro_title; ?></h2>
    <?php endif; ?>

    <?php if (isset($intro)): ?>
      <div><?php print $intro['safe_value']; ?></div>
    <?php endif; ?>
  </div>

  <?php if (!empty($intro_image)): ?>
    <div class="modal__block">
      <?php print $intro_image; ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($galleries)): ?>
    <div class="modal__block">
      <?php foreach ($galleries as $gallery): ?>
        <?php print $gallery['image']; ?>
        <?php if ($gallery['image_title']): ?>
          <h3><?php print $gallery['image_title']; ?></h3>
        <?php endif; ?>
        <?php if ($gallery['image_description']): ?>
          <p><?php print $gallery['image_description']; ?></p>
        <?php endif; ?>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>

  <?php if (isset($additional_text_title) || isset($additional_text)): ?>
    <div class="modal__block">
      <?php if (isset($additional_text_title)): ?>
        <h2><?php print $additional_text_title; ?></h2>
      <?php endif; ?>

      <?php if (isset($additional_text)): ?>
        <?php print $additional_text['safe_value']; ?>
      <?php endif; ?>
    </div>
  <?php endif; ?>

</article>
