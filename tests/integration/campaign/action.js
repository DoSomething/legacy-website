/**
 * action.js
 * Test action page is rendered correctly
 */

var x = require('casper').selectXPath;
var user;

casper.test.begin("Test action page is rendered and functions correctly", {
  /*
   * Prepare CAMPAIGN from fixture.
   */
  setUp: function() {
    user = casper.createTestUser();
    casper.campaignSignup(CAMPAIGN.nid, user.uid);
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
    
    // ## Header 
    casper.thenOpenWhenReady(CAMPAIGN.url, function() {
      // We expect to see the title and subtitle of the CAMPAIGN
      test.assertSelectorHasText("header[role='banner'].-hero .header__title", CAMPAIGN.data.title, "Title of campaign is printed in H1.");
      test.assertSelectorHasText("header[role='banner'].-hero .header__subtitle", CAMPAIGN.data.call_to_action, "Subtitle of campaign is printed in H2.");
    });

    // ## Content
    casper.then(function() {
      test.assertSelectorHasText("#know .heading.-banner", "Step 1: Know It", "\"Know It\" banner exists.");
      test.assertSelectorHasText("#plan .heading.-banner", "Step 2: Plan It", "\"Plan It\" banner exists.");
      test.assertSelectorHasText("#do .heading.-banner", "Step 3: Do It", "\"Do It\" banner exists.");
      test.assertSelectorHasText("#prove .heading.-banner", "Step 4: Prove It", "\"Prove It\" banner exists.");
    });

    // ## Visual tests
    casper.then(function() {
      phantomcss.screenshot("#know", "step1");
      phantomcss.screenshot("#plan", "step2");
      phantomcss.screenshot("#do", "step3");

      phantomcss.compareExplicit([
        ROOT + '/tests/visual/step1.diff.png',
        ROOT + '/tests/visual/step2.diff.png',
        ROOT + '/tests/visual/step3.diff.png',
      ]);
    });

    // ## Know It
    casper.thenOpenWhenReady(CAMPAIGN.url, function() {
      test.assertNotVisible("[data-modal]", "Modals are hidden on page load.");

      this.click(x('//*[text()="Check out our FAQs"]'));

      this.waitUntilVisible("#modal-faq", function() {
        test.assertSelectorHasText("#modal-faq", CAMPAIGN.data.faq[0].header, "FAQ displays in modal on click.");
      });
    });

    casper.then(function() {
      this.click("#modal-faq .js-close-modal");

      this.waitWhileVisible("#modal-faq", function() {
        test.assert(true, "Clicking the close button hides the FAQ modal.")
      });
    });

    casper.then(function() {
      this.click(x('//*[text()="Learn more about ' + CAMPAIGN.data.issue + '"]'));
      
      this.waitUntilVisible("#modal-facts", function() {
        test.assertSelectorHasText("#modal-facts", CAMPAIGN.data.facts[0].title, "Fact displays in modal on click.");
      });
    });

    casper.then(function() {
      this.click("#modal-facts .js-close-modal");

      this.waitWhileVisible("#modal-facts", function() {
        test.assert(true, "Clicking the close button hides the Fact modal.")
      });
    });
    
    // ## Do It
    // @NOTE: Can't use assertVisible() because of "visually-hidden" mixin trickiness.
    var tab1_active = "#tips-during .is-active [data-tab='1']";
    var tab2_active = "#tips-during .is-active [data-tab='2']";
    casper.then(function() {
      test.assertExists(tab1_active, "First tip is visible on page load.");
      test.assertDoesntExist(tab2_active, "Second tip is hidden on page load.");

      this.click("#tips-during [data-tab='2']");
    });

    casper.then(function() {
      test.assertDoesntExist(tab1_active, "First tip is hidden after clicking second tip link.");
      test.assertExists(tab2_active, "Second tip is visible after clicking second tip link.");
    });

    // ## Prove It
    casper.then(function() {
      casper.click(".info-bar .info-bar__secondary a");
      this.waitUntilVisible("#modal-contact-form", function() {
        test.assertSelectorHasText("#modal-contact-form", "Enter your question below.", "Zendesk modal displays on click.");
      });
    });

    casper.then(function() {
      casper.click("#modal-contact-form .js-close-modal");

      this.waitWhileVisible("#modal-contact-form", function() {
        test.assert(true, "Clicking the close button hides the Contact Form modal.")
      });
    });

    // @TODO Update reportback tests for Reportbacks v2!

    casper.run(function() {
      test.done();
    });
  }
});

