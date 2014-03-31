//
//
// The main DS app. This guy runs the show.
//
//

(function() {
  "use strict";

  requirejs.config({
    "name": "app",
    "baseUrl": ".",
    "paths": {
      "neue": "../bower_components/neue/neue",
      "jquery": "../bower_components/jquery/dist/jquery",
      "mailcheck": "../bower_components/mailcheck/src/mailcheck"
    },
    shim: {
      "neue": { deps: ["jquery"], exports: "NEUE" },
      "jquery": { exports: "$" },
      "mailcheck": { exports: "Kicksend.mailcheck" }
    }
  });

  requirejs(["neue", "main"]);
})();
