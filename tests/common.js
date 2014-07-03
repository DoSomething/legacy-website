/**
 * Helper methods and variables for capser test suite.
 */

// Define the url for all tests.
var url = casper.cli.get('url');


casper.login = function() {
casper.thenOpen(url + '/user', function() {
    this.echo("Log a real user in.");
    this.fill('form[action="/user/login"]', {
      name: 'test@example.com',
      pass: 'tester'
    }, true);
 });
}

casper.logout = function() {
  casper.open(url + '/user/logout', function(){
    this.echo('Logout');
  });
}
