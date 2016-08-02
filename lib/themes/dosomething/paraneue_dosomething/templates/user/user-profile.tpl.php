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

  <header role="banner" class="header">
    <div class="wrapper">
      <h1 class="header__title"><?php print $title; ?></h1>
      <?php if (!empty($subtitle)): ?>
        <p class="header__subtitle"><?php print $subtitle; ?></p>
      <?php endif; ?>
    </div>
  </header>

  <section class="container -padded">
    <h2 class="heading -banner"><span><?php print t("You're Doing"); ?></span></h2>
    <div class="wrapper">
      <?php if (empty($doing)): ?>
        <div class="container__block">
          <h2 class="__message"><?php print $no_signups_header; ?></h2>
          <p><?php print $no_signups_copy; ?></p>
          <a href="/campaigns" class="button"><?php print t('Explore Campaigns'); ?></a>
        </div>
      <?php else: ?>
        <?php print $doing_gallery; ?>
      <?php endif; ?>
    </div>
  </section>

  <?php if (!empty($reportbacks)): ?>
    <section class="container -padded">
      <h2 class="heading -banner"><span><?php print t('You Did'); ?></span></h2>
      <div class="wrapper">
        <?php // Missing Photo Link // ?>
        <div class="container__block">
          <a href="#" data-modal-href="#modal-missing-photos">Is your photo not showing up?</a>
        </div>
        <?php print $reportback_gallery; ?>
      </div>
    </section>
  <?php endif; ?>

  <section class="container -padded">
    <h2 class="heading -banner"><span><?php print t('Your Info'); ?></span></h2>
    <div class="wrapper">
      <dl class="container__block -half profile-settings">
        <dt><?php print t('Name'); ?>:</dt>
        <dd>
          <?php print check_plain($first_name); ?>
          <?php if (!empty($last_name)): ?>
            <?php print check_plain($last_name); ?>
          <?php endif; ?>
        </dd>

        <dt><?php print t('Password'); ?>:</dt>
        <dd>*******</dd>

        <dt><?php print t('Email'); ?>:</dt>
        <dd><?php print check_plain($email); ?></dd>

        <?php if (!empty($mobile)): ?>
          <dt><?php print t('Cell'); ?>:</dt>
          <dd><?php print check_plain($mobile); ?></dd>
        <?php endif; ?>

      </dl>
      <div class="container__block -half profile-actions">
        <a class="secondary" href="/<?php print $edit_link; ?>">
          <?php print t('Update my profile'); ?>
        </a>
      </div>
    </div>
  </section>

</article>

<?php // Missing Photo Modal // ?>
<div data-modal id="modal-missing-photos" role="dialog">
  <div class="modal__block">
    <h2 class="heading -emphasized" style="margin: 0;">Is your photo not showing up?</h2>
  </div>
  <div class="modal__block with-lists">
    <p>The other day, we had some issues with our site, and a bug deleted a bunch of images (which may have included yours).</p>
    <p>Some good news:
      <ul>
        <li>We’ve fixed the issue so new photos will not be deleted.</li>
        <li>Even though your photo isn’t showing up, your impact is still being counted.</li>
        <li>And if the campaign had a scholarship opportunity, don't worry! Your entry into the scholarship was still counted.</li>
      </ul>
    </p>
    <p>Here are a few things you can do:
      <ul>
        <li>If you have any new photos to add to or any campaigns you’re signed up for go ahead and upload those now to start sharing your impact.</li>
        <li>If you still have your old photo on your phone or computer, please re-upload it now to guarantee it’s showing up on the campaign you participated in and your profile. If the campaign is now closed, feel free to reach out to us at our <a href="https://help.dosomething.org/hc/en-us">help center</a> and we'll totally upload your photo for you.</li>
      </ul>
    </p>
    <p>
      (P.S. If you have any other questions or problems uploading or viewing photos on the site, definitely let us know. Thanks so much!)</p>
    </p>
  </div>
</div>
