// Move to new folder.

define(function(require) {
  "use strict";

  var $      = require("jquery");
  var Modal  = require("neue/modal");
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
    this.$imageForm      = this.$cropModal.find("#dosomething-reportback-image-form");
    this.$imagePreview   = this.$cropModal.find(".image-preview");
    this.imageValues     = {};

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

      Modal.open(_this.$cropModal,
        {
          animated: false,
        }
      );

      // @TODO - move image preview logic into it's own function
      // so we can use it other places like showing the previewed crop image in the
      // reportback form.
      var $preview = $("<img class='preview' src=''>");
      _this.$imagePreview.html($preview);

      if (/^image/.test(files[0].type)) {
        var reader = new FileReader();
        reader.readAsDataURL(files[0]);

        reader.onloadend = function() {
          $preview.attr("src", this.result);
        };
      }

      var cropEnabled = Drupal.settings.dsReportback.cropEnabled;
      if (cropEnabled) {
        var fileReader = new FileReader();

        fileReader.onload = function() {
          var origImage = new Image();
          origImage.src = fileReader.result;
          ImageCrop.dsCropperInit(origImage);
        };

        fileReader.readAsDataURL(this.files[0]);
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
   * Return an object containing the information gathered in the modal form.
   * Should only be used after the form has been submitted and the modal has closed.
   *
   * Includes:
   * - Caption
   * - @TODO: x, y, width, height for cropping.
   *
   * @return {jQuery} An object of form values.
   */
  ImageUploadBeta.prototype.getImageValues = function() {
    var caption = this.$imageForm.find("#caption").val();

    this.imageValues = {
      caption: (caption) ? caption : null,
    };

    return this.imageValues;
  };

  return ImageUploadBeta;

});

    // // Make sure cropping is enabled.
    // var cropEnabled = Drupal.settings.dsReportback.cropEnabled;
    // if (cropEnabled) {
    //   $(".js-image-upload-beta").on("change", function(event) {
    //     event.preventDefault();

    //     var fileReader = new FileReader();

    //     fileReader.onload = function() {
    //       var origImage = new Image();
    //       origImage.src = fileReader.result;
    //       dsCropperInit(origImage);
    //     };

    //     fileReader.readAsDataURL(this.files[0]);
    //   });
    // }
