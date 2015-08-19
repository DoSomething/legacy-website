<section class="container hot-module">
  <div class="wrapper">
    <div class="container__block">
      <div class="stat-card">
        <div class="stat-card__totals">
          <h4 class="stat-card__verbs"><?php print $reportback_noun_verb ?></h4>
          <p class="stat-card__progress"><?php print number_format($campaign_progress, 0, '', ','); ?></p>
          <p class="stat-card__goal">Out of <?php print number_format($goal, 0, '', ','); ?></p>
        </div>
        <div class="stat-card__timing">
          <?php if(isset($time_left)): ?>
            <p><?php print $time_left ?></p>
          <?php endif; ?>
        </div>
        <div class="stat-card__chart">
          <canvas class="js-progress-chart" width="280" height="200" data-goal="<?php print $goal; ?>"></canvas>
        </div>
      </div>

      <div class="author-callout">
        <div class="author-callout__copy">
          <?php if(isset($progress_copy)): ?>
            <?php print $progress_copy; ?>
          <?php endif; ?>
        </div>

        <article class="figure -left -center">
          <div class="figure__media">
            <div class="avatar">
              <?php if ($author_image): ?>
                <?php print $author_image ?>
              <?php endif; ?>
            </div>
          </div>
          <div class="figure__body">
              <p class="author-callout__first-name"><?php print $author_name ?></p>
              <p class="author-callout__last-name"><?php print $author_title ?></p>
          </div>
        </article>
        <div class="message-callout -above-horizontal -blue">
          <div class="message-callout__copy">
            <p><?php print $share_copy; ?></p>
          </div>
        </div>
        <?php print $share_bar; ?>
      </div>
    </div>

  </div>
</section>