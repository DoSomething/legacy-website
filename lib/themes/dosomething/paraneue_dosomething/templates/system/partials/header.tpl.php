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

    <?php if (isset($sponsors)): ?>
      <div class="promotion promotion--sponsor">
        <div class="wrapper">
          <p class="__copy"><?php print t('Powered by'); ?></p>
          <?php foreach ($sponsors as $sponsor) :?>
            <div class="__image">
              <?php if (isset($sponsor['display'])): print $sponsor['display']; endif; ?>
            </div>
          <?php endforeach; ?>
        </div>
      </div>
    <?php endif; ?>
  </div>
</header>
