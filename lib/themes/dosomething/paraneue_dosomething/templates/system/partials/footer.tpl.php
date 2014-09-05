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

  <?php print theme('social-networks', array(
    'social' => $social,
    'container_classes' => 'mobile',
  )); ?>

  <div class="subfooter">
    <ul class="utility">
      <li><?php print $terms; ?></li>
      <li><?php print $privacy; ?></li>
    </ul>
  </div>
</footer>
