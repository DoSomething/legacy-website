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
      <?php if(!$logged_in): ?>
        <?php if( theme_get_setting('show_profile_link') ): ?>
      <li class="account"><a id="link--register" class="secondary-nav-item" href="<?php print $front_page; ?>user/register" data-modal-href="#modal--register"><?php print t('Create an account'); ?></a></li>
      <?php endif; ?>
      <li class="login"><a id="link--login" class="secondary-nav-item" href="<?php print $front_page; ?>user/login" data-modal-href="#modal--login"><?php print t('Log In'); ?></a></li>
      <?php else: ?> 
      <li class="navigation__dropdown"><p class="navigation__dropdown--toggle"><?php print $user_identifier ?></p>
        <ul>
          <li><?php print l("My Account", 'user/'. $user->uid); ?></li>
          <li><a id="link--logout" href="<?php print $front_page; ?>user/logout"><?php print t('Log Out'); ?></a></li>
        </ul>
      </li>          
    <?php endif; ?>
    </ul>
  </div>
</nav>
