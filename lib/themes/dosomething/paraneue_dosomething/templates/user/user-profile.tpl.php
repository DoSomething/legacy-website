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


  // krumo($variables);
  krumo($user_profile);
  krumo($user_account);

  $recommended = $user_account['recommended'];
  $campaigns = $user_account['campaigns'];
?>


<article id="user-<?php print $user_account['id']; ?>" class="user profile"<?php print $attributes; ?>>
  <?php //print render($user_profile); ?>

  <?php //@TODO: Refactor markup to add wrapper inside header tag, when all headers are refactored. ?>
  <div class="header-wrapper">
    <header class="header">
      <h1 class="title">Hey, <?php print $user_account['first_name']; ?>!</h1>
      <h2 class="subtitle">Let us get to know you better.</h2>
    </header>
  </div>

  <section class="profile--campaigns">
    <h1 class="banner"><span>My Campaigns</span></h1>

    <?php if(!$campaigns): ?>
      <div class="cta">
        <h2>Rut Roh! You haven't signed up for any campaigns yet. Find something to do:</h2>
        <a href="/campaigns" class="btn medium">Explore Campaigns</a>
      </div>
    <?php endif; ?>

    <div class="wrapper">
      <?php if($campaigns): ?>
          <h2>Signed Up</h2>
          <?php print render($campaigns); ?>
      <?php endif; ?>

      <?php if ($recommended): ?>
        <h2>Recommended</h2>
        <ul>
          <?php foreach($recommended as $index => $campaign): ?>
            <li>
              <article class="campaign--teaser" id="campaign-<?php print $campaign['nid']; ?>">
                <?php //print l($campaign['title'], $campaign['src']); ?>
                <?php print $campaign['call_to_action']; ?>
                <img alt="<?php //print $campaign['title']; ?>" src="<?php print $campaign['image']; ?>" />
              </article>
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
        <p><strong>Name:</strong> <?php print $user_account['first_name']; ?>  <?php print $user_account['last_name']; ?></p>
        <p><strong>Email:</strong> <?php print $user_account['email']; ?></p>
        <p><strong>Mobile:</strong> <?php print $user_account['mobile']; ?></p>
        <p><strong>Birthday:</strong> <?php print $user_account['birthday']; ?></p>
      </div>

      <div class="__address-info">
        <p><strong>Address 1:</strong> <?php print $user_account['address']['street']; ?></p>
        <p><strong>Address 2:</strong> <?php print $user_account['address']['premise']; ?></p>
        <p><strong>City, State, Zip:</strong> <?php print $user_account['address']['city']; ?>, <?php print $user_account['address']['state']; ?>, <?php print $user_account['address']['zip']; ?></p>
      </div>
    </div>

    <?php print render($user_profile['update']); ?>
  </section>

</article>
