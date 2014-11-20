/**
 * This is where we load and initialize components of our app.
 */
define("app", function(require) {
  "use strict";

  var $ = require("jquery");

  // let's get going
  var Finder   = require("finder/Finder");
  var Donate   = require("donate/Donate");
  var Revealer = require("revealer/Revealer");

  // Initialize modules on load
  require("neue/main");
  require("campaign/SchoolFinder");
  require("campaign/sources");
  require("campaign/tips");
  require("campaign/tabs");
  require("campaign/ImageUploader");
  require("validation/auth");
  require("validation/reportback");
  require("validation/address");
  require("validation/donate");
  require("Analytics");
  require("tiles");


  $(document).ready(function() {
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


    /**
     * Show hide large galleries.
     * Only applies to taxonomy pages for the time being.
     */
    var $galleries = $body.find(".gallery.-mosaic");

    if ($body.hasClass("page-taxonomy") && $galleries.length > 0) {
      var galleryList = [];

      $galleries.each(function (index, gallery) {
        var $gallery = $(gallery);
        var $tiles = $gallery.find(".campaign");

        if ($tiles.length > 5) {
          galleryList[index] = new Revealer($gallery, $tiles, "gallery");
        }
      });
    }

    
    $("html").addClass("js-ready");
    
  });

});
