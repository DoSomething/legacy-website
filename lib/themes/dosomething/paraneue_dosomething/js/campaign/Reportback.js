define(function(require) {
  "use strict";

  // Not using any jquery yet so this is commented out, but we probs will need it later.
  // var $ = require("jquery");
  var ImageUploadBeta = require("campaign/ImageUploadBeta");

  var Reportback = function() {
    this.init();
  };

  Reportback.prototype.init = function () {
    this.imageCropInit();
  };

  Reportback.prototype.imageCropInit = function () {
    new ImageUploadBeta();
  };

  return Reportback;
});
