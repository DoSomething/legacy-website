<?php

/**
 * Generates site-wide global page nav.
 **/
?>

<header role="banner" class="header <?php if (isset($sponsors)): print ' -sponsored'; endif; ?>">
  <div class="wrapper">
    <h1 class="header__title"><?php print $title; ?></h1>
    <?php if (isset($subtitle)): ?>
    <p class="header__subtitle"><?php if (isset($subtitle)): print $subtitle; endif; ?></p>
    <?php endif; ?>

    <?php if (isset($promotions)) { print $promotions; } ?>
  </div>
</header>
