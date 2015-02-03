/**
 * Provides a fallback for customized file input if the File API is not supported.
 */
define(function(require) {
  "use strict";

  var $ = require("jquery");

  var ImageUploadFallback = {

    init: function ($button, $context) {
      this.$container      = $context;
      this.$uploadButton   = $button

      this.$uploadButton.on('change', function(event) {
        var file = event.target.value;
        var start = file.indexOf("fakepath\\");

        console.log(file);

        if (start >= 0) {
          file = file.substring(start + 9, file.length);
        }

      });
    }
  };


  return ImageUploadFallback;
});
