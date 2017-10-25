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
  <?php if (isset($content->kudos) && isset($content->kudos['fid'])): ?>
    <ul class="form-actions -inline kudos">
      <li>
        <button class="js-kudos-button kudos__icon <?php print $content->kudos['liked_in_rogue'] ? 'is-active' : '' ?>" data-kudos-term-id="1" data-kid="<?php print $content->kudos['liked_in_rogue'] ? $content->id : null ?>"></button>
        <span class="counter"><?php print $content->kudos['reaction_totals']['heart']; ?></span>
      </li>
    </ul>
  <?php endif; ?>

</div>
