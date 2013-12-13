<div class="content clearfix <?php print $classes; ?>">
	<img src="<?php print $cover_image['src']; ?>" alt="<?php print $cover_image['alt']; ?>" />
	<div>
		<p><?php print $campaign->stat_problem; ?></p>
		<p><?php print $campaign->stat_solution; ?></p>
	</div>

	<?php if (!empty($campaign->action_type)): ?>
  <h4>Action Type</h4>
  <ul>
  <?php foreach ($campaign->action_type as $term): ?>
    <li><?php print l($term['name'], 'taxonomy/term/' . $term['tid']); ?></li>
  <?php endforeach; ?>
  </ul>
  <?php endif; ?>

	<?php if (!empty($campaign->cause)): ?>
  <h4>Cause</h4>
  <ul>
  <?php foreach ($campaign->cause as $term): ?>
    <li><?php print l($term['name'], 'taxonomy/term/' . $term['tid']); ?></li>
  <?php endforeach; ?>
  </ul>
  <?php endif; ?>

	<?php if (!empty($campaign->gallery)): ?>
  <div id="gallery">
  <?php foreach ($campaign->gallery as $image): ?>
    <img src="<?php print $image['src']; ?>" alt="<?php print $image['alt']; ?>" />
  <?php endforeach; ?>
  </div>
  <?php endif; ?>

</div>
