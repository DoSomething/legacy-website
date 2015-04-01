define(function(require) {
  "use strict";

  var Validation= require("dosomething-validation");

  // Credit card types
  var cardTypes = {
    Visa: {
      name: "Visa",
      numberPattern: /^4[0-9]{12}(?:[0-9]{3})?$/
    },
    Mastercard: {
      name: "MasterCard",
      numberPattern: /^5[1-5][0-9]{14}$/
    },
    AmericanExpress: {
      name: "American Express",
      numberPattern: /^3[47][0-9]{13}$/
    },
    DinersClub: {
      name: "Diners Club",
      numberPattern: /^3(?:0[0-5]|[68][0-9])[0-9]{11}$/
    },
    Discover: {
      name: "Discover",
      numberPattern: /^6(?:011|5[0-9]{2})[0-9]{12}$/
    },
    JCB: {
      name: "JCB",
      numberPattern: /^(?:2131|1800|35\d{3})\d{11}$/
    }
  };

  /**
  * Validates string for a number
  *
  * @param {String}   string  String to be test against regex
  * @return {boolean}
  */
  function isDigit(string) {
    return (/^\d+$/).test(string);
  }

  /**
  * Validates string for credit card cvv
  *
  * @param {String}   string  String to be test against regex
  * @return {boolean}
  */
  function isValidCVV(string) {
    return (/^\d{3,4}$/).test(string);
  }

  /**
  * Validates string for a valid month [MM]
  *
  * @param {String}   string  String to be test against regex
  * @return {boolean}
  */
  function isValidMonth(string) {
    return (/^(0?[1-9]|1[0-2])$/).test(string);
  }

  /**
  * Validates string for a valid year [YYYY]
  *
  * @param {String}   string  String to be test against regex
  * @return {boolean}
  */
  function isValidYear(string) {
    return (/^[1-9]\d{3,}$/).test(string);
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

  // @TODO: This will be removed when Neue's validation gets refactored.
  function validateDigit(string, done, success, failure) {
    if( isDigit(string) ) {
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

  /**
  * Validates string for a valid credit card number
  *
  * @param {String}   string  String to be test against regex
  * @return {boolean}
  */
  function validateCreditCardNumber(string, done, success, failure) {
    var found = null;
    for (var key in cardTypes) {
      var card = cardTypes[key];
      if (card.numberPattern.test(string)) {
        found = card;
      }
    }
    if (found) {
      return done({
        success: true,
        message: found.name + " " + success
      });
    } else {
      return done({
        success: false,
        message: failure
      });
    }
  }

  /**
  * Validates string for a valid cvv
  *
  * @param {String}   string  String to be test against regex
  * @return {boolean}
  */
  function validateCvv(string, done, success, failure) {
    if ( isValidCVV(string) ) {
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

  /**
  * Validates string for a valid expiration month
  *
  * @param {String}   string  String to be test against regex
  * @return {boolean}
  */
  function validateExpMonth(string, done, success, failure) {
    if ( isValidMonth(string)) {
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

  /**
  * Validates string for a valid expiration year
  *
  * @param {String}   string  String to be test against regex
  * @return {boolean}
  */
  function validateExpYear(string, done, success, failure) {
    if ( isValidYear(string) ) {
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

  Validation.registerValidationFunction("full_name", function(string, done) {
    validateNotBlank(string, done,
      Drupal.t("Hey, @name!", {"@name": string}),
      Drupal.t("We need your full name.")
    );
  });

  Validation.registerValidationFunction("cc_num", function(string, done) {
    validateCreditCardNumber(string, done,
      Drupal.t("number looks good!"),
      Drupal.t("Invalid credit card number.")
    );
  });

  Validation.registerValidationFunction("cvv", function(string, done) {
    validateCvv(string, done,
      Drupal.t("CVV looks good!"),
      Drupal.t("Invalid CVV.")
    );
  });

  Validation.registerValidationFunction("exp_month", function(string, done) {
    validateExpMonth(string, done,
      Drupal.t("Good Month!"),
      Drupal.t("Invalid Month.")
    );
  });

  Validation.registerValidationFunction("exp_year", function(string, done) {
    validateExpYear(string, done,
      Drupal.t("Good Year!"),
      Drupal.t("Invalid Year.")
    );
  });

  Validation.registerValidationFunction("amount", function(string, done) {
    validateDigit(string, done,
      Drupal.t("So Generous!"),
      Drupal.t("Invalid Amount.")
    );
  });

});
