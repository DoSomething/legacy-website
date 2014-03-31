<?php

/**
 * Generates basic HTML structure.
 * @see https://drupal.org/node/1728208
 **/

?>

<!DOCTYPE html>
<html class="no-js">

<head>
  <title><?php print $head_title; ?></title>

  <link type="text/css" rel="stylesheet" href="/<?php print NEUE_PATH; ?>/neue.css" media="all" />
  <link type="text/css" rel="stylesheet" href="/<?php print PARANEUE_DS_PATH; ?>/dist/app.css" media="all" />
  <?php print $styles; ?>

  <!--[if lte IE 8]>
      <link type="text/css" rel="stylesheet" href="/<?php print PARANEUE_DS_PATH; ?>/dist/ie.css" media="all" />
      <script type="text/javascript" src="/<?php print PARANEUE_DS_PATH; ?>/bower_components/html5shiv/dist/html5shiv.js"></script>
  <![endif]-->

  <link rel="shortcut icon" href="/<?php print NEUE_PATH; ?>/assets/images/favicon.ico">
  <link rel="apple-touch-icon-precomposed" href="/<?php print NEUE_PATH; ?>/assets/images/apple-touch-icon-precomposed.png">

  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=Edge,chrome=1">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <?php print $head; ?>
</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php print $page_top; ?>
  <?php print $page; ?>

  <script type="text/javascript" src="/<?php print PARANEUE_DS_PATH; ?>/bower_components/jquery/dist/jquery.min.js"></script>
  <script type="text/javascript" src="/<?php print NEUE_PATH; ?>/neue.js"></script>
  <script type="text/javascript" src="/<?php print PARANEUE_DS_PATH; ?>/dist/app.js"></script>
  <?php print $scripts; ?>

  <?php print $page_bottom; ?>
</body>

</html>
