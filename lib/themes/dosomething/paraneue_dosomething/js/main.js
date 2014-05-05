/**
 * We configure RequireJS options, paths, and shims here.
 *
 *  - baseURL: Path where modules will be loaded from at runtime.
 *  - paths: Load any Bower components in here.
 *  - excludeShallow: Any components that should *not* be included
 *    in the minified production build. They will be loaded in on
 *    demand via the RequireJS loader.
 *  - shim: Shim any non-AMD scripts.
 *
 *  @see https://github.com/jrburke/r.js/blob/master/build/example.build.js
 */
require.config({
  baseUrl: "/profiles/dosomething/themes/dosomething/paraneue_dosomething/js/",
  include: "main",
  includeRequire: "main",
  paths: {
    "neue": "../bower_components/neue/js",
    "mailcheck": "../bower_components/mailcheck/src/mailcheck",
    "lodash": "../bower_components/lodash/dist/lodash",
    "text": "../bower_components/requirejs-text/text",
    "rem-unit-polyfill": "../bower_components/REM-unit-polyfill/js/rem",
    "respond": "../bower_components/respond/dest/respond.min",
  },
  excludeShallow: [
    "respond",
    "rem-unit-polyfill"
  ],
  shim: {
    "mailcheck": { exports: "Kicksend.mailcheck" }
  }
});


/**
 * This is where we load and initialize components of our app.
 */
define("main", function(require) {
  "use strict";

  // let's get going
  var $ = window.jQuery;
  var Finder = require("finder/Finder");
  var Features = require("utils/features");



  // Load polyfills
  if(!Features.mediaQueries) {
    require("respond");
  }

  if(!Features.remUnits) {
    require("rem-unit-polyfill");
  }

  // Initialize modules on load
  require("neue/main");
  require("campaign/sources");
  require("campaign/tips");
  require("campaign/ImageUploader");
  require("validation/auth");
  require("validation/reportback");
  require("validation/address");

  $(function() {
    if( $(".js-finder-form").length ) {
      Finder.init(
        $(".js-finder-form"),
        $(".js-campaign-results"),
        $(".js-campaign-blankslate")
      );
    }
  });
});
