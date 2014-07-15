/**
 * Helper methods and variables for capser test suite.
 */

// Define the url for all tests.
var url = casper.cli.get('url');

// Set default viewport for all tests.
casper.options.viewportSize = { width: 1280, height: 1024 };

// Use to log in before performing a test.
casper.login = function(username, password) {
  // If no arguments are given, log in using default test account
  username = typeof username == "string" ? username : "QA_TEST_ACCOUNT@example.com";
  password = typeof password == "string" ? password : "QA_TEST_ACCOUNT";

  this.echo("Logging in as: " + username);

  // Go home and login.
  casper.thenOpen(url + "/user", function() {
    this.fill('form[action="/user/login"]', {
      name: username,
      pass: password
    }, true);
  });
}

// Use to log out after completing a test.
casper.logout = function() {
  // Go home and click the "Log Out" button
  casper.thenOpen(url + "/user/logout", function() {
    this.echo("Logging out of test user.");
  });
}

// We want to clear session after every test.
casper.test.tearDown(function() {
  phantom.clearCookies();
})
