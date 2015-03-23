<figure class="photo -stacked -framed">
  <?php if (user_access('view any reportback')): ?>
    <div class="admin-edit">
      <a class="button -secondary" href="/admin/reportback/<?php print $content['rbid'] ?>">Edit Status</a>
    </div>
  <?php endif; ?>
  <img src="<?php print $content['image']; ?>" alt="<?php print check_plain($content['caption']); ?>" />
  <figcaption class="__copy">
    <?php print check_plain($content['caption']); ?>
  </figcaption>
</figure>
