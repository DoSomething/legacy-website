define(function(require) {
  "use strict";

  var $ = require("jquery");

  var $uploadButton = $(".js-image-upload-beta");
  var $cropModal = $("#modal--crop");

  var init = function() {
    $uploadButton.on("change", function(event) {
      event.preventDefault();

      var files = !!this.files ? this.files : [];

      // If no file selected/no FileReader support, we're all done
      if (!files.length || !window.FileReader) {
        return;
      }

      // Open Modal
      require(["neue/modal"], function(Modal) {
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
    });
  };

  return {
    init: init,
  };

});
