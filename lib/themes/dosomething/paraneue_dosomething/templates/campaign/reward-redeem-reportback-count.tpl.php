<?php
/**
 * Returns the HTML for the Campaign Reportback Confirmation.
 *
 * Available Variables
 * - $page_title: The page title (string).
 * - $page_subtitle: (string).
 * - $page_copy: (string).
 * - $redeem_form: Array containing variables for Reward Reedem Form, if exists.
 */
?>

<section class="confirmation-wrapper">

  <header role="banner" class="-basic">
    <div class="wrapper">
      <h1 class="__title"><?php print $page_title; ?></h1>
      <h2 class="__subtitle"><?php print $page_subtitle; ?></h2>
    </div>
  </header>

  <div>
    <h2><?php print $page_header; ?></h2>
    <p><?php print $page_copy; ?></h2>
    <?php if (isset($page_image)): ?>
    <?php print $page_image; ?>
    <?php endif; ?>
  </div>

  <a href="#" data-modal-href="#modal-redeem-form" class="btn medium"><?php print $form_link; ?></a>
  <div data-modal id="modal-redeem-form" role="dialog">
    <h2 class="banner"><?php print ($form_header); ?></h2>
    <?php print $form_copy; ?>
    <?php print render($form); ?>
  </div>
  <?php if ($redeem_form['delete_form']): ?>
    <?php print render($redeem_form['delete_form']); ?>
  <?php endif; ?>


</section>
