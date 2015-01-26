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
	<?php // Will change 'Sign Up' to 'Create Account' once we refactor nav and can fit longer text! ?>
	<?php if( theme_get_setting('show_profile_link') ): ?>
	  <li class="account"><a id="link--register" class="secondary-nav-item" href="<?php print $front_page; ?>user/register" data-modal-href="#modal--register"><?php print t('Create an account'); ?></a></li>
	<?php endif; ?>
	<li class="login"><a id="link--login" class="secondary-nav-item" href="<?php print $front_page; ?>user/login" data-modal-href="#modal--login"><?php print t('Log In'); ?></a></li>
      <?php else: ?>
	<li class="navigation__dropdown clicked"><a href="<?php print 'user/' . $user->uid; ?>" class="navigation__dropdown--toggle"><?php print $user_identifier ?></a>
	  <ul>
	    <li><?php print l("My Account", 'user/'. $user->uid); ?></li>
	    <li><a id="link--logout" href="<?php print $front_page; ?>user/logout"><?php print t('Log Out'); ?></a></li>
	  </ul>
	</li>          
      <?php endif; ?>
    </ul>
  </div>
</nav>

<style type="text/css">
  .navigation__dropdown ul {
    visibility: hidden;
  }

  .navigation__dropdown.clicked {
    background-color: #fff;
    padding-top: 0;
    padding-bottom: 0; 
    margin-left: 36px;
    padding-left: 8px;
    padding-right: 8px;
    border-radius: 4px;
    margin-top: 12px;
    margin-right: 8px;
    min-width: 180px;
  }

  .navigation__dropdown.clicked a, ul {
    color: #222;
    font-weight: normal;
    text-shadow: none; 
    margin-left: 0;
    padding-left: 0;
    padding-top: 4px;
    padding-bottom: 4px;
    padding-right: 0px;
  }

  .clicked a.navigation__dropdown--toggle {
    color: #4e2b63;
    font-weight: bold;
    border-bottom: 1px solid #ddd;
    padding-bottom: 1px;
  }

  .navigation__dropdown.clicked li {
    visibility: visible;
    display: block;
    float: none;
    padding-top: 0;
    padding-bottom: 0;  
  }
</style>
