<figure class="photo -stacked -framed" data-reportback-item-id="<?php print $content->id; ?>">
<!--  --><?php //if (isset($content->admin_link)): ?>
<!--    <div class="admin-edit">-->
<!--      <a class="button -secondary" href="--><?php //print $content->admin_link; ?><!--">--><?php //print t('Edit Status'); ?><!--</a>-->
<!--    </div>-->
<!--  --><?php //endif; ?>
  <img src="<?php print $content->media['uri']; ?>" alt="<?php print filter_xss($content->caption); ?>" />
  <figcaption class="__copy">
    <p class="photo__caption"><?php print filter_xss($content->caption); ?></p>
  </figcaption>
  <?php if ($content->allow_reactions): ?>
    <div class="form-actions -inline photo--actions">
      <li><a class="button -mini js-kudos-button" data-kudo-id="<?php print $content->allowed_reactions[0] ?>">&#128150;</a> <span class="counter"><?php print $content->likes ?></span></li>
      <li><a class="button -mini js-kudos-button" data-kudo-id="<?php print $content->allowed_reactions[1] ?>">&#128169;</a> <span class="counter"><?php print $content->poos ?></span></li>
    </div>
  <?php endif; ?>
</figure>
