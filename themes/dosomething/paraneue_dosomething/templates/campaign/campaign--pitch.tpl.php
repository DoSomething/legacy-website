<div class="content clearfix <?php print $classes; ?>">
	<img src="<?php print $cover_image['src']; ?>" alt="<?php print $cover_image['alt']; ?>" />
	<?php print render($content['signup_form']); ?>
	<?php if (!empty($gallery)): ?>
  <div id="gallery">
  <?php foreach ($gallery as $gallery_image): ?>
    <img src="<?php print $gallery_image['src']; ?>" alt="<?php print $gallery_image['alt']; ?>" />
  <?php endforeach; ?>
  </div>
  <?php endif; ?>
</div>
