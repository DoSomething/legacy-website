define(function(require) {
  "use strict";

  var $ = require("jquery");

  var $originalImage;
  var $cropContainer;
  var $resizeHandle = $("<div class='resize-handle-wrapper'><div class='resize-handle'></div></div>");
  var $cropBox = $("<div>").addClass("crop-box").append($resizeHandle);
  // var xPos;
  // var yPos;

  var mouseDown = function(event) {
    event.preventDefault();

    var xPos = event.pageX;
    var yPos = event.pageY;

    $cropBox.css({
      "top":    yPos - $cropContainer.offset().top,
      "left":   xPos - $cropContainer.offset().left,
      "width":  200,
      "height": 200,
    });
    $cropBox.insertBefore($originalImage);

    $cropBox.on("mousedown", function() {
      $(this).addClass("draggable");
      dragCropBox($(this));
    });

    $(".resize-handle").on("mousedown", function() {
      console.log("clicked on corner");
      $cropBox.off("mousedown");
      $(this).on("mousemove",function() {
        console.log("corner moving");
      //   var xMove = event.pageX;
      //   var yMove = event.pageY;
      //   var width  = Math.abs(xMove - xPos);
      //   var height = Math.abs(yMove - yPos);
      //   var xNew;
      //   var yNew;

      //   xNew = (xMove < xPos) ? (xPos - width) : xPos;
      //   yNew = (yMove < yPos) ? (yPos - height) : yPos;

      //   $cropBox.css({
      //     "width": width,
      //     "height": height,
      //     "top": yNew - $cropContainer.offset().top,
      //     "left": xNew - $cropContainer.offset().left,
      //   });
      }).on("mouseup",function() {
        $(this).off("mousemove");
        // REAPEATED CODE.
        $cropBox.on("mousedown", function() {
          $(this).addClass("draggable");
          dragCropBox($(this));
        });
      });
      // // Drag interaction.
      // $(this).on("mousemove", function(event) {
      //   var xMove = event.pageX;
      //   var yMove = event.pageY;
      //   var width  = Math.abs(xMove - xPos);
      //   var height = Math.abs(yMove - yPos);
      //   var xNew;
      //   var yNew;

      //   xNew = (xMove < xPos) ? (xPos - width) : xPos;
      //   yNew = (yMove < yPos) ? (yPos - height) : yPos;

      //   $cropBox.css({
      //     "width": width,
      //     "height": height,
      //     "top": yNew - $cropContainer.offset().top,
      //     "left": xNew - $cropContainer.offset().left,
      //   });
      // }).on("mouseup", function() {
      //   $(this).off("mousemove");
      //   // $cropBox.remove();
      // });
    });
  };

  var dragCropBox = function($el) {
    $el.on("mousemove", function(event) {
      var thisX = event.pageX - $(this).width() / 2;
      var thisY = event.pageY - $(this).height() / 2;

      $el.offset({
        left: thisX,
        top: thisY,
      });
    })
    .on("mouseup", function() {
      $el.off("mousemove");
    });
  };

  // var resize = function($el,xPos,yPos) {
  //   // Drag interaction.
  //   $el.on("mousemove", function(event) {
  //     var xMove = event.pageX;
  //     var yMove = event.pageY;
  //     var width  = Math.abs(xMove - xPos);
  //     var height = Math.abs(yMove - yPos);
  //     var xNew;
  //     var yNew;

  //     xNew = (xMove < xPos) ? (xPos - width) : xPos;
  //     yNew = (yMove < yPos) ? (yPos - height) : yPos;

  //     $cropBox.css({
  //       "width": width,
  //       "height": height,
  //       "top": yNew - $cropContainer.offset().top,
  //       "left": xNew - $cropContainer.offset().left,
  //     });
  //   }).on("mouseup", function() {
  //     $originalImage.off("mousemove");
  //     $cropBox.remove();
  //   });
  // };

  var dsCropperInit = function() {
    // Get the image that needs to be cropped.
    var $previewImage = $("#modal-report-back").find(".preview");
    if (!$previewImage.length) {
      return;
    }
    $originalImage = $previewImage;
    
    $originalImage.wrap($("<div class='image-crop-container'></div>")).css("position", "relative");
    var $container = $(".image-crop-container");
    $cropContainer = $container;

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

    // // Drag interaction.
    // $el.on("mousemove", function(event) {
    //   var xMove = event.pageX;
    //   var yMove = event.pageY;
    //   var width  = Math.abs(xMove - xPos);
    //   var height = Math.abs(yMove - yPos);
    //   var xNew;
    //   var yNew;

    //   xNew = (xMove < xPos) ? (xPos - width) : xPos;
    //   yNew = (yMove < yPos) ? (yPos - height) : yPos;

    //   $cropBox.css({
    //     "width": width,
    //     "height": height,
    //     "top": yNew - $cropContainer.offset().top,
    //     "left": xNew - $cropContainer.offset().left,
    //   });
    // }).on("mouseup", function() {
    //   $originalImage.off("mousemove");
    //   $cropBox.remove();
    // });
