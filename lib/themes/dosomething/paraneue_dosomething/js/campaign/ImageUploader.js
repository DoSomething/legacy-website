define(function(require) {
  "use strict";

  var $ = window.jQuery;
  var Events = require("neue/events");

  var prepareImageUploadUI = function($context) {
    // Toggle visibility of upload button and hide that guy
    var $imageUploads = $context.find(".js-image-upload");

    $imageUploads.each(function(i, el) {
      // We set the field's visibility to "hidden", rather than
      // "display: none" to keep some browsers from disabling the
      // field's "click" action when it is not on the page.
      $(el).css("visibility", "hidden");
      $(el).css("position", "absolute");

      var $uploadBtn = $("<a href='#' class='btn secondary small'>Upload A Pic</a>");
      $uploadBtn.insertAfter( $(el) );

      var $imgPreview = $("<img class='preview' src=''>");
      $imgPreview.insertAfter( $(el) );
      $imgPreview.hide();

      var $fileName = $("<p class='filename'></p>");
      $fileName.insertAfter($uploadBtn);

      $uploadBtn.on("click", function(event) {
        event.preventDefault();
        $(el).trigger("click");
      });

      // Show image preview on upload
      $(el).on("change", function(event) {
        event.preventDefault();
        $imgPreview.hide();

        // Change button state
        $uploadBtn.text("Change Pic");

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

  // When we open a modal, we prepare any `.js-image-upload`s that we find there
  Events.subscribe("Modal:opened", function(topic, args) {
    prepareImageUploadUI(args);
  });

});
