define(function(require) {
  "use strict";

  var $                = require("jquery");
  var Events           = require("neue/events");
  var ImageCrop        = require("images/ImageCrop");
  var ImageCropPreview = require("../images/ImageCropPreview");
  var Modal            = require("neue/modal");


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

          var image = new Image();
          image.src = result;

          image.onload = function() {
            var image = this;
            var isValid = _this.validImage(this);
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
              _this.previewImage(image, _this.$imagePreview);

              // Make sure submit button is enabled when the modal opens.
              _this.enableSubmit();

              // When the user is done with the modal, send crop values to the form.
              _this.$imageForm.submit(function(event) {
                event.preventDefault();
                ImageCrop.populateFields(_this.$reportbackForm);
                ImageCropPreview.cropPreview(image,_this.getCropValues());
                Modal.close();
              });
            }
            // Show user an error if they upload an image that is too small.
            else {
              if (!$errorMsg.length) {
                var $error = $("<div class='messages error'>Please upload a larger photo. Min. size is 480px by 480px.</div>");
                $error.insertAfter(_this.$uploadButton.parent());
              }
            }
          };
        };
      }
    });

    // Close the modal when a user wants to change their photo.
    this.$cropModal.find(".-change").click(function(event) {
      event.preventDefault();
      Modal.close();
    });

    Events.subscribe("Modal:Close", function() {
      _this.resetFileField();
    });
  };

  /**
   * Clears the file field input and resets it globally,
   * so that the user can re-upload an image and edit it.
   */
  ImageUploadBeta.prototype.resetFileField = function() {
    var $input = this.$uploadButton;

    $input.replaceWith(this.$uploadButton = $input.val("").clone(true));
  };

  /**
   * Gets crop values from form and returns an object.
   */
  ImageUploadBeta.prototype.getCropValues = function() {
    return {
      x       : this.$reportbackForm.find("input[name='crop_x']").val(),
      y       : this.$reportbackForm.find("input[name='crop_y']").val(),
      width   : this.$reportbackForm.find("input[name='crop_width']").val(),
      height  : this.$reportbackForm.find("input[name='crop_height']").val(),
      degrees : parseInt(this.$reportbackForm.find("input[name='crop_rotate']").val()),
    };
  };

  /**
   * Enables submit button in modal when it opens.
   */
  ImageUploadBeta.prototype.enableSubmit = function() {
    var $submitButton = this.$cropModal.find(".-done");

    if ($submitButton.prop("disabled")) {
      $submitButton.prop("disabled", false);
    }
  };

  /**
   * Validates image size.
   */
  ImageUploadBeta.prototype.validImage = function(image) {
    return (image.width >= 480 && image.height >= 480);
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
  ImageUploadBeta.prototype.previewImage = function(image, $imageContainer) {
    var _this = this;

    var $preview = $("<img class='preview' src=''>");
    $imageContainer.html($preview);

    $preview.attr("src", image.src).load(function() {
      var $this = $(this);

      _this.resizeImage($this, $imageContainer);

      // Initiate cropping if it is enabled.
      if (_this.cropEnabled) {
        ImageCrop.dsCropperInit(image);
      }
    });
  };

  return ImageUploadBeta;

});
