<?php
/**
 * Returns the HTML for the Campaign Reportback Confirmation.
 *
 * Available Variables
 * - $page_title: The page title (string).
 * - $copy: Positive note message copy (string).
 * - $more_campaigns_link: Link to find more campaigns (string).
 * - $back_to_campaign_link: Link to head back to originating campagin (string).
 * - $recommended: Array containing recommended campaigns for user.
 *   - [nid]: Node ID for campaign (integer).
 *   - [title]: Title of campaign (string).
 *   - [call_to_action]: Call to action text for campaign. (string).
 *   - [image]: URL path for campaign image (string).
 *   - [path]: URL path for campaign node (string).
 *   - [pretty_path]: Pretty URL path for campaign node (string).
 *   - [staff_pick]: Indicate if this campaign a staff pick (boolean).
 * - $redeem_form: Array containing variables for Reward Reedem Form, if exists:
 *   - [copy]: Copy displayed in the Redeem Form modal (string).
 *   - [delete_form]: If staff, the Reward Delete Form to be rendered (array).
 *   - [form]: Reward Reedem Form to be rendered (array).
 *   - [header]: Header text of the Redeem Form modal (string).
 *   - [link]: Label of link to open the Redeem form modal (string).
 */
?>

<section class="confirmation-wrapper">

  <header role="banner" class="header">
    <div class="wrapper">
      <h1 class="header__title"><?php print $page_title; ?></h1>
      <?php if (isset($copy)): ?>
        <p class="header__subtitle"><?php print $copy; ?></p>
      <?php endif; ?>
    </div>
  </header>

  <?php if (isset($recommended)): ?>
    <div class="container -padded">
      <div class="wrapper">
       <div class="container__block">
         <h2><?php print t('Keep it up! Find your next campaign.'); ?></h2>
       </div>

        <div class="gallery -triad">
          <?php foreach ($recommended as $rec): ?>
            <li>
            <div class="figure">
              <?php if (isset($rec['image'])): ?>
                <div class="figure__media">
                  <a href="/<?php print $rec['path_alias']; ?>"><img src="<?php print $rec['image']; ?>"/></a>
                </div>
              <?php endif; ?>

              <div class="figure__body">
                <?php if (isset($rec['title'])): ?>
                  <h3><a href="/<?php print $rec['path_alias']; ?>"><?php print $rec['title']; ?></a></h3>
                <?php endif; ?>

                <?php if (isset($rec['call_to_action'])): ?>
                  <p><?php print $rec['call_to_action']; ?></p>
                <?php endif; ?>
              </div>
            </div>
            </li>
          <?php endforeach; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($more_campaigns_link)): ?>
    <div class="cta">
      <div class="wrapper">
        <?php if (isset($call_to_action)): ?>
        <h2 class="cta__message"><?php print $call_to_action; ?></h2>
        <?php endif; ?>

        <p><?php print $more_campaigns_link; ?></p>
        <p><?php if (isset($back_to_campaign_link)): ?><?php print $back_to_campaign_link; ?><?php endif; ?></p>
      </div>
    </div>
  <?php endif; ?>

</section>
