<?php print $reportback->image; ?>

<?php if ($reportback->caption): ?>
  <?php print filter_xss($reportback->caption); ?>
<?php endif; ?>
