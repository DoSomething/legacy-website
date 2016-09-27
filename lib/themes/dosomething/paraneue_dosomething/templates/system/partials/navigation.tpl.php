<?php

/**
 * Generates site-wide global page nav.
 **/

?>

<nav class="navigation<?php if(isset($modifier_classes)): print ' ' . $modifier_classes; endif; ?>">
  <a class="navigation__logo" href="<?php print $base_path; ?>"><span>DoSomething.org</span></a>
  <a class="navigation__toggle js-navigation-toggle" href="#"><span>Show Menu</span></a>
  <div class="navigation__menu">
    <ul class="navigation__primary">
      <li>
        <a href="/campaigns">
          <strong class="navigation__title"><?php print $explore_campaigns['text']; ?></strong>
          <span class="navigation__subtitle"><?php print $explore_campaigns['subtext']; ?></span>
        </a>
      </li>

      <li>
        <a href="<?php print url('node/' . $who_we_are['link']); ?>">
          <strong class="navigation__title"><?php print $who_we_are['text']; ?></strong>
          <span class="navigation__subtitle"><?php print $who_we_are['subtext']; ?></span>
        </a>
      </li>
    </ul>

    <ul class="navigation__secondary">
      <li>
        <?php print $search_box; ?>
      </li>
      <?php if($logged_in): ?>
        <li class="navigation__dropdown">
          <a href="#" class="navigation__dropdown-toggle"><?php print $user_identifier ?></a>
          <ul>
            <li><?php print l(t('My Account'), 'user/' . $user->uid); ?></li>
            <li><?php print l(t('Log Out'), 'user/logout', ['attributes' => ['class' => ['secondary-nav-item'], 'id' => 'link--logout']]) ?></li>
          </ul>
        </li>
      <?php else: ?>
        <li class="login"><?php print $log_in_link ?></li>
      <?php endif; ?>
    </ul>
  </div>
</nav>
