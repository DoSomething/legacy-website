<div class="photo -stacked -framed" <?php print $content->id ? 'data-reportback-item-id="' . $content->id . '"' : ''; ?>>

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

  <?php if ($content->id && !$content->disable_reactions): ?>
    <ul class="form-actions -inline photo__actions">
      <li>
        <a class="button -mini js-kudos-button <?php print dosomething_kudos_term_is_selected($content, 'heart') ? 'is-active' : '' ?>" data-kudo-id="<?php print array_pop($content->allowed_reactions); ?>">&#128150;</a>
        <span class="counter"><?php print $content->reaction_totals['heart']; ?></span>
      </li>
    </ul>
  <?php endif; ?>

</div>
