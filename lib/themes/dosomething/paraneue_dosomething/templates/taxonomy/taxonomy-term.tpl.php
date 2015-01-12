<div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes; ?>">

  <header role="banner" class="-hero <?php print $classes; ?>">
    <div class="wrapper">
      <h1 class="__title"><?php print $title ?></h1>
      <?php if (isset($subtitle)): ?>
        <h2 class="__subtitle"><?php print $subtitle; ?></h2>
      <?php endif; ?>
    <?php if (!empty($sponsor_logos)): ?>
      <div class="promotions"><?php print $sponsor_logos; ?></div>
    <?php endif; ?>
    </div>
  </header>

  <?php if (isset($intro)): ?>
    <section class="container container--intro">
      <div class="wrapper">
        <?php if (isset($intro_title)): ?>
          <h2 class="inline--alt-color"><?php print $intro_title; ?></h2>
        <?php endif; ?>
        <div class="wrapper <?php if (isset($intro_image) || isset($intro_video)): print '-half'; else: print '-narrow'; endif; ?>">
          <?php print $intro; ?>
          <?php if (isset($modals)): ?>
            <?php print $modals; ?>
          <?php endif; ?>
        </div>
        <?php if (isset($intro_image) || isset($intro_video)): ?>
        <div class="wrapper -half">
          <?php if (isset($intro_video)): ?>
            <div class="media-video">
              <?php print $intro_video; ?>
            </div>
          <?php elseif (isset($intro_image)): ?>
            <?php print $intro_image; ?>
          <?php endif; ?>
        </div>
        <?php endif; ?>
      </div>
    </section>
  <?php endif; ?>


  <?php if (!empty($campaign_gallery)): ?>
    <section id="gallery" class="container container--campaigns">
      <?php print $campaign_gallery; ?>
    </section>
  <?php endif; ?>

  <section class="container additional-text">
    <div class="wrapper -narrow">
      <?php if (!empty($facts)): ?>
        <h2 class="inline--alt-color"><?php print $facts_header; ?></h2>
        <ul>
          <?php foreach ($facts['facts'] as $fact): ?>
            <li><?php print $fact['fact']; ?> <sup><?php print $fact['footnotes']; ?></sup></li>
          <?php endforeach; ?>
        </ul>

        <section class="sources">
          <h3 class="__title js-toggle-sources"><?php print t('Sources'); ?></h3>
          <ul class="__body legal">
            <?php foreach ($facts['sources'] as $key => $source): ?>
              <li><sup><?php print $key + 1; ?></sup> <?php print $source; ?></li>
            <?php endforeach; ?>
          </ul>
        </section>
      <?php endif; ?>

      <?php if (isset($global_copy['campaign_value_proposition'])): ?>
        <h2 class="inline--alt-color"><?php print t('What You Get'); ?></h2>
        <?php print $global_copy['campaign_value_proposition']; ?>
      <?php endif; ?>

      <?php if (isset($global_copy['scholarships'])): ?>
        <h2 class="inline--alt-color"><?php print t('Scholarships and Contests'); ?></h2>
        <?php print $global_copy['scholarships']; ?>
      <?php endif; ?>

      <?php if (isset($global_copy['about_ds'])): ?>
        <h2 class="inline--alt-color"><?php print t('About DoSomething.org'); ?></h2>
        <?php print $global_copy['about_ds']; ?>
      <?php endif; ?>
    </div>
  </section>

  <div class="cta">
    <div class="wrapper">
      <?php if (isset($call_to_action)): ?>
        <h2 class="__message"><?php print $call_to_action; ?></h2>
      <?php endif; ?>
      <a href="#gallery" class="button"><?php print t("Do it"); ?></a>
    </div>
  </div>

  <?php if ($info_bar): ?>
    <?php print $info_bar; ?>
  <?php endif; ?>

</div>
