<ul class="modal-links">
  <?php if (isset($modals['faq'])): ?>
    <li><a href="#modal-faq" class="js-modal-link">Check out our FAQs</a></li>
  <?php endif; ?>

  <?php if (isset($modals['more_facts'])): ?>
    <li><a href="#modal-facts" class="js-modal-link">Learn more about <?php print $modals['issue']; ?></a></li>
  <?php endif; ?>

  <?php if (isset($modals['partner_info'])): ?>
  <?php foreach ($modals['partner_info'] as $delta => $partner): ?>
    <li><a href="#modal-partner-<?php print $delta; ?>" class="js-modal-link">Why we &lt;3 <?php print $partner['name']; ?></a>
  <?php endforeach; ?>
  <?php endif; ?>
</ul>

<?php if (isset($modals['faq'])): ?>
<script id="modal-faq" type="text/cached-modal">
  <a href="#" class="js-close-modal modal-close-button white">×</a>
  <h2 class="banner">FAQs</h2>
  <?php foreach ($modals['faq'] as $item): ?>
    <h4 class="faq-header"><?php print $item['header']; ?></h4>
    <div class="faq-copy"><?php print $item['copy'] ?></div>
  <?php endforeach; ?>
  <a href="#" class="js-close-modal">Back to main page</a>
</script>
<?php endif; ?>

<?php if (isset($modals['more_facts'])): ?>
<script id="modal-facts" type="text/cached-modal">
  <a href="#" class="js-close-modal modal-close-button white">×</a>
  <h2 class="banner">Facts</h2>
  <?php foreach ($modals['more_facts']['facts'] as $key => $fact): ?>
    <div class="fact-more"><?php print $fact['fact']; ?><sup><?php print $fact['footnotes']; ?></sup></div>
  <?php endforeach; ?>
  Sources:
  <?php foreach ($modals['more_facts']['sources'] as $key => $source): ?>
    <div class="legal"><sup><?php print ($key + 1); ?></sup><?php print $source; ?></div>
  <?php endforeach; ?>
  <a href="#" class="js-close-modal">Back to main page</a>
</script>
<?php endif; ?>

<?php if (isset($modals['partner_info'])): ?>
  <?php foreach ($modals['partner_info'] as $delta => $partner): ?>
    <script id="modal-partner-<?php print $delta; ?>" type="text/cached-modal">
      <a href="#" class="js-close-modal modal-close-button white">×</a>
      <h2 class="banner">We &lt;3 <?php print $partner['name']; ?></h2>
      <?php print $partner['copy']; ?>
      <?php if (isset($partner['video'])): print $partner['video']; ?>
      <?php elseif (isset($partner['image'])): print $partner['image']; endif; ?>
      <a href="#" class="js-close-modal">Back to main page</a>
    </script>
  <?php endforeach; ?>
<?php endif; ?>
