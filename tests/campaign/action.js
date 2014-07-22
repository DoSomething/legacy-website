/**
 * action.js
 * Test action page is rendered correctly
 */

var x = require('casper').selectXPath;


casper.test.begin("Test action page is rendered correctly", function suite(test) {
  casper.login("QA_TEST_CAMPAIGN_ACTION@example.com", "QA_TEST_CAMPAIGN_ACTION");
  
  // ## Header 
  casper.thenOpen(url + "/campaigns/test-campaign", function() {
    // We expect to see the title and subtitle of the campaign
    test.assertSelectorHasText("header[role='banner'].-hero .__title", "Test Campaign", "Title of campaign is printed in H1.");
    test.assertSelectorHasText("header[role='banner'].-hero .__subtitle", "This is a test unsponsored campaign.", "Subtitle of campaign is printed in H2.");

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

  casper.run(function() {
    test.done();
  })
});


casper.test.begin("Test action page functions correctly", function suite(test) {
  casper.login("QA_TEST_CAMPAIGN_ACTION@example.com", "QA_TEST_CAMPAIGN_ACTION");

  // ## Know It
  casper.thenOpen(url + "/campaigns/test-campaign", function() {
    test.assertNotVisible("[data-modal]", "Modals are hidden on page load.")

    this.wait(1000, function() { // let's make sure JS has loaded before clicking modal link
      casper.click(x('//*[text()="Check out our FAQs"]'));
      this.waitUntilVisible("#modal-faq", function() {
        test.assertSelectorHasText("#modal-faq", "Why is 'fee awesome?", "FAQ modal displays on click.");
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
    casper.click(x('//*[text()="Learn more about Coffee"]'));
    this.waitUntilVisible("#modal-facts", function() {
      test.assertSelectorHasText("#modal-facts", "1 in 3 teenagers have slept through math", "Fact modal displays on click.");
    });
  });

  // ## Do It
  casper.then(function() {
    // @NOTE: Can't use assertVisible() because of "visually-hidden" mixin trickiness.
    test.assertExists("#tip-1.is-active", "First tip is visible on page load.");
    test.assertDoesntExist("#tip-2.is-active", "Second tip is hidden on page load.");

    casper.click(x('//*[text()="Give Him \'Fee"]'));

    test.assertDoesntExist("#tip-1.is-active", "First tip is hidden after clicking second tip link.");
    test.assertExists("#tip-2.is-active", "Second tip is visible after clicking second tip link.");
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
    this.fill("form[action='/campaigns/test-campaign']", {
      "files[reportback_file]": "tests/fixtures/reportback-image.png",
      "quantity": "10",
      "why_participated": "Test response."
    }, true);
  });


  // Confirmation page
  casper.then(function() {
    test.assertSelectorHasText("header[role='banner'] .__title", "You did it!", "Confirmation page shown after report back.");
    test.assertSelectorHasText("header[role='banner'] .__subtitle", "You sure drank that 'fee. Good work!", "Campaign confirmation message is shown in subtitle.");

    test.assertElementCount(".gallery .gallery-item", 3, "Three suggested campaigns are shown.");

    casper.click(x('//*[text()="Back to Test Campaign"]'));
  });

  // Check that reportback submitted successfully.
  casper.then(function() {
    casper.click(x('//*[text()="Update Submission"]'));
    this.waitUntilVisible("[data-modal]", function() {
      test.assertExists("#modal-report-back .submitted-image img", "Submitted report back image is shown.")
      test.assertField("quantity", "10", "Submitted quantity is shown for editing.")
      test.assertField("why_participated", "Test response.", "Submitted 'Why Participated?' is shown for editing.")
    });
  });

  casper.run(function() {
    test.done();
  });
});

