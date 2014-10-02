/**
 * This is where we load and initialize components of our app.
 */
define("app", function(require) {
  "use strict";

  var $ = require("jquery");

  // let's get going
  var Finder = require("finder/Finder");

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
  require("Analytics");
  require("tiles");

  $(document).ready(function() {
    var $campaignFinderForm = $(".js-finder-form");
    if( $campaignFinderForm.length ) {
      var $results = $(".js-campaign-results");
      var $blankSlate = $(".js-campaign-blankslate");
      Finder.init($campaignFinderForm, $results, $blankSlate);
    }
  });

  $(document).ready(function() {
    $("html").addClass("js-ready");
  });
});
