<?php
/**
 * Returns the HTML for Grouped Campaigns.
 *
 * Available Variables
 * - $nid: Node ID for grouped campaign page (integer).
 * - $title: Title of grouped campaign page (string).
 */
?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <header role="banner">
    <h1 class="title"><?php print $title; ?></h1>
    <?php if (isset($subtitle)): ?>
      <h2 class="subtitle"><?php print $cta; ?></h2>
    <?php endif; ?>

    <?php // @TODO: markup the following! ?>
    <?php if (isset($signup_button)): ?>
      <?php print $call_to_action; ?>
      <?php print render($signup_button); ?>
    <?php endif; ?>

    <?php if (isset($scholarship)): ?>
      <div class="scholarship-callout -action -above">
        <p class="copy"><?php print $scholarship; ?></p>
      </div>
    <?php endif; ?>
  </header>

  <?php if (isset($intro)): ?>
    <section class="intro<?php if (!isset($intro_title)): print ' no-title'; endif; ?>">
      <?php if (isset($intro_title)): ?>
        <h1><?php print $intro_title; ?></h1>
      <?php endif; ?>
        <div class="intro-content<?php if (isset($intro_image) OR isset($intro_video)): print " intro-content-half-width"; endif; ?>"><?php print $intro; ?></div>
        <?php if (isset($intro_image)): ?>
          <?php print $intro_image; ?>
        <?php elseif (isset($intro_video)): ?>
          <?php print $intro_video; ?>
      <?php endif; ?>
    </section>
  <?php endif; ?>

  <?php if (isset($modals)): ?>
    <?php print $modals; ?>
  <?php endif; ?>

  <?php if (isset($post_signup_title) || isset($post_signup_body)): ?>
    <section>
      <?php if (isset($post_signup_title)): ?>
      <div class="post-signup-title-wrapper">
        <div class="post-signup-title">
          <?php if (isset($post_signup_title)): ?>
            <h2><?php print $post_signup_title; ?></h2>
          <?php endif; ?>
        </div>
      </div>
      <?php endif; ?>

      <?php if (isset($post_signup_body)): ?>
      <div class="post-signup-body-wrapper">
        <div class="post-signup-body">
          <?php if (isset($post_signup_body)): ?>
            <h2><?php print $post_signup_body; ?></h2>
          <?php endif; ?>
        </div>
      </div>
      <?php endif; ?>
    </section>
  <?php endif; ?>

    <?php if (isset($additional_text) && isset($campaigns['published'])): ?>
    <div class="additional-text-wrapper">
      <div class="additional-text">
        <?php if (isset($additional_text_title)): ?>
          <h2><?php print $additional_text_title; ?></h2>
        <?php endif; ?>

        <p><?php print $additional_text; ?></p>
      </div>
    </div>
    <?php endif; ?>

  <?php if (!empty($galleries)): ?>
    <?php // @TODO: Need to add a new class for this section. ?>
    <section class="">
      <?php foreach ($galleries as $gallery): ?>
        <?php if (isset($gallery['title'])): ?>
          <h2 class="__title"><?php print $gallery['title']; ?></h2>
        <?php endif; ?>
        <ul class="gallery">
          <?php foreach ($gallery['items'] as $gallery_item): ?>
            <li class="gallery-item">
              <?php if (isset($gallery_item['image'])): ?>
                <?php print $gallery_item['image']; ?>
              <?php endif; ?>
              <?php if (isset($gallery_item['image_title'])): ?>
                  <h3 class="title"><?php print $gallery_item['image_title']; ?></h3>
              <?php endif; ?>
              <?php if (isset($gallery_item['image_description'])): ?>
                <div class="gallery-description"><?php print $gallery_item['image_description']; ?></div>
              <?php endif; ?>
            </li>
          <?php endforeach; ?>
        </ul>
      <?php endforeach; ?>
    </section>
  <?php endif; ?>

</article>
