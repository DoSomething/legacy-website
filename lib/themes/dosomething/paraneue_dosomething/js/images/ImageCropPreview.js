  /**
   * Creates a front-end preview of a reportback image given crop values.
   */
define(function(require) {
  "use strict";

  var $                      = require("jquery");
  var $cropPreview           = $("<figure class='reportback__submission-cropped'></figure>");
  var $reportbackSubmissions = $(".reportback__submissions");
  var $reportbackUploadBtn   = $(".gigantor");

  /**
   * Tests if this is the first reportback submission or not.
   */
  var firstSubmission = function() {
    return ($(".reportback__submission-latest").length) ? false : true;
  };

  /**
   * This returns the amount to translate an image after it has been rotated so
   * so that it stays center in it's container.
   * @TODO - this is a duplicate of a function used in ImageCrop.js. This needs to
   * be made more DRY. Create a separate "ImageCropUtilities.js" file that can
   * hold functions that pertain to calculations needed for cropping and rotation.
   * This should also help clean up the cropping script for easier reading.
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
   * This function actually creates the crop preview image by calculating where to
   * position the image within a square container so it looks like the crop the user chose.
   * The positioning is based on crop and rotation that the user chose.
   *
   * @param {number} imageWidth      Width of the original image (not scaled).
   * @param {number} imageHeight     height of the original image (not scaled).
   * @param {object} cropValues      An object containing x, y, width, and height values describing the crop.
   */
  var getCropPreviewValues = function(imageWidth, imageHeight, cropValues) {
    var cropPreviewSize = $cropPreview.width();
    var horizontalScale = cropValues.width / cropPreviewSize;
    var verticalScale   = cropValues.height / cropPreviewSize;
    var newWidth        = imageWidth / horizontalScale;
    var newHeight       = imageHeight / verticalScale;
    var translateDiff   = getTranslateDifference(newWidth, newHeight, cropValues.degrees);

    return {
      "left"      : -(cropValues.x / horizontalScale) + "px",
      "top"       : -(cropValues.y / verticalScale) + "px",
      "width"     : newWidth,
      "height"    : newHeight,
      "transform" : "rotate("+ cropValues.degrees + "deg) translate(" + translateDiff + "px, " + translateDiff + "px)",
    };
  };

  /**
   * This function handles DOM elements that are already on the page to make room for the crop preview image.
   */
  var setUpCropPreview = function() {
    // If this is the first reportback submission, we need to hide the original button.
    if (firstSubmission()) {
      $reportbackUploadBtn.hide();
    }
    // Otherwise, move the current reportback into the thumbnail list of reportbacks
    else {
      var $lastestSubmission = $reportbackSubmissions.find(".reportback__submission-latest img");
      var $reportbackSubmissionsList = $reportbackSubmissions.find(".reportback__submissions-list");

      // Check if there is a list of reportbacks already on the page,
      // if not, create on to put the old reportback in.
      if (!$reportbackSubmissionsList.length) {
        $reportbackSubmissionsList = $("<ul class='reportback__submissions-list gallery'></ul>");
        $reportbackSubmissions.append($reportbackSubmissionsList);
      }

      // If there are already 4 reportback submissions,
      // then remove the last one and put the current on it it's place.
      var submissionCount = $reportbackSubmissionsList.find("li").length;
      if (submissionCount === 4) {
        $(".reportback__submissions-list li:last-child").remove();
      }

      $lastestSubmission.appendTo($reportbackSubmissionsList).wrap("<li></li>");
    }
  };

  // Create a preview of the crop.
  var cropPreview = function(image, cropValues) {
    // Save the original image dimensions.
    var imageHeight   = image.height;
    var imageWidth    = image.width;
    var $previewImage = "<img src='" + image.src + "'/>";

    // Add crop preview to the page.
    setUpCropPreview();
    $cropPreview.prependTo($reportbackSubmissions).append($previewImage);

    // Set heigth of the preview containter to be the sames as the computed width.
    // This is so the preview container is always a square.
    $cropPreview.css("height", $cropPreview.width());

    // Create the crop preview.
    var cropPreviewValues = getCropPreviewValues(imageWidth, imageHeight, cropValues);
    $cropPreview.find("img").css(cropPreviewValues);
  };

  return {
    cropPreview : cropPreview,
  };
});
