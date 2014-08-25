/* jshint ignore:start */
require(["neue/validation", "validation/auth", "validation/reportback"], function(Validation, auth, reportback) {
  module("Validation");

  test("Name", function() {
    Validation.Validations.name.fn("John", function(result) {
      ok(result.message == "Hey, John!", "should greet");
    });

    Validation.Validations.name.fn("", function(result) {
      ok(result.success == false, "should require name");
    });

  });

  test("Birthdays", function() {
    var now = new Date();
    var birthday_date = (now.getMonth() + 1) + "/" + now.getDate() + "/1990";
    var user_9_years_old = Math.min(now.getMonth() + 2, 12) + "/" + now.getDate() + "/" + (now.getFullYear() - 10);
    var user_19_years_old = Math.min(now.getMonth() + 2, 12) + "/" + now.getDate() + "/" + (now.getFullYear() - 20);

    Validation.Validations.birthday.fn(birthday_date, function(result) {
      ok(result.message == "Wow, happy birthday!", "should wish me a happy birthday");
    });

    Validation.Validations.birthday.fn(user_9_years_old, function(result) {
      ok(result.message == "Wow, you're 9!", "should tell young users their age");
    });

    Validation.Validations.birthday.fn(user_19_years_old, function(result) {
      ok(result.message == "Cool, 19!", "should tell me my age");
    });

    Validation.Validations.birthday.fn("yesterday", function(result) {
      ok(result.success == false, "should reject non-formatted dates");
    });

    Validation.Validations.birthday.fn("1/15/1960", function(result) {
      ok(result.message == "Got it!", "should be cordial to old people");
    });

    Validation.Validations.birthday.fn("1/15/1860", function(result) {
      ok(result.message == "That doesn't seem right.", "should reject users with birthdates too far in the past");
    });

    Validation.Validations.birthday.fn("1/15/2095", function(result) {
      ok(result.message == "Are you a time traveller?", "should reject users with future birthdates");
    });

    Validation.Validations.birthday.fn("61/12/1990", function(result) {
      ok(result.success == false, "should reject users with invalid month values");
    });

    Validation.Validations.birthday.fn("12/42/1990", function(result) {
      ok(result.success == false, "should reject users with day value greater than 31");
    });

    Validation.Validations.birthday.fn("10/25/90", function(result) {
      ok(result.success == false, "should reject dates with two-digit years");
    });

  });


  test("Emails", function() {
    Validation.Validations.email.fn("my.name@gmail.com", function(result) {
      ok(result.success == true, "should accept a valid email");
    });

    Validation.Validations.email.fn("my.name.com", function(result) {
      ok(result.success == false, "should reject an invalid email");
    });

    Validation.Validations.email.fn("myname@com", function(result) {
      ok(result.success == false, "should reject an invalid email");
    });

    Validation.Validations.email.fn("myname@gmail.123", function(result) {
      ok(result.success == false, "should reject an invalid email");
    });
  });


  test("Passwords", function() {
    Validation.Validations.password.fn("12345", function(result) {
      ok(result.success == false, "should reject if too short");
    });

    Validation.Validations.password.fn("super$ecure19", function(result) {
      ok(result.success == true, "should be totally chill with a good password");
    });
  });

  test("Match", function() {
    Validation.Validations.match.fn("dog", "cat", function(result) {
      ok(result.success == false, "should reject if different strings");
    });

    Validation.Validations.match.fn("dog", "Dog", function(result) {
      ok(result.success == false, "should reject if different capitalization");
    });

    Validation.Validations.match.fn("dog", "dog ", function(result) {
      ok(result.success == false, "should reject if different spacing");
    });

    Validation.Validations.match.fn("super$ecure19", "super$ecure19", function(result) {
      ok(result.success == true, "should accept if the same");
    });
  });

  test("Phone numbers", function() {
    Validation.Validations.phone.fn("123-456-7890", function(result) {
      ok(result.success == true, "should accept 10-digit number with dashes");
    });

    Validation.Validations.phone.fn("123.456 7890", function(result) {
      ok(result.success == true, "should accept 10-digit number with dot and space");
    });

    Validation.Validations.phone.fn("1 (123) 456-7890", function(result) {
      ok(result.success == true, "should accept 11-digit US number");
    });

    Validation.Validations.phone.fn("123-555-9942", function(result) {
      ok(result.success == true, "should accept number with some repeating digits");
    });

    Validation.Validations.phone.fn("1 902 #@@ 1234", function(result) {
      ok(result.success == false, "should reject number with invalid symbols");
    });

    Validation.Validations.phone.fn("999 999 9999", function(result) {
      ok(result.success == false, "should reject number with all repeating digits");
    });
  });

  test("Reportback numbers", function() {
    Validation.Validations.positiveInteger.fn("19", function(result) {
      ok(result.success == true, "should accept a valid integer");
    });

    Validation.Validations.positiveInteger.fn(" 5", function(result) {
      ok(result.success == true, "should accept a number with space in front");
    });

    Validation.Validations.positiveInteger.fn("5 ", function(result) {
      ok(result.success == true, "should accept a number with space at the end");
    });

    Validation.Validations.positiveInteger.fn("two", function(result) {
      ok(result.success == false, "should reject a number spelled out as a string");
    });

    Validation.Validations.positiveInteger.fn("4.5", function(result) {
      ok(result.success == false, "should reject a decimal number");
    });

    Validation.Validations.positiveInteger.fn("0", function(result) {
      ok(result.success == false, "should reject zero");
    });
  });

});
