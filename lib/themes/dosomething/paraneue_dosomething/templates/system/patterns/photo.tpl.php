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
        <?php if ($content->kudos['from_rogue']): ?>
          <button class="js-kudos-button kudos__icon is-active" data-kudos-term-id="<?php print $content->kudos['allowed_reactions'][0]; ?>" data-kid="<?php print data_get($content->kudos['existing_kids'], [$content->kudos['allowed_reactions'][0], 'kid']) ?>"></button>
        <?php else: ?>
          <button class="js-kudos-button kudos__icon <?php print dosomething_kudos_term_is_selected($content->kudos, 'heart') ? 'is-active' : '' ?>" data-kudos-term-id="<?php print $content->kudos['allowed_reactions'][0]; ?>" data-kid="<?php print data_get($content->kudos['existing_kids'], [$content->kudos['allowed_reactions'][0], 'kid']) ?>"></button>
        <?php endif; ?>
        <span class="counter"><?php print $content->kudos['reaction_totals']['heart']; ?></span>
      </li>
    </ul>
  <?php endif; ?>

</div>
