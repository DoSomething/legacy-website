
<section class="fact_page-wrapper">
  <article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="header-wrapper">
      <header class="header">
        <h1 class="title"><?php print $title; ?></h1>
        <?php if (isset($subtitle)): ?>
        <h2 class="subtitle"><?php print $subtitle; ?></h2>
        <?php endif; ?>
      </header>
    </div>


    <?php if (isset($intro)): ?>
      <div class="intro-wrapper">
        <div class="intro">
          <?php if (isset($intro_title)): ?>
            <h2><?php print $intro_title; ?></h2>
          <?php endif; ?>
          <div class="intro-content"><?php print $intro; ?></div>
        </div>
      </div>
    <?php endif; ?>


    <?php if (isset($facts)): ?>
      <div class="facts-wrapper">
        <div class="facts">
          <?php if (isset($intro_image)): ?>
            <aside class="media-wrapper">
              <div class="media">
                <?php print $intro_image; ?>
              </div>
            </aside>
          <?php endif; ?>

          <?php foreach ($facts as $key => $fact): ?>
            <p class="fact">
              <?php print ($key + 1) . '. ' . $fact['fact']; ?>

              <?php // @TODO: Sources reinstated, but not sure if the facts need to have numbers associated with their respective source? Need to clarify. ?>
              <?php //<sup></?php print $fact['footnotes']; ?/></sup> ?>
            </p>
          <?php endforeach; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if (isset($sources)): ?>
      <div class="sources-wrapper">
        <div class="sources">
          <h4>Sources</h4>
          <?php print $sources; ?>
         </div>
      </div>
    <?php endif; ?>

    <?php if (isset($call_to_action)): ?>
      <div class="cta-wrapper">
        <div class="cta">
          <h3><?php print $call_to_action; ?></h3>
          <div class="cta_button"><?php print $cta_link; ?></div>
        </div>
      </div>
    <?php endif; ?>
  </article>
</section>
