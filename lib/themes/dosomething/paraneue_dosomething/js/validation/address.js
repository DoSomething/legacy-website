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

  Validation.registerValidationFunction("ups_address", function(fields, done) {
    console.log(fields);
    $.ajax({
      type: "POST",
      url: "/user/10/validate/address",
      data: fields.serializeArray(),
      success: function(data) {
        console.log(data);
      },
      error: function(err) {
        console.log("UH OH");
      }
    })
  });

});
