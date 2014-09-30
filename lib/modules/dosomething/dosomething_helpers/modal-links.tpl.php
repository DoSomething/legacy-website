<ul class="modal-links">
  <?php if (isset($modals['faq'])): ?>
    <li><a href="#" data-modal-href="#modal-faq"><?php print t('Check out our FAQs'); ?></a></li>
  <?php endif; ?>

  <?php if (isset($modals['more_facts'])): ?>
    <li><a href="#" data-modal-href="#modal-facts"><?php print t('Learn more about @issue', array('@issue' => $modals['issue'])); ?></a></li>
  <?php endif; ?>

  <?php if (isset($modals['partner_info'])): ?>
  <?php foreach ($modals['partner_info'] as $delta => $partner): ?>
    <li>
      <a href="#" data-modal-href="#modal-partner-<?php print $delta; ?>">
        <?php print t('Why we &lt;3 @partner', array('@partner' => $partner['name'])); ?> <?php  ?>
      </a>
  <?php endforeach; ?>
  <?php endif; ?>
</ul>

<?php if (isset($modals['faq'])): ?>
<div data-modal id="modal-faq" role="dialog">
  <h2 class="banner"><?php print t('FAQs'); ?></h2>
  <?php foreach ($modals['faq'] as $item): ?>
    <h4 class="faq-header"><?php print $item['header']; ?></h4>
    <div class="faq-copy"><?php print $item['copy'] ?></div>
  <?php endforeach; ?>
  <a href="#" class="js-close-modal"><?php print t('Back to main page'); ?></a>
</div>
<?php endif; ?>

<?php if (isset($modals['more_facts'])): ?>
<div data-modal id="modal-facts" role="dialog">
  <h2 class="banner"><?php print t('Facts'); ?></h2>
  <ul>
  <?php foreach ($modals['more_facts']['facts'] as $key => $fact): ?>
    <li><?php print $fact['fact']; ?><sup><?php print $fact['footnotes']; ?></sup></li>
  <?php endforeach; ?>
  </ul>

  <section class="sources">
    <h3 class="__title js-toggle-sources"><?php print t('Sources'); ?></h3>
    <ul class="__body legal">
    <?php foreach ($modals['more_facts']['sources'] as $key => $source): ?>
      <li><sup><?php print ($key + 1); ?></sup> <?php print $source; ?></li>
    <?php endforeach; ?>
    </ul>
  </section>
  <a href="#" class="js-close-modal"><?php print t('Back to main page'); ?></a>
</div>
<?php endif; ?>

<?php if (isset($modals['partner_info'])): ?>
  <?php foreach ($modals['partner_info'] as $delta => $partner): ?>
    <div data-modal id="modal-partner-<?php print $delta; ?>" role="dialog">
      <h2 class="banner"><?php print t('We &lt;3 @partner', array('@partner' => $partner['name'])); ?></h2>
      <?php print $partner['copy']; ?>
      <?php if (isset($partner['video'])): print $partner['video']; ?>
      <?php elseif (isset($partner['image'])): print $partner['image']; endif; ?>
      <a href="#" class="js-close-modal"><?php print t('Back to main page'); ?></a>
    </div>
  <?php endforeach; ?>
<?php endif; ?>
