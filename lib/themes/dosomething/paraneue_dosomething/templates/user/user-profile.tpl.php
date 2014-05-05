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
 *   - [signedup]: Array containing a data for campaigns a User has signed up for.
 *   - [recommended]: Array containing a data for recommended campaigns for User.
 */

  $signedup = $user_account['signedup'];
  $signedup_count = $user_account['signedup_count'];
  $recommended = $user_account['recommended'];
  $address = $user_account['address'];
?>


<article class="user profile"<?php print $attributes; ?> id="user-<?php print $user_account['id']; ?>">

  <header role="banner">
    <div class="wrapper">
      <h1 class="title">Hey, <?php print $user_account['first_name']; ?>!</h1>
      <h2 class="subtitle">Let us get to know you better.</h2>
    </div>
  </header>

  <section class="profile--campaigns">
    <h1 class="banner"><span>My Campaigns</span></h1>

    <?php if(empty($signedup)): ?>

    <div class="cta">
      <div class="wrapper">
        <h2 class="__message">Rut Roh! You haven't signed up for any campaigns yet. Find something to do:</h2>
        <a href="/campaigns" class="btn medium">Explore Campaigns</a>
      </div>
    </div>

    <?php else: ?>

    <ul class="gallery -mosaic">
      <?php foreach($signedup as $index => $campaign): ?>
        <li>
          <?php print render($campaign); ?>
        </li>
      <?php endforeach; ?>

      <?php if($signedup_count <= 3): ?>
        <li class="empty <?php if ($user_account['empty_class_modifier']) print $user_account['empty_class_modifier']; ?>">
          <div class="wrapper">
            <div class="__message">
              <div class="wrapper">
                <p>More is better. Add a few more campaigns friend!</p>
                <a href="/campaigns">Explore Campaigns</a>
              </div>
            </div>
          </div>
        </li>
      <?php endif; ?>
    </ul>

    <?php endif; ?>

  </section>


  <section class="profile--recommended">
    <h1 class="banner"><span>Recommended Campaigns</span></h1>

    <?php if (!empty($recommended)): ?>

    <ul class="gallery -mosaic">
      <?php foreach($recommended as $index => $campaign): ?>
        <li>
          <?php print render($campaign); ?>
        </li>
      <?php endforeach; ?>
    </ul>

    <?php endif; ?>

  </section>


  <section class="profile--settings">
    <h1 class="banner"><span>My Settings</span></h1>

    <div class="wrapper">
      <dl class="__user-info">
        <dt>Name:</dt>
        <dd><?php print $user_account['first_name']; ?> <?php if (!empty($user_account['last_name'])): ?><?php print $user_account['last_name']; ?><?php endif; ?></dd>
        <dt>Email:</dt>
        <dd><?php print $user_account['email']; ?></dd>

        <?php if (!empty($user_account['mobile'])): ?>
          <dt>Mobile:</dt>
          <dd><?php print $user_account['mobile']; ?></dd>
        <?php endif; ?>

        <dt>Birthday:</dt>
        <dd><?php print date('F j, Y', strtotime($user_account['birthday'])); ?></dd>
      </dl>

      <?php if (!empty($address)): ?>
        <dl class="__address-info">
          <?php if (isset($address['street'])): ?>
            <dt>Address 1:</dt>
            <dd><?php print $address['street']; ?></dd>
          <?php endif;?>

          <?php if (isset($address['premise'])): ?>
            <dt>Address 2:</dt>
            <dd><?php print $address['premise']; ?></dd>
          <?php endif;?>

          <?php if (isset($address['city'])): ?>
            <dt>City:</dt>
            <dd><?php print $address['city']; ?></dd>
          <?php endif;?>

          <?php if (isset($address['state'])): ?>
            <dt>State:</dt>
            <dd><?php print $address['state']; ?></dd>
          <?php endif;?>

          <?php if (isset($address['zip'])): ?>
            <dt>Zip:</dt>
            <dd><?php print $address['zip']; ?></dd>
          <?php endif;?>

          <?php if (isset($address['country'])): ?>
            <dt>Country:</dt>
            <dd><?php print $address['country']; ?></dd>
          <?php endif;?>
        </dl>
      <?php endif; ?>

      <a class="btn medium" href="/<?php print $user_profile['update_link_path']; ?>">Update</a>
    </div>
  </section>

</article>
