// Move to new folder.

define(function(require) {
  "use strict";

  var $ = require("jquery");
  // Initialize variables.
  var resizeState = false;
  var dragState = false;
  // var $cropContainer;
  var xInitPos;
  var yInitPos;
  var offsetLeft;
  var offsetTop;
  var initialCropBoxHeight;
  var initialCropBoxWidth;
  var previewImageWidth;
  var previewImageHeight;
  var minThreshold;
  var resizeClickPositionX = 0;
  var resizeClickPositionY = 0;
  var $cropContainer;
  var $cropBox = $("<div class='cropbox'><div class='resize-handle'><div class='square'></div></div></div>");
  var origImage;
  var origImageWidth;
  var $previewImage;
  var $form;

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
  * Destroys the cropbox. @TODO - REMOVE THIS.
  * Allows for resetting the cropbox position after the image has changed.
  */
  var dsCropperDestroy = function() {
    if ($cropBox.length) {
      $cropBox.remove();
    }
  };

  var croppingReset = function (width, height) {
    // Calculate the initial dimensions of the cropbox. Add the cropbox to the page.
    minThreshold = height / 2;
    // Bind move events to the document.
    $cropBox.on("touchmove mousemove", function(event) {
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

        // Boundary threshold tests.
        var withinTopBounds = (height - cropBoxHeight) > moveDown ? true : false;
        var withinLeftBounds = (width - cropBoxWidth) > moveRight ? true : false;

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
        var withinHeightBounds = (cropBoxHeight + cropBoxTop) < height ? true : false;
        var withinWidthBounds = (cropBoxWidth + cropBoxLeft) < width ? true : false;
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
    $cropBox.on("touchend mouseup", function() {
      dragState = false;
      resizeState = false;

      // Calulate how much the image has been resized.
      var resizeAmount = origImageWidth / $previewImage.width();
      // Calculate cropping information, taking into account how much the image has been scaled.
      var finalCrop = {
        top:    Math.round($cropBox.offset().top - $previewImage.offset().top) * resizeAmount,
        left:   Math.round($cropBox.offset().left - $previewImage.offset().left) * resizeAmount,
        width:  $cropBox.width() * resizeAmount,
        height: $cropBox.height() * resizeAmount,
      };

      // populateFields(finalCrop);
    });
  };

  var setCrop = function(width, height) {
    $cropContainer = $(".crop-bounding-box");

    $cropBox.remove();
    $cropBox.off("touchmove mousemove");
    $cropBox.off("touchend mouseup");

    $cropContainer.width(width);
    $cropContainer.height(height);

    $cropBox.width(height / 2);
    $cropBox.height(height / 2);
    $cropBox.insertBefore($(".preview")).css({
      left: 0,
      top: 0,
    });

    // Initiate dragging and resizing.
    dragCropBoxInit();
    resizeCropBoxInit();

    console.log("width: " + width);
    console.log("height: " + height);

    croppingReset(width,height);
  };

  /**
   * Rotate an image in a container. When the image rotates change the size of the container so it fits.
   * Translate the image to the center of the new height of the container.
   */
  var rotateImage = function($image, $container, degrees) {
    var width = $image.width();
    var height = $image.height();
    var translateDiff;

    // Calculate how much to translate the image by.
    if (degrees === 90) {
      translateDiff = (width / 2) - (height / 2);

      $container.css({
        height: width,
      });

      setCrop(height,width);
    }
    else if (degrees === 270) {
      translateDiff = -((width / 2) - (height / 2));

      $container.css({
        height: width,
      });

      setCrop(height,width);
    }
    else {
      translateDiff = 0;

      $(".crop-bounding-box").css({
        height: height,
        width : width,
      });

      $container.css({
        height: height,
      });

      setCrop(width,height);
    }

    // Do the rotation and translation.
    $image.css({
      "-webkit-transform" : "rotate("+ degrees + "deg) translate(" + translateDiff + "px, " + translateDiff + "px)",
      "-moz-transform"    : "rotate("+ degrees + "deg) translate(" + translateDiff + "px, " + translateDiff + "px)",
      "-ms-transform"     : "rotate("+ degrees + "deg) translate(" + translateDiff + "px, " + translateDiff + "px)",
      "transform"         : "rotate("+ degrees + "deg) translate(" + translateDiff + "px, " + translateDiff + "px)",
    });
  };

  var populateFields = function(cropValues) {
    // Get the hidden form elements.
    var $cropX = $form.find("input[name='crop_x']");
    var $cropY = $form.find("input[name='crop_y']");
    var $cropWidth = $form.find("input[name='crop_width']");
    var $cropHeight = $form.find("input[name='crop_height']");

    // populate fields.
    $cropX.val(cropValues.left);
    $cropY.val(cropValues.top);
    $cropWidth.val(cropValues.width);
    $cropHeight.val(cropValues.height);
  };

  /**
   * Initiates cropping js.
   *
   * @param {jQuery} origImage  Image object to crop
   */
  var dsCropperInit = function(image, $form) {
    origImage = image;
    $form = $form;
    // Get the original width of the image.
    origImageWidth = image.width;

    // Get the preview image.
    $previewImage = $("#modal--crop").find(".preview");
    var $previewImageContainer = $("#modal--crop").find(".image-preview");

    // Make sure there is a preview image on the page before proceeding.
    if (!$previewImage.length) {
      return;
    }


    // @TODO - Move to function that sets the cropbox and cropbounding box whenever called.
    // Wrap the image in a container and get it's dimensions to use as a boundary.
    $previewImage.wrap($("<div class='crop-bounding-box'></div>"));
    previewImageWidth = $previewImage.width();
    previewImageHeight = $previewImage.height();

    setCrop(previewImageWidth, previewImageHeight);

    // // Bind move events to the document.
    // $cropBox.on("touchmove mousemove", function(event) {
    //   event.preventDefault();
    //   var coords = getCoords(event);

    //   var cropBoxHeight = parseInt($cropBox.css("height"),10);
    //   var cropBoxWidth = parseInt($cropBox.css("width"),10);
    //   var cropBoxTop = parseInt($cropBox.css("top"), 10);
    //   var cropBoxLeft = parseInt($cropBox.css("left"), 10);

    //   // If dragging, drag the crop box along.
    //   if (dragState) {
    //     // Calculate how far to move the box down and right based on the mouse position.
    //     var moveRight = offsetLeft + (coords.pageX - xInitPos);
    //     var moveDown = offsetTop + (coords.pageY - yInitPos);

    //     // Boundary threshold tests.
    //     var withinTopBounds = (previewImageHeight - cropBoxHeight) > moveDown ? true : false;
    //     var withinLeftBounds = (previewImageWidth - cropBoxWidth) > moveRight ? true : false;

    //     // Make sure we are still within the bounds of the image and then actully move the box.
    //     if (withinTopBounds && (moveDown > 0)) {
    //       $cropBox.css("top", moveDown);
    //     }
    //     if (withinLeftBounds && (moveRight > 0)) {
    //       $cropBox.css( "left", moveRight);
    //     }
    //   }
    //   // If resizing, resize the crop box.
    //   if (resizeState) {
    //     dragState = false;
    //     // Calculate how much to resize the cropbox.
    //     var resizeHorizontal = initialCropBoxWidth + (coords.pageX - resizeClickPositionX);
    //     var resizeVertical = initialCropBoxHeight + (coords.pageX - resizeClickPositionX);

    //     // Boundary threshold tests.
    //     var withinHeightBounds = (cropBoxHeight + cropBoxTop) < previewImageHeight ? true : false;
    //     var withinWidthBounds = (cropBoxWidth + cropBoxLeft) < previewImageWidth ? true : false;
    //     var cropBoxSizeAllowed = (cropBoxWidth > minThreshold) ? true : false;
    //     var increasingSize = (coords.pageX - resizeClickPositionX) > 0 ? true : false;
    //     var decreasingSize = (coords.pageX - resizeClickPositionX) < 0 ? true : false;

    //     // Make sure we are still in the boundaries of the image, and then resize the box.
    //     if (withinHeightBounds && withinWidthBounds && (cropBoxSizeAllowed || increasingSize)) {
    //       $cropBox.css( "height", resizeVertical);
    //       $cropBox.css( "width", resizeHorizontal);
    //     }
    //     else if (decreasingSize && cropBoxSizeAllowed) {
    //       $cropBox.css( "height", resizeVertical);
    //       $cropBox.css( "width", resizeHorizontal);
    //     }
    //   }
    // });

    // /**
    //  *  When the user stops moving the mouse or touching the screen, turn of the drag and resizing events.
    //  *  Get the final position and size of the crop and populate hidden form elements with them.
    //  */
    // $cropBox.on("touchend mouseup", function() {
    //   dragState = false;
    //   resizeState = false;

    //   // Calulate how much the image has been resized.
    //   var resizeAmount = origImageWidth / $previewImage.width();
    //   // Calculate cropping information, taking into account how much the image has been scaled.
    //   var finalCrop = {
    //     top:    Math.round($cropBox.offset().top - $previewImage.offset().top) * resizeAmount,
    //     left:   Math.round($cropBox.offset().left - $previewImage.offset().left) * resizeAmount,
    //     width:  $cropBox.width() * resizeAmount,
    //     height: $cropBox.height() * resizeAmount,
    //   };

    //   populateFields(finalCrop);
    // });

    // Rotation
    var $rotateButton = $(".image-editor").find(".-rotate");
    var degrees = 0;
    var $cropRotation = $form.find("input[name='crop_rotate']");

    $rotateButton.click(function(e) {
      e.preventDefault();
      degrees = (degrees === 360) ? 90 : degrees + 90;
      $cropRotation.val(degrees);
      rotateImage($previewImage, $previewImageContainer, degrees);
    });
  };

  return {
    dsCropperInit: dsCropperInit,
    dsCropperDestroy: dsCropperDestroy,
  };
});
