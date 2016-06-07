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

  <?php if ($content->id && $content->allow_reactions): ?>

    <ul class="form-actions -inline photo__actions">

      <?php foreach($content->allowed_reactions as $key => $id): ?>
        <li>
          <a class="button -mini js-kudos-button <?php print dosomething_kudos_term_is_selected($id, $content) ? 'is-active' : '' ?>" data-kudo-id="<?php print $id ?>"><?php print dosomething_kudos_get_icon_by_term_id($id) ?></a>
          <span class="counter"><?php print dosomething_kudos_get_count_by_term_id($id, $content) ?></span>
        </li>
      <?php endforeach; ?>

    </ul>
  <?php endif; ?>

</div>
