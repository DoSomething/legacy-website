define(function(require) {
  "use strict";

  var $ = require("jquery");

  var popup = function() {
    // Open share links in a popup dialog.
    var windowOptions = 'scrollbars=yes,resizable=yes,toolbar=no,location=yes';
    var width         = 550;
    var height        = 420;
    var winHeight     = screen.height;
    var winWidth      = screen.width;

    $('body').on('click', 'a.js-share-link', function(event) {
      event.preventDefault();
      var leftPos = Math.round((winWidth / 2) - (width / 2));
      var topPos = 0;

      if (winHeight > height) {
        topPos = Math.round((winHeight / 2) - (height / 2));
      }

      window.open(this.href, '_blank', windowOptions + ',width=' + width +
       ',height=' + height + ',left=' + leftPos + ',top=' + topPos);
    });
  };

  return {
    popup : popup
  };
});
