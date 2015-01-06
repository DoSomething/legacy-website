// Move to new folder.

define(function(require) {
  "use strict";

  var $      = require("jquery");
  var Modal  = require("neue/modal");

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

      // Open the modal.
      Modal.open(_this.$cropModal,
        {
          animated: false,
        }
      );

      // Add the preview image to the modal
      _this.previewImage(files, _this.$imagePreview);
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
   * Return an object containing the information gathered in the modal form.
   * Creates a preview image of a file and adds it to a container.
   * If cropping is enabled, it initiates the cropping script.
   *
   * @param {jQuery} files           An object representing a file.
   * @param {jQuery} $imageContainer The DOM element to put the preview image in.
   */
  ImageUploadBeta.prototype.previewImage = function(files, $imageContainer) {
    var $preview = $("<img class='preview' src=''>");
    $imageContainer.html($preview);

    if (/^image/.test( files[0].type)) {
      var reader = new FileReader();
      reader.readAsDataURL(files[0]);
      var _this = this;

      reader.onloadend = function() {
        var result = this.result;
        $preview.attr("src", result).load(function() {
          // Initiate cropping if it is enabled.
          if (_this.cropEnabled) {
            _this.cropInit(result);
          }
        });
      };
    }
  };

  /**
   * Initiates cropping on a file.
   *
   * @param {jQuery} result  The result property of a file reader object.
   */
  ImageUploadBeta.prototype.cropInit = function(result) {
    var ImageCrop = require("campaign/ImageCrop");
    var origImage = new Image();
    origImage.src = result;

    // Remove any cropping already on the page before initiating.
    // @TODO - remove this check. the crop init js should be smart enough to reset itself it is already initiate.
    ImageCrop.dsCropperDestroy();
    ImageCrop.dsCropperInit(origImage, this.$reportbackForm);
  };

  /**
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
