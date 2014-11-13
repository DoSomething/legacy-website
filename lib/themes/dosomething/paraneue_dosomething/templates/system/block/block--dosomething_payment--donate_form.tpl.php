<?php
/**
 * Available variables:
 * - $block->subject: Block title.
 * - $content: The rendered Payment Form.
 */
?>

<div class="cta">
  <div class="wrapper">
    <a href="#" data-modal-href="#modal--donate-form" class="btn">
      <?php print t("Donate"); ?>
    </a>
    <div data-modal id="modal--donate-form" role="dialog" class="donate--payment">
      <h2 class="donate--header"><?php print $block->subject; ?></h2>
      <?php print $content; ?>
    </div>
  </div>
</div>
