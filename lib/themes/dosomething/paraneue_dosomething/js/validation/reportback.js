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

  // // validate that string isn't blank and less than or equal to 60 characters
  // Validation.registerValidationFunction("caption-modal", function(string, done) {
  //   // @TODO: temporary solution until Neue validation script is
  //   // updated to handle client side only forms.
  //   var $form = $("#dosomething-reportback-image-form");

  //   if( string !== "" && string.length <= 60 ) {
  //     if ($form.length) {
  //       console.log('success!');
  //       $form.data("validation-passed", true);
  //     }

  //     return done({
  //       success: true,
  //       message: Drupal.t("Sounds great!")
  //     });
  //   } else {
  //     if ($form.length) {
  //       console.log('failure!');
  //       $form.data("validation-passed", false);
  //     }

  //     return done({
  //       success: false,
  //       message: Drupal.t("Tell us about your photo!")
  //     });
  //   }
  // });

  // // validate that string isn't blank and less than or equal to 60 characters
  // Validation.registerValidationFunction("caption", function(string, done) {
  //   if( string !== "" && string.length <= 60 ) {
  //     return done({
  //       success: true,
  //       message: Drupal.t("Sounds great!")
  //     });
  //   } else {
  //     return done({
  //       success: false,
  //       message: Drupal.t("Tell us about your photo!")
  //     });
  //   }
  // });


});
