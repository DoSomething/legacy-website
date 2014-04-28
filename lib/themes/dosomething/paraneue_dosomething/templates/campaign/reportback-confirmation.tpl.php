<section class="confirmation-wrapper">
  <div class="header-wrapper">
    <header class="header">
      <h1 class="title">You Did It!</h1>
      <?php if (isset($copy)): ?>
        <h2 class="subtitle"><?php print $copy; ?></h2>
      <?php endif; ?>
    </header>
  </div>

  <?php if (isset($recommended)): ?>
    <div class="gallery-wrapper">
      <h2 class="gallery-title">Keep it up! Find your next campaign.</h2>
      <div class="gallery">
        <?php foreach ($recommended as $rec): ?>
          <div class="gallery-item">
            <?php if (isset($rec['image'])): ?>
              <a href="<?php print $rec['src']; ?>"><img src="<?php print $rec['image']; ?>"/></a>
            <?php endif; ?>

            <?php if (isset($rec['title'])): ?>
              <h3 class="title"><?php print l($rec['title'], $rec['src']); ?></h3>
            <?php endif; ?>

            <?php if (isset($rec['call_to_action'])): ?>
              <div class="gallery-description"><?php print $rec['call_to_action']; ?></div>
            <?php endif; ?>
          </div>
        <?php endforeach; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($more_campaigns_link)): ?>
    <div class="cta-wrapper">
      <div class="cta">
        <div class="cta-more-campaigns"><?php print $more_campaigns_link; ?></div>
        <div class="cta-back-to-campaign"><?php if (isset($back_to_campaign_link)): ?><?php print $back_to_campaign_link; ?><?php endif; ?></div>
      </div>
    </div>
  <?php endif; ?>
</section>
