var campaign;

casper.test.begin("Test pitch page is rendered correctly", 2, {
  /*
   * Prepare campaign from fixture.
   */
  setUp: function() {
    campaign = casper.createCampaign("campaign.json");
  },

  /*
   * Delete test nodes.
   */
  tearDown: function() {
    casper.deleteAllTestNodes();
    phantom.clearCookies();
  },

  /*
   * Test that pitch page is rendered correctly.
   */
  test: function(test) {
    casper.start(url);

    casper.thenOpen(campaign.url, function(){
      // We expect to see the title of the campaign, "Test Campaign"
      test.assertSelectorHasText("header[role='banner'].-hero .__title", campaign.data.title, "Title of campaign is printed in H1.");

      // We expect to see the subtitle for the campaign, "This is a test unsponsored campaign."
      test.assertSelectorHasText("header[role='banner'].-hero .__subtitle", campaign.data.call_to_action, "Subtitle of campaign is printed in H2.");
    });

    casper.run(function() {
      test.done();
    });
  }
});

