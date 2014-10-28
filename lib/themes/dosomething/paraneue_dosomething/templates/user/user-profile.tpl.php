<?php
/**
 * Returns the HTML for User Profile page.
 * @see https://api.drupal.org/api/drupal/modules%21user%21user-profile.tpl.php/7
 *
 * Available Variables
 * - $user_account: An array of user account profile information.
 *   - [id]: User id number (string).
 *   - [username]: Account name (string).
 *   - [email]: Account email address (string).
 *   - [first_name]: User's first name (string).
 *   - [last_name]: User's last name (string).
 *   - [birthday]: User's birthday (string).
 *   - [mobile]: User's mobile cell number (string).
 *   - [location]: Array containing address information whether empty or with data.
 *     - [country]: User's country of residence (string).
 *     - [state]: User's state of residence (string).
 *     - [city]: User's city of residence (string).
 *     - [zip]: User's postal zip code (string).
 *     - [street]: User's street address (string).
 *     - [premise]: User's apartment, suite, etc... (string).
*   - [address]: Array containing address information only for submitted data.
 *     - [country]: User's country of residence (string).
 *     - [state]: User's state of residence (string).
 *     - [city]: User's city of residence (string).
 *     - [zip]: User's postal zip code (string).
 *     - [street]: User's street address (string).
 *     - [premise]: User's apartment, suite, etc... (string).
 *   - [doing]: Array containing a data for campaigns a User has signed up for.
 */
  $address = $user_account['address'];
?>


<article class="user profile"<?php print $attributes; ?> id="user-<?php print $user_account['id']; ?>">

  <header role="banner" class="-basic">
    <div class="wrapper">
      <h1 class="__title"><?php print $title; ?></h1>
      <?php if (!empty($subtitle)): ?>
        <h2 class="__subtitle"><?php print $subtitle; ?></h2>
      <?php endif; ?>
    </div>
  </header>

  <section class="profile--campaigns">
    <h1 class="banner"><span><?php print t("You're Doing"); ?></span></h1>
    <div class="wrapper">
    <?php if (empty($doing)): ?>
      <h2 class="__message"><?php print $no_signups_header; ?></h2>
      <p><?php print $no_signups_copy; ?></p>
      <a href="/campaigns" class="btn"><?php print t('Explore Campaigns'); ?></a>
    <?php else: ?>
      <ul class="gallery -triad">
        <?php foreach($doing as $index => $campaign): ?>
          <li>
            <?php print render($campaign); ?>
          </li>
        <?php endforeach; ?>
      </ul>
    <?php endif; ?>
    </div>
  </section>

  <section class="profile--settings">
    <h1 class="banner"><span><?php print t('My Settings'); ?></span></h1>

    <div class="wrapper">
      <dl class="__user-info">
        <dt><?php print t('Name'); ?>:</dt>
        <dd><?php print $user_account['first_name']; ?> <?php if (!empty($user_account['last_name'])): ?><?php print $user_account['last_name']; ?><?php endif; ?></dd>
        <dt><?php print t('Email'); ?>:</dt>
        <dd><?php print $user_account['email']; ?></dd>

        <?php if (!empty($user_account['mobile'])): ?>
          <dt><?php print t('Mobile'); ?>:</dt>
          <dd><?php print $user_account['mobile']; ?></dd>
        <?php endif; ?>

        <dt><?php print t('Birthday'); ?>:</dt>
        <dd><?php print $user_account['birthday']; ?></dd>
      </dl>

      <?php if (!empty($address)): ?>
        <dl class="__address-info">
          <?php if (isset($address['street'])): ?>
            <dt><?php print t('Address 1'); ?>:</dt>
            <dd><?php print $address['street']; ?></dd>
          <?php endif;?>

          <?php if (isset($address['premise'])): ?>
            <dt><?php print t('Address 2'); ?>:</dt>
            <dd><?php print $address['premise']; ?></dd>
          <?php endif;?>

          <?php if (isset($address['city'])): ?>
            <dt><?php print t('City'); ?>:</dt>
            <dd><?php print $address['city']; ?></dd>
          <?php endif;?>

          <?php if (isset($address['state'])): ?>
            <dt><?php print t('State'); ?>:</dt>
            <dd><?php print $address['state']; ?></dd>
          <?php endif;?>

          <?php if (isset($address['zip'])): ?>
            <dt><?php print t('Zip'); ?>:</dt>
            <dd><?php print $address['zip']; ?></dd>
          <?php endif;?>

          <?php if (isset($address['country'])): ?>
            <dt><?php print t('Country'); ?>:</dt>
            <dd><?php print $address['country']; ?></dd>
          <?php endif;?>
        </dl>
      <?php endif; ?>

      <a class="btn medium" href="/<?php print $edit_link; ?>"><?php print t('Update'); ?></a>
    </div>
  </section>

</article>
