define(function(require) {
  "use strict";

  var $               = require("jquery");
  var Events          = require("neue/events");
  var ImageUploadBeta = require("campaign/ImageUploadBeta");

  var Reportback = {

    $viewMoreButton: $("<button id=\"\" >View more</button>"),
    $uploadButton  : $(".js-image-upload-beta"),
    $reportbackForm: $("#dosomething-reportback-form"),

    /**
     * Initialize the Reportback interface.
     *
     * @param  {jQuery} $container  Reportback container object.
     */
    init: function ($container) {
      var $initialGallery = $container.find(".gallery--reportback");
      this.$viewMoreButton.insertAfter($initialGallery);

      this.$viewMoreButton.on("click", this.request);

      // Initializes image upload modal.
      var imageUpload = new ImageUploadBeta(this.$uploadButton);

      var _this = this;

      // Grab the image caption from the modal only when the user is done with it.
      Events.subscribe("Modal:Close", function() {
        var $captionField = _this.$reportbackForm.find("input[name='caption']");
        $captionField.val(imageUpload.getImageCaption());
      });
    }

  };


  return Reportback;
});
