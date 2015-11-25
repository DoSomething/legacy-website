<h1 class="header__title"><?php print $title; ?></h1>
<p class="header__subtitle"><?php print $campaign->call_to_action; ?></p>

<?php if (isset($campaign->end_date) && $campaign->status != 'closed'): ?>
  <p class="header__date">
    <?php print t('Ends @end_date', ['@end_date' => date('F d', $campaign->end_date)]); ?>
  </p>
<?php endif; ?>
