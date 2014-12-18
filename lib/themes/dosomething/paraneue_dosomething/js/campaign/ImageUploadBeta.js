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
    this.$imageForm      = this.$cropModal.find($("#dosomething-reportback-image-form"));
    this.$imageWrapper   = this.$cropModal.find($(".image-wrapper"));
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
      var $imgPreview = $("<img class='preview' src=''>");
      _this.$imageWrapper.html( $imgPreview );

      if (/^image/.test( files[0].type)) {
        var reader = new FileReader();
        reader.readAsDataURL(files[0]);

        reader.onloadend = function() {
          $imgPreview.attr("src", this.result);
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
   * Return and object containing the information gathered in the modal form.
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
