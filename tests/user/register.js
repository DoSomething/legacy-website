/**
 * register.js
 * Test that a user can create an account.
 */

casper.test.begin('Tests registration flow', 1, function suite(test) {
   casper.start(url);

   casper.thenOpen(url + '/user/register', function() {
     this.echo("Register a new user.");
     this.fill('form[id="user-register-form"]', {
       'field_first_name[und][0][value]': 'Panda',
       'field_birthdate[und][0][value][date]': '01/04/1989',
       'mail': 'testingexample@example.com',
       'pass[pass1]': 'abcdef',
       'pass[pass2]': 'abcdef',
     }, true);
   });

   casper.waitForSelector('.messages', function() {
     this.echo(this.getCurrentUrl());
     this.echo(this.fetchText('.messages'));
     test.assertSelectorHasText('.messages', 'You\'ve created an account with DoSomething.org.');
   });

  casper.logout();

  casper.run(function() {
      test.done();
  });
});
