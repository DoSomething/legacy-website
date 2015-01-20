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

<header role="banner" class="-hero <?php print $classes; ?>">
  <div class="wrapper">
    <?php print $campaign_headings; ?>

    <?php print $promotions; ?>

    <?php print $campaign_scholarship; ?>
  </div>
</header>

<article class="campaign campaign--action action">
  <nav id="nav" class="waypoints waypoints--action-menu js-sticky">
    <ul class="__menu js-scroll-indicator">
      <li><a class="js-jump-scroll" href="#know"><?php print t('Know'); ?></a></li>
      <li><a class="js-jump-scroll" href="#plan"><?php print t('Plan'); ?></a></li>
      <li><a class="js-jump-scroll" href="#do"><?php print t('Do'); ?></a></li>
      <li><a class="primary js-jump-scroll" href="#prove"><?php print t('Prove It'); ?></a></li>
    </ul>
  </nav>


  <?php // KNOW IT ////////////////////////////////////////////////////// ?>
  <section id="know" class="container">
    <h2 class="heading -banner"><span><?php print t('Step 1: Know It'); ?></span></h2>
    <div class="wrapper">
      <div class="container__body -half">
        <?php if (isset($campaign->fact_problem)): ?>
          <h3 class="inline--alt-color"><?php print t('The Problem'); ?></h3>
          <p><?php print $campaign->fact_problem['fact']; ?><sup><?php print $campaign->fact_problem['footnotes']; ?></sup></p>
        <?php endif; ?>

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
      </div>

      <div class="container__body -half">
        <?php if (isset($campaign->fact_solution) || isset($campaign->solution_copy)): ?>
          <h3 class="inline--alt-color"><?php print t('The Solution'); ?></h3>

          <?php if (isset($campaign->fact_solution)): ?>
            <p><?php print $campaign->fact_solution['fact']; ?><sup><?php print $campaign->fact_solution['footnotes']; ?></sup></p>
          <?php elseif (isset($campaign->solution_copy)): ?>
            <?php print $campaign->solution_copy; ?>
          <?php endif; ?>

          <?php if (isset($campaign->solution_support)): ?>
            <?php print $campaign->solution_support; ?>
          <?php endif; ?>

        <?php endif; ?>

        <?php // If there's a PSA image or video, then it was output in the first column above and thus need to output the modals in this second column instead. ?>
        <?php if (isset($psa)): ?>
          <?php if (isset($modals)): ?>
            <?php print $modals; ?>
          <?php endif; ?>
        <?php endif; ?>
      </div>

      <div class="container__body -narrow">
        <?php if (isset($campaign->fact_sources)): ?>
          <section class="sources">
            <h3 class="__title js-toggle-sources"><?php print t('Sources'); ?></h3>
            <ul class="__body legal">
              <?php foreach ($campaign->fact_sources as $key => $source): ?>
                <li><sup><?php print ($key + 1); ?></sup> <?php print $source; ?></li>
              <?php endforeach; ?>
            </ul>
          </section>
        <?php endif; ?>
      </div>
    </div>
  </section>


  <?php // PLAN IT ////////////////////////////////////////////////////// ?>
  <section id="plan" class="container -padded">
    <h2 class="heading -banner"><span><?php print t('Step 2: Plan It'); ?></span></h2>
    <div class="wrapper">
      <div class="container__body -narrow">
        <?php if (isset($starter)) : ?>
          <?php print $starter['safe_value']; ?>
        <?php endif; ?>
      </div>


      <?php if (isset($plan)): ?>
      <?php foreach ($plan as $index => $content): ?>
        <?php if($index % 2 === 0) : ?> <div class="container__row"> <?php endif; ?>
          <div class="container__body -half list-compacted-wrapper">
            <h3 class="inline--alt-color"><?php print $content['title']; ?></h3>
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
              </ul>
            <?php endif; ?>
            <?php  // End: Materials content section. ?>
          </div>
        <?php if($index % 2 === 1 || $index + 1 === $plan_count) : ?> </div> <?php endif; ?>
      <?php endforeach; ?>
      <?php endif; ?>


      <?php if (isset($location_finder['url'])) : ?>
        <div class="container__body -narrow">
          <h3 class="inline--alt-color"><?php print t('Find a Location'); ?></h3>
          <?php if (isset($location_finder['copy'])) : ?>
            <?php print $location_finder['copy']; ?>
          <?php endif; ?>

          <a class="button -secondary" href="<?php print $location_finder['url']; ?>" target="_blank"><?php print t('Locate'); ?></a>
        </div>
      <?php endif; ?>

      <?php // "Plan It" Section Modals ?>
      <?php if (isset($action_guides)): ?>
        <?php foreach ($action_guides as $delta => $action_guide): ?>
        <div data-modal id="modal-action-guide-<?php print $delta; ?>" role="dialog">
          <div><?php print $action_guide['content']; ?></div>
          <a href="#" class="js-close-modal"><?php print t('Back to main page'); ?></a>
        </div>
        <?php endforeach; ?>
      <?php endif; ?>

      <?php if (isset($signup_data_form)): ?>
        <div data-modal id="modal-signup-data-form" class="modal--signup-data" role="dialog">
          <div><?php print render($signup_data_form); ?></div>
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
  <section id="do" class="container -padded container--do">
    <h2 class="heading -banner"><span><?php print t('Step 3: Do It'); ?></span></h2>
    <div class="wrapper">
      <?php foreach ($do as $key => $content): ?>
        <div class="container__body -narrow">

          <?php if (isset($content['image'])): ?>
            <figure class="polaroid">
              <?php print $content['image']; ?>
            </figure>
          <?php endif; ?>

          <?php if (isset($content['header'])): ?>
            <h3 class="inline--alt-color"><?php print $content['header']; ?></h3>
          <?php endif; ?>

          <?php if (isset($content['copy'])): ?>
            <?php print $content['copy']; ?>
          <?php endif; ?>

          <?php if (isset($content['tips'])): ?>
            <section id="<?php print 'tips-' . $key ?>" class="tabbed js-tabs">
              <a href="#" data-modal-href="#modal-tips-<?php print $key; ?>" class="tabs__modal-toggle"><?php print t('View Tips'); ?></a>
              <h4 class="visually-hidden"><?php print t('Tips'); ?></h4>
              <div class="wrapper">
                <nav class="tabs__menu waypoints">
                  <ul class="__menu">
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
                    <li id="tip-<?php print $delta; ?>" class="tab">
                      <h5 class="__title"><?php print $tip['header']; ?></h5>
                      <?php print $tip['copy']; ?>
                    </li>
                  <?php endforeach; ?>
                </ul>
              </div>
            </section>

            <div data-modal id="modal-tips-<?php print $key; ?>" class="modal--tips" role="dialog">
              <h2 class="heading -banner">Tips</h2>
              <?php foreach ($content['tips'] as $delta => $tip): ?>
                <h4 class="inline--alt-color"><?php print $tip['header']; ?></h4>
                <?php print $tip['copy']; ?>
              <?php endforeach; ?>
              <a href="#" class="js-close-modal"><?php print t('Back to main page'); ?></a>
            </div>
          <?php endif; ?>
        </div>
      <?php endforeach; ?>
    </div>
  </section>


  <?php // PROVE IT ////////////////////////////////////////////////////// ?>
  <section id="prove" class="container container--prove inline--alt-bg <?php if($show_new_reportback) print 'reportback-beta'; ?>">
    <h2 class="heading -banner"><span><?php print t('Step 4: Prove It'); ?></span></h2>

    <?php if( $show_new_reportback ): ?>
      <div class="wrapper">
        <div class="container__body">
          <h3><?php print t('Pics or It Didn’t Happen'); ?></h3>

          <?php if (isset($reportback_copy)): ?>
            <p class="copy"><?php print $reportback_copy; ?></p>
          <?php endif; ?>
        </div>

        <div id="reportback" class="reportback" data-nid="<?php print $campaign->nid; ?>" data-prefetched="<?php print $reportbacks_gallery['prefetched']; ?>" data-total="<?php print $reportbacks_gallery['total']; ?>">
          <div class="wrapper">

            <ul class="gallery gallery--reportback">
              <?php for ($i = 0; $i < count($reportbacks_gallery['items']); $i++): ?>
                <li><?php print $reportbacks_gallery['items'][$i]; ?></li>
              <?php endfor; ?>
            </ul>

            <div class="spacer"></div>

            <?php if (isset($reportback_form)): ?>
              <?php print render($reportback_form); ?>
            <?php endif; ?>

            <div class="spacer"></div>

            <div data-modal id="modal--crop" class="modal--crop" role="dialog">
              <h2 class="banner">Edit your photo</h2>
              <div class="image-preview"><!-- Preview image inserted with js --></div>
              <div class="image-editor">
                <div class="__buttons">
                  <a href="#" class="button -tertiary -rotate">rotate photo</a>
                  <div class="-change">
                    <a href="#" class="button -tertiary">change photo</a>
                    <input type="file" class="js-image-upload-beta" />
                  </div>
                </div>
                <!-- This is a purely frontend form that will grab crop options and a caption
                And then when the user submits the form, it will populate the drupal form with these values. -->
                <form action="#" method="post" id="dosomething-reportback-image-form" accept-charset="UTF-8">
                  <label for="caption">Caption</label>
                  <input placeholder="Write something..." type="text" id="caption" name="caption" value="" size="60" maxlength="128">
                  <input type="submit" value="done" class="button -done" />
                </form>
              </div>
            </div>

          </div>
        </div>
      </div>
    <?php else: ?>
      <div class="wrapper">
        <div class="container__body -half">
          <h3><?php print t('Pics or It Didn’t Happen'); ?></h3>

          <?php if (isset($reportback_copy)): ?>
            <p class="copy"><?php print $reportback_copy; ?></p>
          <?php endif; ?>

          <?php if (isset($reportback_link)): ?>
            <p><a href="#" data-modal-href="#modal-report-back" id="link--report-back" class="button"><?php print $reportback_link['label']; ?></a></p>
          <?php endif; ?>

          <?php print $prove_scholarship; ?>

          <?php if (isset($reportback_form)): ?>
            <div data-modal id="modal-report-back" class="modal--reportback inline--alt-bg" role="dialog">
              <h2 class="heading -banner"><?php print t('Prove It'); ?></h2>
              <?php print render($reportback_form); ?>
            </div>
          <?php endif; ?>
        </div>

        <div class="container__body -half">
          <aside class="carousel">
            <?php if (isset($reportback_image)): ?>
              <div id="prev" class="carousel__control -previous">
                <span>Previous Slide</span>
              </div>

              <div class="slides">
                <?php foreach ($reportback_image as $key=>$image): ?>
                <img id="slide<?php print $key ?>" class="carousel__slide bordered" src="<?php print $image ?>" />
                <?php endforeach; ?>
              </div>

              <div id="next" class="carousel__control -next">
                <span>Next Slide</span>
              </div>
            <?php else: ?>
              <?php print $reportback_placeholder; ?>
            <?php endif; ?>
          </aside>
        </div>
      </div>
    <?php endif; ?>

    <?php if (isset($official_rules)): ?>
      <div class="disclaimer">
        <a class="official-rules" href="<?php print $official_rules_src; ?>"><?php print t('Official Rules'); ?></a>
      </div>
    <?php endif; ?>

    <?php if ($info_bar): ?>
      <?php print $info_bar; ?>
    <?php endif; ?>
  </section>

</article>
