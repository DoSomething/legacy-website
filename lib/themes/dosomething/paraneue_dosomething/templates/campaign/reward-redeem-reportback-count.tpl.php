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

<article class="campaign campaign--action action">

  <header role="banner" class="-basic">
    <div class="wrapper">
      <h1 class="__title"><?php print $page_title; ?></h1>
      <?php if (isset($page_subtitle)): ?>
      <p class="__subtitle"><?php print $page_subtitle; ?></p>
      <?php endif; ?>
    </div>
  </header>

  <section class="container -padded">
    <div class="wrapper">
      <div class="container__block <?php if (isset($page_image)): print '-half'; else: print '-narrow'; endif; ?>">
        <?php if (isset($page_header) && !empty($page_header)): ?>
        <h2 class="inline--alt-color"><?php print $page_header; ?></h2>
        <?php endif; ?>
        <p><?php print $page_copy; ?></p>
        <ul class="form-actions -inline -padded">
          <li><a href="#" data-modal-href="#modal-redeem-form" class="button"><?php print $form_link; ?></a></li>
        </ul>
      </div>

      <?php if (isset($page_image)): ?>
        <div class="container__block -half">
          <aside>
            <?php print $page_image; ?>
          </aside>
        </div>
      <?php endif; ?>

      <?php // "Free T-shirts" Modals ?>
      <div data-modal id="modal-redeem-form" role="dialog">
        <h2 class="heading -banner"><?php print ($form_header); ?></h2>
        <div class="modal__block">
          <?php print $form_copy; ?>
        </div>
        <div class="modal__block">
          <?php print render($form); ?>
        </div>
      </div>
    </div>
  </section>

</article>
