//
//
// RequireJS Configuration
// We load and shim external components here.
//
//

(function() {
  "use strict";


  require.config({
    baseUrl: "/profiles/dosomething/themes/dosomething/paraneue_dosomething/js/",
    include: "main",
    paths: {
      "neue": "../bower_components/neue/js",
      "mailcheck": "../bower_components/mailcheck/src/mailcheck",
      "lodash": "../bower_components/lodash/dist/lodash"
    },
    shim: {
      "mailcheck": { exports: "Kicksend.mailcheck" }
    }
  });
})();
