<h1 class="__title"><?php print $title; ?></h1>
<h2 class="__subtitle"><?php print $campaign->call_to_action; ?></h2>

<?php if (isset($campaign->end_date) && $campaign->status != 'closed'): ?>
  <p class="__date">Ends <?php print date('F d', $campaign->end_date); ?></p>
<?php endif; ?>
