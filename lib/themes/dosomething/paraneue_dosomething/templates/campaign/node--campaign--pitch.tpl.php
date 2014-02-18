<section class="c--wrapper">
  <header class="header <?php print $classes; ?>" style="background-image: url(<?php print $hero_image_l_url; ?>);">
    <div class="meta">
      <h1 class="title"><?php print $title; ?></h1>
      <p class="cta"><?php print $cta; ?></p>

      <?php print render($signup_button); ?>

      <img class="arrow" src="https://trello-attachments.s3.amazonaws.com/52de9089aa3032b85e9b0962/52e1724e23eeb26f4e9fc427/7e9e3ef8974d815230449b9829e98ac0/arrow.png" alt="Click the button!" />
      <p class="scholarship"><span class="highlight"><?php print $scholarship; ?></span></p>

      <div class="sponsor">
        <?php if (isset($sponsors)): ?>
          <?php foreach ($sponsors as $key => $sponsor) :?>
            <?php print $sponsor['name']; ?>
            <?php // print $sponsor['img']; ?>
          <?php endforeach; ?>
        <?php endif; ?>
      </div>
    </div>
  </header>
</section>
