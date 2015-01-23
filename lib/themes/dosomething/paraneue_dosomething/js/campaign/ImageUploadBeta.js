// @TODO - Move to new folder.

define(function(require) {
  "use strict";

  var $         = require("jquery");
  var Modal     = require("neue/modal");
  var ImageCrop = require("campaign/ImageCrop");

  /**
   * Handles the modal interface for image upload buttons.
   * Requires a modal to be on the page with an id '#modal--crop'
   * The modal should have a form '#dosomething-reportback-image-form'
   * and a div to place the image preview '.image-wrapper'.
   *
   * @param {jQuery} $button  The file upload button
   */
  var ImageUploadBeta = function($button) {
    this.$uploadButton   = $button;
    this.$cropModal      = $("#modal--crop");
    this.$reportbackForm = $("#dosomething-reportback-form");
    this.$imageForm      = this.$cropModal.find("#dosomething-reportback-image-form");
    this.$imagePreview   = this.$cropModal.find(".image-preview");
    this.imageValues     = {};
    this.cropEnabled     = (typeof Drupal.settings.dsReportback.cropEnabled !== "undefined") ? Drupal.settings.dsReportback.cropEnabled : false;

    this.init();
  };

  /**
   * Initalizes event listeners
   *
   */
  ImageUploadBeta.prototype.init = function () {
    var _this = this;

    this.$uploadButton.on("change", function(event) {
      event.preventDefault();

      var files = !!this.files ? this.files : [];

      // If no file selected/no FileReader support, we're all done
      if (!files.length || !window.FileReader) {
        return;
      }

      if (/^image/.test( files[0].type)) {
        var reader = new FileReader();
        reader.readAsDataURL(files[0]);

        reader.onloadend = function() {
          var result = this.result;

          var isValid = _this.validImage(result);
          var $errorMsg = _this.$uploadButton.parent().siblings(".error");

          if(isValid) {
            // Remove any previously added error message.
            if ($errorMsg.length) {
              $errorMsg.remove();
            }

            // Open the modal.
            Modal.open(_this.$cropModal,
              {
                animated: false,
              }
            );

            // Add the preview image to the modal
            _this.previewImage(result, _this.$imagePreview);

            // Make sure submit button is enabled when the modal opens.
            var $submitButton = _this.$cropModal.find(".-done");

            if ($submitButton.prop("disabled")) {
              $submitButton.prop("disabled", false);
            }
          }
          // Show user an error if they upload an image that is too small.
          else {
            if (!$errorMsg.length) {
              var $error = $("<div class='messages error'>Please upload a larger photo. Min. size is 480px by 480px.</div>");
              $error.insertAfter(_this.$uploadButton.parent());
            }
          }
        };
      }
    });

    /**
     * On submission of the form, close the modal.
     * This publishes a close event that other scripts can subscribe to
     * to use the information collected in the modal.
     */
    this.$imageForm.submit(function(event) {
      event.preventDefault();
      Modal.close(false);
    });
  };

  /**
   *
   */
  ImageUploadBeta.prototype.validImage = function(fileReaderResult) {
    var image = new Image();
    image.src = fileReaderResult;

    return (image.width > 480 && image.height > 480);
  };

  /**
   * Resizes an image so that the dimensions of the scaled image.
   * are never greater than it's container's maximum width (height of the container is variable).
   *
   * @param {jQuery} $image           The image to resize.
   * @param {jQuery} $container       The container to resize within.
   */
  ImageUploadBeta.prototype.resizeImage = function($image, $container) {
    var imageWidth  = $image.width();
    var imageHeight = $image.height();
    var containerMaxWidth = $container.width();
    var orientation = (imageWidth > imageHeight) ? "landscape" : "portrait";

    if ((imageWidth > containerMaxWidth) || (imageHeight > containerMaxWidth)) {
      if (orientation === "portrait") {
        $image.height(containerMaxWidth);
      }
      else {
        $image.width(containerMaxWidth);
      }
    }
    else {
      return;
    }
  };

  /**
   * Creates a preview image of an uploaded file and adds it to a container.
   * If cropping is enabled, it initiates the cropping script.
   *
   * @param {jQuery} fileReaderResult   The result property of a file reader object.
   * @param {jQuery} $imageContainer    The DOM element to put the preview image in.
   */
  ImageUploadBeta.prototype.previewImage = function(fileReaderResult, $imageContainer) {
    var _this = this;

    var $preview = $("<img class='preview' src=''>");
    $imageContainer.html($preview);

    $preview.attr("src", fileReaderResult).load(function() {
      var $this = $(this);

      _this.resizeImage($this, $imageContainer);

      // Initiate cropping if it is enabled.
      if (_this.cropEnabled) {
        _this.cropInit(fileReaderResult);
      }
    });
  };

  /**
   * Initiates cropping on a file.
   *
   * @param {jQuery} fileReaderResult  The result property of a file reader object.
   */
  ImageUploadBeta.prototype.cropInit = function(fileReaderResult) {
    var originalImage = new Image();
    originalImage.src = fileReaderResult;

    ImageCrop.dsCropperInit(originalImage);
  };

  /**
   * @TODO - revisit this. Is this nessecary?
   * Returns the value of the caption field.
   * Should only be used after the form has been submitted and the modal has closed.
   *
   * @return {jQuery} An object of form values.
   */
  ImageUploadBeta.prototype.getImageCaption = function() {
    return this.$imageForm.find("#caption").val();
  };

  return ImageUploadBeta;

});
