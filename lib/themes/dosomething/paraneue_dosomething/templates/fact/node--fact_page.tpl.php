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
    <section class="container">
      <div class="wrapper">
        <div class="container__body -narrow">
          <?php print $intro; ?>
        </div>
      </div>
    </section>
  <?php endif; ?>

  <?php if (isset($facts_chunked)): ?>
    <?php foreach ($facts_chunked as $key_chunk => $fact_chunk): ?>
      <?php
        $start_value = (($key_chunk * 5) + 1); // Start value for list of facts
        $is_first = ($start_value === 1); // First set of facts
        $is_last = ($key_chunk === (sizeof($facts_chunked) - 1)); // Last set of facts
      ?>

      <section class="container container--fact">
        <div class="wrapper">
          <div class="container__body">

            <?php if (isset($intro_image) && $is_first): ?>
              <aside class="fact-aside">
                <?php print $intro_image; ?>
              </aside>
            <?php endif; ?>

            <ol start="<?php print $start_value; ?>">
              <?php foreach ($fact_chunk as $key => $fact): ?>
                <li><?php print $fact['fact']; ?></li>
              <?php endforeach; ?>
            </ol>

            <?php if (isset($sources) && $is_last): ?>
              <section class="sources">
                <h3 class="__title js-toggle-sources"><?php print t('Sources'); ?></h3>
                <ul class="__body legal">
                  <?php foreach ($sources as $key => $source): ?>
                    <li><sup><?php print ($key + 1); ?></sup> <?php print $source; ?></li>
                  <?php endforeach; ?>
                </ul>
              </section>
            <?php endif; ?>

          </div>
        </div>
      </section>

      <?php if (isset($call_to_action) && $is_first): ?>
      <div class="cta">
        <div class="wrapper">
          <h2 class="cta__message"><?php print $call_to_action; ?></h2>
          <?php print $cta_link; ?>
        </div>
      </div>
      <?php endif; ?>

    <?php endforeach; ?>
  <?php endif; ?>

  <?php if (isset($call_to_action)): ?>
    <div class="cta">
      <div class="wrapper">
        <h2 class="cta__message"><?php print $call_to_action; ?></h2>
        <?php print $cta_link; ?>
      </div>
    </div>
  <?php endif; ?>

</article>
