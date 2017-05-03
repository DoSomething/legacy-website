<?php
/**
 * Returns the HTML for the Campaign Closed page.
 *
 * Available Variables
 * - $campaign: A campaign object. @see dosomething_campaign_load()
 * - $title: Title for the campaign closed page (string).
 * - $classes: Additional classes passed for output (string).
 * - $presignup_callout: Call to action (string).
 * - $sponsors: List of sponsors (array).
 * - $total_participants: Number of members participated (string).
 * - $total_quantity: Total quantity of campaign items (string).
 * - $total_quantity_label: Label for the campign items donated (string).
 * - $intro: Intro copy for campaign closed page (string).
 * - $reportback_gallery: Galleries for 'What You Did' (array).
 */
?>

<article class="campaign campaign--closed closed">

  <header role="banner" class="header -hero <?php print $classes; ?>">
    <div class="wrapper">
      <?php print $campaign_headings; ?>

      <?php if (isset($signup_button)): ?>
        <div class="header__signup">
          <?php if (isset($presignup_callout)): ?>
          <div class="message-callout -above -white -dynamic-right">
            <div class="message-callout__copy">
              <p><?php print $presignup_callout; ?></p>
            </div>
          </div>
          <?php endif; ?>

          <?php print render($signup_button); ?>
        </div>
      <?php endif; ?>

      <?php print $promotions; ?>
    </div>
  </header>

  <?php // WHAT YOU DID ////////////////////////////////////////////////////// ?>
  <section class="container container--did">
    <h2 class="heading -banner"><span><?php print t('What You Did'); ?></span></h2>

    <?php // Campaign statistics ?>

    <div class="wrapper">
      <div class="container__block">
      <?php if (isset($total_participants)): ?>

        <?php // Number of members  participated ?>
        <div class="statistic<?php if ($participants_columned): ?> -columned -odd<?php endif; ?>">
          <div class="statistic__body">
            <p>
              <strong class="inline-sponsor-color"><?php print $total_participants; ?></strong>
              <em><?php print t('Members Participated'); ?></em>
            </p>
          </div>
        </div>
      <?php endif; ?>

      <?php if (isset($total_quantity_label)) : ?>

        <?php if (isset($total_quantity)): ?>

          <?php // Total quantity & label ?>
          <div class="statistic<?php if ($quantity_columned): ?> -columned -even -col-last<?php endif; ?>">
            <div class="statistic__body">
              <p>
                <strong class="inline-sponsor-color"><?php print $total_quantity; ?></strong>
                <em><?php print $total_quantity_label; ?></em>
              </p>
            </div>
          </div>

        <?php else: ?>

          <?php if (isset($total_quantity_placeholder)): ?>

            <?php // Placeholder copy when quantity has not been entered ?>
            <div class="statistic<?php if ($quantity_columned): ?> -columned -even -col-last<?php endif; ?>">
              <div class="statistic__body">
                <div class="placeholder">
                  <p><?php print $total_quantity_placeholder; ?></p>
                </div>
              </div>
            </div>

          <?php endif; ?>

        <?php endif; ?>

      <?php endif; ?>
      </div>

    <?php // Intro copy ?>
    <?php if (isset($intro)): ?>
      <div class="container__block">
        <?php print $intro['safe_value']; ?>
      </div>
    <?php endif; ?>

    <?php // Reportback gallery ?>
    <?php if (isset($reportback_gallery)): ?>
      <div class="container__block">
        <ul class="gallery -triad">
          <?php foreach ($reportback_gallery as $key => $reportback_gallery_item) :?>

            <li <?php if (isset($reportback_gallery_item['order_class'])): ?> class="<?php print $reportback_gallery_item['order_class']; ?>" <?php endif; ?>>
              <div class="figure">
                <?php if (isset($reportback_gallery_item['image'])): ?>
                  <div class="figure__media">
                    <?php print $reportback_gallery_item['image']; ?>
                  </div>
                <?php endif; ?>
                <div class="figure__body">
                  <?php if (isset($reportback_gallery_item['first_name'])): ?>
                    <h3><?php print check_plain($reportback_gallery_item['first_name']); ?></h3>
                  <?php endif; ?>
                  <?php if (isset($reportback_gallery_item['caption'])): ?>
                    <?php print filter_xss($reportback_gallery_item['caption']); ?>
                  <?php endif; ?>
                </div>
              </div>
            </li>

          <?php endforeach; ?>
        </ul>
      </div>
    <?php endif; ?>

    </div>
  </section>

  <?php if ($display_buzz_section): ?>
  <?php // THE BUZZ ////////////////////////////////////////////////////// ?>
    <section class="container container--celebs">
      <h2 class="heading -banner"><span><?php print t('The Buzz'); ?></span></h2>

      <div class="wrapper">

        <div class="container__block <?php if (isset($psa)): print '-half'; else: print '-narrow'; endif; ?>">
          <?php if (isset($additional_text_title)): ?>
          <h3 class="inline-sponsor-color"><?php print $additional_text_title; ?></h3>
          <?php endif; ?>

          <?php if (isset($additional_text)): ?>
          <div><?php print $additional_text['safe_value']; ?></div>
          <?php endif; ?>
        </div>

        <?php if (isset($psa)): ?>
          <div class="container__block -half">
            <aside class="media-video">
              <?php print $psa; ?>
            </aside>
          </div>
        <?php endif; ?>

        <?php foreach ($klout_gallery as $key => $klout_gallery_item) :?>
        <div class="container__block">
          <h3 class="inline-sponsor-color"><?php print $klout_gallery_item['title']; ?></h3>

          <?php // The klout galleries ?>
          <ul class="gallery <?php print $klout_gallery_item['style']; ?>">
            <?php foreach ($klout_gallery_item['items'] as $key => $gallery_item) :?>

              <?php if ($klout_gallery_item['type'] === 'mention') : ?>
                <li class="<?php print $gallery_item['order_class']; ?>">
                  <div class="figure -left -medium">
                    <?php if (isset($gallery_item['image'])): ?>
                    <div class="figure__media">
                      <?php if (isset($gallery_item['url']) && !empty($gallery_item['url'])): ?>
                        <a href="<?php print $gallery_item['url']; ?>"><?php print $gallery_item['image']; ?></a>
                      <?php else: ?>
                        <?php print $gallery_item['image']; ?>
                      <?php endif; ?>
                    </div>
                    <?php endif; ?>

                    <div class="figure__body">
                      <?php if (isset($gallery_item['title']) && !empty($gallery_item['title'])): ?>
                        <h3><?php print $gallery_item['title']; ?></h3>
                      <?php endif; ?>
                      <?php if (isset($gallery_item['desc'])): ?>
                        <?php print $gallery_item['desc']; ?>
                      <?php endif; ?>
                    </div>
                  </div>
                </li>
              <?php else: ?>
                <li class="<?php print $gallery_item['order_class']; ?>">
                  <div class="figure">
                    <?php if (isset($gallery_item['image'])): ?>
                      <div class="figure__media">
                        <?php if (isset($gallery_item['url']) && !empty($gallery_item['url'])): ?>
                          <a href="<?php print $gallery_item['url']; ?>"><?php print $gallery_item['image']; ?></a>
                        <?php else: ?>
                          <?php print $gallery_item['image']; ?>
                        <?php endif; ?>
                      </div>
                    <?php endif; ?>
                    <?php if (isset($gallery_item['title']) && !empty($gallery_item['title'])): ?>
                      <h3><?php print $gallery_item['title']; ?></h3>
                    <?php endif; ?>
                    <?php if (isset($gallery_item['desc'])): ?>
                      <div class="figure__body"><?php print $gallery_item['desc']; ?></div>
                    <?php endif; ?>
                  </div>
                </li>
              <?php endif; ?>

            <?php endforeach; ?>
          </ul>

        </div>
        <?php endforeach; ?>

      </div>
    </section>
  <?php endif; ?>


  <?php if ($display_winners): ?>
  <?php // CONGRATULATIONS TO... ////////////////////////////////////////////////////// ?>
  <section class="container container--congrats">
    <h2 class="heading -banner"><span><?php print t('Congrats to&hellip;'); ?></span></h2>

    <div class="wrapper">
      <?php // If winners have been picked, display as a gallery ?>
      <?php if (isset($winners)): ?>
        <?php foreach ($winners as $key => $winner) :?>
          <div class="container__row">
            <div class="container__block <?php if (isset($winner['image'])): print '-half'; else: print '-narrow'; endif; ?>">
              <?php if (isset($winner['fname'])): ?>
                <h3 class="inline-sponsor-color"><?php print $winner['fname']; ?></h3>
              <?php endif; ?>

              <?php if (isset($winner['field_winner_type'])): ?>
                <h4><?php print t('@field_winner_type Winner', ['@field_winner_type' => $winner['field_winner_type']]); ?></h4>
              <?php endif; ?>


              <?php if (isset($winner['field_winner_description'])): ?>
                <p><?php print $winner['field_winner_description']; ?></p>
              <?php endif; ?>

              <?php if (isset($winner['field_winner_quote'])): ?>
                <p>"<?php print $winner['field_winner_quote']; ?>"</p>
              <?php endif; ?>
            </div>

            <?php if (isset($winner['image'])): ?>
              <div class="container__block -half">
                <?php print $winner['image']; ?>
              </div>
            <?php endif; ?>
          </div>
        <?php endforeach; ?>
      <?php // Else display the default placeholder copy while winners are being chosen ?>
      <?php elseif (isset($default_winners)) : ?>
        <div class="container__block">
          <div class="placeholder">
            <p><?php print $default_winners; ?></p>
          </div>
        </div>
      <?php endif; ?>
    </div>
  </section>
  <?php endif; ?>

  <?php if ($info_bar): ?>
    <?php print $info_bar; ?>
  <?php endif; ?>

</article>
