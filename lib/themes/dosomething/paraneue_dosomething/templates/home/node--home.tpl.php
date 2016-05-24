<?php

/**
 * If theme setting is checked, show the new Campaign
 * Finder/new homepage design.
 * @see dosomething_user.module
 */

  // Checks if current site is an international affiliate
  $is_affiliate = dosomething_settings_is_affiliate();
?>

<header role="banner" class="header header--home">
  <div class="wrapper">
    <h1 class="header__title"><?php print $title; ?></h1>
    <h2 class="header__subtitle"><?php print $subtitle; ?></h2>

    <?php if( $show_campaign_finder ): ?>
    <div class="finder--form js-finder-form">
      <h3 class="visually-hidden"><?php print t('Start by finding a campaign below'); ?></h3>
      <div class="dropdown large">
        <div class="wrapper">
          <div class="caret-toggle facet-field" data-toggle="dropdown">
            <h4 class="__title"><?php print t('Cause'); ?></h4>
            <p class="__question"><?php print t('What are you passionate about?'); ?></p>
          </div>
          <div class="dropdown-menu">
            <ul class="two-col">
              <li><input id="cause-animals" name="cause" type="checkbox" value="16" /><label for="cause-animals"><?php print t('Animals'); ?></label></li>
              <li><input id="cause-bullying-violence" name="cause" type="checkbox" value="(13 OR 17)" /><label for="cause-bullying-violence"><?php print t('Bullying + Violence'); ?></label></li>
              <li><input id="cause-disasters" name="cause" type="checkbox" value="12" /><label for="cause-disasters"><?php print t('Disasters'); ?></label></li>
              <li><input id="cause-discrimination" name="cause" type="checkbox" value="14" /><label for="cause-discrimination"><?php print t('Discrimination'); ?></label></li>
              <li><input id="cause-education" name="cause" type="checkbox" value="2" /><label for="cause-education"><?php print t('Education'); ?></label></li>
              <li><input id="cause-environment" name="cause" type="checkbox" value="4" /><label for="cause-environment"><?php print t('Environment'); ?></label></li>
              <li><input id="cause-health" name="cause" type="checkbox" value="(19 OR 5)" /><label for="cause-health"><?php print t('Health'); ?></label></li>
              <li><input id="cause-homelessness-poverty" name="cause" type="checkbox" value="(6 OR 15)" /><label for="cause-homelessness-poverty"><?php print t('Homelessness + Poverty'); ?></label></li>
              <li><input id="cause-sex-relationships" name="cause" type="checkbox" value="(1 OR 21)" /><label for="cause-sex-relationships"><?php print t('Sex + Relationships'); ?></label></li>
            </ul>
          </div>
        </div>
      </div>

      <div class="dropdown small">
        <div class="wrapper">
          <div class="caret-toggle facet-field" data-toggle="dropdown">
            <h4 class="__title"><?php print t('Time'); ?></h4>
            <p class="__question"><?php print t('How long do you have?'); ?></p>
          </div>
          <div class="dropdown-menu">
            <ul>
              <li><input id="time-1-or-less" name="time" type="checkbox" value="[* TO 1]" /><label for="time-1-or-less"><?php print t('1 hour or less'); ?></label></li>
              <li><input id="time-2-to-5" name="time" type="checkbox" value="[2 TO 5]" /><label for="time-2-to-5"><?php print t('2-5 hours'); ?></label></li>
              <li><input id="time-5-or-more" name="time" type="checkbox" value="[6 TO *]" /><label for="time-5-or-more"><?php print t('5+ hours'); ?></label></li>
            </ul>
          </div>
        </div>
      </div>

      <div class="dropdown large last">
        <div class="wrapper">
            <div class="caret-toggle facet-field" data-toggle="dropdown">
              <h4 class="__title"><?php print t('Type'); ?></h4>
              <p class="__question"><?php print t('What would you like to do?'); ?></p>
            </div>
            <div class="dropdown-menu">
              <ul class="two-col">
                <li><input id="action-donate-something" name="action-type" type="checkbox" value="7" /><label for="action-donate-something"><?php print t('Donate Something'); ?></label></li>
                <li><input id="action-face-to-face" name="action-type" type="checkbox" value="3" /><label for="action-face-to-face"><?php print t('Face to Face'); ?></label></li>
                <li><input id="action-host-event" name="action-type" type="checkbox" value="11" /><label for="action-host-event"><?php print t('Host an Event'); ?></label></li>
                <li><input id="action-improve-space" name="action-type" type="checkbox" value="8" /><label for="action-improve-space"><?php print t('Improve a Space'); ?></label></li>
                <li><input id="action-make-something" name="action-type" type="checkbox" value="9" /><label for="action-make-something"><?php print t('Make Something'); ?></label></li>
                <li><input id="action-share-something" name="action-type" type="checkbox" value="18" /><label for="action-share-something"><?php print t('Share Something'); ?></label></li>
                <li><input id="action-start-something" name="action-type" type="checkbox" value="10" /><label for="action-start-something"><?php print t('Start Something'); ?></label></li>
                <li><input id="action-take-stand" name="action-type" type="checkbox" value="20" /><label for="action-take-stand"><?php print t('Take a Stand'); ?></label></li>
              </ul>
            </div>
          </div>
        </div>
      </div>
    <?php endif; ?>
  </div>
</header>

<section class="container finder--results -blankslate js-campaign-blankslate">
  <ul class="gallery -quartet -featured -mosaic">
    <?php foreach($thumbnails as $thumbnail) { print '<li>' . $thumbnail . '</li>'; } ?>
  </ul>
</section>

<?php if( $show_campaign_finder ): ?>
<section class="container finder--results js-campaign-results"></section>
<?php endif; ?>

<?php if( $show_sponsors && !$is_affiliate ) : ?>
<section class="container container--sponsors">
  <div class="wrapper">
    <div class="container__block">
      <h4><?php print t('Sponsors'); ?></h4>
      <ul>
        <?php foreach($partners as $partner) { print '<li><img src="' . $partner['logo']['path'] . '" title="' . $partner['name'] . '"></li>'; } ?>
      </ul>
    </div>
  </div>
</section>
<?php endif; ?>
