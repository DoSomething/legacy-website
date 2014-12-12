define(function(require) {
  "use strict";

  var $ = require("jquery");

  /**
   * Controls reportback behavior and interations.
   */
  var ImageUploadBeta = function() {
    this.$uploadButton = $(".js-image-upload-beta");
    this.$cropModal = $("#modal--crop");

    this.init();
  };

  ImageUploadBeta.prototype.init = function () {
    this.imageCropInit();
  };

  /**
   * Opens a modal after the user uploads a file. Initiates cropping.
   */
  ImageUploadBeta.prototype.imageCropInit = function () {
    var $btn = this.$uploadButton;
    var $modal = this.$cropModal;

    $btn.on("change", function(event) {
      event.preventDefault();

      var _this = this;
      var files = !!_this.files ? _this.files : [];

      // If no file selected/no FileReader support, we're all done
      if (!files.length || !window.FileReader) {
        return;
      }

      // Open Modal
      require(["neue/modal"], function(Modal) {
        Modal.open($modal,
          {
            animated: false,
          }
        );
      });
    });
  };

  return ImageUploadBeta;

});
