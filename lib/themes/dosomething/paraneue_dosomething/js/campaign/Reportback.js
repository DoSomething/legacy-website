define(function(require) {
  "use strict";

  var $               = require("jquery");
  var ImageUploadBeta = require("campaign/ImageUploadBeta");
  var Revealer        = require("revealer/Revealer");


  var Reportback = {

    $viewMoreButton: $("<button id=\"\" >View more</button>"),

    /**
     * Initialize the Reportback interface.
     *
     * @param  {jQuery} $container  Reportback container object.
     */
    init: function ($container) {
      $initialGallery = $container.find('.gallery--reportback');
      this.$viewMoreButton.insertAfter($initialGallery);

      this.$viewMoreButton.on('click', this.request);

      new ImageUploadBeta();
    },


    /**
     * [request description]
     * @return {[type]} [description]
     */
    request: function () {
      // Add AJAX call here.
      // $.ajax({
      //   url: '',
      //   dataType: 'json'
      // }).done(function () {

      // }).fail(function () {

      // }).always(function () {

      // });
    }

  };


  return Reportback;
});
