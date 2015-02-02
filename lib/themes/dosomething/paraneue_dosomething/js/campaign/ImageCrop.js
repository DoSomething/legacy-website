define(function(require) {
  "use strict";

  var $ = require("jquery");

  // Initialize variables.
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
  var $cropBox = $("<div class='cropbox'><div class='resize-handle'><div class='square'></div></div></div>");
  var $previewImage;
  var origImage;
  var scale = 1;
  var degrees = 0;
  var minThreshold = 480;

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
   * This returns the amount to translate an image after it has been rotated so
   * so that it stays center in it's container.
   *
   * @param {jQuery} width      Width of the image.
   * @param {jQuery} height     height of the image.
   * @param {jQuery} degrees    How many degrees the image has been rotated.
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
        offsetTop = parseInt($cropBox.css("top"), 10);
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
        initialCropBoxWidth = parseInt($cropBox.css("width"), 10);
      }

      // Set the position of the mouse.
      resizeClickPositionX = coords.pageX;
      resizeClickPositionY = coords.pageY;

      // Turn on resizing.
      resizeState = true;
    });
  };

  var croppingReset = function (width, height) {
    // Turn off any previously bound events so
    // we can rebind them later using new settings.
    $cropBox.off("touchmove mousemove");
    $cropBox.off("touchend mouseup");

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
    });
  };

  /**
   * This sets up the cropping interface with a given height and width.
   *
   * @param {jQuery} $image     Image to be rotated.
   * @param {jQuery} $container Container the image will be rotated in.
   * @param {jQuery} degrees    How many degrees to rotate the image.
   */
  var setupCrop = function(width, height) {
    if (!$previewImage.length) {
      return;
    }

    var $cropContainer = $previewImage.parent();

    // Expicitly set the dimensions of the crop area.
    $cropContainer.width(width);
    $cropContainer.height(height);

    $cropBox.insertBefore($previewImage).css({
      // Center the crop box on the image initially.
      "left"   : Math.floor((width / 2) - (minThreshold / 2)),
      "top"    : Math.floor((height / 2) - (minThreshold / 2)),
      "width"  : minThreshold,
      "height" : minThreshold,
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
   * @param {jQuery} $container Container the image will be rotated in.
   * @param {jQuery} degrees    How many degrees to rotate the image.
   */
  var rotateImage = function($image, degrees) {
    var width = $image.width();
    var height = $image.height();
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
   * @param {jQuery} cropValues Object containing x, y, width and height of the crop.
   * @param {jQuery} degrees    (optional) How many degrees to rotate the image.
   */
  var populateFields = function($form) {
    // Get the hidden form elements.
    var $cropX = $form.find("input[name='crop_x']");
    var $cropY = $form.find("input[name='crop_y']");
    var $cropWidth = $form.find("input[name='crop_width']");
    var $cropHeight = $form.find("input[name='crop_height']");
    var $cropRotation = $form.find("input[name='crop_rotate']");
    var $captionField = $form.find("input[name='caption']");
    var caption = $("#dosomething-reportback-image-form").find("#caption").val();


    // Calculate cropping information.
    var cropValues = {
      top:    Math.round(($cropBox.offset().top - $previewImage.offset().top) * scale),
      left:   Math.round(($cropBox.offset().left - $previewImage.offset().left) * scale),
      width:  Math.round($cropBox.outerWidth() * scale),
      height: Math.round($cropBox.outerHeight() * scale),
      degrees: degrees,
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
   * Preview image.
   */
  var cropPreview = function() {
    var firstSubmission = ($(".reportback__submission-latest").length) ? true : false;

    var $cropPreview = $("<figure class='reportback__submission-cropped'></figure>");
    $(".reportback__submissions").prepend($cropPreview);
    $cropPreview.append($previewImage);

    var x = $("#dosomething-reportback-form").find("input[name='crop_x']").val();
    var y = $("#dosomething-reportback-form").find("input[name='crop_y']").val();
    var w = $("#dosomething-reportback-form").find("input[name='crop_width']").val();
    var h = $("#dosomething-reportback-form").find("input[name='crop_height']").val();

    var translateDiff = getTranslateDifference(previewImageWidth, previewImageHeight, degrees);
    var cropPreviewSize = $cropPreview.width();

    $cropPreview.css("height", cropPreviewSize);

    $cropPreview.find(".preview").css({
      "left": -(x / (w / cropPreviewSize)) + "px",
      "top": -(y / (h / cropPreviewSize)) + "px",
      "width": origImage.width / (w / cropPreviewSize),
      "height": origImage.height / (h / cropPreviewSize),
      "transform" : "rotate("+ degrees + "deg) translate(" + translateDiff + "px, " + translateDiff + "px)",
    });

    if (!firstSubmission) {
      $(".gigantor").hide();
    }
    else {
      var $lastestSubmission = $(".reportback__submission-latest img");
      var submissionCount = $(".reportback__submissions-list li").length;

      if (submissionCount === 4) {
        $(".reportback__submissions-list li:last-child").remove();
      }
      $lastestSubmission.appendTo($(".reportback__submissions-list")).wrap("<li></li>");
    }

  };

  /**
   * Initiates cropping js.
   *
   * @param {jQuery} origImage  Image object to crop
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
    previewImageWidth = $previewImage.width();
    previewImageHeight = $previewImage.height();
    scale = origImage.width / $previewImage.width();
    minThreshold = getMinimumSize();

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
    cropPreview    : cropPreview,
  };
});
