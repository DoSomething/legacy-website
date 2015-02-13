<div class="figure <?php print $classes; ?>">
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
  <div class="figure__body">
    <?php if (!empty($content['title'])): ?>
      <h3>
        <?php if (!empty($content['url'])): ?>
          <a href="<?php print $content['url']; ?>">
            <?php print $content['title']; ?>
          </a>
        <?php else: ?>
          <?php print $content['title']; ?>
        <?php endif; ?>
      </h3>
    <?php endif; ?>
    <?php if (!empty($content['description'])): ?>
      <?php print $content['description']; ?>
    <?php endif; ?>
  </div>

  <?php if (!empty($content['url']) && !empty($content['button_text'])): ?>
    <a class="button" href="<?php print $content['url'] ?>"><?php print $content['button_text'] ?></a>
  <?php endif; ?>
</div>
