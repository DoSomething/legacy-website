<div class="tile tile--figure">
  <?php if (!empty($content['image'])): ?>
    <div class="__media">
      <?php print $content['image']; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['title'])): ?>
    <h3 class="__title">
      <?php print $content['title']; ?>
    </h3>
  <?php endif; ?>
  <?php if (!empty($content['description'])): ?>
    <div class="__description">
      <?php print $content['description']; ?>
    </div>
  <?php endif; ?>
</div>
