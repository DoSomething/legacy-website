define(function (require) {
  "use strict";

  var Validation= require("neue/validation");

  // validate number of items
  Validation.registerValidationFunction("positiveInteger", function(string, done) {
    var trimmedString = string.replace(" ", "");
    if( trimmedString !== "" && /^[1-9]\d*$/.test(trimmedString) ) {
      return done({
        success: true,
        message: Drupal.t("That's great!")
      });
    } else {
      return done({
        success: false,
        message: Drupal.t("Enter a valid number!")
      });
    }
  });

  // validate that string isn't blank
  Validation.registerValidationFunction("reportbackReason", function(string, done) {
    if( string !== "" ) {
      return done({
        success: true,
        message: Drupal.t("Thanks for caring!")
      });
    } else {
      return done({
        success: false,
        message: Drupal.t("Tell us why you cared!")
      });
    }
  });

});
