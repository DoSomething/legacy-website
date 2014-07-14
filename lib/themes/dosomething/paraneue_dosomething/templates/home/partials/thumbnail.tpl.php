
<article class="tile tile--campaign campaign-result <?php print $modifier_classes ?>">
  <?php //krumo($link); ?>
  <?php // @TODO: need variable to store href URL and not the entire <a> link tag! ?>
  <a class="wrapper" href="#">
    <?php if ($staff_pick): ?>
      <div class="__flag -staff-pick">Staff Pick</div>
    <?php endif; ?>
    <div class="tile--meta">
      <h1 class="__title"><?php print $title; ?></h1>
      <p class="__tagline"><?php print $cta; ?></p>
    </div>
    <img src="data:image/gif;base64,R0lGODlhAQABAIAAAAUEBAAAACwAAAAAAQABAAACAkQBADs=" data-src="<?php print $image ?>" alt="<?php print $title; ?>">
  </a>
</article>


<?php /*
<article class="campaign-result <?php print $modifier_classes ?>">
  <?php if($staff_pick) { ?>
    <div class="flag staff-pick">Staff Pick</div>
  <?php } ?>
  <img src="data:image/gif;base64,R0lGODlhAQABAIAAAAUEBAAAACwAAAAAAQABAAACAkQBADs=" data-src="<?php print $image ?>" alt="<?php print $title; ?>">
  <div class="headline">
    <h3><?php print $title; ?></h3>
    <p><?php print $cta; ?></p>
  </div>
  <?php print $link; ?>
</article>
*/ ?>
