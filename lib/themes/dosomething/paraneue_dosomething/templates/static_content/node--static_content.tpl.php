<?php
/**
 * Returns the HTML for Static Content pages.
 *
 * Available Variables
 * - $title: Title for the page (string).
 * - $subtitle: Subtitle for the page (string).
 */
?>


<article id="node-<?php print $node->nid; ?>" class="static <?php print $classes; ?>"<?php print $attributes; ?>>

  <?php //@TODO: Aiming to add this back in once a better solution is found for default pages. ?>
  <?php //print $variables['header']; ?>

  <?php if (isset($intro)): ?>
    <section class="container">
      <div class="wrapper">
      <?php if(isset($intro_image) || isset($intro_video)): ?>
        <?php /** There's an image, so show two columns. */ ?>
        <div class="container__block -half with-lists">
          <?php if (isset($intro_title)): ?>
            <h1 class="inline--alt-color"><?php print $intro_title; ?></h1>
          <?php endif; ?>

          <?php print $intro; ?>
        </div>

        <div class="container__block -half">
          <?php if (isset($intro_video)): ?>
            <div class="media-video">
              <?php print $intro_video; ?>
            </div>
          <?php elseif (isset($intro_image)): ?>
            <?php print $intro_image; ?>
          <?php endif; ?>
        </div>

      <?php else: ?>
        <?php /** No image, so show three-quarters width intro block. */ ?>
        <div class="container__block -narrow with-lists">
          <?php if (isset($intro_title)): ?>
            <h1 class="inline--alt-color"><?php print $intro_title; ?></h1>
          <?php endif; ?>

          <?php print $intro; ?>
        </div>
      <?php endif ?>
      </div>
    </section>
  <?php endif; ?>

  <?php if (isset($call_to_action)): ?>
    <div class="cta">
      <div class="wrapper">
        <h2 class="cta__message"><?php print $call_to_action; ?></h2>
        <?php print $cta_link; ?>
      </div>
    </div>
  <?php endif; ?>


  <?php if (!empty($content['field_blocks'])): ?>
    <?php print render($content['field_blocks']); ?>
  <?php endif; ?>


  <?php if (!empty($galleries)): ?>
    <?php foreach ($galleries as $gallery): ?>
    <section class="container">
      <div class="wrapper">
        <?php if (isset($gallery['title'])): ?>
        <div class="container__block -narrow">
          <h2 class="inline--alt-color"><?php print $gallery['title']; ?></h2>
        </div>
        <?php endif; ?>

        <ul class="gallery <?php print $gallery['class']; ?>">
          <?php foreach ($gallery['items'] as $gallery_item): ?>
            <li>
              <div class="figure">
                <?php if (isset($gallery_item['image'])): ?>
                  <div class="figure__media">
                    <?php if (isset($gallery_item['image_title']) AND $gallery_item['image_url'] !== '') : ?>
                      <a href="<?php print $gallery_item['image_url']; ?>"><?php print $gallery_item['image']; ?></a>
                    <?php else : ?>
                      <?php print $gallery_item['image']; ?>
                    <?php endif; ?>
                  </div>
                <?php endif; ?>

                <div class="figure__body">
                  <?php if (isset($gallery_item['image_title'])): ?>
                    <h3 class="__title"><?php print $gallery_item['image_title']; ?></h3>
                  <?php endif; ?>
                  <?php if (isset($gallery_item['image_description'])): ?>
                    <div class="__description"><?php print $gallery_item['image_description']; ?></div>
                  <?php endif; ?>
                </div>
              </div>
            </li>
          <?php endforeach; ?>
        </ul>

      </div>
    </section>
    <?php endforeach; ?>
  <?php endif; ?>


  <?php if (!empty($additional_text)): ?>
  <section class="container -padded">
    <div class="wrapper">
      <?php if(isset($additional_text_image)): ?>
        <div class="container__block -half with-lists">
          <?php if (isset($additional_text_title)): ?>
            <h2 class="inline--alt-color"><?php print $additional_text_title; ?></h2>
          <?php endif; ?>

          <?php print $additional_text; ?>
        </div>

        <aside class="container__block -half">
          <?php print $additional_text_image; ?>
        </aside>
      <?php else: ?>
        <div class="container__block -narrow with-lists">
          <?php if (isset($additional_text_title)): ?>
            <h2 class="inline--alt-color"><?php print $additional_text_title; ?></h2>
          <?php endif; ?>

          <?php print $additional_text; ?>
        </div>
      <?php endif; ?>
    </div>
  </section>
  <?php endif; ?>


  <?php if (isset($call_to_action)): ?>
    <div class="cta">
      <div class="wrapper">
        <h2 class="cta__message"><?php print $call_to_action; ?></h2>
        <?php print $cta_link; ?>
      </div>
    </div>
  <?php endif; ?>


  <?php if ($info_bar): ?>
    <?php print $info_bar; ?>
  <?php endif; ?>

</article>
