<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <h2 class="heading -banner"><?php print $title; ?></h2>

  <?php if (isset($subtitle)): ?>
    <h3 class="subtitle"><?php print $subtitle; ?></h3>
  <?php endif; ?>

  <?php if (isset($intro_title)): ?>
    <h2><?php print $intro_title; ?></h2>
  <?php endif; ?>

  <?php if (isset($intro)): ?>
    <div><?php print $intro['safe_value']; ?></div>
  <?php endif; ?>

  <?php if (isset($intro_image)): ?>
    <?php print $intro_image; ?>
  <?php endif; ?>

  <?php if (isset($galleries)): ?>
    <?php foreach ($galleries as $gallery): ?>
      <?php print $gallery['image']; ?>
      <?php if ($gallery['image_title']): ?>
        <h3><?php print $gallery['image_title']; ?></h3>
      <?php endif; ?>
      <?php if ($gallery['image_description']): ?>
        <p><?php print $gallery['image_description']; ?></p>
      <?php endif; ?>
    <?php endforeach; ?>
  <?php endif; ?>

  <?php if (isset($additional_text_title)): ?>
    <h2><?php print $additional_text_title; ?></h2>
  <?php endif; ?>

  <?php if (isset($additional_text)): ?>
    <?php print $additional_text['safe_value']; ?>
  <?php endif; ?>

</article>
