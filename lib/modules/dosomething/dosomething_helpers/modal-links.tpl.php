<ul class="list -compacted">
  <?php if (isset($modals['faq'])): ?>
    <li><a href="#" data-modal-href="#modal-faq"><?php print t('FAQs'); ?></a></li>
  <?php endif; ?>

  <?php if (isset($modals['more_facts'])): ?>
    <li><a href="#" data-modal-href="#modal-facts"><?php print t('Learn more about @issue', ['@issue' => $modals['issue']]); ?></a></li>
  <?php endif; ?>

  <?php if (isset($modals['partner_info'])): ?>
  <?php foreach ($modals['partner_info'] as $delta => $partner): ?>
    <li>
      <a href="#" data-modal-href="#modal-partner-<?php print $delta; ?>">
        <?php print t('Why we &lt;3 @partner', ['@partner' => $partner['name']]); ?> <?php  ?>
      </a>
  <?php endforeach; ?>
  <?php endif; ?>
</ul>

<?php if (isset($modals['faq'])): ?>
<div data-modal id="modal-faq" role="dialog">
  <div class="modal__block">
    <h2><?php print t('FAQs'); ?></h2>
  </div>
  <div class="modal__block with-lists">
    <?php foreach ($modals['faq'] as $item): ?>
      <h4><?php print $item['header']; ?></h4>
      <?php print $item['copy'] ?>
    <?php endforeach; ?>
  </div>
  <div class="modal__block">
    <div class="form-actions">
      <a href="#" class="js-close-modal"><?php print t('Back to main page'); ?></a>
    </div>
  </div>
</div>
<?php endif; ?>

<?php if (isset($modals['more_facts'])): ?>
<div data-modal id="modal-facts" role="dialog">
  <div class="modal__block">
      <h2><?php print t('Facts'); ?></h2>
  </div>
  <div class="modal__block">
    <ul class="list">
      <?php foreach ($modals['more_facts']['facts'] as $key => $fact): ?>
        <li><?php print $fact['fact']; ?><sup><?php print $fact['footnotes']; ?></sup></li>
      <?php endforeach; ?>
    </ul>
  </div>

  <div class="modal__block">
    <section class="footnote">
      <h4 class="js-footnote-toggle"><?php print t('Sources'); ?></h4>
      <ul class="js-footnote-hidden">
        <?php foreach ($modals['more_facts']['sources'] as $key => $source): ?>
          <li><sup><?php print($key + 1); ?></sup> <?php print $source; ?></li>
        <?php endforeach; ?>
      </ul>
    </section>
  </div>
  <div class="modal__block">
    <div class="form-actions">
      <a href="#" class="js-close-modal"><?php print t('Back to main page'); ?></a>
    </div>
  </div>
</div>
<?php endif; ?>

<?php if (isset($modals['partner_info'])): ?>
  <?php foreach ($modals['partner_info'] as $delta => $partner): ?>
    <div data-modal id="modal-partner-<?php print $delta; ?>" role="dialog">
      <div class="modal__block">
        <h2><?php print t('We &lt;3 @partner', ['@partner' => $partner['name']]); ?></h2>
      </div>
      <div class="modal__block with-lists">
        <?php print $partner['copy']; ?>
      </div>
      <?php if (isset($partner['video']) || isset($partner['image'])): ?>
        <div class="modal__block">
          <?php if (isset($partner['video'])): print $partner['video']; ?>
          <?php elseif (isset($partner['image'])): print $partner['image']; endif; ?>
        </div>
      <?php endif; ?>
      <div class="modal__block">
        <div class="form-actions">
          <a href="#" class="js-close-modal"><?php print t('Back to main page'); ?></a>
        </div>
      </div>
    </div>
  <?php endforeach; ?>
<?php endif; ?>
