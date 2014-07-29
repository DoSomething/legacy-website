<?php
/**
 * Expected variables:
 *  - $sponsors: (array) Expected data:
 *    - logo_url: (string) URL of the logo file to render.
 *    - name: (string) Sponsor name
 */
?>

<div class="promotion promotion--sponsor">
  <div class="wrapper">
    <p class="__copy"><?php print t('Powered by'); ?></p>
    <?php foreach ($sponsors as $sponsor) :?>
      <div class="__image">
        <img src="<?php print $sponsor['logo_url']; ?>" alt="<?php print $sponsor['name']; ?>" />
      </div>
    <?php endforeach; ?>
  </div>
</div>
