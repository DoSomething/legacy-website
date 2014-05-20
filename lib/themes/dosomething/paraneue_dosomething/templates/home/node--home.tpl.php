<?php

/**
 * If theme setting is checked, show the new Campaign
 * Finder/new homepage design.
 * @see dosomething_user.module
 */
if( theme_get_setting('show_campaign_finder') ) {

?>

<div class="home--wrapper">
  <div class="finder--form">
    <div class="home--hero">
      <div class="header">
        <h1 class="title">Join 2.5 million young people.</h1>
        <h2 class="subtitle">Any cause, anytime, anywhere.</h2>
      </div>
      <div class="js-finder-form header">
        <h3 class="visually-hidden">Start by finding a campaign below</h3>
        <div class="dropdown large">
          <div class="caret-toggle facet-field" data-toggle="dropdown">
            <h4 class="__title">Cause</h4>
            <p class="__question">What are you passionate about?</p>
          </div>
          <div class="dropdown-menu">
            <ul class="two-col">
              <li><input id="cause-animals" name="cause" type="checkbox" value="16" /><label for="cause-animals">Animals</label></li>
              <li><input id="cause-bullying-violence" name="cause" type="checkbox" value="(13 OR 17)" /><label for="cause-bullying-violence">Bullying + Violence</label></li>
              <li><input id="cause-disasters" name="cause" type="checkbox" value="12" /><label for="cause-disasters">Disasters</label></li>
              <li><input id="cause-discrimination" name="cause" type="checkbox" value="14" /><label for="cause-discrimination">Discrimination</label></li>
              <li><input id="cause-education" name="cause" type="checkbox" value="2" /><label for="cause-education">Education</label></li>
              <li><input id="cause-environment" name="cause" type="checkbox" value="4" /><label for="cause-environment">Environment</label></li>
              <li><input id="cause-health" name="cause" type="checkbox" value="(19 OR 5)" /><label for="cause-health">Health</label></li>
              <li><input id="cause-homelessness-poverty" name="cause" type="checkbox" value="(6 OR 15)" /><label for="cause-homelessness-poverty">Homelessness + Poverty</label></li>
              <li><input id="cause-sex-relationships" name="cause" type="checkbox" value="(1 OR 21)" /><label for="cause-sex-relationships">Sex + Relationships</label></li>
            </ul>
          </div>
        </div>

        <div class="dropdown small">
          <div class="caret-toggle facet-field" data-toggle="dropdown">
            <h4 class="__title">Time</h4>
            <p class="__question">How long do you have?</p>
          </div>
          <div class="dropdown-menu">
            <ul>
              <li><input id="time-1-or-less" name="time" type="checkbox" value="[* TO 1]" /><label for="time-1-or-less">1 hour or less</label></li>
              <li><input id="time-2-to-5" name="time" type="checkbox" value="[2 TO 5]" /><label for="time-2-to-5">2-5 hours</label></li>
              <li><input id="time-5-or-more" name="time" type="checkbox" value="[6 TO *]" /><label for="time-5-or-more">5+ hours</label></li>
            </ul>
          </div>
        </div>

        <div class="dropdown large last">
          <div class="caret-toggle facet-field" data-toggle="dropdown">
            <h4 class="__title">Type</h4>
            <p class="__question">What would you like to do?</p>
          </div>
          <div class="dropdown-menu">
            <ul class="two-col">
              <li><input id="action-donate-something" name="action-type" type="checkbox" value="7" /><label for="action-donate-something">Donate Something</label></li>
              <li><input id="action-face-to-face" name="action-type" type="checkbox" value="3" /><label for="action-face-to-face">Face to Face</label></li>
              <li><input id="action-host-event" name="action-type" type="checkbox" value="11" /><label for="action-host-event">Host an Event</label></li>
              <li><input id="action-improve-space" name="action-type" type="checkbox" value="8" /><label for="action-improve-space">Improve a Space</label></li>
              <li><input id="action-make-something" name="action-type" type="checkbox" value="9" /><label for="action-make-something">Make Something</label></li>
              <li><input id="action-share-something" name="action-type" type="checkbox" value="18" /><label for="action-share-something">Share Something</label></li>
              <li><input id="action-start-something" name="action-type" type="checkbox" value="10" /><label for="action-start-something">Start Something</label></li>
              <li><input id="action-take-stand" name="action-type" type="checkbox" value="20" /><label for="action-take-stand">Take a Stand</label></li>
            </ul>
          </div>
        </div>

        <div class="campaign-search">
          <button class="btn">Find a Campaign</button>
        </div>
      </div>
    </div>
  </div>

  <div class="finder--results -blankslate js-campaign-blankslate">
    <?php foreach($thumbnails as $thumbnail) { print $thumbnail; } ?>
  </div>

  <div class="finder--results js-campaign-results"></div>

  <div class="home--sponsors">
    <h4>Sponsors</h4>
    <p>
      <i title="H&amp;R Block" class="sprite sprite-HRB"></i>
      <i title="Aeropostale" class="sprite sprite-aeropostale"></i>
      <i title="Channel One" class="sprite sprite-channel-one"></i>
      <i title="Fastweb" class="sprite sprite-fastweb"></i>
      <i title="Toyota" class="sprite sprite-toyota"></i>
      <i title="JetBlue" class="sprite sprite-jetblue"></i>
      <i title="AARP" class="sprite sprite-aarp"></i>
      <i title="Sprint" class="sprite sprite-sprint"></i>
      <i title="H&amp;M" class="sprite sprite-hm"></i>
      <i title="Salt" class="sprite sprite-salt"></i>
      <i title="American Express" class="sprite sprite-amex"></i>
      <i title="Google" class="sprite sprite-google"></i>
    </p>
  </div>

<?php

/**
 * If not, let's just use the current homepage contents.
 */
} else {

?>

 <div class="homepage--wrapper">
  <div class="homepage--hero">
    <div class="header">
      <h1>Join over 2.5 million young people taking action.</h1>
      <p>Make the world suck less. Pick a campaign below to get started.</p>
    </div>
  </div>

  <div class="homepage--grid">

    <div class="block-big" style="background-image: url('//www.dosomething.org/files/u/neue-homepage/pregnancytext-large.jpg'); background-position: center center;">
      <a class="full-link" href="/baby"><span>Do This</span></a>
      <div class="headline">
        <h2>Send your friends a text baby to show them how their lives would change if they were a parent.</h2>
      </div>
    </div>

    <div class="block-small" style="background-image: url('//www.dosomething.org/files/u/neue-homepage/comebackclothes-small.jpg'); background-position: top center;">
      <a class="full-link" href="/campaigns/comeback-clothes"><span>Do This</span></a>
      <div class="headline">
        <h2>Recycle old or worn-out clothes to help our planet.</h2>
      </div>
    </div>

    <div class="block-small" style="background-image: url('//www.dosomething.org/files/u/neue-homepage/pbj-small.jpg'); background-position: center center;">
      <a class="full-link" href="/campaigns/peanut-butter-jam-slam"><span>Do This</span></a>
      <div class="headline">
        <h2>Collect peanut butter for your local food bank.</h2>
      </div>
    </div>

    <div class="block-small" style="background-image: url('//www.dosomething.org/files/u/neue-homepage/bullytext-block.jpg'); background-position: center center;">
      <a class="full-link" href="/bully"><span>Do This</span></a>
      <div class="headline">
        <h2>Everyone has the power to stop bullying. Learn how.</h2>
      </div>
    </div>
  </div>

<?php if( theme_get_setting('show_sponsors') ) : ?>
  <div class="homepage--sponsors">
    <h4>Sponsors</h4>
    <p>
      <i title="H&amp;R Block" class="sprite sprite-HRB"></i>
      <i title="Aeropostale" class="sprite sprite-aeropostale"></i>
      <i title="Channel One" class="sprite sprite-channel-one"></i>
      <i title="Fastweb" class="sprite sprite-fastweb"></i>
      <i title="Toyota" class="sprite sprite-toyota"></i>
      <i title="JetBlue" class="sprite sprite-jetblue"></i>
      <i title="AARP" class="sprite sprite-aarp"></i>
      <i title="Sprint" class="sprite sprite-sprint"></i>
      <i title="H&amp;M" class="sprite sprite-hm"></i>
      <i title="Salt" class="sprite sprite-salt"></i>
      <i title="American Express" class="sprite sprite-amex"></i>
      <i title="Google" class="sprite sprite-google"></i>
    </p>
  </div>
</div>
<?php endif; ?>

<?php

}

?>
