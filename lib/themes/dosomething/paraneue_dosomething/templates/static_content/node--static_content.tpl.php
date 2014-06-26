<?php
/**
 * Returns the HTML for Static Content pages.
 *
 * Available Variables
 * - $title: Title for the page (string).
 * - $subtitle: Subtitle for the page (string).
 */

// krumo('spacer');
// krumo('STATIC NODE TPL');
// krumo($variables);
?>


<article id="node-<?php print $node->nid; ?>" class="static <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $variables['header']; ?>

  <div class="wrapper">

    <?php if (isset($intro)): ?>
      <section id="intro" class="container container--intro">
        <div class="wrapper">
          <?php if (isset($intro_title)): ?>
            <h2 class="container__title inline--alt-color"><?php print $intro_title; ?></h2>
          <?php endif; ?>

          <div class="container__body">
            <div<?php if (isset($intro_image) || isset($intro_video)): print ' class="-columned"'; endif; ?>>
              <?php print $intro; ?>
            </div>

            <?php if (isset($intro_image) || isset($intro_video)): ?>
            <aside class="-columned -col-last">
              <?php if (isset($intro_video)): ?>
                <div class="video">
                  <?php print $intro_video; ?>
                </div>
              <?php elseif (isset($intro_image)): ?>
                <?php print $intro_image; ?>
              <?php endif; ?>
            </aside>
            <?php endif; ?>
          </div>
        </div>
      </section>
    <?php endif; ?>


    <?php if (isset($call_to_action)): ?>
      <div class="cta">
        <div class="wrapper">
          <h2 class="__message"><?php print $call_to_action; ?></h2>
          <?php print $cta_link; ?>
        </div>
      </div>
    <?php endif; ?>


    <?php if (!empty($content['field_blocks'])): ?>
    <?php print render($content['field_blocks']); ?>
      <pre>WHAT THE CRAP ARE THESE</pre>
    <?php endif; ?>


    <?php if (!empty($galleries)): ?>
      <?php foreach ($galleries as $gallery): ?>
      <section class="container container--gallery">
        <div class="wrapper">
        <?php if (isset($gallery['title'])): ?>
          <h2 class="container__title inline--alt-color"><?php print $gallery['title']; ?></h2>
        <?php endif; ?>

        <ul class="gallery -triad">
          <?php foreach ($gallery['items'] as $gallery_item): ?>
            <li class="<?php print $gallery_item['order_class']; ?>">
              <div class="tile tile--figure">
                <?php if (isset($gallery_item['image'])): ?>
                  <?php if (isset($gallery_item['image_title']) AND $gallery_item['image_url'] !== '') : ?>
                    <a href="<?php print $gallery_item['image_url']; ?>"><?php print $gallery_item['image']; ?></a>
                  <?php else : ?>
                    <?php print $gallery_item['image']; ?>
                  <?php endif; ?>
                <?php endif; ?>

                <?php if (isset($gallery_item['image_title'])): ?>
                  <h3 class="__title"><?php print $gallery_item['image_title']; ?></h3>
                <?php endif; ?>
                <?php if (isset($gallery_item['image_description'])): ?>
                  <div class="__description"><?php print $gallery_item['image_description']; ?></div>
                <?php endif; ?>
              </div>
            </li>
          <?php endforeach; ?>
        </ul>

        </div>
      </section>
      <?php endforeach; ?>
    <?php endif; ?>


    <?php if (isset($additional_text)): ?>
    <section class="container additional-text">
      <div class="wrapper">
        <?php if (isset($additional_text_title)): ?>
          <h2 class="container__title inline--alt-color"><?php print $additional_text_title; ?></h2>
        <?php endif; ?>

        <div class="container__body">
          <div<?php if (isset($additional_text_image)): print ' class="-columned"'; endif; ?>>
          <?php print $additional_text; ?>
        </div>

        <?php if (isset($additional_text_image)): ?>
          <aside class="-columned -col-last">
            <?php print $additional_text_image; ?>
          </aside>
        <?php endif; ?>
      </div>
    </section>
    <?php endif; ?>


    <?php if (isset($call_to_action)): ?>
      <div class="cta">
        <div class="wrapper">
          <h2 class="__message"><?php print $call_to_action; ?></h2>
          <?php print $cta_link; ?>
        </div>
      </div>
    <?php endif; ?>


    <?php if (isset($sponsors)): ?>
    <footer class="info-bar">
      <div class="wrapper">
        <?php if (isset($sponsors)): ?>
          <div class="sponsor">
            In partnership with <?php print $formatted_partners; ?>
          </div>
        <?php endif; ?>
      </div>
    </footer>
    <?php endif; ?>

  </div>

</article>
