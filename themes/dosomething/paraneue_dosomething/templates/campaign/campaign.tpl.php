<div class="content clearfix <?php print $classes; ?>">
	<img src="<?php print $cover_image['src']; ?>" alt="<?php print $cover_image['alt']; ?>" />

	<div id="know">
		<h2>Know</h2>
		<p><?php print $campaign->fact_problem['fact']; ?></p>
		<p class="legal"><?php print $campaign->fact_problem['source']; ?></p>
		<p><?php print $campaign->fact_solution['fact']; ?></p>
		<p class="legal"><?php print $campaign->fact_solution['source']; ?></p>
		<p><?php print $campaign->solution_statement; ?></p>
		<?php if (!empty($campaign->facts)): ?>
	  <h3>More Facts</h3>
	  <?php foreach ($campaign->facts as $fact): ?>
		  <p><?php print $fact['fact']; ?></p>
		  <p class="legal"><?php print $fact['source']; ?></p>
	  <?php endforeach; ?>
	  <?php endif; ?>
		<?php if (!empty($campaign->faq)): ?>
	  <h3>FAQ</h3>
	  <?php foreach ($campaign->faq as $faq): ?>
		  <h4><?php print $faq['title']; ?></h4>
		  <?php print $faq['body']; ?></p>
	  <?php endforeach; ?>
	  <?php endif; ?>
	</div>

	<div id="prep">
		<h2>Prep</h2>
		<p><?php print $campaign->prep_intro; ?></p>
		<p><?php print $campaign->time_and_place; ?></p>
		<p><?php print $campaign->people_involved; ?></p>
		<p><?php print $campaign->items_needed; ?></p>
		<p><?php print $campaign->promoting_tips; ?></p>
	</div>

	<div id="do">
		<h2>Do</h2>
		<?php if (!empty($campaign->step_pre)): ?>
	  <?php foreach ($campaign->step_pre as $step): ?>
		  <h3><?php print $step['title']; ?></h3>
		  <?php print $step['body']; ?></p>
	  <?php endforeach; ?>
	  <?php endif; ?>
	  <h3>Take a Photo</h3>
	  <p><?php print $campaign->step_photo; ?></p>
		<?php if (!empty($campaign->step_post)): ?>
	  <?php foreach ($campaign->step_post as $step): ?>
		  <h3><?php print $step['title']; ?></h3>
		  <?php print $step['body']; ?></p>
	  <?php endforeach; ?>
	  <?php endif; ?>
	</div>

	<?php if (!empty($campaign->action_type)): ?>
  <h4>Action Type</h4>
  <ul>
  <?php foreach ($campaign->action_type as $term): ?>
    <li><?php print $term['link'] ?></li>
  <?php endforeach; ?>
  </ul>
  <?php endif; ?>

	<?php if (!empty($campaign->cause)): ?>
  <h4>Cause</h4>
  <ul>
  <?php foreach ($campaign->cause as $term): ?>
    <li><?php print $term['link'] ?></li>
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
