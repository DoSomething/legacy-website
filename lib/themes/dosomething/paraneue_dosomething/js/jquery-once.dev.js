define(function() {
  "use strict";

  // In development, we concatenate jQuery.once to the app.js build
  // so that it is exposed as a global for Drupal scripts (rather
  // than loading it normally.)

  return window.jQuery;
});
