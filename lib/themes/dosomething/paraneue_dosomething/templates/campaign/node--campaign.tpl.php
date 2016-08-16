<?php
/**
 * Returns the HTML for the Campaign Action page.
 *
 * Available Variables
 * - $campaign: A campaign object. @see dosomething_campaign_load()
 * - $scholarship: Scholarship amount (string).
 * - $classes: Additional classes passed for output (string).
 * - $campaign_creator: HTML for the Campaign Creator link/modal.
 */
?>

<header role="banner" class="header -hero header--action <?php print $classes; ?>">
  <div class="wrapper">
    <?php print $campaign_headings; ?>

    <?php print $promotions; ?>

    <?php print $campaign_scholarship; ?>
  </div>
</header>

<article class="campaign campaign--action">
  <nav class="campaign-nav js-fixedsticky">
    <ul class="waypoints -primary waypoints--action js-scroll-indicator">
      <li><a class="js-jump-scroll" href="#know"><?php print t('Know'); ?></a></li>
      <li><a class="js-jump-scroll" href="#plan"><?php print t('Plan'); ?></a></li>
      <li><a class="js-jump-scroll" href="#do"><?php print t('Do'); ?></a></li>
      <li><a class="waypoints__primary-link js-jump-scroll" href="#prove"><?php print t('Prove It'); ?></a></li>
    </ul>
  </nav>

  <?php // KNOW IT ////////////////////////////////////////////////////// ?>
  <section id="know" class="container -padded">
    <div class="wrapper">
      <div class="container__row">
        <div class="container__block">
          <h2 class="heading -emphasized"><span><?php print t('Step 1: Know It'); ?></span></h2>
        </div>
      </div>
      <div class="container__row">
        <div class="container__block -half">
          <?php if (isset($campaign->fact_problem)): ?>
            <h3 class="inline-sponsor-color"><?php print t('The Problem'); ?></h3>
            <p><?php print $campaign->fact_problem['fact']; ?><sup><?php print $campaign->fact_problem['footnotes']; ?></sup></p>

            <?php // Show problem social share buttons if feature flag is turned on. ?>
            <?php if ($show_problem_shares): ?>
              <div class="message-callout -above-horizontal -blue">
                <div class="message-callout__copy">
                  <p><?php print $problem_share_prompt; ?></p>
                </div>
              </div>
              <?php print $share_bar; ?>
            <?php endif; ?>
          <?php endif; ?>

          <?php if ($show_problem_shares): ?>
            <?php // If there's a PSA image or video, output it in this column. ?>
            <?php if (isset($psa)): ?>
              <p <?php if ($is_video_psa) echo 'class="media-video"'; ?>>
                <?php print $psa; ?>
              </p>
            <?php endif; ?>
          <?php else: ?>
            <?php // If there's a PSA image or video, output it in this column, otherwise output the modals list if it exists. ?>
            <?php if (isset($psa)): ?>
              <p <?php if ($is_video_psa) echo 'class="media-video"'; ?>>
                <?php print $psa; ?>
              </p>
            <?php else: ?>
              <?php if (isset($modals)): ?>
                <?php print $modals; ?>
              <?php endif; ?>
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

          <?php if ($show_problem_shares): ?>
            <?php // Always output modals in the second column. ?>
            <?php if (isset($modals)): ?>
             <?php print $modals; ?>
            <?php endif; ?>
          <?php else: ?>
            <?php // If there's a PSA image or video, then it was output in the first column above and thus need to output the modals in this second column instead. ?>
            <?php if (isset($psa)): ?>
              <?php if (isset($modals)): ?>
                <?php print $modals; ?>
              <?php endif; ?>
            <?php endif; ?>
          <?php endif; ?>
        </div>
      </div>

      <div class="container__row">
        <div class="container__block -narrow">
          <?php if (isset($campaign->fact_sources)): ?>
            <section class="footnote">
              <h4 class="js-footnote-toggle"><?php print t('Sources'); ?></h4>
              <ul class="js-footnote-hidden">
                <?php foreach ($campaign->fact_sources as $key => $source): ?>
                  <li><sup><?php print($key + 1); ?></sup> <?php print $source; ?></li>
                <?php endforeach; ?>
              </ul>
            </section>
          <?php endif; ?>
        </div>
      </div>
    </div>
  </section>


  <?php // PLAN IT ////////////////////////////////////////////////////// ?>
  <section id="plan" class="container -padded">
    <div class="wrapper">
      <div class="container__row">
        <div class="container__block">
          <h2 class="heading -emphasized"><span><?php print t('Step 2: Plan It'); ?></span></h2>
        </div>
      </div>
      <div class="container__row">
        <div class="container__block">
          <?php if (isset($starter)) : ?>
            <?php print $starter['safe_value']; ?>
          <?php endif; ?>
        </div>
      </div>

      <?php if (isset($plan)): ?>
      <?php foreach ($plan as $index => $content): ?>
        <?php if($index % 2 === 0) : ?> <div class="container__row"> <?php endif; ?>
          <div class="container__block -half">
            <h3 class="inline-sponsor-color"><?php print $content['title']; ?></h3>
            <div class="with-lists -compacted -concatenated">
              <?php print $content['content']; ?>

              <?php // Start: Content specifically for Materials content section. ?>
              <?php if ($content['category'] === 'materials'): ?>
                <ul>
                  <?php if(isset($action_guides)): ?>
                    <?php  foreach ($action_guides as $delta => $action_guide): ?>
                      <li><a href="#" data-modal-href="#modal-action-guide-<?php print $delta; ?>"><?php print $action_guide['desc']; ?></a></li>
                    <?php endforeach; ?>
                  <?php endif; ?>

                  <?php if (!empty($campaign->downloads)): ?>
                    <?php foreach ($campaign->downloads as $link): ?>
                      <li><?php print l($link['description'], $link['url']); ?></li>
                    <?php endforeach; ?>
                  <?php endif; ?>

                  <?php if (isset($signup_data_form_link)): ?>
                    <li><a href="#" data-modal-href="#modal-signup-data-form"><?php print $signup_data_form_link; ?></a></li>
                  <?php endif; ?>

                  <?php if (isset($shipment_form_link)): ?>
                    <li><a href="#" data-modal-href="#modal-shipment-form"><?php print $shipment_form_link; ?></a></li>
                  <?php endif; ?>

                  <?php if ($register_voters && $can_vote) : ?>
                    <li><a href="#" data-modal-href="#modal-voter-registration">Register to Vote</a></li>
                  <?php endif; ?>

                </ul>
              <?php endif; ?>
              <?php  // End: Materials content section. ?>
            </div>
          </div>
        <?php if($index % 2 === 1 || $index + 1 === $plan_count) : ?> </div> <?php endif; ?>
      <?php endforeach; ?>
      <?php endif; ?>


      <?php if (isset($location_finder['url'])) : ?>
        <div class="container__block -narrow">
          <h3 class="inline-sponsor-color"><?php print t('Find a Location'); ?></h3>
          <?php if (isset($location_finder['copy'])) : ?>
            <?php print $location_finder['copy']; ?>
          <?php endif; ?>

          <div>
            <ul class="form-actions -inline">
              <li><a class="button -secondary" href="<?php print $location_finder['url']; ?>" target="_blank"><?php print t('Locate'); ?></a></li>
            </ul>
          </div>
        </div>
      <?php endif; ?>

      <?php // "Plan It" Section Modals ?>
      <?php if (isset($action_guides)): ?>
        <?php foreach ($action_guides as $delta => $action_guide): ?>
        <div data-modal id="modal-action-guide-<?php print $delta; ?>" role="dialog">
          <div class="with-lists">
            <?php print $action_guide['content']; ?>
          </div>

          <div class="modal__block">
            <div class="form-actions">
              <a href="#" class="js-close-modal"><?php print t('Back to main page'); ?></a>
            </div>
          </div>
        </div>
        <?php endforeach; ?>
      <?php endif; ?>

      <?php if (isset($signup_data_form)): ?>
        <div data-modal id="modal-signup-data-form" class="modal--signup-data" role="dialog" >
          <?php if ($register_voters && $can_vote) : ?>
            <?php print $voter_reg_form ?>
          <?php else: ?>
            <div><?php print render($signup_data_form); ?></div>
          <?php endif; ?>
          <?php if ($register_voters && dosomething_campaign_feature_on($campaign, 'social_share_unique_link')) : ?>
            <div class="modal__block">
              <p>Copy and paste your share link:</p>
              <code><?php print $custom_social_share_link ?></code>
            </div>
          <?php endif; ?>
          <?php if (isset($skip_signup_data_form)): ?>
            <div><?php print render($skip_signup_data_form); ?></div>
          <?php endif; ?>
        </div>
      <?php endif; ?>

      <?php if (isset($shipment_form)): ?>
        <div data-modal id="modal-shipment-form" class="modal--shipment" role="dialog">
          <div><?php print render($shipment_form); ?></div>
        </div>
      <?php endif; ?>
    </div>
  </section>


  <?php // DO IT ////////////////////////////////////////////////////// ?>
  <?php if (!empty($do)): ?>
    <section id="do" class="container -padded container--do">
      <div class="wrapper">
        <div class="container__row">
          <div class="container__block">
            <h2 class="heading -emphasized"><span><?php print t('Step 3: Do It'); ?></span></h2>
          </div>
        </div>
        <?php foreach ($do as $key => $content): ?>
        <div class="container__row">
          <div class="container__block -narrow">

            <?php if (isset($content['image'])): ?>
              <figure class="polaroid">
                <?php print $content['image']; ?>
              </figure>
            <?php endif; ?>

            <?php if (isset($content['header'])): ?>
              <h3 class="inline-sponsor-color"><?php print $content['header']; ?></h3>
            <?php endif; ?>

            <?php if (isset($content['copy'])): ?>
              <?php print $content['copy']; ?>
            <?php endif; ?>

            <?php if (isset($content['tips'])): ?>
              <section id="<?php print 'tips-' . $key ?>" class="tabs tabs--campaign js-tabs">
                <a href="#" data-modal-href="#modal-tips-<?php print $key; ?>" class="tabs__modal-toggle"><?php print t('View Tips'); ?></a>
                <h4 class="visually-hidden"><?php print t('Tips'); ?></h4>
                <div class="wrapper">
                  <nav class="tabs__menu">
                    <ul class="waypoints">
                      <?php foreach ($content['tips'] as $delta => $tip): ?>
                        <?php $delta++; ?>
                        <li class="<?php if ($delta === 1) print ' is-active'?>">
                          <a href="#tip-<?php print $delta; ?>" data-tab="<?php print $delta; ?>"><?php print $tip['header']; ?></a>
                        </li>
                      <?php endforeach; ?>
                    </ul>
                  </nav>

                  <ul class="tabs__body">
                    <?php foreach ($content['tips'] as $delta => $tip): ?>
                      <?php $delta++; ?>
                      <li id="tip-<?php print $delta; ?>" class="tabs__tab">
                        <h5 class="tabs__title"><?php print $tip['header']; ?></h5>
                        <?php print $tip['copy']; ?>
                      </li>
                    <?php endforeach; ?>
                  </ul>
                </div>
              </section>

              <div data-modal id="modal-tips-<?php print $key; ?>" class="modal--tips" role="dialog">
                <div class="modal__block">
                  <h2><?php print t('Tips'); ?></h2>
                </div>
                <div class="modal__block">
                  <?php foreach ($content['tips'] as $delta => $tip): ?>
                    <h4 class="inline-sponsor-color"><?php print $tip['header']; ?></h4>
                    <?php print $tip['copy']; ?>
                  <?php endforeach; ?>
                </div>
                <div class="modal__block">
                  <div class="form-actions">
                    <a href="#" class="js-close-modal"><?php print t('Back to main page'); ?></a>
                  </div>
                </div>
              </div>
            <?php endif; ?>
          </div>
        </div>
        <?php endforeach; ?>
        </div>
    </section>
  <?php endif; ?>


  <?php // PROVE IT ////////////////////////////////////////////////////// ?>
  <section id="prove" class="container container--prove inline-alt-background-color">
    <div class="wrapper">
      <div class="container__row">
        <div class="container__block">
          <h2 class="heading -emphasized -inverse"><span><?php print t('Step 4: Prove It'); ?></span></h2>
        </div>
      </div>
      <div class="container__row">
          <div class="container__block">
            <h3 class="inline-alt-text-color"><?php print t('Pics or It Didn&rsquo;t Happen'); ?></h3>
            <?php if (isset($reportback_copy)): ?>
              <p class="copy inline-alt-text-color"><?php print $reportback_copy; ?></p>
            <?php endif; ?>
            <?php if(dosomething_reportback_exists($campaign->nid)): ?>
              <a href="#" data-modal-href="#modal-missing-photos">Is your photo not showing up?</a>
            <?php endif; ?>
          </div>
      </div>

      <div id="reportback" class="reportback" data-nid="<?php print $campaign->nid; ?>" data-ids="<?php print implode(',', $reportbacks_gallery['item_ids']); ?>" data-remaining="<?php print $reportbacks_gallery['remaining']; ?>" data-admin="<?php print $reportbacks_gallery['admin_access']; ?>">
        <div class="wrapper">

          <ul class="gallery gallery--reportback">
            <?php for ($i = 0; $i < count($reportbacks_gallery['items']); $i++): ?>
              <li <?php if ($i === 1) print ' class="-second"'; ?>>
                <?php print $reportbacks_gallery['items'][$i]; ?>
              </li>
            <?php endfor; ?>
          </ul>

          <div class="reportback__spacer"></div>

          <?php if (isset($reportback_form)): ?>
            <?php print render($reportback_form); ?>
          <?php endif; ?>

          <div class="reportback__spacer"></div>

          <div data-modal id="modal--crop" class="modal--crop" role="dialog">
            <div class="modal__block">
              <h2><?php print t('Edit your photo'); ?></h2>
            </div>
            <div class="image-preview"><!-- Preview image inserted with js --></div>
            <div class="image-editor">
              <div class="__buttons">
                <a href="#" class="button -tertiary -rotate"><?php print t('rotate photo'); ?></a>
                <div class="-change">
                  <label class="button -tertiary" id="edit-reportback-file">
                    <span><?php print t('change photo'); ?></span>
                  </label>
                </div>
              </div>
              <?php /*
              This is a purely frontend form that will grab crop options and a caption
              And then when the user submits the form, it will populate the drupal form with these values.
              */?>
              <div class="modal__block">
                <div id="dosomething-reportback-image-form" class="pseudo-form">
                  <div class="form-item">
                    <label class="field-label" for="modal-caption"><?php print t('Caption'); ?></label>
                    <input class="text-field" placeholder="<?php print $reportback_form['reportback_inputs']['caption']['#attributes']['placeholder'] ?>" type="text" id="modal-caption" name="modal-caption" data-validate="caption" data-validate-required maxlength="60" >
                  </div>
                  <div class="form-action">
                    <button class="button -done"><?php print t('Crop'); ?></button>
                  </div>
                </div>
              </div>
            </div>
          </div>

        </div>
      </div>


        <?php // Voter Registration Modal // ?>
        <?php if ($register_voters) : ?>
          <div data-modal id="modal-voter-registration" role="dialog">
            <?php print $voter_reg_form ?>
            <div class="modal__block">
              <p>Copy and paste your share link:</p>
              <code><?php print $custom_social_share_link ?></code>
            </div>
          </div>
       <?php endif; ?>


      <?php // Custom Share Modal // ?>
      <?php if ($custom_social_share_link) : ?>
        <div data-modal id="modal-share" role="dialog">
          <div class="modal__block">
            <h3>Share this Campaign</h3><br>
            <p>Copy and paste your share link:</p>
            <code><?php print $custom_social_share_link ?></code>
          </div>
        </div>
       <?php endif; ?>


  <?php // Missing Photo Modal // ?>
  <div data-modal id="modal-missing-photos" role="dialog">
    <h2 class="heading -emphasized" >Is your photo not showing up?</h2>
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

      <?php // Organ Donation Modal // ?>
      <?php if (isset($register_organ_donor)): ?>
        <div data-modal id="modal-organ-donation" role="dialog">
          <div class="takeover-container">
            <div class='takeover'>
              <div class="takeover__screen js-collect-zip-code" data-index="0">
                <div class="modal__block">
                  <h2 class="heading -emphasized">Thanks for signing up.</h2>
                </div>
                <div class="modal__block">
                  <form class="organize-zipcode-form">
                      <div class="form-item -padded">
                        <label class="field-label" for="postal_code">Zip Code</label>
                        <input type="text" name="postal_code" id="postal_code" data-validate="zipcode" data-validate-required class="text-field" placeholder="Enter Zip Code" />
                      </div>

                      <div class="form-item -padded submit-button-container">
                        <input type="submit" class="button submit-postal-code" value="Submit" />
                      </div>
                  </form>
                </div>
              </div>

              <div class="takeover__screen js-collect-registration" data-index="1">
                <div class="modal__block">
                  <h2 class="heading -emphasized">Signup to register</h2>
                  <div class="button -muted back-button">&LeftArrow; back</div>
                </div>
                <div class="modal__block">
                  <form class="organize-registration-form">
                      <div class="js-form-fields">
                        <?php // fields get injected here based on response from Organize ?>
                      </div>
                      <div class="form-item">
                        <div class="js-organize-errors"></div>
                      </div>
                      <div class="form-item -padded submit-registration-container">
                        <input type="submit" class="button submit-registration" name="submit-registration" value="Submit" />
                      </div>
                  </form>
                </div>
              </div>

              <div class="takeover__screen js-share-confirmation" data-index="2">
                <div class="modal__block">
                  <h2 class="heading -emphasized">Thanks for registering!</h2>
                </div>
                <div class="modal__block">
                  <h3>Share with your friends!</h3>
                  <p><?php print $social_share_bar ?></p>
                  <p>Copy and paste your share link:</p>
                  <code><?php print $custom_social_share_link ?></code>
                  <div class="form-item -padded submit-done-container">
                    <input type="submit" class="button js-close-modal" value="Done" />
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      <?php endif; ?>

      <?php if (isset($official_rules)): ?>
        <div class="container__block -narrow">
          <div class="footnote">
            <a class="official-rules" href="<?php print $official_rules_src; ?>"><?php print t('Official Rules'); ?></a>
          </div>
        </div>
      <?php endif; ?>
    </div>

    <?php if ($info_bar): ?>
      <?php print $info_bar; ?>
    <?php endif; ?>
  </section>

</article>
