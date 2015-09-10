<section class="container win-module">
  <div class="container win-module__progress">
    <div class="wrapper">
      <div class="win-module__titles">
        <h2><?php print number_format($campaign_progress, 0, '', ',') ?></h2>
        <h4><?php print $reportback_noun_verb ?></h4>
      </div>
    </div>
  </div>
  <div class="container win-module__copy">
    <div class="wrapper">
      <div class="author-callout">
        <div class="chat-bubble">
          <?php print $win_copy; ?>
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
              <h3><?php print $author_name ?></h3>
              <p><?php print $author_title ?></p>
          </div>
        </article>
        <div class="win-module__share-bar">
          <div class="message-callout -above-horizontal -blue">
            <div class="message-callout__copy">
              <p><?php print $share_copy; ?></p>
            </div>
          </div>
          <?php print $share_bar; ?>
        </div>
      </div>
      <div class="win-module__reportback show-at-large">
        <?php if ($promoted_image): ?>
          <img src="<?php print $promoted_image ?>" />
        <?php endif; ?>
      </div>
    </div>
  </div>
</section>
