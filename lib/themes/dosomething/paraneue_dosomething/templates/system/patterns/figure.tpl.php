<div class="figure">
  <?php if (!empty($content['image'])): ?>
    <div class="figure__media">
      <?php if (!empty($content['url'])): ?>
        <a href="<?php print $content['url']; ?>">
          <?php print $content['image']; ?>
        </a>
      <?php else: ?>
        <?php print $content['image']; ?>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['title'])): ?>
    <h3 class="figure__title">
      <?php print $content['title']; ?>
    </h3>
  <?php endif; ?>
  <?php if (!empty($content['description'])): ?>
    <div class="figure__description">
      <?php print $content['description']; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['url']) && !empty($content['button_text'])): ?>
    <a class="button" href="<?php print $content['url'] ?>"><?php print $content['button_text'] ?></a>
  <?php endif; ?>
</div>
