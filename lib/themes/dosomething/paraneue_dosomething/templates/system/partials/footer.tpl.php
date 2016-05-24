<?php

/**
 * Generates site-wide global page footer.
 **/

?>

<footer class="footer">
  <div class="footer__columns">
    <div class="footer__column -social">
      <?php print theme('social-networks', ['social' => $social]); ?>
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
  </div>

  <div class="footer__subfooter">
    <ul>
      <li><?php print $terms; ?></li>
      <li><?php print $privacy; ?></li>
    </ul>
  </div>
</footer>
