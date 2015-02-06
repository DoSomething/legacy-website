define(function(require) {
  "use strict";

  var Validation = require("neue/validation");
  var $          = require("jquery");

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

  // validate that string isn't blank and less than or equal to 60 characters
  Validation.registerValidationFunction("caption", function(string, done) {
    if( string !== "" && string.length <= 60 ) {
      // @TODO: temporary solution until Neue validation script is updated to 
      // handle client side only forms.
      $("#dosomething-reportback-image-form").data("validation-passed", true);
      return done({
        success: true,
        message: Drupal.t("Great!")
      });
    } else {
      return done({
        success: false,
        message: Drupal.t("Tell us about your photo!")
      });
    }
  });

});
