<?php

/**
 * Generates site-wide global page nav.
 **/

?>

<nav class="chrome--nav">
  <a class="logo" href="<?php print $base_path; ?>"><img src="<?php print NEUE_ASSET_PATH; ?>/assets/images/ds-logo.png" alt="DoSomething.org"></a>
  <a class="hamburger js-toggle-mobile-menu" href="#">&#xe606;</a>
  <div class="menu">
    <ul class="primary-nav">
      <li>
        <a href="/campaigns">
          <strong>Explore Campaigns</strong>
          <span>Any cause, anytime, anywhere.</span>
        </a>
      </li>

      <li>
        <a href="<?php print url('node/538');  ?>">
          <?php //<strong>What is D<span>o</span>S<span>omething</span>.org?</strong> @TODO: Temp hidden. ?>
          <strong>What is DoSomething.org?</strong>
          <span>Young people + social change.</span>
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
        <li class="account"><a href="<?php print $front_page; ?>user/register" class="secondary-nav-item js-modal-link" data-cached-modal="#modal--register">Register</a></li>
        <?php endif; ?>
        <li class="login"><a href="<?php print $front_page; ?>user/login" class="secondary-nav-item js-modal-link" data-cached-modal="#modal--login">Log In</a></li>
        <?php else: ?>
        <?php if( theme_get_setting('show_profile_link') ): ?>
        <li class="account"><?php print l($user_identifier, 'user/'. $user->uid); ?></li>
        <?php endif; ?>
        <li class="login"><a href="<?php print $front_page; ?>user/logout" class="secondary-nav-item">Log Out</a></li>
        <?php endif; ?>
      </ul>
    </div>
  </div>
</nav>
