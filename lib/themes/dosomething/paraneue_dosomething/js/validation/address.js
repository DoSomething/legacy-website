define(["jquery", "neue"], function ($, NEUE) {
  "use strict";
  // ## fName
  // We could probably do these in one function or something. I DONT KNOW.
  NEUE.Validation.Functions.fname = function(string, done) {
    if( string !== "" ) {
      return done({
        success: true,
        message: "yaa, " + string + "!"
      });
    } else {
      return done({
        success: false,
        message: "We need your first name."
      });
    }
  };

  NEUE.Validation.Functions.lname = function(string, done) {
    if( string !== "" ) {
      return done({
        success: true,
        message: "yoyo, " + string + "!"
      });
    } else {
      return done({
        success: false,
        message: "We need your last name."
      });
    }
  };
});
