<h1>THIS IS THE MODULE TEMPLATE</h1>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      //print render($content);
    ?>
  </div>

  <div>
    <h1><?php print $title; ?></h1>
    <?php if ($subtitle): ?>
      <h2><?php print $subtitle; ?></h2>
    <?php endif; ?>
  </div>



</article>
