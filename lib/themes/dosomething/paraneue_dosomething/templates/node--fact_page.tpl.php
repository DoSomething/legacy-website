<section class="fact_page-wrapper">
  <article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="header-wrapper">
      <header class="header">
        <h1 class="title"><?php print $title; ?></h1>
        <?php if (isset($subtitle)): ?>
        <h3 class="subtitle"><?php print $subtitle; ?></h3>
        <?php endif; ?>
      </header>
    </div>

    <div class="intro-wrapper">
      <div class="intro">
        <?php if (isset($intro_title)): ?>
          <h2><?php print $intro_title; ?></h2>
        <?php endif; ?>
        <?php if (isset($intro)): ?>
          <div class="intro-content"><?php print $intro; ?></div>
        <?php endif; ?>
        <?php if (isset($intro_image)): ?>
          <?php print $intro_image; ?>
        <?php elseif (isset($intro_video)): ?>
          <?php print $intro_video; ?>
        <?php endif; ?>
      </div>
    </div>

    <?php if (isset($facts)): ?>
      <div class="facts-wrapper">
        <div class="facts">
          <?php foreach ($facts as $key => $fact): ?>
            <p class="fact">
              <?php print ($key + 1) . '. ' . $fact['fact']; ?>

              <?php // @TODO: Temporarily commented out until the new 'sources' solution in campaigns is implemented and we can use it here! ?>
              <?php //<sup></?php print $fact['footnotes']; ?/></sup> ?>
            </p>
          <?php endforeach; ?>
        </div>
      </div>
    <?php endif; ?>
  
    <?php // @TODO: Temporarily commented out until the new 'sources' solution in campaigns is implemented and we can use it here! ?>
    <?php
    // <?/php if (isset($sources)): ?/>
    //   <div class="sources-wrapper">
    //     <div class="sources">
    //       <h4>Sources</h4>
    //       <?/php foreach ($sources as $key => $source): ?/>
    //         <div class="source">
    //           <?/php // @TODO: Need <sup> to print within the $source's <p> tag. Source markup needs a rework. ?/>
    //           <sup><?/php print ($key + 1); ?/></sup><?/php print $source; ?/>
    //         </div>
    //       <?/php endforeach; ?/>
    //     </div>
    //   </div>
    // <?/php endif; ?/>
    ?>

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