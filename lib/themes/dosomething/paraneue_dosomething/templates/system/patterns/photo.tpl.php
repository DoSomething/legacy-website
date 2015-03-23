<figure class="photo -stacked -framed">
  <?php if (isset($content['admin_link'])): ?>
    <div class="admin-edit">
      <a class="button -secondary" href="<?php print $content['admin_link']?>">Edit Status</a>
    </div>
  <?php endif; ?>
  <img src="<?php print $content['image']; ?>" alt="<?php print check_plain($content['caption']); ?>" />
  <figcaption class="__copy">
    <?php print check_plain($content['caption']); ?>
  </figcaption>
</figure>
