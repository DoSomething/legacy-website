<?php
/**
 * Returns the HTML for a single Campaign Block.
 *
 * Available Variables
 * - $nid: Node ID for campaign (integer).
 * - $title: Title of campaign (string).
 * - $call_to_action: Call to action text for campaign. (string).
 * - $image: URL path for campaign image (string).
 * - $path_alas: Pretty URL path for campaign node (string).
 * - $staff_pick: Indicate if this campaign a staff pick (boolean).
 */

/*
 * Will need to combine other elements into this template from the
 * /templates/home/partials/thumbnail.tpl.php template...
 * Address during refactor of home page and unify these templates.
 */
?>

<article class="tile tile--campaign" id="campaign-<?php print $nid; ?>">
  <?php if ($status): ?>
  <a class="wrapper" href="/<?php print $path_alias; ?>">
  <?php else: ?>
  <div class="wrapper">
  <?php endif; ?>
    <?php if ($staff_pick): ?>
      <div class="__flag -staff-pick"><?php print t('Staff Pick'); ?></div>
    <?php endif; ?>

    <div class="tile--meta">
      <h1 class="__title"><?php print $title; ?></h1>
      <p class="__tagline"><?php print $call_to_action; ?></p>
    </div>
    <img alt="<?php print $title; ?>" src="<?php print $image; ?>" />
  <?php if ($status): ?>
  </a>
  <?php else: ?>
  </div>
  <?php endif;?>
</article>
