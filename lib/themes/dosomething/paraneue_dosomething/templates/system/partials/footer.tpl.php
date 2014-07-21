<?php

/**
 * Generates site-wide global page footer.
 **/

  // Checks if current site is an international affiliate
  $is_affiliate = dosomething_settings_is_affiliate();
?>

<footer class="chrome--footer<?php if ($is_affiliate): ?> -affiliate <?php endif; ?>">

  <?php if (isset($affiliate_logo)): ?>
  <div class="col branding">
    <h4><?php print $affiliate_logo['text'] ?></h4>
    <?php 
      print theme_image(array(
        'path'  => $affiliate_logo['file'],
        'title' => $affiliate_logo['text'],
        'alt'   => $affiliate_logo['text'],
      )); 
    ?>
  </div>
  <?php endif; ?>

  <?php print theme('social-networks', array(
    'social' => $social,
    'container_classes' => 'tablet',
  )); ?>

  <?php foreach($links as $column): ?>
  <div class="col <?php print $column['class']; ?> js-footer-col">
    <h4><?php print $column['heading']; ?></h4>
    <?php if (!empty($column['links'])): ?>
    <ul>
      <?php foreach($column['links'] as $link): ?>
        <li><?php print $link; ?></li>
      <?php endforeach; ?>
    </ul>
    <?php endif; ?>
  </div>
  <?php endforeach; ?>

  <div class="social mobile">
    <ul>
      <?php if ($social['facebook'] !== 0): ?>
      <li><a class="social-link" title="dosomething on Facebook" href="https://www.facebook.com/dosomething">&#xe600;</a></li>
      <?php endif; ?>
      <?php if ($social['twitter'] !== 0): ?>
      <li><a class="social-link" title="@dosomething on Twitter" href="https://twitter.com/dosomething">&#xe603;</a></li>
      <?php endif; ?>
      <?php if ($social['tumblr'] !== 0): ?>
      <li><a class="social-link" title="@dosomething on Tumblr" href="http://dosomething.tumblr.com">&#xe602;</a></li>
      <?php endif; ?>
      <?php if ($social['instagram'] !== 0): ?>
      <li><a class="social-link" title="@dosomething on Instagram" href="http://instagram.com/dosomething">&#xe604;</a></li>
      <?php endif; ?>
      <?php if ($social['youtube'] !== 0): ?>
      <li><a class="social-link" title="dosomething1 on YouTube" href="http://www.youtube.com/dosomething1">&#xe601;</a></li>
      <?php endif; ?>
    </ul>
  </div>

  <div class="subfooter">
    <ul class="utility">
      <li><?php print l("Terms of Service", "node/1049") ?></li>
      <li><?php print l("Privacy Policy", "node/1050") ?></li>
    </ul>
  </div>
</footer>
