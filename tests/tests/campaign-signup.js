/**
 * signup.js
 * Test that a user signup for a campaign.
 */



casper.test.begin('Tests campaign signup flow', 3, function suite(test) {
   casper.start(url);
   casper.login();
   casper.thenOpen(url, function(){
     // Is the finder resturning results.
     test.assertExists('.finder--results');
     casper.waitForSelector('.campaign-result', function() {

       test.assertExists('.campaign-result');
       // Get the first finder result.
       var campaign = this.getElementAttribute('.campaign-result a', 'href');


      casper.thenOpen(url + '/' + campaign, function() {
        // What campaign are we signing up for?
        this.echo(this.getTitle());
        casper.waitForSelector('.pitch', function() {

          // Now click signup button.
          this.click('form#dosomething-signup-form input[type="submit"]');
        });

      });
    });
  });

  // Make sure the signup happened.
  casper.waitForSelector('.messages', function() {
    test.assertSelectorHasText('.messages', 'You\'re signed up for', 'Signed up for a campaign');
  });

  casper.logout();

  casper.run(function() {
      test.done();
  });
});
