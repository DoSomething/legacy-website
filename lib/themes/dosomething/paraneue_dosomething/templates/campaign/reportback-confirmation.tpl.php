<section class="confirmation--wrapper">
  <header class="header">
    <div class="content">
      <h1>You Did It!</h1>
      <p><?php print $copy; ?></p>
      <?php print $more_campaigns_link; ?>
      <?php print $back_to_campaign_link; ?>
    </div>
  </header>

  <section class="campaigns">
    <div class="content">
    <?php foreach ($recommended as $rec): ?>
      <div class="campaign">
        <h3 class="title"><?php print $rec['title']; ?></h3>
        <?php if (isset($rec['image'])): ?>
        <figure class="image"><img src="<?php print $rec['image']; ?>" alt="Campaign Image" /></figure>
        <?php endif; ?>
        <p><?php print $rec['call_to_action']; ?></p>
      </div>
    <?php endforeach; ?>
    </div>
  </section>
</section>
