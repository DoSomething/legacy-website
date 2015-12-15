<header role="banner" class="header -hero" style="background-image: url('<?php print $cover_image ?>')">
  <div class="wrapper">
    <h1 class="header__title"><?php print $title ?></h1>
    <p class="header__subtitle"><?php print $tagline ?></p>
    <p class="header__actions"><a class="button" href="#" data-modal-href="#modal--register">Sign Up</a></p>
  </div>
</header>

<div class="container -padded container--campaign-gallery">
  <h1 class="heading -banner"><span>The Gallery</span></h1>
  <div class="wrapper">
    <div class="container__block">
      <h2><?php print t('Check out these lunches, and vote eat it or trash it!'); ?></h2>
      <p><?php print t('Man, this food looks delicious. Or does it?!') ?></p>
    </div>

    <div id="reportback" class="reportback" data-nid="<?php print $campaign->id; ?>" data-prefetched="<?php print $reportbacks_gallery['prefetched']; ?>" data-total="<?php print $reportbacks_gallery['total_approved']; ?>" data-admin="false">
      <div class="wrapper">
        <ul class="gallery gallery--reportback">
          <?php for ($i = 0; $i < count($reportbacks_gallery['items']); $i++): ?>
            <li>
              <?php print $reportbacks_gallery['items'][$i]; ?>
            </li>
          <?php endfor; ?>
        </ul>
      </div>
    </div>
  </div>
</div>

<div class="cta">
  <div class="wrapper">
    <?php if (isset($tagline)): ?>
      <h2 class="cta__message"><?php print $tagline; ?></h2>
    <?php endif; ?>

    <p><a class="button" href="#" data-modal-href="#modal--register">Sign Up</a></p>
  </div>
</div>
