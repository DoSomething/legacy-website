<?php
/**
 * Returns the HTML for the Campaign Reportback Confirmation.
 *
 * Available Variables
 * - $page_title: The page title (string).
 * - $page_subtitle: (string).
 * - $page_header: (string).
 * - $page_copy: (string).
 * - $page_image: Rendered image (string).
 * - $form_link: (string).
 * - $form_header: (string).
 * - $form_copy: (string).
 * - $form: Array containing Reward Reedem Form.
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

</section>
