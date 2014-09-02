/**
 * register.js
 * Test that a user can create an account.
 */

var REGISTER_SUCCESSFUL_MESSAGE = "You've created an account";
var testEmail, testPassword;

casper.test.begin("Test that a user can create an account.", 4, {
  setUp: function() {
    testEmail = casper.randomEmail();
    testPassword = casper.randomPassword();
  },

  tearDown: function() {
    casper.deleteUserWithEmail(testEmail);
    phantom.clearCookies();
  },

  test: function(test) {
    casper.start(url);

    casper.then(function() {
      // We reference the login link's ID to avoid a crazy selector.
      test.assertExists("#link--login", "Login link exists on page for anonymous user");

      // Click the login link in the header navigation menu.
      this.click("#link--login");

      this.waitUntilVisible("[data-modal]", function() {
        this.click("#link--register");

        // Enter with some incorrect fields (email and confirmation)
        this.fill("form[id='user-register-form']", {
          "field_first_name[und][0][value]": "Panda",
          "field_birthdate[und][0][value][date]": "01/04/1989",
          "mail": "testingex.com",
          "pass[pass1]": "abcdef",
          "pass[pass2]": "zyxwvu",
        }, true);

        // We should see error messages for the fields that weren't correct.
        test.assertExists("#edit-mail.error", "Email is marked with error if invalid");
        test.assertExists("#edit-pass-pass2.error", "Confirm Password is marked with error if not matching");
      });
    });

    casper.then(function() {
      // Now, let's register with real data.
      this.fill("form[id='user-register-form']", {
        "field_first_name[und][0][value]": "Panda",
        "field_birthdate[und][0][value][date]": "01/04/1989",
        "mail": testEmail,
        "pass[pass1]": testPassword,
        "pass[pass2]": testPassword,
      }, true);

      // This should be fine, so let's look for a successful confirmation message.
      casper.waitForSelector(".messages", function() {
        test.assertSelectorHasText(".messages", REGISTER_SUCCESSFUL_MESSAGE);
      });
    });

    casper.run(function() {
      test.done();
    });
  }
});
