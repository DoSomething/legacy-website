var campaign, user;

casper.test.begin("Test that a logged-in user can sign up for a campaign.", 1, {
  /*
   * Prepare campaign from fixture.
   */
  setUp: function() {
    campaign = casper.createCampaign("campaign.json");
    user = casper.createTestUser();
  },

  /*
   * Delete test nodes.
   */
  tearDown: function() {
    casper.deleteAllTestNodes();
    casper.deleteUserWithEmail(user.email);
    phantom.clearCookies();
  },

  test: function(test) {
    casper.start(url);
    casper.login(user.email, user.password);

    casper.thenOpen(campaign.url, function(){
      // We expect to see a sign up button, and to be able to click it to sign up.
      this.click("form#dosomething-signup-form input[type='submit']");
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
