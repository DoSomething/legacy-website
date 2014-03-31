//
//
// The main DS app. This guy runs the show.
//
//

window.NEUE = window.NEUE || {};

(function() {
  "use strict";

  // Define dependencies
  // var _ = require("underscore");

  // We configure Underscore templating to use brackets (Mustache-style) syntax.
  // _.templateSettings = {
  //   evaluate:    /\{\{#([\s\S]+?)\}\}/g,            // {{# console.log("blah") }}
  //   interpolate: /\{\{[^#\{]([\s\S]+?)[^\}]\}\}/g,  // {{ title }}
  //   escape:      /\{\{\{([\s\S]+?)\}\}\}/g,         // {{{ title }}}
  // };

  // Import scripts
  require("./campaign/tips.js")();
  require("./campaign/sources.js")();

  // Set up additional validators
  NEUE.Validation = NEUE.Validation || {};
  NEUE.Validation.Functions = NEUE.Validation.Functions || {};
  require("./validation/reportback.js")(NEUE.Validation.Functions);
  require("./validation/auth.js")(NEUE.Validation.Functions);
})();
