<article class="tile tile--campaign campaign-result <?php print $modifier_classes ?>">
  <a class="wrapper" href="<?php print $pretty_path; ?>">
    <?php if ($staff_pick): ?>
      <div class="__flag -staff-pick"><?php print t('Staff Pick'); ?></div>
    <?php endif; ?>
    <div class="tile--meta">
      <h1 class="__title"><?php print $title; ?></h1>
      <p class="__tagline"><?php print $cta; ?></p>
    </div>
    <img src="data:image/gif;base64,R0lGODlhAQABAIAAAAUEBAAAACwAAAAAAQABAAACAkQBADs=" data-src="<?php print $image ?>" alt="<?php print $title; ?>">
  </a>
</article>

