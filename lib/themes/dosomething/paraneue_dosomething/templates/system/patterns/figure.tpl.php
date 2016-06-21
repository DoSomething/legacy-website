<div class="figure <?php print $classes; ?>">
  <?php if (!empty($content['image'])): ?>
    <div class="figure__media">
      <?php if (!empty($content['url'])): ?>
        <a href="<?php print $content['url']; ?>">
          <?php print $content['image']; ?>
        </a>
      <?php else: ?>
        <?php print $content['image']; ?>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <div class="figure__body">
    <?php if (!empty($content['title'])): ?>
      <h3>
        <?php if (!empty($content['url'])): ?>
          <a href="<?php print $content['url']; ?>">
            <?php print $content['title']; ?>
          </a>
        <?php else: ?>
          <?php print $content['title']; ?>
        <?php endif; ?>
      </h3>
    <?php endif; ?>
    <?php if (!empty($content['description'])): ?>
      <?php print $content['description']; ?>
    <?php endif; ?>
    <?php if (array_key_exists('disable_reactions', $content) && !$content['disable_reactions']): ?>
      <ul class="form-actions -inline photo__actions" <?php print $content['id'] ? 'data-reportback-item-id="' . $content['id'] . '"' : ''; ?>>
        <li>
          <button class="js-kudos-button photo__kudos <?php print dosomething_kudos_term_is_selected($content, 'heart') ? 'is-active' : '' ?>" data-kudos-term-id="<?php print $content['allowed_reactions'][0]; ?>" data-kid="<?php print array_key_exists($content['allowed_reactions'][0], $content['existing_kids']) ? dosomething_helpers_isset($content['existing_kids'][$content['allowed_reactions'][0]], 'kid') : false ?>"></button>
          <span class="counter"><?php print $content['reaction_totals']['heart']; ?></span>
        </li>
      </ul>
    <?php endif; ?>
  </div>

  <?php if (!empty($content['url']) && !empty($content['button_text'])): ?>
    <div class="form-actions">
      <a class="button" href="<?php print $content['url'] ?>"><?php print $content['button_text'] ?></a>
    </div>
  <?php endif; ?>
</div>
