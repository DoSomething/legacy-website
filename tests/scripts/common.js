/**
 * Helper methods and variables for capser test suite.
 */

var pwd = require('system').env['PWD'];
var ROOT = pwd;

// Define the url for all tests.
var url = casper.cli.get('url');
var campaign_nid = casper.cli.get('campaign_nid');
var campaign_url = url + '/node/' + campaign_nid;

var phantomcss = require(ROOT + '/node_modules/phantomcss/phantomcss');

function formattedFilename(test) {
  return test.filename.replace(ROOT + "/tests/visual/", "").replace(".png", "");
}

phantomcss.init({
  libraryRoot: ROOT + '/node_modules/phantomcss',
  screenshotRoot: ROOT + '/tests/visual',
  failedComparisonsRoot: ROOT + '/tests/visual/failures',
  addLabelToFailedImage: false,
  mismatchTolerance: 2.00,
  onPass: function(test) {
    casper.test.pass('No changes found for visual regression test "' + formattedFilename(test) + '".');
  },
  onFail: function(test) {
    casper.test.fail('Visual change found in "' + formattedFilename(test) + '" (' + test.mismatch + '% mismatch)');
  },
  onNewImage: function(test) {
    casper.test.info('New baseline screenshot generated at "'+ formattedFilename(test) + '".');
  },
  onComplete: function(tests, noOfFails, noOfErrors) {
    if( tests.length === 0){
      casper.test.info("No tests run.");
    } else {
      if(noOfFails !== 0) {
        casper.test.info("Visual diffs generated in 'tests/visual/failures' for failing tests.");
        casper.test.info("If changes are expected, replace testName.png with testName.fail.png to \"merge\" the changes so that future tests pass, and commit the updated test image.");
      }
    }
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
  outputSettings: {
    errorColor: {
      red: 255,
      green: 0,
      blue: 255
    },
    errorType: 'movement',
    transparency: 0.3,
    largeImageThreshold: 1440
  }
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

  casper.then(function() {
    if(casper.exists(".messages.error")) {
      casper.log(this.getElementInfo(".messages.error").text, "warning");
    }
  })
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
