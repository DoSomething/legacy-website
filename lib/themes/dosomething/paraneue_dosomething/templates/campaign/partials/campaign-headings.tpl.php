<h1 class="header__title"><?php print $title; ?></h1>
<p class="header__subtitle"><?php print $campaign->call_to_action; ?></p>

<?php if (isset($campaign->end_date) && $campaign->status != 'closed'): ?>
  <p class="header__date">
    <?php print t('Ends ' . $campaign_end_date); ?>
  </p>
<?php endif; ?>
