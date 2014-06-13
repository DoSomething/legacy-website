define(function(require) {
  "use strict";

  var $ = require("jquery");

  var $sources = $(".sources") || null;

  if ($sources) {
    var $list = $sources.find("ul, div:first");

    // Hide the fact sources list if present.
    $list.hide();

    // Toggle visibility of fact sources.
    $(".js-toggle-sources").on("click", function() {

      // Toggle visibility of fact sources list.
      $list.slideToggle();

    });
  }

});
