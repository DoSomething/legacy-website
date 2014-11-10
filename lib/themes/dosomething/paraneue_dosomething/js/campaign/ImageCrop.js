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
  var resizeClickPositionX = 0;
  var resizeClickPositionY = 0;
  var $resizeHandle = $("<div class='resize-handle-wrapper'><div class='resize-handle'></div></div>");
  var $cropBox = $("<div>").addClass("crop-box").append($resizeHandle);

  var dragCropBoxInit = function() {
    $cropBox.on("mousedown", function(event) {
      xInitPos = event.pageX;
      yInitPos = event.pageY;
      offsetLeft = parseFloat($cropBox.css("left"), 10);
      offsetTop = parseFloat($cropBox.css("top"), 10);
      dragState = true;
    });
  };

  var resizeCropBoxInit = function() {
    $(".resize-handle").on("mousedown", function(event) {
      initialCropBoxHeight = parseFloat($cropBox.css("height"), 10);
      initialCropBoxWidth = parseFloat($cropBox.css("width"), 10);
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
    // // Allow the user to drag the crop box around/.
    // $cropBox.on("mousedown", function(event) {
    //   xInitPos = event.pageX;
    //   yInitPos = event.pageY;
    //   offsetLeft = parseFloat($cropBox.css("left"), 10);
    //   offsetTop = parseFloat($cropBox.css("top"), 10);
    //   dragState = true;
    // });

    // $(".resize-handle").on("mousedown", function(event) {
    //   initialCropBoxHeight = parseFloat($cropBox.css("height"), 10);
    //   initialCropBoxWidth = parseFloat($cropBox.css("width"), 10);
    //   resizeClickPositionX = event.pageX;
    //   resizeClickPositionY = event.pageY;
    //   resizeState = true;
    //   $cropBox.off("mousedown");
    // });

    $(document).on("mousemove", function(e){
      if (dragState) {
        var moveRight = offsetLeft + (e.pageX - xInitPos); // calculates a new horiontal position
        var moveDown = offsetTop + (e.pageY - yInitPos); // calculates a new vertical position
        
        $cropBox.css("top", moveDown ); // move the box vertically
        $cropBox.css( "left", moveRight ); // move the box horizontally      
      }

      if (resizeState) {
        var resizeHorizontal = initialCropBoxWidth + (e.pageX - resizeClickPositionX); // calculate new width
        var resizeVertical = initialCropBoxHeight + (e.pageX - resizeClickPositionX); // calculate new height
        
        $cropBox.css( "height", resizeVertical);
        $cropBox.css( "width", resizeHorizontal);
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
