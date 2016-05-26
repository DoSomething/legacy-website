/* eslint-disable */

/* ----------------------------------------------------------
 * @TODO: ^ Enable linting by removing `eslint-disable`! ^
 * ----------------------------------------------------------
 * Linting is disabled in this file. Remove this line and
 * clean this file up according to our coding standards next
 * time it is touched.
 */

import setting from '../utilities/Setting';

define(function(require) {
  "use strict";

  var Validation = require("dosomething-validation");

  // We use Mailcheck (https://github.com/mailcheck/mailcheck) to provide
  // suggestions for typos in email addresses. See the "email" validator below.
  var Mailcheck = require("mailcheck");

  // We'll add a few extra domains to the defaults provided.
  // @see: https://github.com/mailcheck/mailcheck/blob/v1.1.1/src/mailcheck.js#L16-L25
  Mailcheck.defaultDomains.push("dosomething.org", "sina.com");


  // # Helpers
  // Basic sanity check used by email validation.
  // This won't catch everything, but should prevent validating some simple mistakes
  function isValidEmailSyntax(string) {
    var email = string.toUpperCase();
    if( email.match(/^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]+$/) ) {
      var lastChar = "";
      for(var i = 0, len = email.length; i < len; i++) {
        // fail if we see two dots in a row
        if(lastChar === "."  && email[i] === ".") {
          return false;
        }

        lastChar = email[i];
      }

      return true;
    }

    return false;
  }

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

  // ## Birthday
  // Validates correct date input, reasonable birthdate, and says a nice message.
  Validation.registerValidationFunction("birthday", function(string, done) {
    var birthday, birthMonth, birthDay, birthYear, format;

    // Use Drupal dateFormat validation format if available
    format = setting('dsValidation.dateFormat', 'MM/DD/YYYY');

    // parse date from string
    if( format === "MM/DD/YYYY" && /^\d{1,2}\/\d{1,2}\/\d{4}$/.test(string) ) {
      // US formatting
      birthday = string.split("/");
      birthMonth = parseInt(birthday[0]);
      birthDay = parseInt(birthday[1]);
      birthYear = parseInt(birthday[2]);
    } else if( format === "DD/MM/YYYY" && /^\d{1,2}\/\d{1,2}\/\d{4}$/.test(string) ) {
      // UK formatting
      birthday = string.split("/");
      birthDay = parseInt(birthday[0]);
      birthMonth = parseInt(birthday[1]);
      birthYear = parseInt(birthday[2]);
    } else {
      return done({
        success: false,
        message: Drupal.t("Enter your birthday " + format + "!")
      });
    }

    // fail if incorrect month
    if (birthMonth > 12 || birthMonth === 0) {
      return done({
        success: false,
        message: Drupal.t("That doesn't seem right.")
      });
    }

    //list of last days in months and check for leap year
    var endDates = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    if(((birthYear % 4 === 0) && (birthYear % 100 !== 0)) || (birthYear % 400 === 0)){
      endDates[2] = 29;
    }

    // fail if incorrect day
    if (birthDay > endDates[birthMonth]) {
      return done({
        success: false,
        message: Drupal.t("That doesn't seem right.")
      });
    }

    // calculate age
    // Source: http://stackoverflow.com/questions/4060004/calculate-age-in-javascript#answer-7091965
    var birthDate = new Date(birthYear, birthMonth - 1, birthDay);
    var now = new Date();
    var age = now.getFullYear() - birthDate.getFullYear();
    var m = now.getMonth() - birthDate.getMonth();
    if (m < 0 || (m === 0 && now.getDate() < birthDate.getDate())) {
      age--;
    }

    if (age < 0)  {
      return done({
        success: false,
        message: Drupal.t("Are you a time traveller?")
      });
    } else if( age > 0 && age <= 25  ) {

      if (birthDate.getMonth() === now.getMonth() && now.getDate() === birthDate.getDate() ) {
        return done({
          success: true,
          message: Drupal.t("Wow, happy birthday!")
        });
      } else if ( age < 10) {
        return done({
          success: true,
          message: Drupal.t("Wow, you're @age!", {"@age": age})
        });
      } else {
        return done({
          success: true,
          message: Drupal.t("Cool, @age!", {"@age": age})
        });
      }

    } else if (age > 25 && age < 130) {
      return done({
        success: true,
        message: Drupal.t("Got it!")
      });
    } else if (string === "") {
      return done({
        success: false,
        message: Drupal.t("We need your birthday.")
      });
    } else {
      return done({
        success: false,
        message: Drupal.t("That doesn't seem right.")
      });
    }
  });

  // ## Email
  // Performs some basic sanity checks on email format (see helper method), and
  // uses Kicksend's mailcheck library to offer suggestions for misspellings.
  Validation.registerValidationFunction("email", function(string, done) {
    if ( isValidEmailSyntax(string) ) {
      // We use mailcheck.js to find some common email mispellings
      Mailcheck.run({
        email: string,
        suggested: function(s) {
          return done({
            success: true,
            suggestion: s
          });
        },
        empty: function() {
          return done({
            success: true,
            message: Drupal.t("Great, thanks!")
          });
        }
      });
    } else {
      return done({
        success: false,
        message: Drupal.t("We need a valid email.")
      });
    }
  });

  // ## Password
  // Checks that password is 6 or more characters long.
  // Matches validation performed in dosomething_user.module.
  Validation.registerValidationFunction("password", function(string, done) {
    if(string.length >= 6) {
      return done({
        success: true,
        message: Drupal.t("Keep it secret, keep it safe!")
      });
    } else {
      return done({
        success: false,
        message: Drupal.t("Must be 6+ characters.")
      });
    }
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
