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
    if( $(".js-campaign-finder").length ) {
      Finder.init(
        $(".js-campaign-results"),
        $(".js-campaign-blankslate"),
        $(".campaign-search"),
        $("input[name='cause']"),
        $("input[name='time']"),
        $("input[name='action-type']")
      );
    }
  })(jquery);


});
