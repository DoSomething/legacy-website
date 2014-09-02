var campaign, user;

casper.test.begin("Test that a logged-out user can log in & sign up for a campaign.", 1, {
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
    casper.start(campaign.url, function(){
      // We expect to see a sign up button, and to be able to click it to sign up.
      this.waitUntilVisible("#link--campaign-signup-login", function() {
        this.click("#link--campaign-signup-login");
      });
    });

    casper.then(function() {
      this.waitUntilVisible("[data-modal]", function() {
        this.fill("form#user-login-form", {
          name: user.email,
          pass: user.password
        }, true);
      });
    });

    // Make sure the signup happened.
    casper.then(function() {
      casper.waitForSelector('.messages.status', function() {
        test.assertSelectorHasText('.messages.status', CAMPAIGN_SIGNUP_MESSAGE, 'User can log in and sign up for a campaign');
      });
    });

    casper.run(function() {
      test.done();
    });
  }
});

