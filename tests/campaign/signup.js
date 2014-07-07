/**
 * signup.js
 * Test that a user can sign up for a campaign.
 */

casper.test.begin("Test that a user can sign up for a campaign.", 3, function suite(test) {
 casper.start(url);
 casper.login();

 casper.thenOpen(url + "/campaigns/test-campaign", function(){
   // We expect to see the title of the campaign, "Test Campaign"
   test.assertSelectorHasText("header[role='banner'].-hero .__title", "Test Campaign", "Title of campaign is printed in H1.");

   // We expect to see the subtitle for the campaign, "This is a test unsponsored campaign."
   test.assertSelectorHasText("header[role='banner'].-hero .__subtitle", "This is a test unsponsored campaign.", "Subtitle of campaign is printed in H2.");

   // We expect to see a sign up button, and to be able to click it to sign up.
   this.click('form#dosomething-signup-form input[type="submit"]');
  });

  // Make sure the signup happened.
  casper.waitForSelector('.messages', function() {
    test.assertSelectorHasText('.messages', 'You\'re signed up for', 'Clicking "Sign Up" signs up for a campaign');
  });

  casper.logout();

  casper.run(function() {
      test.done();
  });
});
