/**
 * login.js
 * Test that a user can authenticate correctly.
 */


casper.test.begin('Tests login flow', 5, function suite(test) {
   casper.start(url, function() {
    test.assertTitle("DoSomething.org | Largest organization for teens and social cause", "Dosomething.org homepage title is the one expected");
    test.assertExists('#modal--login', 'login link is there');

   });

   // Let's try a fake address first.
   casper.thenOpen(url + '/user', function() {
     this.echo("Try a fake email/password combo.");
     this.fill('form[action="/user/login"]', {
       name: 'test@example.com',
       pass: 'zzzzz'
     }, true);
   });

   casper.waitForSelector('.messages', function() {
     test.assertExists('div.error', 'Error message appears on screen');
     this.echo(this.fetchText('.messages'));
   })

   casper.login();

   casper.then(function() {
     test.assertExists('.profile--campaigns', 'Has a user profile');
     test.assertDoesntExist('#modal--login', '"Login" link is not found.');
   });

  casper.logout();

  casper.run(function() {
      test.done();
  });
});
