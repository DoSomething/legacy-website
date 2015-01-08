<?php

/**
 * Generates site-wide global page footer.
 **/

  // Checks if current site is an international affiliate
  $is_affiliate = dosomething_settings_is_affiliate();
?>

<footer class="footer<?php if ($is_affiliate): ?> -affiliate <?php endif; ?>">

  <?php if (isset($affiliate_logo)): ?>
  <div class="footer__column -branding">
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

  <div class="footer__column -social">
    <?php print theme('social-networks', array('social' => $social)); ?>
  </div>

  <?php foreach($links as $column): ?>
  <div class="footer__column -links">
    <h4 class="js-toggle-collapsed"><?php print $column['heading']; ?></h4>
    <?php if (!empty($column['links'])): ?>
    <ul>
      <?php foreach($column['links'] as $link): ?>
        <li><?php print $link; ?></li>
      <?php endforeach; ?>
    </ul>
    <?php endif; ?>
  </div>
  <?php endforeach; ?>

  <div class="footer__subfooter">
    <ul>
      <li><?php print $terms; ?></li>
      <li><?php print $privacy; ?></li>
    </ul>
  </div>
</footer>
