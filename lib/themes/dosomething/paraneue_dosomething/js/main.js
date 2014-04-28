//
//
// The main DS app. This guy runs the show.
//
//

define("main", function(require) {
  "use strict";

  // let's get going
  require("campaign/sources");
  require("campaign/tips");
  require("validation/auth");
  require("validation/reportback");
  require("validation/address");

  var jquery = require("jquery");
  var jquery = require("jquery-once");
  // @NOTE: jQuery.once plugin is concatenated in uglify step
  // so that it is available on page load for Drupal modules.

  var Finder = require("finder/Finder");

  (function($) {
    if( $(".js-finder-form").length ) {
      Finder.init(
        $(".js-finder-form"),
        $(".js-campaign-results"),
        $(".js-campaign-blankslate")
      );
    }
  })(jquery);


});
