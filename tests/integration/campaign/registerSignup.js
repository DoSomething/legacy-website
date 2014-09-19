var userEmail, userPassword;

casper.test.begin("Test that an unregistered user can register & sign up for a campaign.", 1, {
  /*
   * Prepare campaign from fixture.
   */
  setUp: function() {
    userEmail = casper.randomEmail();
    userPassword = casper.randomPassword();
  },

  /*
   * Delete test nodes.
   */
  tearDown: function() {
    casper.deleteUserWithEmail(userEmail);
    phantom.clearCookies();
  },

  test: function(test) {
    casper.start(url);

    // We expect to see a sign up button, and to be able to click it to sign up.
    casper.thenOpen(CAMPAIGN.url, function(){
      this.waitUntilVisible("#link--campaign-signup-login", function() {
        this.click("#link--campaign-signup-login");
      });
    });

    // There should be a link to the registration form within the sign-in modal.
    casper.then(function() {
      this.waitUntilVisible("[data-modal]", function() {
        this.click("#link--register");
      });
    });

    // Now, let's register with real data.
    casper.then(function() {
      this.fill("form[id='user-register-form']", {
        "field_first_name[und][0][value]": "Panda",
        "field_birthdate[und][0][value][date]": "01/04/1989",
        "mail": userEmail,
        "pass[pass1]": userPassword,
        "pass[pass2]": userPassword,
      }, true);
    });

    // Make sure the signup happened.
    casper.then(function() {
      casper.waitForSelector('.messages.status', function() {
        test.assertSelectorHasText('.messages.status', CAMPAIGN_SIGNUP_MESSAGE, 'User can register and sign up for a campaign');
      });
    });

    casper.run(function() {
      test.done();
    });
  }
});

