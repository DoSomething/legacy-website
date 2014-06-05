<?php
/**
 * Returns the HTML for the Fact page.
 *
 * Available Variables
 * - $nid: Node ID for fact page (integer).
 * - $classes: Additional classes passed for output (string).
 * - $title: Title of fact page (string).
 * - $subtitle: Subtitle of fact page (string).
 * - $intro_title: Introductory title of fact page (string).
 * - $facts: Array of facts for the fact page (array).
 * - $sources: List of sources for the fact page (string).
 * - $cta_link: Call To Action link of fact page (string).
 */
?>

<section class="fact_page-wrapper">
  <article id="node-<?php print $node->nid; ?>" class="fact fact-page <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <header role="banner" class="-basic">
      <div class="wrapper">
        <h1 class="__title"><?php print $title; ?></h1>
        <?php if (isset($subtitle)): ?>
        <h2 class="__subtitle"><?php print $subtitle; ?></h2>
        <?php endif; ?>
      </div>
    </header>

    <?php if (isset($intro)): ?>
      <section class="container intro">
        <div class="wrapper">
          <?php if (isset($intro_title)): ?>
            <h2 class="container__title inline--alt-color"><?php print $intro_title; ?></h2>
          <?php endif; ?>
        </div>
      </section>
    <?php endif; ?>

    <?php if (isset($facts)): ?>
      <section class="container container--fact">

        <div class="wrapper">

          <div class="container__body">

            <?php if (isset($intro_image)): ?>
              <aside class="media -inline">
                 <?php print $intro_image; ?>
              </aside>
            <?php endif; ?>

            <ol>
              <?php foreach ($facts as $key => $fact): ?>
                <li><?php print ($key + 1) . '. ' . $fact['fact']; ?>
                  <?php // @TODO: Sources reinstated, but not sure if the facts need to have numbers associated with their respective source? Need to clarify. ?>
                  <?php //<sup></?php print $fact['footnotes']; ?/></sup> ?>
                </li>
              <?php endforeach; ?>
            </ol>            

          </div>

          <?php if (isset($sources)): ?>
            <section class="sources">
              <h3 class="__title  js-toggle-sources">Sources</h3>
              <div class="__body legal">
                <?php print $sources; ?>
              </div>
            </section>
          <?php endif; ?>
        </div>

      </section>

      <?php if (isset($call_to_action)): ?>
        <div class="cta">
          <div class="wrapper">
            <h2 class="__message"><?php print $call_to_action; ?></h2>
            <?php print $cta_link; ?>
          </div>
        </div>
      <?php endif; ?>
      
    <?php endif; ?>

  </article>
</section>
