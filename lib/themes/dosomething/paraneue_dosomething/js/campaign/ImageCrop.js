define(function(require) {
  "use strict";

  var $ = require("jquery");

  var $originalImage;

  var mouseDown = function(event) {
    event.preventDefault();
    console.log("mousedown");
  };

  var mouseUp = function(event) {
    event.preventDefault();
    console.log("mouseUp");
  };

  var mouseMove = function(event) {
    event.preventDefault();
    console.log("mousemove");
  };


  var dsCropperInit = function() {
    console.log("Initialize cropper");
    // Get the image that needs to be cropped.
    var $previewImage = $("#modal-report-back").find(".preview");
    if (!$previewImage.length) {
      return;
    }
    $originalImage = $previewImage;
    // Initialize event listeners on image.
    $originalImage.on("mousedown", mouseDown);
    $originalImage.on("mouseup", mouseUp);
    $originalImage.on("mousemove", mouseMove);
  };

  $(document).ready(function() {
    $(".js-image-upload").on("change", function(event) {
      event.preventDefault();
      dsCropperInit();
    });
  });
});
