<header role="banner" class="header -hero">
  <div class="wrapper">
    <h1 class="header__title">Campaign Title</h1>
    <p class="header__subtitle">Subtitle</p>
    <p class="header__actions"><a class="button" href="#">Sign Up</a></p>
  </div>
</header>

<div class="container -padded">
  <div class="wrapper">
    <div class="container__block">
      <h2><?php print t('Check out these lunches, and vote eat it or trash it!'); ?></h2>
      <p><?php print t('Man, this food looks delicious. Or does it?!') ?></p>
    </div>

    <div class="gallery -triad">
      <li>Whaaa</li>
      <li>Whaaa</li>
      <li>Whaaa</li>
    </div>
  </div>
</div>

<div class="cta">
  <div class="wrapper">
    <?php if (isset($call_to_action)): ?>
      <h2 class="cta__message"><?php print $call_to_action; ?></h2>
    <?php endif; ?>

    <p><?php if (isset($back_to_campaign_link)): ?><?php print $back_to_campaign_link; ?><?php endif; ?></p>
  </div>
</div>
