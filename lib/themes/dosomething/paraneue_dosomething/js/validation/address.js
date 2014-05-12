define(function(require) {
  "use strict";

  var $ = window.jQuery;
  var Validation= require("neue/validation");

  // ## fName
  // We could probably do these in one function or something. I DONT KNOW.
  Validation.registerValidationFunction("fname", function(string, done) {
    if( string !== "" ) {
      return done({
        success: true,
        message: "Oh hey, " + string + "!"
      });
    } else {
      return done({
        success: false,
        message: "We need your name. We’re on a first-name basis, right?"
      });
    }
  });

  Validation.registerValidationFunction("lname", function(string, done) {
    if( string !== "" ) {
      return done({
        success: true,
        message: "The " + string + "-inator! People call you that, right?"
      });
    } else {
      return done({
        success: false,
        message: "We need your last name."
      });
    }
  });


  /**
   * Custom validation for UPS address fieldset.
   */
  var $addressFieldSet = $(".js-validate-ups-address");

  var validateUpsAddress = function(event) {
    console.log("CHANGED SOME STUFF: " + event);

    // We don't know if this fieldset validates yet.
    $addressFieldSet.data("validated-custom", false);

    // If we haven't filled out all the required fields yet, do nothing
    // @TODO

    // Once we know we have, submit them to the AJAX endpoint
    $.ajax({
      type: "POST",
      url: "/user/validate/address",
      data: {test: "blah"},
      success: function(data) {
        // On a successful response, check if "sorry" or "ambiguous"
        // @TODO
        if(data.sorry || data.ambiguous) {
          $addressFieldSet.data("validated-custom", false);

          // If so, mark suggestions on corrected fields
          // @TODO
        } else {
          // Otherwise, set as validated
          $addressFieldSet.data("validated-custom", true);
        }

        console.log(data);
      },
      error: function() {
        // We're having trouble getting the validation over AJAX, let's mark as
        // validated and leave it up to the server just to be safe.
        console.error("Error getting AJAX UPS validation result.");
        $addressFieldSet.data("validated-custom", true);
      }
    });
  };

  $addressFieldSet.find("input").on("blur", validateUpsAddress);
  $addressFieldSet.find("select").on("change", validateUpsAddress);
  $addressFieldSet.parent("form").on("submit", validateUpsAddress);
});
