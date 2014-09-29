var user;

casper.test.begin("Test that a logged-in user can sign up for a campaign.", 1, {
  /*
   * Prepare campaign from fixture.
   */
  setUp: function() {
    user = casper.createTestUser();
  },

  /*
   * Delete test nodes.
   */
  tearDown: function() {
    casper.deleteUser(user.uid);
    phantom.clearCookies();
  },

  test: function(test) {
    casper.start(url);
    casper.login(user.email, user.password);

    casper.thenOpenWhenReady(CAMPAIGN.url, function() {
      // We expect to see a sign up button, and to be able to click it to sign up.
      casper.waitForSelector("#dosomething-signup-form-primary input[type='submit']", function() {
        this.click("#dosomething-signup-form-primary input[type='submit']");
      });
    });

    // Make sure the signup happened.
    casper.then(function() {
      casper.waitForSelector('.messages.status', function() {
        test.assertSelectorHasText('.messages.status', CAMPAIGN_SIGNUP_MESSAGE, 'Clicking "Sign Up" signs up for a campaign');
      });
    });

    casper.run(function() {
      test.done();
    });
  }
});
