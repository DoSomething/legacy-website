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
    <?php if (isset($content['kudos']) && isset($content['kudos']['fid'])): ?>
      <ul class="form-actions -inline kudos" <?php print $content['kudos']['fid'] ? 'data-reportback-item-id="' . $content['kudos']['fid'] . '"' : ''; ?>>
        <li>
          <?php if (variable_get('rogue_collection', FALSE)): ?>
            <button class="js-kudos-button kudos__icon <?php print $content['kudos']['liked_in_rogue'] ? 'is-active' : '' ?>" data-kudos-term-id="1" data-kid="<?php print $content['kudos']['liked_in_rogue'] ? $content['kudos']['fid'] : null ?>"></button>
          <?php else: ?>
            <button class="js-kudos-button kudos__icon <?php print dosomething_kudos_term_is_selected($content['kudos'], 'heart') ? 'is-active' : '' ?>" data-kudos-term-id="<?php print $content['kudos']['allowed_reactions'][0]; ?>" data-kid="<?php print array_key_exists($content['kudos']['allowed_reactions'][0], $content['kudos']['existing_kids']) ? dosomething_helpers_isset($content['kudos']['existing_kids'][$content['kudos']['allowed_reactions'][0]], 'kid') : false ?>"></button>
          <?php endif; ?>
          <span class="counter"><?php print $content['kudos']['reaction_totals']['heart']; ?></span>
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
