define(function(require) {
  "use strict";

  var $ = require("jquery");
  var $body = $("body");
  var $gallery = $body.find(".gallery.-mosaic");


  // Extract the gallery items to hide.
  var detachTiles = function($gallery) {
    var $tiles = $gallery.find(".campaign");
    
    if ($tiles.length > 5) {
      $tiles = $tiles.slice(5);
      $tiles.detach();

      enableButton($tiles);
    }
  };


  // Reattach the gallery tiles.
  var attachTiles = function($tiles) {
    $gallery.append($tiles);
  };


  // Add and enable the Show More button.
  var enableButton = function($tiles) {
    var $button = $("<button class=\"secondary\">Show More</button>");
    $button.insertAfter($gallery);

    $button.on("click", function() {

      $(this).remove();
      attachTiles($tiles);
    });
  };


  // Show the hidden gallery items.
  var expandGallery = function() {

  };


  if ($body.hasClass("page-taxonomy") && $gallery.length > 0) {
    detachTiles($gallery);
  }

});