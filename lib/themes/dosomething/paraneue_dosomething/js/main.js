//
//
// The main DS app. This guy runs the show.
//
//

define("main", function(require) {
  "use strict";

  // let's get going
  var $ = window.jQuery;
  var Finder = require("finder/Finder");

  require("neue/main");

  // Load polyfills
  require("neue/vendor/polyfills/respond");
  require("neue/vendor/polyfills/rem");

  // Initialize modules on load
  require("campaign/sources");
  require("campaign/tips");
  require("campaign/ImageUploader");
  require("validation/auth");
  require("validation/reportback");
  require("validation/address");

  $(function() {
    if( $(".js-finder-form").length ) {
      Finder.init(
        $(".js-finder-form"),
        $(".js-campaign-results"),
        $(".js-campaign-blankslate")
      );
    }
  });


});
