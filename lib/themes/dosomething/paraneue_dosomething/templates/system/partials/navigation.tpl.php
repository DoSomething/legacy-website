<?php

/**
 * Generates site-wide global page nav.
 **/

?>

<nav class="chrome--nav">
  <a class="logo" href="<?php print $base_path; ?>"><img src="/<?php print NEUE_PATH; ?>/assets/images/ds-logo.png" alt="DoSomething.org"></a>
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
          <strong>What is D<span>o</span>S<span>omething</span>.org?</strong>
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
        <li class="account"><a href="<?php print $front_page; ?>user/register" class="secondary-nav-item js-modal-link" data-cached-modal="#modal--register">Register</a></li>
        <li class="login"><a href="<?php print $front_page; ?>user/login" class="secondary-nav-item js-modal-link" data-cached-modal="#modal--login">Log In</a></li>
        <?php else: ?>
        <li class="account"><a href="/users/<?php print $user->uid ?>"><?php print $user_identifier; ?></a></li>
        <li class="login"><a href="<?php print $front_page; ?>user/logout" class="secondary-nav-item">Log Out</a></li>
        <?php endif; ?>
      </ul>
    </div>
  </div>
</nav>
