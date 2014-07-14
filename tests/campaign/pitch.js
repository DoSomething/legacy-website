/**
 * signup.js
 * Test that a user can sign up for a campaign.
 */

var CAMPAIGN_SIGNUP_MESSAGE = "You're signed up for";

casper.test.begin("Test pitch page is rendered correctly", 2, function suite(test) {
 casper.start(url);

 casper.thenOpen(url + "/campaigns/test-campaign", function(){
    // We expect to see the title of the campaign, "Test Campaign"
    test.assertSelectorHasText("header[role='banner'].-hero .__title", "Test Campaign", "Title of campaign is printed in H1.");

    // We expect to see the subtitle for the campaign, "This is a test unsponsored campaign."
    test.assertSelectorHasText("header[role='banner'].-hero .__subtitle", "This is a test unsponsored campaign.", "Subtitle of campaign is printed in H2.");
  });

  casper.run(function() {
    test.done();
  });
});


casper.test.begin("Test that an unregistered user can register & sign up for a campaign.", 1, function suite(test) {
  casper.start(url);

  casper.thenOpen(url + "/campaigns/test-campaign", function(){
    // We expect to see a sign up button, and to be able to click it to sign up.
    this.click("#link--campaign-signup-login");

    this.waitUntilVisible(".modal-content", function() {
      this.click("#link--register");
    });
  });

  casper.then(function() {
    // Now, let's register with real data.
    this.fill("form[id='user-register-form']", {
      "field_first_name[und][0][value]": "Panda",
      "field_birthdate[und][0][value][date]": "01/04/1989",
      "mail": "QA_TEST_CAMPAIGN_SIGNUP_NEW@example.com",
      "pass[pass1]": "QA_TEST_CAMPAIGN_SIGNUP_NEW",
      "pass[pass2]": "QA_TEST_CAMPAIGN_SIGNUP_NEW",
    }, true);
    
    // Make sure the signup happened.
    casper.waitForSelector('.messages.status', function() {
      test.assertSelectorHasText('.messages.status', CAMPAIGN_SIGNUP_MESSAGE, 'User can register and sign up for a campaign');
    });
  });

  casper.run(function() {
    test.done();
  });
});

casper.test.begin("Test that a logged-out user can log in & sign up for a campaign.", 1, function suite(test) {
  casper.start(url);

  casper.thenOpen(url + "/campaigns/test-campaign", function(){
    // We expect to see a sign up button, and to be able to click it to sign up.
    this.click("#link--campaign-signup-login");

    this.waitUntilVisible(".modal-content", function() {
      this.fill("form#user-login-form", {
        name: 'QA_TEST_CAMPAIGN_SIGNUP_EXISTING@example.com',
        pass: 'QA_TEST_CAMPAIGN_SIGNUP_EXISTING'
      }, true);

      // Make sure the signup happened.
      casper.waitForSelector('.messages.status', function() {
        test.assertSelectorHasText('.messages.status', CAMPAIGN_SIGNUP_MESSAGE, 'User can log in and sign up for a campaign');
      });
    });
  });

  casper.run(function() {
    test.done();
  });
});

casper.test.begin("Test that a logged-in user can sign up for a campaign.", 1, function suite(test) {
  casper.start(url);
  casper.login();

  casper.thenOpen(url + "/campaigns/test-campaign", function(){
    // We expect to see a sign up button, and to be able to click it to sign up.
    this.click("form#dosomething-signup-form input[type='submit']");

    // Make sure the signup happened.
    casper.waitForSelector('.messages.status', function() {
      test.assertSelectorHasText('.messages.status', CAMPAIGN_SIGNUP_MESSAGE, 'Clicking "Sign Up" signs up for a campaign');
    });
  });

  casper.run(function() {
    test.done();
  });
});
