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
 *   - [address]: Array containing address information.
 *     - [country]: User's country of residence (string).
 *     - [state]: User's state of residence (string).
 *     - [city]: User's city of residence (string).
 *     - [zip]: User's postal zip code (string).
 *     - [street]: User's street address (string).
 *     - [premise]: User's apartment, suite, etc... (string).
 *   - [mobile]: User's mobile cell number (string).
 *   - [campaigns]: Array containing a data for campaigns a User has signed up for.
 *   - [recommended]: Array containing a data for recommended campaigns for User.
 */

  $signedup = $user_account['campaigns_signedup'];
  $recommended = $user_account['campaigns_recommended'];
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
        <h2>Rut Roh! You haven't signed up for any campaigns yet. Find something to do:</h2>
        <a href="/campaigns" class="btn medium">Explore Campaigns</a>
      </div>
    <?php endif; ?>

    <div class="wrapper">
      <?php if(!empty($signedup)): ?>
        <h2>Signed Up</h2>
        <ul>
          <?php foreach($signedup as $index => $campaign): ?>
            <li>
              <?php print render($campaign); ?>
            </li>
          <?php endforeach; ?>
        </ul>
      <?php endif; ?>

      <?php if (!empty($recommended)): ?>
        <h2>Recommended</h2>
        <ul>
          <?php foreach($recommended as $index => $campaign): ?>
            <li>
              <?php print render($campaign); ?>
            </li>
          <?php endforeach; ?>
        </ul>
      <?php endif; ?>
    </div>
  </section>


  <section class="profile--settings">
    <h1 class="banner"><span>My Settings</span></h1>

    <div class="wrapper">
      <div class="__user-info">
        <div><strong>Name:</strong> <?php print $user_account['first_name']; ?>  <?php if (!empty($user_account['last_name'])): ?><?php print $user_account['last_name']; ?><?php endif; ?></div>
        <div><strong>Email:</strong> <?php print $user_account['email']; ?></div>

        <?php if (!empty($user_account['mobile'])): ?>
          <div><strong>Mobile:</strong> <?php print $user_account['mobile']; ?></div>
        <?php endif; ?>

        <div><strong>Birthday:</strong> <?php print date('F j, Y', strtotime($user_account['birthday'])); ?></div>
      </div>

      <?php if (!empty($address)): ?>
        <div class="__address-info">
          <?php if (isset($address['street'])): ?>
            <div><strong>Address 1:</strong> <?php print $address['street']; ?></div>
          <?php endif;?>

          <?php if (isset($address['premise'])): ?>
            <div><strong>Address 2:</strong> <?php print $address['premise']; ?></div>
          <?php endif;?>

          <?php if (isset($address['city'])): ?>
            <div><strong>City:</strong> <?php print $address['city']; ?></div>
          <?php endif;?>

          <?php if (isset($address['state'])): ?>
            <div><strong>State:</strong> <?php print $address['state']; ?></div>
          <?php endif;?>

          <?php if (isset($address['zip'])): ?>
            <div><strong>Zip:</strong> <?php print $address['zip']; ?></div>
          <?php endif;?>

          <?php if (isset($address['country'])): ?>
            <div><strong>Country:</strong> <?php print $address['country']; ?></div>
          <?php endif;?>
        </div>
      <?php endif; ?>
    </div>

    <?php print render($user_profile['updated']); ?>
  </section>

</article>
