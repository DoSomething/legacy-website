<figure class="photo -stacked -framed">
  <?php if (isset($content->admin_link)): ?>
    <div class="admin-edit">
      <a class="button -secondary" href="<?php print $content->admin_link; ?>"><?php print t('Edit Status'); ?></a>
    </div>
  <?php endif; ?>
  <img src="<?php print $content->media['uri']; ?>" alt="<?php print filter_xss($content->caption); ?>" />
  <figcaption class="__copy">
    <p class="photo__caption"><?php print filter_xss($content->caption); ?></p>
    <?php $schools = ['Masuk High School', 'Chalk Hill Middle School', 'University of Connecticut', 'Fawn Hollow Elementary School', 'New York University', 'Columbia University']; ?>
    <div class="footnote"><?php print $schools[array_rand($schools)] ?></div>
    <div class="form-actions -inline photo--actions">
      <li><a class="button -mini js-kudos-like-button">Eat it!</a> <span class="counter"><?php print rand(13, 1042) ?></span></li>
      <li><a class="button -mini js-kudos-trash-button">Toss it!</a> <span class="counter"><?php print rand(13, 1042) ?></span></li>
      <ul class="photo--shares">
        <li><a href="https://www.facebook.com/share.php?u=http://staging.beta.dosomething.org/reportback/1299" class="social-icon -facebook -secondary js-share-link"><span>Facebook</span></a></li>
        <li><a href="#" class="social-icon -twitter -secondary js-share-link"><span>Twitter</span></a></li>
        <li><a href="#" class="social-icon -tumblr -secondary js-share-link"><span>Tumblr</span></a></li>
      </ul>
    </div>
  </figcaption>
>>>>>>> Hacky prototype for Share For Good.
</figure>
