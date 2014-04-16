define(["jquery", "neue"], function ($, NEUE) {
  "use strict";
  // ## fName
  // We could probably do these in one function or something. I DONT KNOW.
  NEUE.Validation.Functions.fname = function(string, done) {
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
  };

  NEUE.Validation.Functions.lname = function(string, done) {
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
  };
});
