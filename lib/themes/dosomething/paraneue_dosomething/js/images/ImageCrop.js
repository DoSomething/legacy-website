define(function(require) {
  "use strict";

  var $ = require("jquery");

  // Initialize variables.
  var xInitPos;
  var yInitPos;
  var offsetLeft;
  var offsetTop;
  var initialCropBoxHeight;
  var initialCropBoxWidth;
  var previewImageWidth;
  var previewImageHeight;
  var $previewImage;
  var origImage;
  var resizeState          = false;
  var dragState            = false;
  var $cropBox             = $("<div class='cropbox'><div class='resize-handle'></div></div>");
  var resizeClickPositionX = 0;
  var resizeClickPositionY = 0;
  var scale                = 1;
  var degrees              = 0;
  var minThreshold         = 480;

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
        pageX: e.pageX,
        pageY: e.pageY,
      };
    }

    return coords;
  };

  /**
   * Returns a value equal to the minimum allowed crop size scaled down to fit the image.
   */
  var getMinimumSize = function() {
    return minThreshold / scale;
  };

  /**
   * Calculates the initial size of the cropbox. The initial
   * size of the cropbox should be 50% of the size of the image,
   * but have a minimum equal to the minimum allowed crop size.
   *
   * @param {number} width      width of the image.
   * @param {number} height     height of the image.
   * @param {number} minimum    minimum size of the cropbox
   */
  var getCropBoxSize = function(width, height, minimum) {
    var cropBoxSize;
    var orientation = (width > height) ? "landscape" : "portrait";

    // Make the cropbox half the size of the largest dimension.
    // But, make sure the cropbox will fit in the image by
    // checking that it isn't ever greater than smallest dimension.
    if (orientation === "landscape") {
      var halfWidth = width / 2;

      if (halfWidth > height) {
        cropBoxSize = height;
      }
      else {
        cropBoxSize = halfWidth;
      }
    }
    else {
      var halfHeight = height / 2;

      if (halfHeight > width) {
        cropBoxSize = width;
      }
      else {
        cropBoxSize = halfHeight;
      }
    }

    return (cropBoxSize > minimum) ? cropBoxSize : minimum;
  };

  /**
   * This returns the amount to translate an image after it has been rotated so
   * so that it stays center in it's container.
   *
   * @param {number} width      Width of the image.
   * @param {number} height     height of the image.
   * @param {number} degrees    How many degrees the image has been rotated.
   */
  var getTranslateDifference = function(width, height, degrees) {
    var translateDiff = (width / 2) - (height / 2);

    if (degrees === 90 || degrees === 270) {
      return (degrees === 270) ? -(translateDiff) : translateDiff;
    }
    else {
      return 0;
    }
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
      if ($cropBox.length) {
        offsetLeft = parseInt($cropBox.css("left"), 10);
        offsetTop  = parseInt($cropBox.css("top"), 10);
      }

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
      if ($cropBox.length) {
        initialCropBoxHeight = parseInt($cropBox.css("height"), 10);
        initialCropBoxWidth  = parseInt($cropBox.css("width"), 10);
      }

      // Set the position of the mouse.
      resizeClickPositionX = coords.pageX;
      resizeClickPositionY = coords.pageY;

      // Turn on resizing.
      resizeState = true;
    });
  };

  /**
   * Sets up the mouse events on the cropping interface using a give width and height.
   *
   * @param {number} width     Width of the crop area.
   * @param {number} height    Height of the crop area.
   */
  var croppingReset = function (width, height) {
    // Turn off any previously bound events so
    // we can rebind them later using new settings.
    $(document).off("touchmove mousemove");
    $(document).off("touchend mouseup");

    // Bind move events to the document.
    $(document).on("touchmove mousemove", function(event) {
      var coords        = getCoords(event);
      var cropBoxHeight = parseInt($cropBox.css("height"),10);
      var cropBoxWidth  = parseInt($cropBox.css("width"),10);
      var cropBoxTop    = parseInt($cropBox.css("top"), 10);
      var cropBoxLeft   = parseInt($cropBox.css("left"), 10);

      // If dragging, drag the crop box along.
      if (dragState) {
        // Calculate how far to move the box down and right based on the mouse position.
        var moveRight = offsetLeft + (coords.pageX - xInitPos);
        var moveDown  = offsetTop + (coords.pageY - yInitPos);

        // Boundary threshold tests.
        var withinTopBounds  = (height - cropBoxHeight) > moveDown ? true : false;
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
        var resizeVertical   = initialCropBoxHeight + (coords.pageX - resizeClickPositionX);

        // Boundary threshold tests.
        var withinHeightBounds = (cropBoxHeight + cropBoxTop) < height ? true : false;
        var withinWidthBounds  = (cropBoxWidth + cropBoxLeft) < width ? true : false;
        var cropBoxSizeAllowed = (cropBoxWidth > minThreshold) ? true : false;
        var increasingSize     = (coords.pageX - resizeClickPositionX) > 0 ? true : false;
        var decreasingSize     = (coords.pageX - resizeClickPositionX) < 0 ? true : false;

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
    $(document).on("touchend mouseup", function() {
      dragState   = false;
      resizeState = false;
    });
  };

  /**
   * This sets up the cropping interface with a given height and width.
   *
   * @param {number} width     Width of the crop area.
   * @param {number} height    Height of the crop area.
   */
  var setupCrop = function(width, height) {
    if (!$previewImage.length) {
      return;
    }

    var $cropContainer = $previewImage.parent();
    var cropBoxSize = getCropBoxSize(width, height, minThreshold);

    // Expicitly set the dimensions of the crop area.
    $cropContainer.width(width);
    $cropContainer.height(height);

    // Set the initial position of the cropbox in the center of the image
    // and with a minimum value of 480px.
    $cropBox.insertBefore($previewImage).css({
      "left"   : Math.floor((width / 2) - (cropBoxSize / 2)),
      "top"    : Math.floor((height / 2) - (cropBoxSize / 2)),
      "width"  : cropBoxSize,
      "height" : cropBoxSize,
    });

    // Initiate dragging and resizing.
    dragCropBoxInit();
    resizeCropBoxInit();

    croppingReset(width, height);
  };

  /**
   * Rotate an image in a container. When the image rotates, update the size
   * of the container so it fits. Then, translate the image to the center of
   * the new height of the container.
   *
   * @param {jQuery} $image     Image to be rotated.
   * @param {number} degrees    How many degrees to rotate the image.
   */
  var rotateImage = function($image, degrees) {
    var width          = $image.width();
    var height         = $image.height();
    var $cropContainer = $previewImage.parent();

    // Calculate how much to translate the image by.
    var translateDiff = getTranslateDifference(width, height, degrees);

    if (degrees === 90 || degrees === 270) {
      $cropContainer.css({
        height: width,
      });

      // reset cropping events with new dimensions of crop area.
      setupCrop(height,width);
    }
    else {
      $cropContainer.css({
        height: height,
      });

      setupCrop(width,height);
    }

    // Actually do the rotation and translation.
    $image.css({
      "transform" : "rotate("+ degrees + "deg) translate(" + translateDiff + "px, " + translateDiff + "px)",
    });
  };

  /**
   * Populates fields in the main reportback form with values to use for cropping
   * and rotating on the backend.
   *
   * @param {jQuery} form       The form to populate.
   */
  var populateFields = function($form) {
    // Get the hidden form elements.
    var $cropX        = $form.find("input[name='crop_x']");
    var $cropY        = $form.find("input[name='crop_y']");
    var $cropWidth    = $form.find("input[name='crop_width']");
    var $cropHeight   = $form.find("input[name='crop_height']");
    var $cropRotation = $form.find("input[name='crop_rotate']");
    var $captionField = $form.find("input[name='caption']");
    var caption       = $("#dosomething-reportback-image-form").find("#caption").val();


    // Calculate cropping information.
    var cropValues = {
      top     :  Math.round(($cropBox.offset().top - $previewImage.offset().top) * scale),
      left    :  Math.round(($cropBox.offset().left - $previewImage.offset().left) * scale),
      width   :  Math.round($cropBox.outerWidth() * scale),
      height  :  Math.round($cropBox.outerHeight() * scale),
      degrees :  degrees,
    };

    // Populate fields.
    $cropX.val(cropValues.left);
    $cropY.val(cropValues.top);
    $cropWidth.val(cropValues.width);
    $cropHeight.val(cropValues.height);
    $cropRotation.val(cropValues.degrees);
    $captionField.val(caption);
  };

  /**
   * Initiates cropping js.
   *
   * @param {Image} origImage  Image object to crop
   */
  var dsCropperInit = function(image) {
    // Store the image;
    origImage = image;

    // Get the preview image.
    $previewImage = $("#modal--crop").find(".preview");

    if (!$previewImage.length) {
      return;
    }

    // Set global valuea.
    previewImageWidth  = $previewImage.width();
    previewImageHeight = $previewImage.height();
    scale              = origImage.width / $previewImage.width();
    minThreshold       = getMinimumSize();

    // Create the crop area.
    $previewImage.wrap($("<div class='crop-bounding-box'></div>"));

    // Turn on cropping.
    setupCrop(previewImageWidth, previewImageHeight);

    // Rotation
    var $rotateButton = $(".image-editor").find(".-rotate");

    $rotateButton.click(function(e) {
      e.preventDefault();
      degrees = (degrees === 360) ? 90 : degrees + 90;
      rotateImage($previewImage, degrees);
    });
  };

  return {
    dsCropperInit  : dsCropperInit,
    populateFields : populateFields,
  };
});
