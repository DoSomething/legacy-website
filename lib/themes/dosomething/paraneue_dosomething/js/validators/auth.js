/* eslint-disable */

/* ----------------------------------------------------------
 * @TODO: ^ Enable linting by removing `eslint-disable`! ^
 * ----------------------------------------------------------
 * Linting is disabled in this file. Remove this line and
 * clean this file up according to our coding standards next
 * time it is touched.
 */

define(function(require) {
  "use strict";

  var Validation = require("dosomething-validation");

  // @TODO: This will be removed when Neue's validation gets refactored.
  function validateNotBlank(string, done, success, failure) {
    if( string !== "" ) {
      return done({
        success: true,
        message: success
      });
    } else {
      return done({
        success: false,
        message: failure
      });
    }
  }

  // # Add validation functions...

  // ## Name
  // Greets the user when they enter their name.
  Validation.registerValidationFunction("name", function(string, done) {
    validateNotBlank(string, done,
      Drupal.t("Hey, @name!", {"@name": string}),
      Drupal.t("We need your first name.")
    );
  });

  Validation.registerValidationFunction("last_name", function(string, done) {
    validateNotBlank(string, done,
      Drupal.t("Got it, @name!", {"@name": string}),
      Drupal.t("We need your last name.")
    );
  });

  // ## Phone
  // Matches validation performed in dosomething_user.module.
  Validation.registerValidationFunction("phone", function(string, done) {
    // Matches server-side validation from `dosomething_user_valid_cell()` in `dosomething_user.module`.
    var numberWithoutFormatting = string.replace(/[\-\s\.]/g, "");
    var isValidFormat = /^(?:\+?([0-9]{1,3})([\-\s\.]{1})?)?\(?([0-9]{3})\)?(?:[\-\s\.]{1})?([0-9]{3})(?:[\-\s\.]{1})?([0-9]{4})/.test(numberWithoutFormatting);

    var sanitizedNumber = string.replace(/[^0-9]/g, "");
    var allRepeatingDigits = /([0-9]{1})\1{9,}/.test(sanitizedNumber);

    if(isValidFormat && !allRepeatingDigits) {
      return done({
        success: true,
        message: Drupal.t("Thanks!")
      });
    } else {
      return done({
        success: false,
        message: Drupal.t("Enter a valid telephone number.")
      });
    }
  });
});
