define(function() {
  "use strict";

  var Swapper = function ($content) {
    this.$image   = $content.find("img");

    this.init();
  };


  Swapper.prototype.init = function () {
    var srcLarge = this.$image.data("src-large") || null;

    this.exchange(srcLarge);
  };


  Swapper.prototype.exchange = function (url) {
    if (url) {
      this.$image.attr("src", url);
    }
  };


  return Swapper;

});
