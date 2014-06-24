define(function(require) {
  "use strict";

  var $ = require("jquery");
  var Events = require("neue/events");
  var Modal= require("neue/modal");


  var toggleSources = function(container) {
    var $list = container.find("ul, div:first");

    // Hide the fact sources list if present.
    $list.hide();

    // Toggle visibility of fact sources.
    $(".js-toggle-sources").on("click", function() {

      // Toggle visibility of fact sources list.
      $list.slideToggle();

    });
  }


  var $sources = $(".sources") || null;

  // If there's a list of sources output in a modal, activate the toggle.
  Events.subscribe("Modal:opened", function(topic, args) {
    var $sources = $(".modal .sources") || null;
    toggleSources($sources);
  });


  // If there's a list of sources output on the page, activate the toggle.
  if ($sources) {
    toggleSources($sources);
  }

});
