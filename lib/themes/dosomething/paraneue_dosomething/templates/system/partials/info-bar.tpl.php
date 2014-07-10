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
      Questions? <a href="#modal-contact-form" class="js-modal-link">Contact Us</a>
      <script id="modal-contact-form" class="modal--contact" type="text/cached-modal" data-modal-close="true" data-modal-close-class="white">
        <h2 class="banner">Contact Us</h2>
        <p>Enter your question below. Please be as specific as possible.</p>
        <?php print render($zendesk_form); ?>
      </script>
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

