<section class="confirmation--wrapper">
  <header class="header">
    <div class="content">
      <h1>You Did It!</h1>
      <?php if (isset($copy)): ?><p><?php print $copy; ?></p><?php endif; ?>
      <?php if (isset($more_campaign_link)): ?><?php print $more_campaigns_link; ?><?php endif; ?>
      <?php if (isset($back_to_campaign_link)): ?><?php print $back_to_campaign_link; ?><?php endif; ?>
    </div>
  </header>

  <section class="campaigns">
    <div class="content">
    <?php foreach ($recommended as $rec): ?>
      <div class="campaign">
        <?php if (isset($rec['title'])): ?><h3 class="title"><?php print $rec['title']; ?></h3><?php endif; ?>
        <?php if (isset($rec['image'])): ?>
        <figure class="image"><img src="<?php print $rec['image']; ?>" alt="Campaign Image" /></figure>
        <?php endif; ?>
        <?php if (isset($rec['call_to_action'])): ?><p><?php print $rec['call_to_action']; ?></p><?php endif; ?>
      </div>
    <?php endforeach; ?>
    </div>
  </section>
</section>
