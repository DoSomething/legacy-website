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

  var jquery = require("jquery");
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
