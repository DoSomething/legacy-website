<section class="campaign-wrapper <?php print $classes; ?>" style="background-image: url(https://trello-attachments.s3.amazonaws.com/52de9089aa3032b85e9b0962/52e1724e23eeb26f4e9fc427/7bbfd71b19c829a2b0feb38073cdb205/campaign-hero.jpg);">
  <div class="campaign-container">
    <h1 class="campaign-title"><?php print $title; ?></h1>
    <p class="campaign-cta"><?php print $cta; ?></p>

    <?php print render($signup_form); ?>

    <img class="campaign-arrow" src="https://trello-attachments.s3.amazonaws.com/52de9089aa3032b85e9b0962/52e1724e23eeb26f4e9fc427/7e9e3ef8974d815230449b9829e98ac0/arrow.png" alt="Click the button!" />
    <p class="campaign-scholarship"><span class="highlight"><?php print $scholarship; ?></span></p>
  </div>
</section>
