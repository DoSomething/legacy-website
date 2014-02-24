//
//
// The main DS app. This guy runs the show.
//
//

// global variables
var DS;

(function() {
  "use strict";

  var _ = require('underscore');
  var campaign = require('./campaign.js');

  // We configure Underscore templating to use brackets (Mustache-style) syntax.
  _.templateSettings = {
    evaluate:    /\{\{#([\s\S]+?)\}\}/g,            // {{# console.log("blah") }}
    interpolate: /\{\{[^#\{]([\s\S]+?)[^\}]\}\}/g,  // {{ title }}
    escape:      /\{\{\{([\s\S]+?)\}\}\}/g,         // {{{ title }}}
  };

  campaign();

})();
