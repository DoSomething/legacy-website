describe("Validation", function(){
  var Validations;

  beforeEach(function() {
    Validations = DS.Validation.Validations;
  });

  describe("name", function(){
    it("should greet the user by name", function() {
      Validations.name.fn("John", function(result) {
        assert.ok(result.message === "Hey, John!");
      });

      Validations.name.fn("Hou-Tai", function(result) {
        assert.ok(result.message === "Hey, Hou-Tai!");
      });

      Validations.name.fn("明美", function(result) {
        assert.ok(result.message === "Hey, 明美!");
      });
    });

    it("should refuse blank names", function() {
      Validations.name.fn("", function(result) {
        assert.ok(result.success === false);
      });
    });
  });

  describe("birthday", function() {
    var now = new Date();
    var birthday_date = (now.getMonth() + 1) + "/" + now.getDate() + "/1990";

    it("should wish me a happy birthday", function() {
      Validations.birthday.fn(birthday_date, function(result) {
        assert.strictEqual(result.message, "Wow, happy birthday!");
      });
    });

    it("should tell young users their age", function() {
      var user_9_years_old = Math.min(now.getMonth() + 2, 12) + "/" + now.getDate() + "/" + (now.getFullYear() - 10);
      Validations.birthday.fn(user_9_years_old, function(result) {
        assert.strictEqual(result.message, "Wow, you're 9!");
      });
    });

    it("should tell target-demo users their age", function() {
      var user_19_years_old = Math.min(now.getMonth() + 2, 12) + "/" + now.getDate() + "/" + (now.getFullYear() - 20);
      Validations.birthday.fn(user_19_years_old, function(result) {
        assert.strictEqual(result.message, "Cool, 19!");
      });
    });

    it("should reject non-formatted dates", function() {
      Validations.birthday.fn("yesterday", function(result) {
        assert.isFalse(result.success);
      });
    });

    it("should be cordial to old people", function() {
      Validations.birthday.fn("1/15/1960", function(result) {
        assert.strictEqual(result.message, "Got it!");
      });
    });

    it("should reject users with birthdates too far in the past", function() {
      Validations.birthday.fn("1/15/1860", function(result) {
        assert.strictEqual(result.message, "That doesn't seem right.");
      });
    });

    it("should reject users with future birthdates", function() {
      Validations.birthday.fn("1/15/2095", function(result) {
        assert.strictEqual(result.message, "Are you a time traveller?");
      });
    });

    it("should reject users with invalid month values", function() {
      Validations.birthday.fn("61/12/1990", function(result) {
        assert.isFalse(result.success);
      });
    });

    it("should reject users with day value greater than 31", function() {
      Validations.birthday.fn("12/42/1990", function(result) {
        assert.isFalse(result.success);
      });
    });

    it("should reject dates with two-digit years", function() {
      Validations.birthday.fn("10/25/90", function(result) {
        assert.isFalse(result.success);
      });
    });
  });

  describe("email", function() {
    it("should accept a valid email", function() {
      Validations.email.fn("my.name@gmail.com", function(result) {
        assert.isTrue(result.success);
      });
    });

    it("should reject an invalid email", function() {
      Validations.email.fn("my.name.com", function(result) {
        assert.isFalse(result.success);
      });

      Validations.email.fn("myname@com", function(result) {
        assert.isFalse(result.success);
      });

      Validations.email.fn("myname@gmail.123", function(result) {
        assert.isFalse(result.success);
      });
    });
  });

  describe("passwords", function() {
    it("should be totally chill with a good password", function() {
      Validations.password.fn("super$ecure19", function(result) {
        assert.isTrue(result.success);
      });
    });

    it("should reject if too short", function() {
      Validations.password.fn("12345", function(result) {
        assert.isFalse(result.success);
      });
    });
  });

  describe("match", function() {
    it("should reject if different strings", function() {
      Validations.match.fn("dog", "cat", function(result) {
        assert.isFalse(result.success);
      });
    });

    it("should reject if different capitalization", function() {
      Validations.match.fn("dog", "Dog", function(result) {
        assert.isFalse(result.success);
      });
    });

    it("should reject if different spacing", function() {
      Validations.match.fn("dog", "dog ", function(result) {
        assert.isFalse(result.success);
      });
    });

    it("should accept if identical strings", function() {
      Validations.match.fn("super$ecure19", "super$ecure19", function(result) {
        assert.isTrue(result.success);
      });
    });
  });


  describe("phone", function() {
    it("should accept 10-digit number dashes, dots, or spaces", function() {
      Validations.phone.fn("123-456-7890", function(result) {
        assert.isTrue(result.success);
      });

      Validations.phone.fn("123.456 7890", function(result) {
        assert.isTrue(result.success);
      });
    });

    it("should accept 11-digit US number", function() {
      Validations.phone.fn("1 (123) 456-7890", function(result) {
        assert.isTrue(result.success);
      });
    });

    it("should accept number with some repeating digits", function() {
      Validations.phone.fn("123-555-9942", function(result) {
        assert.isTrue(result.success);
      });
    });

    it("should reject number with invalid symbols", function() {
      Validations.phone.fn("1 902 #@@ 1234", function(result) {
        assert.isFalse(result.success);
      });
    });

    it("should reject number with all repeating digits", function() {
      Validations.phone.fn("999 999 9999", function(result) {
        assert.isFalse(result.success);
      });
    });

    it("should accept number with non-US formatting", function() {
      Validations.phone.fn("44 07708 200 305", function(result) {
        assert.isTrue(result.success);
      });
    });

    it("should accept number with non-US country code", function() {
      Validations.phone.fn("44 07708 200 305", function(result) {
        assert.isTrue(result.success);
      });
    });
  });


  describe("positiveInteger", function() {
 
    it("should accept a valid integer", function() {
      Validations.positiveInteger.fn("19", function(result) {
        assert.isTrue(result.success);
      });
    });

    it("should accept a number with leading or trailing space", function() {
      Validations.positiveInteger.fn(" 5", function(result) {
        assert.isTrue(result.success);
      });

      Validations.positiveInteger.fn("5 ", function(result) {
        assert.isTrue(result.success);
      });
    });

    it("should reject a number spelled out as a string", function() {
      Validations.positiveInteger.fn("two", function(result) {
        assert.isFalse(result.success);
      });
    });

    it("should reject a decimal number", function() {
      Validations.positiveInteger.fn("4.5", function(result) {
        assert.isFalse(result.success);
      });
    });

    it("should reject zero", function() {
      Validations.positiveInteger.fn("0", function(result) {
        assert.isFalse(result.success);
      });
    });
  });
});

