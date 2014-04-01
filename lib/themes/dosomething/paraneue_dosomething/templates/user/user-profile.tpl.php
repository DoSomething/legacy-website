<?php
/**
 * Returns the HTML for User Profile page.
 * @see https://api.drupal.org/api/drupal/modules%21user%21user-profile.tpl.php/7
 */
?>

<div class="profile"<?php print $attributes; ?>>
  <h1>USER</h1>
  <?php print render($user_profile); ?>
</div>
