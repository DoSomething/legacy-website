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
  <?php if (isset($intro_image)): ?>
    <?php print $intro_image; ?>
  <?php elseif ($intro_video): ?>
    <?php print $intro_video; ?>
  <?php endif; ?>
  <?php if (isset($call_to_action)): ?>
    <div class="cta">
      <h2><?php print $call_to_action; ?></h2>
      <div class="cta_button"><?php print $cta_link; ?></div>
    </div>
  <?php endif; ?>
 <br/>
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
    <p><?php print $additional_text; ?></p>
  <?php endif; ?>
  
  <?php if (isset($call_to_action)): ?>
    <div class="cta">
      <h2><?php print $call_to_action; ?></h2>
      <div class="cta_button"><?php print $cta_link; ?></div>
    </div>
  <?php endif; ?>
</article>
