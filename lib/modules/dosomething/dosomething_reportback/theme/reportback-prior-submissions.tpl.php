<p class="legal"><?php print t('Last updated:'); ?> <?php print $updated; ?></p>
<?php foreach ($reportbacks as $reportback): ?>
  <?php print $reportback->image; ?>
<?php endforeach; ?>
