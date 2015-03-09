casper.test.begin("Test pitch page is rendered correctly", 2, {
  /*
   * Prepare campaign from fixture.
   */
  setUp: function() {

  },

  /*
   * Delete test nodes.
   */
  tearDown: function() {
    // ...
    phantom.clearCookies();
  },

  /*
   * Test that pitch page is rendered correctly.
   */
  test: function(test) {
    casper.start(CAMPAIGN.url);
    
    casper.thenWhenReady(function(){
      // We expect to see the title of the campaign, "Test Campaign"
      test.assertSelectorHasText("header[role='banner'].-hero .header__title", CAMPAIGN.data.title, "Title of campaign is printed in H1.");

      // We expect to see the subtitle for the campaign, "This is a test unsponsored campaign."
      test.assertSelectorHasText("header[role='banner'].-hero .header__subtitle", CAMPAIGN.data.call_to_action, "Subtitle of campaign is printed in H2.");
    });

    casper.run(function() {
      test.done();
    });
  }
});

