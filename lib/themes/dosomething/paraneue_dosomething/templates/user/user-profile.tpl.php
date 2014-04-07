<?php
/**
 * Returns the HTML for User Profile page.
 * @see https://api.drupal.org/api/drupal/modules%21user%21user-profile.tpl.php/7
 *
 * Available Variables
 * - $user_profile: An array of profile items.
 *   - [campaigns]: A render array item.
 *   - [user_picture]: A render array item.
 *   - [field_first_name]: A render array item.
 *   - [field_last_name]: A render array item.
 *   - [field_address]: A render array item.
 *   - [field_birthday]: A render array item.
 *   - [field_under_thirteen]: A render array item.
 *   - [field_mobile]: A render array item.
 *   - [field_partner]: A render array item.
 *   - [summary]: A render array item.
 *
 *   - [user_info]: An array of profile information that only contains the values.
 *     - [id]: User id number (string).
 *     - [username]: Account name (string).
 *     - [email]: Account email address (string).
 *     - [first_name]: User's first name (string).
 *     - [last_name]: User's last name (string).
 *     - [birthday]: User's birthday (string).
 *     - [address]: Array containing address information.
 *       - [country]: User's country of residence (string).
 *       - [state]: User's state of residence (string).
 *       - [city]: User's city of residence (string).
 *       - [zip]: User's postal zip code (string).
 *       - [street]: User's street address (string).
 *       - [premise]: User's apartment, suite, etc... (string).
 */


  $user_info = $user_profile['user_info'];

  // krumo($variables);
  // krumo($user_profile);
  // krumo($user_info);
?>


<article id="user-<?php print $user_info['id']; ?>" class="user profile"<?php print $attributes; ?>>
  <?php //print render($user_profile); ?>

  <div class="header-wrapper">
    <header class="header">
      <h1 class="title">Hey, <?php print $user_info['first_name']; ?>!</h1>
      <h2 class="subtitle">Let us get to know you better.</h2>
    </header>
  </div>

  <div class="profile-info-wrapper">
    <section>
      <h2>My Campaigns</h2>
        <p>Rut Roh! You haven't signed up for any campaigns yet. Find something to do:</p>
      <h3>Signed Up</h3>

      <h3>Recommended</h3>
    </section>

    <section>
      <h2>My Settings</h2>

      <p><span>Name:</span> <?php print $user_info['first_name']; ?>  <?php print $user_info['last_name']; ?></p>
      <p><span>Email:</span> <?php print $user_info['email']; ?></p>
      <p><span>Mobile:</span> <?php print $user_info['mobile']; ?></p>
      <p><span>Birthday:</span> <?php print $user_info['birthday']; ?></p>

      <div class="address">
        <p><span>Address 1:</span> <?php print $user_info['address']['street']; ?></p>
        <p><span>Address 2:</span> <?php print $user_info['address']['premise']; ?></p>
        <p><span>City, State, Zip:</span> <?php print $user_info['address']['city']; ?>, <?php print $user_info['address']['state']; ?>, <?php print $user_info['address']['zip']; ?></p>
      </div>

      <?php print render($user_profile['updated']); ?>
    </section>

  </div>

</article>
