define(function() {
  // In development, we concatenate jQuery to the app.js build
  // so that it is exposed as a global for Drupal scripts (rather
  // than loading it normally.a)

  return window.jQuery;
});
