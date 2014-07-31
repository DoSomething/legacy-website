<?php
/**
 * Returns the HTML for a block.
 * @see https://drupal.org/node/1728246
 *
 * @see
 * paraneue_dosomething_preprocess_block() in includes/preprocess.inc
 * If the $clean_output variable is set to TRUE, then the content for
 * the block will be output, without any of the extra markup around it.
 */
?>

<?php if ($clean_output): ?>

  <?php print $content ?>

<?php else: ?>

  <div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

    <?php print render($title_prefix); ?>
  <?php if ($block->subject): ?>
    <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
  <?php endif;?>
    <?php print render($title_suffix); ?>

    <div class="content"<?php print $content_attributes; ?>>
      <?php print $content ?>
    </div>
  </div>

<?php endif; ?>
