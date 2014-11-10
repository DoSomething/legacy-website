define(function(require) {
  "use strict";

  var $ = require("jquery");

  var $cropContainer;
  var resizeState = false;
  var dragState = false;
  var xInitPos;
  var yInitPos;
  var offsetLeft;
  var offsetTop;
  var initialCropBoxHeight;
  var initialCropBoxWidth;
  var previewImageWidth;
  var previewImageHeight;
  var resizeClickPositionX = 0;
  var resizeClickPositionY = 0;
  var $resizeHandle = $("<div class='resize-handle-wrapper'><div class='resize-handle'></div></div>");
  var $cropBox = $("<div>").addClass("crop-box").append($resizeHandle);

  var dragCropBoxInit = function() {
    $cropBox.on("mousedown", function(event) {
      xInitPos = event.pageX;
      yInitPos = event.pageY;
      offsetLeft = parseInt($cropBox.css("left"), 10);
      offsetTop = parseInt($cropBox.css("top"), 10);
      dragState = true;
    });
  };

  var resizeCropBoxInit = function() {
    $(".resize-handle").on("mousedown", function(event) {
      initialCropBoxHeight = parseInt($cropBox.css("height"), 10);
      initialCropBoxWidth = parseInt($cropBox.css("width"), 10);
      resizeClickPositionX = event.pageX;
      resizeClickPositionY = event.pageY;
      resizeState = true;
      $cropBox.off("mousedown");
    });
  };

  var dsCropperInit = function() {
    // Get the image that needs to be cropped.
    var $previewImage = $("#modal-report-back").find(".preview");
    if (!$previewImage.length) {
      return;
    }
    $previewImage.wrap($("<div class='image-crop-container'></div>")).css("position", "relative");
    $cropContainer = $(".image-crop-container");

    $cropBox.css({
      "top":    10,
      "left":   10,
      "width":  200,
      "height": 200,
    });
    $cropBox.insertBefore($previewImage);

    dragCropBoxInit();
    resizeCropBoxInit();

    $(document).on("mousemove", function(e){
      if (dragState) {
        var moveRight = offsetLeft + (e.pageX - xInitPos);
        var moveDown = offsetTop + (e.pageY - yInitPos);
        previewImageWidth = $previewImage.width();
        previewImageHeight = $previewImage.height();
        if (((previewImageHeight - parseInt($cropBox.css("height"),10)) > moveDown) && (moveDown > 0)) {
          $cropBox.css("top", moveDown);
        }
        if (((previewImageWidth - parseInt($cropBox.css("width"),10)) > moveRight) && (moveRight > 0)) {
          $cropBox.css( "left", moveRight);
        }
      }
      if (resizeState) {
        var resizeHorizontal = initialCropBoxWidth + (e.pageX - resizeClickPositionX);
        var resizeVertical = initialCropBoxHeight + (e.pageX - resizeClickPositionX);
        if ((parseInt($cropBox.css("height"), 10) + parseInt($cropBox.css("top"), 10) + 2) < previewImageHeight && (parseInt($cropBox.css("width"), 10) + parseInt($cropBox.css("left"), 10) + 2) < previewImageWidth && (parseInt($cropBox.css("width"), 10) > 40 || ((e.pageX - resizeClickPositionX) > 0))) {
        //if ((parseInt($cropBox.css("height")) + parseInt($cropBox.css("top"))) < previewImageHeight && (parseInt($cropBox.css("width"), 10) + parseInt($cropBox.css("left"), 10)) < previewImageWidth) {
          $cropBox.css( "height", resizeVertical);
          $cropBox.css( "width", resizeHorizontal);
        }
        else if((e.pageX - resizeClickPositionX) < 0 && parseInt($cropBox.css("width"), 10) > 40) {
          $cropBox.css( "height", resizeVertical);
          $cropBox.css( "width", resizeHorizontal);
        }
      }
    });
    $(document).mouseup(function(){
      if (dragState) {
        $cropBox.off("mousemove");
        dragState = false;
      }
      if (resizeState) {
        resizeState = false;
        dragCropBoxInit();
      }
    });
  };

  $(document).ready(function() {
    $(".js-image-upload").on("change", function(event) {
      event.preventDefault();
      dsCropperInit();
    });
  });
});
