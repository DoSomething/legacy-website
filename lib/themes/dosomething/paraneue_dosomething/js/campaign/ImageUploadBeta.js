define(function(require) {
  "use strict";

  var $     = require("jquery");
  var Modal = require("neue/modal");

  var $uploadButton   = $(".js-image-upload-beta");
  var $cropModal      = $("#modal--crop");
  var $imageForm      = $("#dosomething-reportback-image-form");
  var imageValues     = null;

  var init = function() {
    $uploadButton.on("change", function(event) {
      event.preventDefault();

      var files = !!this.files ? this.files : [];

      // If no file selected/no FileReader support, we're all done
      if (!files.length || !window.FileReader) {
        return;
      }

      // Open Modal
      Modal.open($cropModal,
        {
          animated: false,
        }
      );

      var $imgPreview = $("<img class='preview' src=''>");
      $(".image-wrapper").html( $imgPreview );

      if (/^image/.test( files[0].type)) {
        var reader = new FileReader();
        reader.readAsDataURL(files[0]);

        reader.onloadend = function() {
          $imgPreview.attr("src", this.result);
        };
      }
    });

    // Submit form.
    $imageForm.submit(function(event) {
      event.preventDefault();

      var $captionField = $("#caption");

      // Store the values from the form into an object
      // that we later expose so other scripts can use it.
      // @TODO - Store cropping values in here as well.
      imageValues = {
        caption: ($("#caption").val()) ? $("#caption").val() : null,
      };

      Modal.close(false);
    });
  };

  // Public
  return {
    init:        init,
    imageValues: imageValues,
  };

});
