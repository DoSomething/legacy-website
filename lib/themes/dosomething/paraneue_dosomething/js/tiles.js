define(function(require) {
  "use strict";

  var $ = require("jquery");

  // Lazy-load in tile images
  $(".tile").find("img").unveil(200, function() {
    $(this).load(function() {
      this.style.opacity = 1;
    });
  });

});
