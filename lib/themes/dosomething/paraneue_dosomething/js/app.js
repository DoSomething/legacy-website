/**
 * This is where we load and initialize components of our app.
 */
define("app", function (require) {
  "use strict";

  var $ = require("jquery");
  var _ = require("lodash");

  // let's get going
  var Finder   = require("finder/Finder");
  var Donate   = require("donate/Donate");
  var Revealer = require("revealer/Revealer");
  var Swapper  = require("swapper/Swapper");

  // Initialize modules on load
  require("neue/main");
  require("campaign/SchoolFinder");
  require("campaign/sources");
  require("campaign/tips");
  require("campaign/tabs");
  require("campaign/ImageUploader");
  require("campaign/ImageCrop");
  require("validation/auth");
  require("validation/reportback");
  require("validation/address");
  require("validation/donate");
  require("Analytics");
  require("tiles");


  $(document).ready(function () {
    var $body = $("body");

    var $campaignFinderForm = $(".js-finder-form");
    if( $campaignFinderForm.length ) {
      var $results = $(".js-campaign-results");
      var $blankSlate = $(".js-campaign-blankslate");
      Finder.init($campaignFinderForm, $results, $blankSlate);
    }


    var $donateForm = $("#modal--donate-form");
    if( $donateForm.length ) {
      Donate.init();
    }


    var $mosaicGalleries = $body.find(".gallery.-mosaic");

    /**
     * Show hide large galleries.
     * Only applies to taxonomy pages for the time being.
     */
    if ($body.hasClass("page-taxonomy") && $mosaicGalleries.length > 0) {
      var galleryList = [];

      $mosaicGalleries.each(function (index, gallery) {
        var $gallery = $(gallery);
        var $tiles = $gallery.find("li");

        if ($tiles.length > 5) {
          galleryList[index] = new Revealer($gallery, $tiles, "gallery");
        }
      });
    }


    /**
     * Swap low resolution images for feature tiles in mosaic gallery
     * with higher resolution version from tablet size up.
     */
    if ($mosaicGalleries.length && $mosaicGalleries.hasClass("-featured")) {
      var swappedImagesList = [];

      $(window).on("resize", _.debounce(function () {

        if (window.matchMedia("(min-width: 768px)").matches && !swappedImagesList.length) {
          $mosaicGalleries.each(function (index) {
            var $featureTile = $(this).find("li").first();
            swappedImagesList[index] = new Swapper($featureTile);
          });
        }
      }, 500));

    }


    $("html").addClass("js-ready");

  });

});
