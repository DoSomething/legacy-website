define(function(require) {
  "use strict";

  var $ = require("jquery");

  var prepareImageUploadUI = function($context) {
    // Toggle visibility of upload button and hide that guy
    var $imageUploads = $context.find(".js-image-upload");

    $imageUploads.each(function(i, el) {
      $(el).wrap( $("<div class='image-upload-container'></div>") );
      var $container = $(el).parent(".image-upload-container");

      $container.wrap("<div style='clear: both'></div>");

      var $uploadBtn = $("<a href='#' class='btn secondary small'>" + Drupal.t("Upload A Pic") + "</a>");
      $uploadBtn.insertAfter( $(el) );

      var $imgPreview = $("<img class='preview' src=''>");
      $imgPreview.insertBefore( $container );
      $imgPreview.hide();

      var $fileName = $("<p class='filename'></p>");
      $fileName.insertAfter($uploadBtn);

      // Show image preview on upload
      $(el).on("change", function(event) {
        event.preventDefault();

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
