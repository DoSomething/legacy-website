<?php

/**
 * Generates info bar footer.
 **/
?>

<?php if (isset($zendesk_form) || isset($sponsors)): ?>
<footer class="info-bar">
  <div class="wrapper">

    <?php if (isset($zendesk_form)): ?>
    <div class="help">
      Questions? <a href="#" data-modal-href="#modal-contact-form">Contact Us</a>
      <div data-modal id="modal-contact-form" class="modal--contact" role="dialog">
        <h2 class="banner">Contact Us</h2>
        <p><?php print $zendesk_form_header; ?></p>
        <?php print render($zendesk_form); ?>
      </div>
    </div>
    <?php endif; ?>

    <?php if (isset($sponsors)): ?>
      <div class="sponsor">
        In partnership with <?php print $formatted_partners; ?>
      </div>
    <?php endif; ?>
  </div>
</footer>
<?php endif; ?>

