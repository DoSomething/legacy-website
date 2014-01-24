<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>

  <div>
    <h1><?php print $title; ?></h1>
    <?php print $hero_image; ?>
    <?php if ($subtitle): ?>
      <h2><?php print $subtitle; ?></h2>
    <?php endif; ?>
  </div>
  <h2><?php print $intro_title; ?></h2>
  <div class="left"><?php print $intro; ?></div>
  <?php print $intro_image; ?>
  <div class="cta">
    <h2><?php print $cta; ?></h2>
    <div class="cta_button btn"><?php print $cta_button; ?></div>
  </div>
 <br/>
  <?php foreach ($galleries as $gallery): ?>
    <?php print $gallery['image']; ?>
    <h3><?php print $gallery['image_title']; ?></h3>
    <p><?php print $gallery['image_description']; ?></p>
  <?php endforeach; ?>

  
  <h2><?php print $additional_text_title; ?></h2>
  <p><?php print $additional_text; ?></p>

  <div class="cta">
    <h2><?php print $cta; ?></h2>
    <div class="cta_button btn"><?php print $cta_button; ?></div>
  </div>

</article>
