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
 */

// krumo($variables);
// krumo($user_profile);
?>

<article>

  <div class="user profile"<?php print $attributes; ?>>
    <?php print render($user_profile); ?>
  </div>

</article>
