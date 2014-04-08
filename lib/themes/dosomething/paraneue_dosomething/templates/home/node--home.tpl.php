<?php

/**
 * If theme setting is checked, show the new Campaign
 * Finder/new homepage design.
 * @see dosomething_user.module
 */
if( theme_get_setting('show_campaign_finder') ) {

?>

<div class="home--wrapper">
  <div class="finder--form js-campaign-finder">
    <div class="home--hero">
      <div class="header">
        <h1>What do you wanna do <span class="underline">today</span>?</h1>
      </div>
      <div class="header">
        <div class="dropdown large">
          <div class="caret-toggle facet-field" data-toggle="dropdown">Cause</div>
          <p class="facet-field">What are you passionate about?</p>
          <div class="dropdown-menu">
            <ul class="two-col">
              <li><label><input name="cause" type="checkbox" value="16" />Animals</label></li>
              <li><label><input name="cause" type="checkbox" value="13 OR 17" />Bullying + Violence</label></li>
              <li><label><input name="cause" type="checkbox" value="12" />Disasters</label></li>
              <li><label><input name="cause" type="checkbox" value="14" />Discrimination</label></li>
              <li><label><input name="cause" type="checkbox" value="2" />Education</label></li>
              <li><label><input name="cause" type="checkbox" value="4" />Environment</label></li>
              <li><label><input name="cause" type="checkbox" value="19 OR 5" />Health</label></li>
              <li><label><input name="cause" type="checkbox" value="6 OR 15" />Homelessness + Poverty</label></li>
              <li><label><input name="cause" type="checkbox" value="1 OR 21" />Sex + Relationships</label></li>
            </ul>
          </div>
        </div>

        <div class="dropdown small">
          <div class="caret-toggle facet-field" data-toggle="dropdown">Time</div>
          <p class="facet-field">How long do you have?</p>
          <div class="dropdown-menu">
            <ul>
              <li><label><input name="time" type="checkbox" value="[* TO 2]" />Less than 2 hours</label></li>
              <li><label><input name="time" type="checkbox" value="[2 TO 5]" />5 hours</label></li>
              <li><label><input name="time" type="checkbox" value="[5 TO *]" />10 hours</label></li>
            </ul>
          </div>
        </div>

        <div class="dropdown large">
          <div class="caret-toggle facet-field" data-toggle="dropdown">Type</div>
          <p class="facet-field">What would you like to do?</p>
          <div class="dropdown-menu">
            <ul class="two-col">
              <li><label><input name="action-type" type="checkbox" value="7" />Donate Something</label></li>
              <li><label><input name="action-type" type="checkbox" value="3" />Face to Face</label></li>
              <li><label><input name="action-type" type="checkbox" value="11" />Host an Event</label></li>
              <li><label><input name="action-type" type="checkbox" value="8" />Improve a Space</label></li>
              <li><label><input name="action-type" type="checkbox" value="9" />Make Something</label></li>
              <li><label><input name="action-type" type="checkbox" value="18" />Share Something</label></li>
              <li><label><input name="action-type" type="checkbox" value="10" />Start Something</label></li>
              <li><label><input name="action-type" type="checkbox" value="20" />Take a Stand</label></li>
            </ul>
          </div>
        </div>

        <div class="campaign-search">
          <button class="btn">Find a Campaign</button>
        </div>
      </div>
    </div>
  </div>

  <div id="campaign-results" class="finder--results">
  </div>
  </div>


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

<?php

}

?>
