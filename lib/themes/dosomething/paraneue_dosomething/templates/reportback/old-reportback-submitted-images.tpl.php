<div class="submitted-image">
  <p class="footnote"><?php print t("Last updated: @updated", array("@updated" => $updated)); ?></p>
  <?php foreach ($images as $image): ?>
    <?php print $image; ?>
  <?php endforeach; ?>
</div>
