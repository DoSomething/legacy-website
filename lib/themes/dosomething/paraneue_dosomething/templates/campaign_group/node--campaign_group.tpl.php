<?php
/**
 * Returns the HTML for Grouped Campaigns page.
 *
 * Available Variables
 * - $nid: Node ID for grouped campaigns page (integer).
 * - $title: Title of grouped campaigns page (string).
 * - $subtitle: Subtitle of grouped campaigns page (string).
 * - $signup_button: Render array for outputting Signup form button (array).
 * - $call_to_action: Call To Action of grouped campaigns page (string).
 * - $scholarship: Scholarship amount (string).
 * - $partners: Array of partners for grouped campaigns (array).
 * - $partner_info: Array of information regarding partners for grouped campaigns (array).
 */
?>

<article id="node-<?php print $node->nid; ?>" class="campaign campaign--grouped <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <header role="banner" class="-hero">
    <div class="wrapper">
      <h1 class="__title"><?php print $title; ?></h1>
      <?php if (isset($call_to_action)): ?>
      <h2 class="__subtitle"><?php print $call_to_action; ?></h2>
      <?php endif; ?>

      <?php if (isset($end_date)): ?><p class="__date"><?php print $end_date; ?></p><?php endif; ?>

      <?php if (isset($signup_button_primary)): ?>
        <div class="__signup">
          <?php print render($signup_button_primary); ?>
          <?php if (isset($scholarship)): ?>
            <div class="message-callout -below -white -dynamic-right">
              <div class="__copy">
                <p><?php print $scholarship; ?></p>
              </div>
            </div>
          <?php endif; ?>
        </div>
      <?php endif; ?>

      <?php if (isset($sponsors[0]['display'])): ?>
      <div class="sponsor">
        <p class="__copy"><?php print t('Powered by'); ?></p>
        <?php foreach ($sponsors as $key => $sponsor) :?>
          <?php if (isset($sponsor['display'])): print $sponsor['display']; endif; ?>
        <?php endforeach; ?>
      </div>
      <?php endif; ?>
    </div>
  </header>



  <?php if (isset($intro)): ?>
    <section class="container container--intro">
      <div class="wrapper">
        <?php if (isset($intro_title)): ?>
          <h2 class="container__title inline--alt-color"><?php print $intro_title; ?></h2>
        <?php endif; ?>

        <div class="container__body">
          <div<?php if (isset($intro_image) || isset($intro_video)): print ' class="-columned"'; endif; ?>>
          <?php print $intro; ?>

          <?php if (isset($modals)): ?>
            <?php print $modals; ?>
          <?php endif; ?>
          </div>

          <?php if (isset($intro_image) || isset($intro_video)): ?>
          <aside class="-columned -col-last">
            <?php if (isset($intro_video)): ?>
              <div class="media-video">
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



  <?php if (isset($post_signup_copy)): ?>
    <section class="container post-signup">
      <div class="wrapper">
        <?php if (isset($post_signup_title)): ?>
          <h2 class="container__title inline--alt-color"><?php print $post_signup_title; ?></h2>
        <?php endif; ?>

        <div class="container__body">
          <?php print $post_signup_copy; ?>
        </div>
      </div>
    </section>
  <?php endif; ?>


  <?php if (isset($pre_launch_copy)): ?>
    <section class="container pre-launch">
      <div class="wrapper">
        <?php if (isset($pre_launch_title)): ?>
          <h2 class="container__title inline--alt-color"><?php print $pre_launch_title; ?></h2>
        <?php endif; ?>

        <div class="container__body">
          <?php print $pre_launch_copy; ?>
        </div>
      </div>
    </section>
  <?php endif; ?>


  <?php if (!empty($campaigns)): ?>
    <section class="container container--campaigns">
      <ul class="gallery -mosaic -featured">

        <?php if (isset($campaigns['published'])): ?>
          <?php foreach ($campaigns['published'] as $published_campaign): ?>
            <li class="campaign -published">
              <?php print render($published_campaign); ?>
            </li>
          <?php endforeach; ?>
        <?php endif; ?>

        <?php if (isset($campaigns['unpublished'])): ?>
          <?php foreach ($campaigns['unpublished'] as $unpublished_campaign): ?>
            <li class="campaign -unpublished">
              <?php print render($unpublished_campaign); ?>
            </li>
          <?php endforeach; ?>
        <?php endif; ?>

      </ul>
    </section>
  <?php endif; ?>


  <?php if (!empty($additional_text)): ?>
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


  <?php if (!empty($galleries)): ?>
    <?php // @TODO: Need to add a new class for this section. ?>
    <section class="container container--gallery">
      <div class="wrapper">

        <?php foreach ($galleries as $gallery): ?>
          <?php if (isset($gallery['title'])): ?>
            <h2 class="container__title inline--alt-color"><?php print $gallery['title']; ?></h2>
          <?php endif; ?>

          <ul class="gallery -triad">
            <?php foreach ($gallery['items'] as $gallery_item): ?>
              <li class="<?php print $gallery_item['order_class']; ?>">
                <div class="tile tile--figure">
                  <?php if (isset($gallery_item['image'])): ?>
                    <?php print $gallery_item['image']; ?>
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

        <?php endforeach; ?>

      </div>
    </section>
  <?php endif; ?>

  <?php if (isset($signup_button_secondary)): ?>
    <div class="cta">
      <div class="wrapper">
        <h2 class="__message"><?php print $call_to_action; ?></h2>
        <?php if (isset($signup_button_secondary)): ?>
          <?php print render($signup_button_secondary); ?>
        <?php endif; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($info_bar): ?>
    <?php print $info_bar; ?>
  <?php endif; ?>

</article>
