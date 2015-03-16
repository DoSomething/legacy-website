<?php
/**
 * Available variables:
 * - $block->subject: Block title.
 * - $content: The rendered Payment Form, or a confirmation message.
 *
 * @see dosomething_payment_block_view().
 */
?>

<div class="cta">
  <div class="wrapper">

    <?php // If query string present, display confirmation message. ?>
    <?php if (isset($_GET['donated'])): ?>

      <h2><?php print $content; ?></h2>

    <?php // Else: display Donate Form into modal, and a link to it. ?>
    <?php else: ?>

      <a href="#" data-modal-href="#modal--donate-form" class="button">
        <?php print t("Donate"); ?>
      </a>
      <div data-modal id="modal--donate-form" role="dialog" class="donate--payment">
        <div class="modal__block">
          <h2 class="donate--header"><?php print $block->subject; ?></h2>
        </div>
        <div class="modal__block">
          <?php print $content; ?>
        </div>
      </div>

    <?php endif; ?>

  </div>
</div>
