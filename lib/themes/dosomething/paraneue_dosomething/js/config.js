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
      "jquery": "../bower_components/jquery/jquery",
      "neue": "../bower_components/neue/neue",
      "mailcheck": "../bower_components/mailcheck/src/mailcheck",
      "lodash": "../bower_components/lodash/dist/lodash",
      "unveil": "../bower_components/unveil/jquery.unveil"
    },
    shim: {
      "neue": { deps: ["jquery"], exports: "NEUE" },
      "mailcheck": { exports: "Kicksend.mailcheck" },
      "unveil": { deps: ["jquery"], exports: "jQuery.fn.unveil" }
    }
  });
})();
