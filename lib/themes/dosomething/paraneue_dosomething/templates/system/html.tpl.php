<?php
/**
 * Generates basic HTML structure.
 * @see https://drupal.org/node/1728208
 **/
?>

<!DOCTYPE html>
<!--[if lte IE 8 ]> <html dir="<?php print $language->dir ?>" lang="<?php print $language->language ?>" class="modernizr-no-js ie8"> <![endif]-->
<!--[if IE 9 ]> <html dir="<?php print $language->dir ?>" lang="<?php print $language->language ?>" class="modernizr-no-js ie9"> <![endif]-->
<!--[if (gt IE 9)|!(IE)]><!--><html dir="<?php print $language->dir ?>" lang="<?php print $language->language ?>" class="modernizr-no-js"><!--<![endif]-->

<!-- DoSomething.org Platform <?php print $variables['ds_version'] ?> -->

<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=Edge,chrome=1">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  
  <meta name="drupal-user-id" content="<?php print $drupal_user_id; ?>">

  <title><?php print $head_title; ?></title>

  <?php print $styles; ?>

  <!--[if lte IE 8]>
      <script type="text/javascript" src="<?php print '/' . VENDOR_ASSET_PATH . '/html5shiv/dist/html5shiv.min.js' ?>"></script>
      <script type="text/javascript" src="<?php print '/' . VENDOR_ASSET_PATH . '/es5-shim/es5-shim.min.js' ?>"></script>
      <script type="text/javascript" src="<?php print '/' . VENDOR_ASSET_PATH . '/es5-shim/es5-sham.min.js' ?>"></script>
      <script type="text/javascript" src="<?php print '/' . VENDOR_ASSET_PATH . '/respond.js/dest/respond.min.js' ?>"></script>
  <![endif]-->

  <link rel="shortcut icon" href="<?php print '/' . FORGE_ASSET_PATH . '/dist/assets/images/favicon.ico' ?>">
  <link rel="apple-touch-icon-precomposed" href="<?php print '/' . FORGE_ASSET_PATH . '/dist/assets/images/apple-touch-icon-precomposed.png' ?>">
  <?php print $head; ?>

  <script type="text/javascript" src="<?php print '/' . PARANEUE_PATH . '/dist/modernizr.js' ?>"></script>
</head>

<body class="<?php print $classes; if ($variables['is_affiliate']) print ' -affiliate'; ?>" <?php print $attributes;?>>
  <div class="chrome">
    <?php print $page_top; ?>
    <?php print $page; ?>
  </div>

  <?php print $scripts; ?>
  <?php print $page_bottom; ?>
</body>

</html>
