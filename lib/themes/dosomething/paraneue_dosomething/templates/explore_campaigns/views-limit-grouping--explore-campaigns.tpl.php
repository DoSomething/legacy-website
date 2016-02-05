<?php

/**
 * @file views-limit-grouping.tpl.php
 * Basically, just a copy of views-view-unformatted.tpl.php.
 */
?>
<div class="search-result">
  <?php foreach ($rows as $id => $row): ?>
      <?php print $row; ?>
  <?php endforeach; ?>
</div>