var testSignUpUser;

casper.test.begin("Test that a logged-out user can log in & sign up for a campaign.", 1, {
  /*
   * Prepare campaign from fixture.
   */
  setUp: function() {
    testSignUpUser = casper.createTestUser();
  },

  /*
   * Delete test nodes.
   */
  tearDown: function() {
    casper.deleteUser(testSignUpUser.uid);
    phantom.clearCookies();
  },


  test: function(test) {
    casper.start(CAMPAIGN.url);

    casper.thenWhenReady(function() {
      // We expect to see a sign up button, and to be able to click it to sign up.
      this.waitUntilVisible("#link--campaign-signup-login", function() {
        this.click("#link--campaign-signup-login");
      });
    });

    casper.then(function() {
      this.waitUntilVisible("[data-modal]", function() {
        this.fill("#user-login-form", {
          name: testSignUpUser.email,
          pass: testSignUpUser.password
        }, true);
      });
    });

    // Make sure the signup happened.
    casper.then(function() {
      casper.waitForSelector('.messages', function() {
        test.assertSelectorHasText('.messages', CAMPAIGN_SIGNUP_MESSAGE, 'User can log in and sign up for a campaign');
      });
    });

    casper.run(function() {
      test.done();
    });
  }
});

