//
//
// The main DS app. This guy runs the show.
//
//

(function() {
  "use strict";

  // Define dependencies
  var _ = require("underscore");

  // Import scripts
  require("./campaign/carousel.js")();
  require("./campaign/tips.js")();

  // We configure Underscore templating to use brackets (Mustache-style) syntax.
  _.templateSettings = {
    evaluate:    /\{\{#([\s\S]+?)\}\}/g,            // {{# console.log("blah") }}
    interpolate: /\{\{[^#\{]([\s\S]+?)[^\}]\}\}/g,  // {{ title }}
    escape:      /\{\{\{([\s\S]+?)\}\}\}/g,         // {{{ title }}}
  };

})();
