define(function (require) {
  "use strict";

  var Validation= require("neue/validation");

  // validate number of items
  Validation.registerValidationFunction("reportbackNumber ", function(string, done) {
    if( string !== "" && /^[,0-9]+$/.test(string) ) {
      return done({
        success: true,
        message: "That's great!"
      });
    } else {
      return done({
        success: false,
        message: "Enter a number!"
      });
    }
  });

  // validate that string isn't blank
  Validation.registerValidationFunction("reportbackReason", function(string, done) {
    if( string !== "" ) {
      return done({
        success: true,
        message: "Thanks for caring!"
      });
    } else {
      return done({
        success: false,
        message: "Tell us why you cared!"
      });
    }
  });

});
