<section class="campaign--wrapper">
  <header class="header <?php print $classes; ?>" <?php print (isset($hero_img_l_url) ? 'style="background:url(' . $hero_img_l_url . ');"' : ''); ?>>
    <div class="meta">
      <h1 class="title"><?php print $title; ?></h1>
      <p class="cta"><?php print $cta; ?></p>
    <p class="date"> <?php print $end_date; ?> </p>


      <?php print render($signup_button); ?>

      <?php if (isset($scholarship)): ?>
      <?php //@TODO: Remove Trello-hosted placeholder ?>
      <img class="arrow" src="https://trello-attachments.s3.amazonaws.com/52de9089aa3032b85e9b0962/52e1724e23eeb26f4e9fc427/7e9e3ef8974d815230449b9829e98ac0/arrow.png" alt="Click the button!" />
      <p class="scholarship"><span class="highlight"><?php print $scholarship; ?></span></p>
      <?php endif; ?>

      <?php if (isset($sponsors)): ?>
      <div class="sponsor">
        <?php foreach ($sponsors as $key => $sponsor) :?>
          <?php print $sponsor['name']; ?>
          <?php // print $sponsor['img']; ?>
        <?php endforeach; ?>
      </div>
      <?php endif; ?>
    </div>
  </header>

  <footer class="boilerplate">
    <strong>A DoSomething.org Campaign</strong>
    <span>Join over 2.4 million young people taking action. Any Cause. Any Time. Anywhere.</span>
  </footer>
</section>
