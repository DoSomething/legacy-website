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
  var finalCrop = {};

  var dragCropBoxInit = function() {
    $cropBox.on("touchstart mousedown", function(event) {
      event.preventDefault();
      // Get coordinates of a touch event.
      if (event.originalEvent.type === "touchstart") {
        var coords = event.originalEvent.targetTouches[0];
        xInitPos = coords.pageX;
        yInitPos = coords.pageY;
      }
      // Get coordinates of mouse event.
      else {
        xInitPos = event.pageX;
        yInitPos = event.pageY;
      }
      offsetLeft = parseInt($cropBox.css("left"), 10);
      offsetTop = parseInt($cropBox.css("top"), 10);
      dragState = true;
    });
  };

  var resizeCropBoxInit = function() {
    $(".resize-handle").on(" touchstart mousedown", function(event) {
      var coords = {};
      // Get the coordinates of a touchevent.
      if (event.originalEvent.type === "touchstart") {
        coords = event.originalEvent.targetTouches[0];
      }
      // Get coordinates of mouse event.
      else {
        coords = {
          pageX: event.pageX,
          pageY: event.pageY,
        };
      }
      initialCropBoxHeight = parseInt($cropBox.css("height"), 10);
      initialCropBoxWidth = parseInt($cropBox.css("width"), 10);
      resizeClickPositionX = coords.pageX;
      resizeClickPositionY = coords.pageY;
      resizeState = true;
      $cropBox.off("touchstart mousedown");
    });
  };

  var dsCropperInit = function(origImage) {
    // Get the image that needs to be cropped.
    var origImageWidth = origImage.width;

    var $previewImage = $("#modal-report-back").find("img");
    if (!$previewImage.length) {
      return;
    }

    $previewImage.wrap($("<div class='image-crop-container'></div>")).css("position", "relative");
    $cropContainer = $(".image-crop-container");
    $cropBox.insertBefore($previewImage);

    dragCropBoxInit();
    resizeCropBoxInit();

    $(document).on("touchmove mousemove", function(event){
      event.preventDefault();
      var coords = {};
      // Get the coordinates of a touchevent.
      if (event.originalEvent.type === "touchmove") {
        coords = event.originalEvent.targetTouches[0];
      }
      // Get coordinates of mouse event.
      else {
        coords = {
          pageX: event.pageX,
          pageY: event.pageY,
        };
      }
      if (dragState) {
        var moveRight = offsetLeft + (coords.pageX - xInitPos);
        var moveDown = offsetTop + (coords.pageY - yInitPos);
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
        var resizeHorizontal = initialCropBoxWidth + (coords.pageX - resizeClickPositionX);
        var resizeVertical = initialCropBoxHeight + (coords.pageX - resizeClickPositionX);
        if ((parseInt($cropBox.css("height"), 10) + parseInt($cropBox.css("top"), 10) + 2) < previewImageHeight && (parseInt($cropBox.css("width"), 10) + parseInt($cropBox.css("left"), 10) + 2) < previewImageWidth && (parseInt($cropBox.css("width"), 10) > 40 || ((coords.pageX - resizeClickPositionX) > 0))) {
          $cropBox.css( "height", resizeVertical);
          $cropBox.css( "width", resizeHorizontal);
        }
        else if((coords.pageX - resizeClickPositionX) < 0 && parseInt($cropBox.css("width"), 10) > 40) {
          $cropBox.css( "height", resizeVertical);
          $cropBox.css( "width", resizeHorizontal);
        }
      }
    });
    $(document).on("touchend mouseup", function(){
      var aspect = $previewImage.width() / origImageWidth;
      console.log(aspect);
      var $cropX = $("#dosomething-reportback-form").find("input[name='crop_x']");
      var $cropY = $("#dosomething-reportback-form").find("input[name='crop_y']");
      var $cropWidth = $("#dosomething-reportback-form").find("input[name='crop_width']");
      var $cropHeight = $("#dosomething-reportback-form").find("input[name='crop_height']");

      if (dragState) {
        $cropBox.off("touchmove mousemove");
        dragState = false;
        finalCrop = {
          top:    Math.round($cropBox.offset().top - $previewImage.offset().top * aspect),
          left:   Math.round($cropBox.offset().left - $previewImage.offset().left * aspect),
          width:  $cropBox.width(),
          height: $cropBox.height(),
        };
        // populate fields.
        $cropX.val(finalCrop.left);
        $cropY.val(finalCrop.top);
        $cropWidth.val(finalCrop.width);
        $cropHeight.val(finalCrop.height);
        console.log(finalCrop);
      }

      if (resizeState) {
        resizeState = false;
        dragCropBoxInit();
        finalCrop = {
          top:    Math.round($cropBox.offset().top - $previewImage.offset().top * aspect),
          left:   Math.round($cropBox.offset().left - $previewImage.offset().left * aspect),
          width:  $cropBox.width(),
          height: $cropBox.height(),
        };
        $cropX.val(finalCrop.left);
        $cropY.val(finalCrop.top);
        $cropWidth.val(finalCrop.width);
        $cropHeight.val(finalCrop.height);
        console.log(finalCrop);
      }
    });
  };

  $(document).ready(function() {
    $(".js-image-upload").on("change", function(event) {
      event.preventDefault();

      var fileReader = new FileReader();

      fileReader.onload = function() {
        var origImage = new Image();
        origImage.src = fileReader.result;
        dsCropperInit(origImage);
      };

      fileReader.readAsDataURL(this.files[0]);
    });
  });
});
