<figure class="photo -stacked -framed">
<!--  --><?php //if (isset($content->admin_link)): ?>
<!--    <div class="admin-edit">-->
<!--      <a class="button -secondary" href="--><?php //print $content->admin_link; ?><!--">--><?php //print t('Edit Status'); ?><!--</a>-->
<!--    </div>-->
<!--  --><?php //endif; ?>
  <img src="<?php print $content->media['uri']; ?>" alt="<?php print filter_xss($content->caption); ?>" />
  <figcaption class="__copy">
    <p class="photo__caption"><?php print filter_xss($content->caption); ?></p>
  </figcaption>
  <div class="form-actions -inline photo--actions">
    <li><a class="button -mini js-kudos-like-button">&#128150;</a> <span class="counter"><?php print rand(13, 1042) ?></span></li>
    <li><a class="button -mini js-kudos-trash-button">&#128169;</a> <span class="counter"><?php print rand(13, 1042) ?></span></li>
  </div>
</figure>
