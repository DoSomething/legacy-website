define(function(require) {
  "use strict";

  var $ = require("jquery");
  // Initialize variables.
  var resizeState = false;
  var dragState = false;
  var $cropContainer;
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
  var $resizeHandle = $("<div class='resize-handle-wrapper'><div class='resize-handle'><div class='resize-triangle'></div></div></div>");
  var $cropBox = $("<div>").addClass("crop-box").append($resizeHandle);
  var finalCrop = {};

  /**
   * Returns the coordinates of a touch or mouse event.
   */
  var getCoords = function(e) {
    var coords = {};
    var eventType = e.originalEvent.type;

    // Get the coordinates of a touchevent.
    if (eventType === "touchstart" || eventType === "touchmove" || eventType === "touchend") {
      coords = e.originalEvent.targetTouches[0];
    }
    // Get coordinates of mouse event.
    else {
      coords = {
        pageX: event.pageX,
        pageY: event.pageY,
      };
    }

    return coords;
  };

  /**
   * Turns on the ability to drag the crop box.
   */
  var dragCropBoxInit = function() {
    // Bind touch and mouse events.
    $cropBox.on("touchstart mousedown", function(event) {
      event.preventDefault();
      var coords = getCoords(event);

      // Set the initial position of the mouse.
      xInitPos = coords.pageX;
      yInitPos = coords.pageY;

      // Sets the initial positioning of the crop box.
      offsetLeft = parseInt($cropBox.css("left"), 10);
      offsetTop = parseInt($cropBox.css("top"), 10);

      // Turns on dragging.
      dragState = true;
    });
  };

  /**
   * Turns on the ability to resize the crop box.
   */
  var resizeCropBoxInit = function() {
    $(".resize-handle").on("touchstart mousedown", function(event) {
      event.preventDefault();

      // Grab the postioning of the event.
      var coords = getCoords(event);

      // Set the initial size of the crop box.
      initialCropBoxHeight = parseInt($cropBox.css("height"), 10);
      initialCropBoxWidth = parseInt($cropBox.css("width"), 10);

      // Set the position of the mouse.
      resizeClickPositionX = coords.pageX;
      resizeClickPositionY = coords.pageY;

      // Turn on resizing.
      resizeState = true;
    });
  };

  /**
   * Initiates cropping js.
   * @params - the original image to crop.
   */
  var dsCropperInit = function(origImage) {
    // Get the original width of the image.
    var origImageWidth = origImage.width;

    // Get the preview image.
    var $previewImage = $("#modal-report-back").find(".preview");

    // Make sure there is a preview image on the page before proceeding.
    if (!$previewImage.length) {
      return;
    }

    // Wrap the image in a container to use as a boundary.
    $previewImage.wrap($("<div class='image-crop-container'></div>"));
    $cropContainer = $(".image-crop-container");

    // Add the cropbox to the page.
    $cropBox.insertBefore($previewImage);

    // Initiate dragging and resizing.
    dragCropBoxInit();
    resizeCropBoxInit();

    // Bind move events to the document.
    $cropContainer.on("touchmove mousemove", function(event) {
      event.preventDefault();
      var coords = getCoords(event);

      var cropBoxHeight = parseInt($cropBox.css("height"),10);
      var cropBoxWidth = parseInt($cropBox.css("width"),10);
      var cropBoxTop = parseInt($cropBox.css("top"), 10);
      var cropBoxLeft = parseInt($cropBox.css("left"), 10);

      // If dragging, drag the crop box along.
      if (dragState) {
        // Calculate how far to move the box down and right based on the mouse position.
        var moveRight = offsetLeft + (coords.pageX - xInitPos);
        var moveDown = offsetTop + (coords.pageY - yInitPos);

        // Set the height and width of the preview image to use as a boundary.
        previewImageWidth = $previewImage.width();
        previewImageHeight = $previewImage.height();

        // Boundary threshold tests.
        var withinTopBounds = (previewImageHeight - cropBoxHeight) > moveDown ? true : false;
        var withinLeftBounds = (previewImageWidth - cropBoxWidth) > moveRight ? true : false;

        // Make sure we are still within the bounds of the image and then actully move the box.
        if (withinTopBounds && (moveDown > 0)) {
          $cropBox.css("top", moveDown);
        }
        if (withinLeftBounds && (moveRight > 0)) {
          $cropBox.css( "left", moveRight);
        }
      }
      // If resizing, resize the crop box.
      if (resizeState) {
        dragState = false;
        // Calculate how much to resize the cropbox.
        var resizeHorizontal = initialCropBoxWidth + (coords.pageX - resizeClickPositionX);
        var resizeVertical = initialCropBoxHeight + (coords.pageX - resizeClickPositionX);

        // Boundary threshold tests.
        var minThreshold = 40;
        var withinHeightBounds = (cropBoxHeight + cropBoxTop) < previewImageHeight ? true : false;
        var withinWidthBounds = (cropBoxWidth + cropBoxLeft) < previewImageWidth ? true : false;
        var cropBoxSizeAllowed = (cropBoxWidth > minThreshold) ? true : false;
        var increasingSize = (coords.pageX - resizeClickPositionX) > 0 ? true : false;
        var decreasingSize = (coords.pageX - resizeClickPositionX) < 0 ? true : false;

        // Make sure we are still in the boundaries of the image, and then resize the box.
        if (withinHeightBounds && withinWidthBounds && (cropBoxSizeAllowed || increasingSize)) {
          $cropBox.css( "height", resizeVertical);
          $cropBox.css( "width", resizeHorizontal);
        }
        else if (decreasingSize && cropBoxSizeAllowed) {
          $cropBox.css( "height", resizeVertical);
          $cropBox.css( "width", resizeHorizontal);
        }
      }
    });

    /**
     *  When the user stops moving the mouse or touching the screen, turn of the drag and resizing events.
     *  Get the final position and size of the crop and populate hidden form elements with them.
     */
    $cropContainer.on("touchend mouseup", function(){
      // Calulate how much the image has been resized.
      var resizeAmount = origImageWidth / $previewImage.width();
      // Get the hidden form elements.
      var $cropX = $("#dosomething-reportback-form").find("input[name='crop_x']");
      var $cropY = $("#dosomething-reportback-form").find("input[name='crop_y']");
      var $cropWidth = $("#dosomething-reportback-form").find("input[name='crop_width']");
      var $cropHeight = $("#dosomething-reportback-form").find("input[name='crop_height']");
      dragState = false;
      resizeState = false;
      // Calculate cropping information, taking into account how much the image has been scaled.
      finalCrop = {
        top:    Math.round($cropBox.offset().top - $previewImage.offset().top) * resizeAmount,
        left:   Math.round($cropBox.offset().left - $previewImage.offset().left) * resizeAmount,
        width:  $cropBox.width() * resizeAmount,
        height: $cropBox.height() * resizeAmount,
      };
      // populate fields.
      $cropX.val(finalCrop.left);
      $cropY.val(finalCrop.top);
      $cropWidth.val(finalCrop.width);
      $cropHeight.val(finalCrop.height);
    });
  };

  $(document).ready(function() {
    // Make sure cropping is enabled.
    var cropEnabled = Drupal.settings.dsReportback.cropEnabled;
    if (cropEnabled) {
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
    }
  });
});
