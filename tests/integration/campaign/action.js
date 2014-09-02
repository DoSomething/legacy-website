/**
 * action.js
 * Test action page is rendered correctly
 */

var x = require('casper').selectXPath;
var campaign, user;

casper.test.begin("Test action page is rendered and functions correctly", {
  /*
   * Prepare campaign from fixture.
   */
  setUp: function() {
    campaign = casper.createCampaign("campaign.json");
    user = casper.createTestUser();
    casper.campaignSignup(campaign.nid, user.uid);
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
    
    // ## Header 
    casper.thenOpen(campaign.url, function() {
      this.capture("yo.png");
      // We expect to see the title and subtitle of the campaign
      test.assertSelectorHasText("header[role='banner'].-hero .__title", campaign.data.title, "Title of campaign is printed in H1.");
      test.assertSelectorHasText("header[role='banner'].-hero .__subtitle", campaign.data.call_to_action, "Subtitle of campaign is printed in H2.");
    });

    // ## Content
    casper.then(function() {
      test.assertSelectorHasText("#know .container__title", "Step 1: Know It", "\"Know It\" banner exists.");
      test.assertSelectorHasText("#plan .container__title", "Step 2: Plan It", "\"Plan It\" banner exists.");
      test.assertSelectorHasText("#do .container__title", "Step 3: Do It", "\"Do It\" banner exists.");
      test.assertSelectorHasText("#prove .container__title", "Step 4: Prove It", "\"Prove It\" banner exists.");
    });

    // ## Visual tests
    casper.then(function() {
      phantomcss.screenshot("#know", "step1");
      phantomcss.screenshot("#plan", "step2");
      phantomcss.screenshot("#do", "step3");
      phantomcss.screenshot("#prove", "step4");
      phantomcss.compareAll();
    });

    // ## Know It
    casper.thenOpen(campaign.url, function() {
      test.assertNotVisible("[data-modal]", "Modals are hidden on page load.")

      this.wait(1000, function() { // let's make sure JS has loaded before clicking modal link
        casper.click(x('//*[text()="Check out our FAQs"]'));
        this.waitUntilVisible("#modal-faq", function() {
          test.assertSelectorHasText("#modal-faq", campaign.data.faq[0].header, "FAQ displays in modal on click.");
        });
      });
    });

    casper.then(function() {
      casper.click("#modal-faq .js-close-modal");
      this.waitWhileVisible("#modal-faq", function() {
        test.assert(true, "Clicking the close button hides the modal.")
      });
    });

    casper.then(function() {
      casper.click(x('//*[text()="Learn more about ' + campaign.data.issue + '"]'));
      this.waitUntilVisible("#modal-facts", function() {
        test.assertSelectorHasText("#modal-facts", campaign.data.facts[0].title, "Fact displays in modal on click.");
      });
    });
    
    // ## Do It
    // @NOTE: Can't use assertVisible() because of "visually-hidden" mixin trickiness.
    var tab1_active = "#tips-during .is-active [data-tab='1']";
    var tab2_active = "#tips-during .is-active [data-tab='2']";
    casper.then(function() {
      test.assertExists(tab1_active, "First tip is visible on page load.");
      test.assertDoesntExist(tab2_active, "Second tip is hidden on page load.");

      casper.click("#tips-during [data-tab='2']");
    });

    casper.then(function() {
      test.assertDoesntExist(tab1_active, "First tip is hidden after clicking second tip link.");
      test.assertExists(tab2_active, "Second tip is visible after clicking second tip link.");
    });

    // ## Prove It
    casper.then(function() {
      casper.click(".info-bar .help a");
      this.waitUntilVisible("#modal-contact-form", function() {
        test.assertSelectorHasText("#modal-contact-form", "Enter your question below.", "Zendesk modal displays on click.");
      });
    });

    casper.then(function() {
      casper.click("#modal-contact-form .js-close-modal");
    });

    // ## Report Back
    casper.then(function() {
      casper.click(x('//*[text()="Submit Your Pic"]'));
      this.waitUntilVisible("[data-modal]", function() {
        test.assertSelectorHasText("#modal-report-back", "Prove It", "Report Back modal displays on click.");
      });
    });

    casper.then(function() {
      this.fill("#dosomething-reportback-form", {
        "files[reportback_file]": ROOT + "/tests/fixtures/reportback-image.png",
        "quantity": "10",
        "why_participated": "Test response."
      }, true);
    });


    // Confirmation page
    casper.then(function() {
      test.assertSelectorHasText("header[role='banner'] .__title", "You did it!", "Confirmation page shown after report back.");
      test.assertSelectorHasText("header[role='banner'] .__subtitle", campaign.data.reportback_confirm_msg, "Campaign confirmation message is shown in subtitle.");

      test.assertElementCount(".gallery .gallery-item", 3, "Three suggested campaigns are shown.");
    });

    // Check that reportback submitted successfully.
    casper.thenOpen(campaign.url, function() {
      test.assertSelectorHasText("#link--report-back", "Update Submission", "Report back button changed to 'Update Submission'.");
      casper.click("#link--report-back");
      this.waitUntilVisible("[data-modal]", function() {
        test.assertExists("#modal-report-back .submitted-image img", "Submitted report back image is shown.")
        test.assertField("quantity", "10", "Submitted quantity is shown for editing.")
        test.assertField("why_participated", "Test response.", "Submitted 'Why Participated?' is shown for editing.")
      });
    });

    casper.run(function() {
      test.done();
    });
  }
});

