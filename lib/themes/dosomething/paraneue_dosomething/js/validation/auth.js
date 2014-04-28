define(function(require) {
  "use strict";

  var NEUE = require("neue");
  var mailcheck = require("mailcheck");

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

  // # Add validation functions...

  // ## Name
  // Greets the user when they enter their name.
  NEUE.Validation.Functions.name = function(string, done) {
    if( string !== "" ) {
      return done({
        success: true,
        message: "Hey, " + string + "!"
      });
    } else {
      return done({
        success: false,
        message: "We need your first name."
      });
    }
  };

  // ## Birthday
  // Validates correct date input, reasonable birthdate, and says a nice message.
  NEUE.Validation.Functions.birthday = function(string, done) {
    var birthday, birthMonth, birthDay, birthYear;

    // parse date from string
    if( /^\d{1,2}\/\d{1,2}\/\d{4}$/.test(string) ) {
      // default, typed by user MM/DD/YYYY
      birthday = string.split("/");
      birthMonth = parseInt(birthday[0]);
      birthDay = parseInt(birthday[1]);
      birthYear = parseInt(birthday[2]);
    } else {
      return done({
        success: false,
        message: "Enter your birthday MM/DD/YYYY!"
      });
    }

    // fail if incorrect month
    if (birthMonth > 12) {
      return done({
        success: false,
        message: "That doesn't seem right."
      });
    }

    // fail if incorrect day
    // @TODO: Doesn't account for non-31 day months or leap years... meh.
    if (birthDay > 31) {
      return done({
        success: false,
        message: "That doesn't seem right."
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
        message: "Are you a time traveller?"
      });
    } else if( age > 0 && age <= 25  ) {

      if (birthDate.getMonth() === now.getMonth() && now.getDate() === birthDate.getDate() ) {
        return done({
          success: true,
          message: "Wow, happy birthday!"
        });
      } else if ( age < 10) {
        return done({
          success: true,
          message: "Wow, you're " + age + "!"
        });
      } else {
        return done({
          success: true,
          message: "Cool, " + age + "!"
        });
      }

    } else if (age > 25 && age < 130) {
      return done({
        success: true,
        message: "Yikes, you're old!"
      });
    } else if (string === "") {
      return done({
        success: false,
        message: "We need your birthday."
      });
    } else {
      return done({
        success: false,
        message: "That doesn't seem right."
      });
    }
  };

  // ## Email
  // Performs some basic sanity checks on email format (see helper method), and
  // uses Kicksend's mailcheck library to offer suggestions for misspellings.
  NEUE.Validation.Functions.email = function(string, done) {
    if ( isValidEmailSyntax(string) ) {
      // we use mailcheck.js to find some common email mispellings
      mailcheck.run({
        email: string,
        domains: ["yahoo.com", "google.com", "hotmail.com", "gmail.com", "me.com", "aol.com", "mac.com",
                  "live.com", "comcast.net", "googlemail.com", "msn.com", "hotmail.co.uk", "yahoo.co.uk",
                  "facebook.com", "verizon.net", "sbcglobal.net", "att.net", "gmx.com", "mail.com", "outlook.com",
                  "aim.com", "ymail.com", "rocketmail.com", "bellsouth.net", "cox.net", "charter.net", "me.com",
                  "earthlink.net", "optonline.net", "dosomething.org"],
        suggested: function(s) {
          return done({
            success: true,
            suggestion: s
          });
        },
        empty: function() {
          return done({
            success: true,
            message: "Great, thanks!"
          });
        }
      });
    } else {
      return done({
        success: false,
        message: "We need a valid email."
      });
    }
  };

  // ## Password
  // Checks that password is 6 or more characters long.
  // Matches validation performed in dosomething_user.module.
  NEUE.Validation.Functions.password = function(string, done) {
    if(string.length >= 6) {
      return done({
        success: true,
        message: "Keep it secret, keep it safe!"
      });
    } else {
      return done({
        success: false,
        message: "Must be 6+ characters."
      });
    }
  };

  // ## Phone
  // Does some crazy regex shit to validate phone numbers.
  // Matches validation performed in dosomething_user.module.
  NEUE.Validation.Functions.phone = function(string, done) {
    // Matches server-side validation from `dosomething_user_valid_cell()` in `dosomething_user.module`.
    var sanitizedNumber = string.replace(/[^0-9]/g, "");
    var isValidFormat = /^(?:\+?1([\-\s\.]{1})?)?\(?([0-9]{3})\)?(?:[\-\s\.]{1})?([0-9]{3})(?:[\-\s\.]{1})?([0-9]{4})/.test(string);
    var allRepeatingDigits = /([0-9]{1})\1{9,}/.test(sanitizedNumber);
    var hasRepeatingFives = /555/.test(string);

    if(isValidFormat && !allRepeatingDigits && !hasRepeatingFives) {
      return done({
        success: true,
        message: "Thanks!"
      });
    } else {
      return done({
        success: false,
        message: "Enter a valid telephone number."
      });
    }
  };
});
