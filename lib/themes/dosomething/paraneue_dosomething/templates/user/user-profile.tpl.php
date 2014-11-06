<?php
/**
 * Returns the HTML for User Profile page.
 * @see https://api.drupal.org/api/drupal/modules%21user%21user-profile.tpl.php/7
 *
 * Available variables:
 *  - $title: (string).
 *  - $subtitle: (string).
 *  - $email: Account email address (string).
 *  - $first_name: User's first name (string).
 *  - $last_name: User's last name (string).
 *  - $mobile: User's mobile cell number (string).
 *  - $doing: Array containing campaign blocks for campaigns User is doing.
 */
?>
<article class="user profile"<?php print $attributes; ?> id="user-<?php print $user->uid; ?>">

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
        <?php foreach ($doing as $index => $campaign): ?>
          <li>
            <?php print render($campaign); ?>
          </li>
        <?php endforeach; ?>
      </ul>
    <?php endif; ?>
    </div>
  </section>

  <?php if (!empty($reportbacks)): ?>
    <section class="profile--reportbacks">
      <h1 class="banner"><span><?php print t("You Did"); ?></span></h1>
      <div class="wrapper">
        <?php print $reportback_gallery; ?>
      </div>
    </section>
  <?php endif; ?>

  <section class="profile--settings">
    <h1 class="banner"><span><?php print t('Your Info'); ?></span></h1>

    <div class="wrapper">
      <h2><?php print t('Account Info'); ?></h2>
      <dl class="__user-info">
        <dt><?php print t('Name'); ?>:</dt>
        <dd><?php print $first_name; ?> <?php if (!empty($last_name)): ?><?php print $last_name; ?><?php endif; ?></dd>
        <dt><?php print t('Password'); ?>:</dt>
        <dd>*******</dd>
        <dt><?php print t('Email'); ?>:</dt>
        <dd><?php print $email; ?></dd>
        <?php if (!empty($mobile)): ?>
          <dt><?php print t('Cell'); ?>:</dt>
          <dd><?php print $mobile; ?></dd>
        <?php endif; ?>
      </dl>
      <a class="secondary" href="/<?php print $edit_link; ?>">
        <?php print t('Update my profile'); ?>
      </a>
    </div>
  </section>

</article>
