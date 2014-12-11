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

<article class="campaign campaign--action action"><?php // @TODO: need to deal w/ "action" class. ?>

  <header role="banner" class="-hero <?php print $classes; ?>">
    <div class="wrapper">
      <?php print $campaign_headings; ?>

      <?php print $promotions; ?>

      <?php print $campaign_scholarship; ?>

    </div>
  </header>

  <div class="wrapper">
    <nav id="nav" class="waypoints waypoints--action-menu js-sticky">
      <ul class="__menu js-scroll-indicator">
        <li><a class="js-jump-scroll" href="#know"><?php print t('Know'); ?></a></li>
        <li><a class="js-jump-scroll" href="#plan"><?php print t('Plan'); ?></a></li>
        <li><a class="js-jump-scroll" href="#do"><?php print t('Do'); ?></a></li>
        <li><a class="primary js-jump-scroll" href="#prove"><?php print t('Prove It'); ?></a></li>
      </ul>
    </nav>


    <?php // KNOW IT ////////////////////////////////////////////////////// ?>
    <section id="know" class="container container--know">
      <h2 class="container__title banner"><span><?php print t('Step 1: Know It'); ?></span></h2>

      <div class="wrapper">

        <div class="container__body">
          <div class="-columned -odd">
            <?php if (isset($campaign->fact_problem)): ?>
            <h3 class="inline--alt-color"><?php print t('The Problem'); ?></h3>
            <p><?php print $campaign->fact_problem['fact']; ?><sup><?php print $campaign->fact_problem['footnotes']; ?></sup></p>
            <?php endif; ?>

            <?php // If there's a PSA image or video, output it in this column, otherwise output the modals list if it exists. ?>
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

          <div class="-columned -even -col-last">
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
        </div>

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
    </section>


    <?php // PLAN IT ////////////////////////////////////////////////////// ?>
    <section id="plan" class="container container--plan">
      <h2 class="container__title banner"><span><?php print t('Step 2: Plan It'); ?></span></h2>

      <div class="wrapper">

        <div class="container__body">

        <?php if (isset($starter)) : ?>
          <?php print $starter['safe_value']; ?>
        <?php endif; ?>

        <?php if (isset($plan)): ?>
          <?php foreach ($plan as $index => $content): ?>

            <?php if ($index%2 === 0) print '<div class="__row">'; ?>
            <div class="-columned <?php print $index%2 ? '-even' : '-odd'; ?>">


              <h3 class="inline--alt-color"><?php print $content['title']; ?></h3>
              <?php print $content['content']; ?>

              <?php // Start: Content specifically for Materials content section. ?>
              <?php if ($content['category'] === 'materials'): ?>

                <?php if (isset($action_guides)): ?>
                  <ul>
                  <?php  foreach ($action_guides as $delta => $action_guide): ?>
                    <li><a href="#" data-modal-href="#modal-action-guide-<?php print $delta; ?>"><?php print $action_guide['desc']; ?></a></li>
                  <?php endforeach; ?>
                  </ul>
                <?php endif; ?>

                <?php if (!empty($campaign->downloads)): ?>
                  <ul>
                    <?php foreach ($campaign->downloads as $link): ?>
                      <li><?php print l($link['description'], $link['url']); ?></li>
                    <?php endforeach; ?>
                  </ul>
                <?php endif; ?>

                <?php if (isset($signup_data_form_link)): ?>
                  <ul>
                    <li><a href="#" data-modal-href="#modal-signup-data-form"><?php print $signup_data_form_link; ?></a></li>
                  </ul>
                <?php endif; ?>

                <?php if (isset($shipment_form_link)): ?>
                  <ul>
                    <li><a href="#" data-modal-href="#modal-shipment-form"><?php print $shipment_form_link; ?></a></li>
                  </ul>
                <?php endif; ?>

              <?php endif; ?>
              <?php  // End: Materials content section. ?>

            </div>
            <?php if ($index%2 === 1 || $index + 1 === $plan_count) print '</div>'; ?>

          <?php endforeach; ?>
        <?php endif; ?>


        <?php if (isset($location_finder['url'])) : ?>
          <div class="__row">
            <h3 class="inline--alt-color"><?php print t('Find a Location'); ?></h3>
            <?php if (isset($location_finder['copy'])) : ?>
              <?php print $location_finder['copy']; ?>
            <?php endif; ?>

            <a class="btn secondary" href="<?php print $location_finder['url']; ?>" target="_blank"><?php print t('Locate'); ?></a>
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
    <section id="do" class="container container--do">
      <h2 class="container__title banner"><span><?php print t('Step 3: Do It'); ?></span></h2>

      <div class="wrapper">

        <div class="container__body -compact">

          <?php foreach ($do as $key => $content): ?>
            <div class="__row">

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
                  <h2 class="banner">Tips</h2>
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

      </div>
    </section>


    <?php // PROVE IT ////////////////////////////////////////////////////// ?>
    <section id="prove" class="container container--prove inline--alt-bg">
      <h2 class="container__title banner"><span><?php print t('Step 4: Prove It'); ?></span></h2>

      <div class="wrapper">
        <?php if( $show_new_reportback ): ?>


          <h3><?php print t('Pics or It Didn’t Happen'); ?></h3>

          <?php if (isset($reportback_copy)): ?>
            <p class="copy"><?php print $reportback_copy; ?></p>
          <?php endif; ?>

          <div class="reportback">
            <div class="wrapper">
              <ul class="gallery gallery--reportback">
                <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/animals" alt="aminals" />
                    <figcaption class="__copy">Lorem ipsum dolor sit amet.</figcaption>
                  </figure>
                </li>
                <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/tech" alt="tech" />
                    <figcaption class="__copy">Lorem ipsum dolor sit amet, consectetur adipisicing.</figcaption>
                  </figure>
                </li>
                <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/arch" alt="architecture" />
                    <figcaption class="__copy">Lorem ipsum dolor sit.</figcaption>
                  </figure>
                </li>
                <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/nature" alt="nature" />
                    <figcaption class="__copy">Lorem ipsum dolor sit amet, consectetur.</figcaption>
                  </figure>
                </li>
                <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/people" alt="people" />
                    <figcaption class="__copy">Lorem ipsum dolor sit amet, consectetur.</figcaption>
                  </figure>
                </li>
                <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/animals" alt="aminals" />
                    <figcaption class="__copy">Lorem ipsum dolor sit amet, consectetur.</figcaption>
                  </figure>
                </li>
              </ul>

              <div class="spacer"></div>

              <form enctype="multipart/form-data" action="#" method="post" id="dosomething-reportback-form" accept-charset="UTF-8">
                <div>

                  <div class="gigantor -square">
                    <div class="wrapper">
                      <div class="message-callout -below">
                        <div class="__copy">
                          <p>Be the first!<br/> Add your photo here!</p>
                        </div>
                      </div>
                      <img src="data:image/gif;base64,R0lGODlhCgAKAJEAAAAAAP////Ly8gAAACwAAAAACgAKAAACCJSPqcvtD2MrADs=" alt="">
                      <!-- <img src="http://placeimg.com/300/300/animals" alt=""> -->
                      <input class="js-image-upload form-file" type="file" id="edit-reportback-file" name="files[reportback_file]" size="60">
                    </div>
                  </div>

                  <div class="form-item form-type-textfield form-item-caption-new">
                    <label for="edit-caption">Caption <span class="form-required" title="This field is required.">*</span></label>
                    <input data-validate-required="" placeholder="Write something..." type="text" id="edit-caption" name="caption" value="" size="60" maxlength="128" class="form-text required">
                  </div>

                  <div class="form-item form-type-textfield form-item-quantity">
                    <label for="edit-quantity">
                      <div class="inner-label">
                        <div class="label">Total # of Coffee Consumed <span class="form-required" title="This field is required.">*</span></div>
                        <div class="message"></div>
                      </div>
                    </label>
                    <input placeholder="Enter # here" class="js-validate form-text required" data-validate="positiveInteger" data-validate-required="" type="text" id="edit-quantity" name="quantity" value="" size="60" maxlength="128">
                  </div>

                  <div class="form-item form-type-textarea form-item-why-participated">
                  <label for="edit-why-participated">
                    <div class="inner-label">
                      <div class="label">Why is this important to you? <span class="form-required" title="This field is required.">*</span></div>
                      <div class="message"></div>
                    </div>
                    </label>
                  <div class="form-textarea-wrapper resizable">
                    <textarea placeholder="Write something..." class="js-validate form-textarea required" data-validate="reportbackReason" data-validate-required="" id="edit-why-participated" name="why_participated" cols="60" rows="5"></textarea>
                  </div>
                </div>

                <div class="form-actions form-wrapper" id="edit-actions--4">
                  <input class="btn form-submit" type="submit" id="edit-submit--5" name="op" value="Update Pic">
                </div>

                </div>
              </form>

              <div data-modal id="modal--image-crop" role="dialog">
                <h2 class="banner">Example Content</h2>
                <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Voluptatem, officia impedit eius velit consectetur provident ullam! Incidunt, rem, maxime sit non natus praesentium nobis voluptas enim repudiandae. Commodi, eum, accusamus. Let us take a look at.</p>
                <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Voluptatem, officia impedit eius velit consectetur provident ullam! Incidunt, rem, maxime sit non natus praesentium nobis voluptas enim repudiandae. Commodi, eum, accusamus.</p>
                <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Voluptatem, officia impedit eius velit consectetur provident ullam! Incidunt, rem, maxime sit non natus praesentium nobis voluptas enim repudiandae. Commodi, eum, accusamus. Lorem ipsum dolor sit amet, consectetur adipisicing elit. Voluptatem, officia impedit eius velit consectetur provident ullam! Incidunt, rem, maxime sit non natus praesentium nobis voluptas enim repudiandae. Commodi, eum, accusamus.</p>
              </div>
            </div>

            <ul class="gallery gallery--extended -quartet">
                <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/animals" alt="aminals" />
                    <figcaption class="__copy">Lorem ipsum dolor sit amet.</figcaption>
                  </figure>
                </li>
                <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/tech" alt="tech" />
                    <figcaption class="__copy">Lorem ipsum dolor sit amet, consectetur adipisicing.</figcaption>
                  </figure>
                </li>
                <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/arch" alt="architecture" />
                    <figcaption class="__copy">Lorem ipsum dolor sit.</figcaption>
                  </figure>
                </li>
                <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/nature" alt="nature" />
                    <figcaption class="__copy">Lorem ipsum dolor sit amet, consectetur.</figcaption>
                  </figure>
                </li>
                <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/people" alt="people" />
                    <figcaption class="__copy">Lorem ipsum dolor sit amet, consectetur.</figcaption>
                  </figure>
                </li>
                <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/animals" alt="aminals" />
                    <figcaption class="__copy">Lorem ipsum dolor sit amet, consectetur.</figcaption>
                  </figure>
                </li>
                <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/tech" alt="tech" />
                    <figcaption class="__copy">Lorem ipsum dolor sit amet, consectetur adipisicing.</figcaption>
                  </figure>
                </li>
                 <li>
                  <figure class="media -stacked -framed">
                    <img src="http://placeimg.com/300/300/arch" alt="architecture" />
                    <figcaption class="__copy">Lorem ipsum dolor sit.</figcaption>
                  </figure>
                </li>
              </ul>
          </div>



        <?php else: ?>
          <div class="container__body">
            <div class="-columned">
              <h3><?php print t('Pics or It Didn’t Happen'); ?></h3>

              <?php if (isset($reportback_copy)): ?>
                <p class="copy"><?php print $reportback_copy; ?></p>
              <?php endif; ?>

              <?php if (isset($reportback_link)): ?>
                <a href="#" data-modal-href="#modal-report-back" id="link--report-back" class="btn"><?php print $reportback_link['label']; ?></a>
              <?php endif; ?>

              <?php print $prove_scholarship; ?>

              <?php if (isset($reportback_form)): ?>
                <div data-modal id="modal-report-back" class="modal--reportback inline--alt-bg" role="dialog">
                  <h2 class="banner"><?php print t('Prove It'); ?></h2>
                  <?php print render($reportback_form); ?>
                </div>
              <?php endif; ?>
            </div>

            <aside class="carousel-wrapper gallery -columned">
              <?php if (isset($reportback_image)): ?>
                <div id="prev" class="prev-wrapper">
                  <div class="prev-button"><span class="arrow">&#xe605;</span></div>
                </div>

                <div class="slide-wrapper">
                  <?php foreach ($reportback_image as $key=>$image): ?>
                  <figure id="slide<?php print $key ?>" class="slide"><img src="<?php print $image ?>" /></figure>
                  <?php endforeach; ?>
                </div>

                <div id="next" class="next-wrapper">
                  <div class="next-button"><span class="arrow">&#xe60a;</span></div>
                </div>
              <?php else: ?>
              <div class="carousel-wrapper">
                <figure class="slide visible"><?php print $reportback_placeholder; ?></figure>
                </div>
              <?php endif; ?>
            </aside>
          </div>
        <?php endif; ?>

        <?php if (isset($official_rules)): ?>
          <div class="disclaimer">
            <a class="official-rules" href="<?php print $official_rules_src; ?>"><?php print t('Official Rules'); ?></a>
          </div>
        <?php endif; ?>
      </div>
    </section>

    <?php if ($info_bar): ?>
      <?php print $info_bar; ?>
    <?php endif; ?>

  </div>

</article>
