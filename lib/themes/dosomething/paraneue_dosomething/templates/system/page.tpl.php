<?php

/**
 * Generates site-wide page chrome.
 * @see https://drupal.org/node/1728148
 **/

?>

<?php if (!empty($tabs['#primary'])): ?><nav class="admin--tabs"><?php print render($tabs); ?></nav><?php endif; ?>
<?php print $messages; ?>
<div class="chrome--wrapper">
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
          <li><a href="<?php print $front_page; ?>user/login" class="secondary-nav-item js-modal-link" data-cached-modal="#modal--login">Log In</a></li>
          <?php else: ?>
          <li><a href="<?php print $front_page; ?>user/logout" class="secondary-nav-item">Log Out</a></li>
          <?php endif; ?>
        </ul>
      </div>
    </div>
  </nav>

  <main role="main">
    <?php print render($page['content']); ?>
  </main>
</div>

<footer class="chrome--footer">
  <div class="social tablet">
    <ul>
      <li><a class="social-link" title="dosomething on Facebook" href="https://www.facebook.com/dosomething">&#xe600;</a></li>
      <li><a class="social-link" title="@dosomething on Twitter" href="https://twitter.com/dosomething">&#xe603;</a></li>
      <li><a class="social-link" title="@dosomething on Tumblr" href="http://dosomething.tumblr.com">&#xe602;</a></li>
      <li><a class="social-link" title="@dosomething on Instagram" href="http://instagram.com/dosomething">&#xe604;</a></li>
      <li><a class="social-link" title="dosomething1 on YouTube" href="http://www.youtube.com/dosomething1">&#xe601;</a></li>
    </ul>
  </div>
  <div class="col help js-footer-col">
    <h4>Help</h4>
    <ul>
      <li><?php print l("Contact Us", "node/516") ?></li>
      <li><?php print l("Hotlines", "node/518") ?></li>
      <li><?php print l("FAQs", "node/1052") ?></li>
    </ul>
  </div>
  <div class="col knowus js-footer-col">
    <h4>Get to Know Us</h4>
    <ul>
      <li><?php print l("Partners", "node/532") ?></li>
      <li><?php print l("Donate", "node/539") ?></li>
      <li><a href="http://www.tmiagency.org">TMI Agency</a></li>
    </ul>
  </div>
  <div class="col about js-footer-col">
    <h4>About</h4>
    <ul>
      <li><?php print l("What is DoSomething.org?", "node/538") ?></li>
      <li><?php print l("Our Team", "node/1044") ?></li>
      <li><?php print l("Jobs", "node/565") ?></li>
      <li><?php print l("Internships", "node/940") ?></li>
      <li><?php print l("Old People", "node/329") ?></li>
      <li><?php print l("Sexy Financials", "node/540") ?></li>
      <li><?php print l("International", "node/523") ?></li>
    </ul>
  </div>

  <div class="social mobile">
    <ul>
      <li><a class="social-link" title="dosomething on Facebook" href="https://www.facebook.com/dosomething">&#xe600;</a></li>
      <li><a class="social-link" title="@dosomething on Twitter" href="https://www.twitter.com/dosomething">&#xe603;</a></li>
      <li><a class="social-link" title="@dosomething on Tumblr" href="http://dosomething.tumblr.com">&#xe602;</a></li>
      <li><a class="social-link" title="@dosomething on Instagram" href="http://www.instagram.com/dosomething">&#xe604;</a></li>
      <li><a class="social-link" title="dosomething1 on YouTube" href="https://www.youtube.com/dosomething1">&#xe601;</a></li>
    </ul>
  </div>

  <div class="subfooter">
    <ul class="utility">
      <li><?php print l("Terms of Service", "node/1049") ?></li>
      <li><?php print l("Privacy Policy", "node/1050") ?></li>
    </ul>
  </div>
</footer>
</div>
