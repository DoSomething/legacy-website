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

  <meta name="csrf-token" content="<?php print $csrf_token; ?>">
  <meta name="drupal-user-id" content="<?php print $drupal_user_id; ?>">

  <title><?php print $head_title; ?></title>

  <?php print $styles; ?>

  <!--[if lte IE 8]>
      <script type="text/javascript" src="<?php print '/' . VENDOR_ASSET_PATH . '/html5shiv/dist/html5shiv.min.js' ?>"></script>
      <script type="text/javascript" src="<?php print '/' . VENDOR_ASSET_PATH . '/es5-shim/es5-shim.min.js' ?>"></script>
      <script type="text/javascript" src="<?php print '/' . VENDOR_ASSET_PATH . '/es5-shim/es5-sham.min.js' ?>"></script>
      <script type="text/javascript" src="<?php print '/' . VENDOR_ASSET_PATH . '/respond.js/dest/respond.min.js' ?>"></script>
  <![endif]-->

  <link rel="shortcut icon" href="<?php print '/' . FORGE_ASSET_PATH . '/assets/images/favicon.ico' ?>">
  <link rel="apple-touch-icon-precomposed" href="<?php print '/' . FORGE_ASSET_PATH . '/assets/images/apple-touch-icon-precomposed.png' ?>">
  <?php print $head; ?>

  <script type="text/javascript" src="<?php print '/' . PARANEUE_PATH . '/dist/modernizr.js' ?>"></script>
</head>

<body class="<?php print $classes; if ($variables['is_affiliate']) print ' -affiliate'; ?>" <?php print $attributes;?>>
  <div class="chrome">
    <?php print $page_top; ?>
    <?php print $page; ?>
  </div>

  <?php print $scripts; ?>

  <?php if ($variables['enable_ad_tracking']): ?>
    <!-- Twitter single-event website tag code -->
    <script src="//platform.twitter.com/oct.js" type="text/javascript"></script>
    <script type="text/javascript">twttr.conversion.trackPid('nvo4z', { tw_sale_amount: 0, tw_order_quantity: 0 });</script>
    <noscript>
    <img height="1" width="1" style="display:none;" alt="" src="https://analytics.twitter.com/i/adsct?txn_id=nvo4z&p_id=Twitter&tw_sale_amount=0&tw_order_quantity=0" />
    <img height="1" width="1" style="display:none;" alt="" src="//t.co/i/adsct?txn_id=nvo4z&p_id=Twitter&tw_sale_amount=0&tw_order_quantity=0" />
    </noscript>

    <!-- Facebook Pixel Code -->
    <script>
    !function(f,b,e,v,n,t,s){if(f.fbq)return;n=f.fbq=function(){n.callMethod?
    n.callMethod.apply(n,arguments):n.queue.push(arguments)};if(!f._fbq)f._fbq=n;
    n.push=n;n.loaded=!0;n.version='2.0';n.queue=[];t=b.createElement(e);t.async=!0;
    t.src=v;s=b.getElementsByTagName(e)[0];s.parentNode.insertBefore(t,s)}(window,
    document,'script','https://connect.facebook.net/en_US/fbevents.js');
    fbq('init', '883788485091123');
    fbq('track', 'PageView');
    fbq('track', 'CompleteRegistration');
    </script>
    <noscript><img height="1" width="1" style="display:none"
    src="https://www.facebook.com/tr?id=883788485091123&ev=PageView&noscript=1"
    /></noscript>
  <?php endif; ?>
</body>

</html>
