define(function(require) {
  "use strict";

  var $ = window.jQuery;
  var Validation= require("neue/validation");

  /** @NOTE: Temporary, testing out some new ideas. */
  var requiredValidator = function(string, done, args) {
    if( string !== "" ) {
      return done({
        success: true,
        message: args.success
      });
    } else {
      return done({
        success: false,
        message: args.failure
      });
    }
  };

  /**
   * Validators for individual address form fields:
   */
  Validation.registerValidationFunction("fname", function(string, done) {
    return requiredValidator(string, done, {
      success: "Oh hey, " + string + "!",
      failure: "We need your name. We’re on a first-name basis, right?"
    });
  });

  Validation.registerValidationFunction("lname", function(string, done) {
    return requiredValidator(string, done, {
      success: "The " + string + "-inator! People call you that, right?",
      failure: "We need your last name."

    });
  });

  Validation.registerValidationFunction("address1", function(string, done) {
    return requiredValidator(string, done, {
      success: "Got it!",
      failure: "We need your street name and number."
    });
  });

  Validation.registerValidationFunction("address2", function(string, done) {
    return requiredValidator(string, done, {
      success: "Got that too!",
      failure: ""
    });
  });

  Validation.registerValidationFunction("city", function(string, done) {
    return requiredValidator(string, done, {
      success: "Nice place!",
      failure: "We need your city."
    });
  });

  Validation.registerValidationFunction("state", function(string, done) {
    return requiredValidator(string, done, {
      success: "Sweet, thanks!",
      failure: "We need your state."
    });
  });

  Validation.registerValidationFunction("zipcode", function(string, done) {
    if( string.match(/\d{5}/) ) {
      return done({
        success: true,
        message: "Almost done!"
      });
    } else {
      return done({
        success: false,
        message: "We need your 5-digit zip code."
      });
    }
  });

  Validation.registerValidationFunction("why_signedup", function(string, done) {
    return requiredValidator(string, done, {
      success: "Thanks for caring!",
      failure: "We need to know why you signed up."
    });
  });


  /**
   * Custom validation for UPS address fieldset.
   */
  var $addressFieldSet = $("#addressfield-wrapper");

  var validateUpsAddress = function(event) {
    console.log("CHANGED SOME STUFF: " + event);

    // We don't know if this fieldset validates yet.
    $addressFieldSet.attr("data-validate-custom", false);

    // If we haven't filled out all the required fields yet, do nothing


    // Once we know we have, submit them to the AJAX endpoint
    $.ajax({
      type: "POST",
      url: "/user/validate/address",
      data: {test: "blah"},
      success: function(data) {
        // On a successful response, check if "sorry" or "ambiguous"
        // @TODO
        if(data.sorry || data.ambiguous) {
          $addressFieldSet.attr("data-validate-custom", false);
          console.log(data);

          // If so, mark suggestions on corrected fields
          // @TODO
        } else {
          // Otherwise, set as validated
          $addressFieldSet.attr("data-validate-custom", true);
        }

      },
      error: function() {
        // We're having trouble getting the validation over AJAX, let's mark as
        // validated and leave it up to the server just to be safe.
        console.error("Error getting AJAX UPS validation result.");
        $addressFieldSet.attr("data-validate-custom", true);
      }
    });
  };

  $addressFieldSet.find("input").on("blur", validateUpsAddress);
  $addressFieldSet.find("select").on("change", validateUpsAddress);
  $addressFieldSet.parent("form").on("submit", validateUpsAddress);
});
