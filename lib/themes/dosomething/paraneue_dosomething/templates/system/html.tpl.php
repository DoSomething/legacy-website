<?php
/**
 * Generates basic HTML structure.
 * @see https://drupal.org/node/1728208
 **/
?>

<!DOCTYPE html>
<!--[if lte IE 8 ]> <html dir="ltr" lang="en-US" class="modernizr-no-js ie8"> <![endif]-->
<!--[if IE 9 ]> <html dir="ltr" lang="en-US" class="modernizr-no-js ie9"> <![endif]-->
<!--[if (gt IE 9)|!(IE)]><!--><html class="modernizr-no-js"><!--<![endif]-->

<!-- DoSomething.org Platform <?php print $variables['ds_version'] ?> -->

<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=Edge,chrome=1">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta name="crowdcurity-site-verification" content="voJ0lyI8JXV5Ab1XAYMaoQj7WsoScgkfk9TLG0dA">

  <title><?php print $head_title; ?></title>
  <script type="text/javascript" src="<?php print DS_ASSET_PATH; ?>/dist/modernizr.js"></script>

  <link rel="stylesheet" href="<?php print DS_STYLE_PATH; ?>" type="text/css" />
  <?php print $styles; ?>

  <!--[if lte IE 8]>
      <script type="text/javascript" src="<?php print VENDOR_ASSET_PATH; ?>/html5shiv/dist/html5shiv.min.js"></script>

      <script type="text/javascript" src="<?php print VENDOR_ASSET_PATH; ?>/respond/dest/respond.min.js"></script>
      <link href="<?php print VENDOR_ASSET_PATH; ?>/respond/cross-domain/respond-proxy.html" id="respond-proxy" rel="respond-proxy" />
      <link href="<?php print LOCAL_ASSET_PATH; ?>/bower_components/respond/cross-domain/respond.proxy.gif" id="respond-redirect" rel="respond-redirect" />
      <script type="text/javascript" src="<?php print LOCAL_ASSET_PATH; ?>/bower_components/respond/cross-domain/respond.proxy.js"></script>
  <![endif]-->

  <link rel="shortcut icon" href="<?php print NEUE_ASSET_PATH; ?>/assets/images/favicon.ico">
  <link rel="apple-touch-icon-precomposed" href="<?php print NEUE_ASSET_PATH; ?>/assets/images/apple-touch-icon-precomposed.png">
  <?php print $head; ?>
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
