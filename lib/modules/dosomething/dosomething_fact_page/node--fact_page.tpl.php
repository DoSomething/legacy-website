<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>

  <div>
    <h1><?php print $title; ?></h1>
    <?php if (isset($hero_image)): ?>
      <?php print $hero_image; ?>
    <?php endif; ?>
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
  <br/>
  <?php if (isset($facts)): ?>
    <?php foreach ($facts as $key => $fact): ?>
      <?php print '#' . ($key + 1) . ' ' . $fact['fact']; ?>
      <?php if (is_array($fact['sources'])): ?>
        <?php foreach ($fact['sources'] as $source): ?>
          <p class="legal">Source: <?php print $source; ?></p>
        <?php endforeach; ?>
      <?php elseif (isset($fact['source'])): ?>
         <p class="legal">Source: <?php print $fact['source']; ?></p>
      <?php endif; ?>
    <?php endforeach; ?>
  <?php endif; ?>

  <?php if (isset($call_to_action)): ?>
    <div class="cta">
      <h2><?php print $call_to_action; ?></h2>
      <div class="cta_button"><?php print $cta_link; ?></div>
    </div>
  <?php endif; ?>
</article>