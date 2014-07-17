/**
 * Helper methods and variables for capser test suite.
 */

var ROOT = '/var/www/vagrant/';

// Define the url for all tests.
var url = casper.cli.get('url');
var phantomcss = require(ROOT + 'scripts/tests/vendor/phantomcss');
phantomcss.init({
  onPass: function(test) {
    casper.test.pass('No changes found for visual regression test "' + test.filename + '".');
  },
  onFail: function(test) {
    casper.test.fail('Visual change found in "' + test.filename + '" (' + test.mismatch + '% mismatch)');
  },
  onNewImage: function(test) {
    casper.test.info('New baseline screenshot generated at "'+ test.filename + '".');
  },
  fileNameGetter: function(root,filename){ 
    var expected = root + fs.separator + filename + '.png';
    var diff = root + fs.separator + filename + '.diff.png';
    if(fs.isFile(expected)){
      return diff;
    } else {
      return expected;
    }
  },

});

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

// We want to start at the homepage on each test.
casper.test.setUp(function() {
  casper.start(url);
});

// We want to clear session after every test.
casper.test.tearDown(function() {
  phantom.clearCookies();
})
