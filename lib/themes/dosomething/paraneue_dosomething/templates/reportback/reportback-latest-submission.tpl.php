<figure class="reportback__submission-latest">
  <?php print $reportback->image; ?>

  <?php if ($reportback->caption): ?>
    <figcaption class="reportback__submission__copy">
      <?php print check_plain($reportback->caption); ?>
    </figcaption>
  <?php endif; ?>
</figure>
