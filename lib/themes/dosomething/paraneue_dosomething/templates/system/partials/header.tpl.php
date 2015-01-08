<?php

/**
 * Generates site-wide global page nav.
 **/
?>

<header role="banner" class="-basic<?php if (isset($sponsors)): print ' -sponsored'; endif; ?>">
  <div class="wrapper">
    <h1 class="__title"><?php print $title; ?></h1>
    <?php if (isset($subtitle)): ?>
    <p class="__subtitle"><?php if (isset($subtitle)): print $subtitle; endif; ?></p>
    <?php endif; ?>

    <?php if (isset($sponsors)): ?>
    <div class="sponsor">
      <p class="__copy"><?php print t('Powered by'); ?></p>
      <?php foreach ($sponsors as $key => $sponsor) :?>
        <?php if (isset($sponsor['display'])): print $sponsor['display']; endif; ?>
      <?php endforeach; ?>
    </div>
    <?php endif; ?>
  </div>
</header>
