define(function(require) {
  "use strict";

  var $ = require("jquery");

  var prepareImageUploadUI = function($context) {
    // Toggle visibility of upload button and hide that guy
    var $imageUploads = $context.find(".js-image-upload");

    // @TODO: Not ideal location; will be refactored during new reportback implementation.
    // This should actually sit within the Reportback.js code, but would need to implement
    // an event that can respond to an image being uploaded. Temporarily placed here until
    // upcoming refactor. (2014.11.18 - Diego)
    var $caption       = $context.find(".form-item-caption");
    var submittedImage = $context.find(".submitted-image").length === 0 ? false : true;

    // If no prior submitted image is present, caption should be hidden.
    if (!submittedImage) {
      $caption.hide();
    }

    $imageUploads.each(function(i, el) {
      $(el).wrap( $("<div class='image-upload-container'></div>") );
      var $container = $(el).parent(".image-upload-container");

      $container.wrap("<div style='clear: both'></div>");

      var $uploadBtn = $("<a href='#' class='button -secondary'>" + Drupal.t("Upload A Pic") + "</a>");
      $uploadBtn.insertAfter( $(el) );

      var $imgPreview = $("<img class='preview' src=''>");
      $imgPreview.insertBefore( $container );
      $imgPreview.hide();

      var $fileName = $("<p class='filename'></p>");
      $fileName.insertAfter($uploadBtn);

      // Show image preview on upload
      $(el).on("change", function(event) {
        event.preventDefault();

        // New image added, show the caption.
        submittedImage = true;
        $caption.show();

        // Change button state
        $uploadBtn.text(Drupal.t("Change Pic"));

        var files = !!this.files ? this.files : [];

        // Show file name below field
        if( files[0] && files[0].name ) {
          $fileName.text( files[0].name );
        } else {
          var file = $(el).val().replace("C:\\fakepath\\", "");
          $fileName.text(file);
        }

        // If no file selected/no FileReader support, we're all done
        if (!files.length || !window.FileReader) {
          return;
        }

        if (/^image/.test( files[0].type)) {
          var reader = new FileReader();
          reader.readAsDataURL(files[0]);

          reader.onloadend = function() {
            $imgPreview.show();
            $imgPreview.attr("src", this.result);
          };
        }

      });
    });
  };

  // On DOM ready, we prepare any `.js-image-upload`s that we find on the page
  $(function() {
    prepareImageUploadUI( $("body") );
  });

});
