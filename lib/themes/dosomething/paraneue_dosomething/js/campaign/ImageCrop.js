define(function(require) {
  "use strict";

  var $ = require("jquery");

  var $originalImage;
  var $cropBox = $("<div>").addClass("crop-box");


  // var mouseUp = function(event) {
  //   event.preventDefault();
  //   console.log("mouseUp");
  // };

  // var mouseMove = function(event) {
  //   event.preventDefault();
  //   console.log("mousemove");
  // };

  var mouseDown = function(event) {
    event.preventDefault();

    var $cropContainer = $(".image-crop-container");
    var xPos = event.pageX;
    var yPos = event.pageY;

    $cropBox.css({
      "top":    yPos - $cropContainer.offset().top,
      "left":   xPos - $cropContainer.offset().left,
      "width":  0,
      "height": 0,
    });
    $cropBox.insertBefore($originalImage);

    // Drag interaction.
    $originalImage.on("mousemove", function(event) {
      var xMove = event.pageX;
      var yMove = event.pageY;
      var width  = Math.abs(xMove - xPos);
      var height = Math.abs(yMove - yPos);
      var xNew;
      var yNew;

      xNew = (xMove < xPos) ? (xPos - width) : xPos;
      yNew = (yMove < yPos) ? (yPos - height) : yPos;

      $cropBox.css({
        "width": width,
        "height": height,
        "top": yNew - $cropContainer.offset().top,
        "left": xNew - $cropContainer.offset().left,
      });
    }).on("mouseup", function() {
      $originalImage.off("mousemove");
      $cropBox.remove();
    });
  };

  var dsCropperInit = function() {
    console.log("Initialize cropper");
    // Get the image that needs to be cropped.
    var $previewImage = $("#modal-report-back").find(".preview");
    if (!$previewImage.length) {
      return;
    }
    $originalImage = $previewImage;
    $originalImage.wrap($("<div class='image-crop-container'></div>")).css("position", "relative");
    // Initialize event listeners on image.
    $originalImage.on("mousedown", mouseDown);
    
  };

  $(document).ready(function() {
    $(".js-image-upload").on("change", function(event) {
      event.preventDefault();
      dsCropperInit();
    });
  });
});

// $(function() {
//     var $container = $('#container');
//     var $selection = $('<div>').addClass('selection-box');

//     $container.on('mousedown', function(e) {
//         var click_y = e.pageY;
//         var click_x = e.pageX;

//         $selection.css({
//           'top':    click_y,
//           'left':   click_x,
//           'width':  0,
//           'height': 0
//         });
//         $selection.appendTo($container);

//         $container.on('mousemove', function(e) {
//             var move_x = e.pageX,
//                 move_y = e.pageY,
//                 width  = Math.abs(move_x - click_x),
//                 height = Math.abs(move_y - click_y),
//                 new_x, new_y;

//             new_x = (move_x < click_x) ? (click_x - width) : click_x;
//             new_y = (move_y < click_y) ? (click_y - height) : click_y;

//             $selection.css({
//               'width': width,
//               'height': height,
//               'top': new_y,
//               'left': new_x
//             });
//         }).on('mouseup', function(e) {
//             $container.off('mousemove');
//             $selection.remove();
//         });
//     });
// });