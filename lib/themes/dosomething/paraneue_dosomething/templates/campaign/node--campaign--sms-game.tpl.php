<?php
/**
 * Returns the HTML for the Campaign SMS Game page.
 *
 * Available Variables
 * - $campaign: A campaign object. @see dosomething_campaign_load()
 * - $scholarship: Scholarship amount (string).
 * - $classes: Additional classes passed for output (string).
 */
?>

<article id="node-<?php print $node->nid; ?>" class="campaign campaign--sms <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <header role="banner" class="header -hero <?php print $classes; ?>">
    <div class="wrapper">
      <?php print $campaign_headings; ?>

      <?php print $promotions; ?>
    </div>
  </header>

  <div class="wrapper">

    <section id="know" class="container">
      <h2 class="heading -banner"><span><?php print t('Step 1: Know It'); ?></span></h2>
      <div class="wrapper">

        <div class="container__block -half">
          <?php if (isset($campaign->fact_problem)): ?>
          <h3 class="inline-sponsor-color"><?php print t('The Problem'); ?></h3>
          <p><?php print $campaign->fact_problem['fact']; ?><sup><?php print $campaign->fact_problem['footnotes']; ?></sup></p>
          <?php endif; ?>

          <?php if (isset($psa)): ?>
            <aside <?php if ($is_video_psa) echo 'class="media-video"'; ?>>
              <?php print $psa; ?>
            </aside>
          <?php else: ?>
            <?php if (isset($modals)): ?>
              <?php print $modals; ?>
            <?php endif; ?>
          <?php endif; ?>
        </div>

        <div class="container__block -half">
          <?php if (isset($campaign->fact_solution) || isset($campaign->solution_copy)): ?>
              <h3 class="inline-sponsor-color"><?php print t('The Solution'); ?></h3>

            <?php if (isset($campaign->fact_solution)): ?>
              <p><?php print $campaign->fact_solution['fact']; ?><sup><?php print $campaign->fact_solution['footnotes']; ?></sup></p>
            <?php elseif (isset($campaign->solution_copy)): ?>
              <?php print $campaign->solution_copy; ?>
            <?php endif; ?>

            <?php if (isset($campaign->solution_support)): ?>
              <?php print $campaign->solution_support; ?>
            <?php endif; ?>

          <?php endif; ?>

          <?php if (isset($psa)): ?>
            <?php if (isset($modals)): ?>
              <?php print $modals; ?>
            <?php endif; ?>
          <?php endif; ?>
        </div>

        <div class="container__block -narrow">
          <?php if (isset($campaign->fact_sources)): ?>
          <section class="footnote">
            <h4 class="js-footnote-toggle"><?php print t('Sources'); ?></h4>
            <ul class="js-footnote-hidden">
              <?php foreach ($campaign->fact_sources as $key => $source): ?>
                <li><sup><?php print ($key + 1); ?></sup> <?php print $source; ?></li>
              <?php endforeach; ?>
            </ul>
          </section>
          <?php endif; ?>
        </div>
      </div>
    </section>


    <section id="do" class="container container--do inline-alt-background-color">
      <h2 class="heading -banner"><span><?php print t('Step 2: Do It'); ?></span></h2>
      <div class="wrapper">

        <div class="container__block -narrow">
          <?php if (isset($starter_header)) : ?>
            <h3 class="inline-alt-text-color"><?php print $starter_header; ?></h3>
          <?php endif; ?>
          <?php if (isset($starter)) : ?>
            <div><?php print $starter['safe_value']; ?></div>
          <?php endif; ?>
        </div>

        <?php if (isset($signup_form)) : ?>
          <?php print render($signup_form); ?>
        <?php endif; ?>

        <!-- ########## A/B Test For SMS First Names ##########  -->
        <!-- We find the fieldset "edit-group1" in the form above, and replace  -->
        <!-- with the below snippet. This allows us to swap out form fields -->
        <!-- without losing CSRF tokens: -->

        <!--  var $ = jQuery; var $form = $("#dosomething-signup-sms-game-form"); $form.css('padding-top', '100px'); $form.find(".form-item-alpha-first-name").remove(); $form.find("#edit-group1").html($("#ab-test-sms-names").html());  --->

        <div id="ab-test-sms-names" style="display: none;">
          <div class="fieldset-wrapper">
            <div class="form-item form-type-textfield">
              <label class="field-label" for="edit-alpha-first-name">Your First Name <span class="form-required" title="This field is required.">*</span></label>
              <input data-validate="fname" data-validate-required="" placeholder="First Name" type="text" id="edit-alpha-first-name" name="alpha_first_name" value="" size="60" maxlength="128" class="text-field required has-success">
            </div>

            <div class="form-item form-type-textfield form-item-alpha-mobile">
              <label class="field-label" for="edit-alpha-mobile">Your Cell Number <span class="form-required" title="This field is required.">*</span></label>
              <input data-validate="phone" data-validate-required="" placeholder="(555) 555-5555" autocomplete="off" type="text" id="edit-alpha-mobile" name="alpha_mobile" value="" size="60" maxlength="128" class="text-field required">
            </div>

            <div class="form-item form-type-textfield">
              <label class="field-label" for="edit-beta-first-name-0">Your Friend's Name <span class="form-required" title="This field is required.">*</span></label>
              <input data-validate="friend_name" data-validate-required="" placeholder="Friend's Name" type="text" id="edit-beta-first-name-0" name="beta_first_name_0" value="" size="60" maxlength="128" class="text-field required has-success">
            </div>

            <div class="form-item form-type-textfield form-item-alpha-mobile">
              <label class="field-label" for="edit-beta-mobile-0">Friend's Cell Number <span class="form-required" title="This field is required.">*</span></label>
              <input data-validate="phone" data-validate-required="" placeholder="(555) 555-5555" autocomplete="off" type="text" id="edit-beta-mobile-0" name="beta_mobile_0" value="" size="60" maxlength="128" class="text-field required">
            </div>

            <div class="form-item form-type-textfield ">
              <label class="field-label" for="edit-beta-first-name-1">Your Friend's Name <span class="form-required" title="This field is required.">*</span></label>
              <input data-validate="friend_name" data-validate-required="" placeholder="Friend's Name" type="text" id="edit-beta-first-name-1" name="beta_first_name_1" value="" size="60" maxlength="128" class="text-field required has-success">
            </div>

            <div class="form-item form-type-textfield form-item-alpha-mobile">
              <label class="field-label" for="edit-beta-mobile-1">Friend's Cell Number <span class="form-required" title="This field is required.">*</span></label>
              <input data-validate="phone" data-validate-required="" placeholder="(555) 555-5555" autocomplete="off" type="text" id="edit-beta-mobile-1" name="beta_mobile_1" value="" size="60" maxlength="128" class="text-field required">
            </div>

            <div class="form-item form-type-textfield">
              <label class="field-label" for="edit-beta-first-name-2">Your Friend's Name <span class="form-required" title="This field is required.">*</span></label>
              <input data-validate="friend_name" data-validate-required="" placeholder="Friend's Name" type="text" id="edit-beta-first-name-2" name="beta_first_name_2" value="" size="60" maxlength="128" class="text-field required has-success">
            </div>

            <div class="form-item form-type-textfield form-item-alpha-mobile">
              <label class="field-label" for="edit-beta-mobile-2">Friend's Cell Number <span class="form-required" title="This field is required.">*</span></label>
              <input data-validate="phone" data-validate-required="" placeholder="(555) 555-5555" autocomplete="off" type="text" id="edit-beta-mobile-2" name="beta_mobile_2" value="" size="60" maxlength="128" class="text-field required">
            </div>
          </div>
        </div>
        <!-- ########## END A/B Test For SMS First Names ########## -->

        <div class="container__block -narrow">
          <?php if (isset($official_rules)): ?>
            <p class="footnote">
              <a class="official-rules" href="<?php print $official_rules_src; ?>"><?php print t('Official Rules'); ?></a>
            </p>
          <?php endif; ?>

          <p class="footnote">
            <?php
            print t("Taking part in this experience means you agree to our !terms_link &amp; to receive our weekly update. Message &amp; data rates may apply. Text STOP to opt-out, HELP for help.",
              array("!terms_link" => l(t('Terms of Service'), 'about/terms-service'))); ?>
          </p>
        </div>
      </div>


      <?php if ($info_bar): ?>
        <?php print $info_bar; ?>
      <?php endif; ?>

    </section>


  </div>

</article>
