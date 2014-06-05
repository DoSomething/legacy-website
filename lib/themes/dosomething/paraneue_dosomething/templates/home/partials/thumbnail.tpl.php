<div class="campaign-result <?php print $modifier_classes ?>">
  <?php if($staff_pick) { ?>
    <div class="flag staff-pick">Staff Pick</div>
  <?php } ?>
  <img src="data:image/gif;base64,R0lGODlhAQABAIAAAAUEBAAAACwAAAAAAQABAAACAkQBADs=" data-src="<?php print $image ?>" alt="<?php print $title; ?>">
  <div class="headline">
    <h3><?php print $title; ?></h3>
    <p><?php print $cta; ?></p>
  </div>
  <?php print $link; ?>
</div>
