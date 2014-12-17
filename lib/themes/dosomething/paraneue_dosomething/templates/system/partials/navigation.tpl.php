<?php

/**
 * Generates site-wide global page nav.
 **/
?>

<nav class="chrome--nav<?php if(isset($modifier_classes)): print ' ' . $modifier_classes; endif; ?>">
  <a class="logo" href="<?php print $base_path; ?>"><img src="<?php print $logo ?>" ></a>
  <a class="hamburger js-toggle-mobile-menu" href="#">&#xe606;</a>
  <div class="menu">
    <ul class="primary-nav">
      <li>
        <a href="/campaigns">
          <strong><?php print $explore_campaigns['text']; ?></strong>
          <span><?php print $explore_campaigns['subtext']; ?></span>
        </a>
      </li>

      <li>
        <a href="<?php print url('node/' . $who_we_are['link']); ?>">
          <?php //<strong>What is D<span>o</span>S<span>omething</span>.org?</strong> @TODO: Temp hidden. ?>
          <strong><?php print $who_we_are['text']; ?></strong>
          <span><?php print $who_we_are['subtext']; ?></span>
        </a>
      </li>
    </ul>

    <div class="secondary-nav">
      <ul>
        <li class="searchfield">
          <?php print $search_box; ?>
        </li>
        <?php if(!$logged_in): ?>
        <?php // Will change 'Sign Up' to 'Create Account' once we refactor nav and can fit longer text! ?>
        <?php if( theme_get_setting('show_profile_link') ): ?>
        <li class="account"><a id="link--register" class="secondary-nav-item" href="<?php print $front_page; ?>user/register" data-modal-href="#modal--register"><?php print t('Register'); ?></a></li>
        <?php endif; ?>
        <li class="login"><a id="link--login" class="secondary-nav-item" href="<?php print $front_page; ?>user/login" data-modal-href="#modal--login"><?php print t('Log In'); ?></a></li>
        <?php else: ?>
        <li class="account"><?php print l($user_identifier, 'user/'. $user->uid); ?></li>
        <li class="login"><a id="link--logout" href="<?php print $front_page; ?>user/logout" class="secondary-nav-item"><?php print t('Log Out'); ?></a></li>
        <?php endif; ?>
      </ul>
    </div>
  </div>
</nav>
