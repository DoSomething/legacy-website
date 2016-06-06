<div class="photo -stacked -framed" data-reportback-item-id="<?php print $content->id; ?>">
  <figure class="wrapper">
    <?php if (isset($content->admin_link)): ?>
      <div class="admin-edit">
        <a class="button -secondary" href="<?php print $content->admin_link; ?>"><?php print t('Edit Status'); ?></a>
      </div>
    <?php endif; ?>
    <img src="<?php print $content->media['uri']; ?>" alt="<?php print filter_xss($content->caption); ?>" />
    <figcaption class="photo__copy">
      <p class="photo__caption"><?php print filter_xss($content->caption); ?></p>
    </figcaption>
  </figure>

  <?php if ($content->allow_reactions): ?>
    <ul class="form-actions -inline photo__actions">
      <li><a class="button -mini js-kudos-button <?php print ! empty($content->existing_kids[$content->allowed_reactions[0]]->kid) ? 'is-active' : '' ?>" data-kudo-id="<?php print $content->allowed_reactions[0] ?>" data-kid="<?php print dosomething_helpers_isset($content->existing_kids[$content->allowed_reactions[0]], 'kid') ?>">&#128150;</a> <span class="counter"><?php print $content->likes ?></span></li>
      <li><a class="button -mini js-kudos-button <?php print ! empty($content->existing_kids[$content->allowed_reactions[1]]->kid) ? 'is-active' : '' ?>" data-kudo-id="<?php print $content->allowed_reactions[1] ?>" data-kid="<?php print dosomething_helpers_isset($content->existing_kids[$content->allowed_reactions[1]], 'kid') ?>">&#128169;</a> <span class="counter"><?php print $content->poos ?></span></li>
    </ul>
  <?php endif; ?>
</div>
