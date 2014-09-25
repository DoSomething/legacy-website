/**
 * Helper methods and variables for capser test suite.
 */

/**
 * Log an action to the Casper console output.
 */
casper.logAction = function(action) {
  casper.echo(action, "PARAMETER");
}

/**
 * Remove test IPs from flood table (preventing tests from failing after repeated failed logins).
 */
casper.clearFloodTable = function() {
  casper.logAction("Removing localhost entries from flood table...")
  
  // Remove failed login attempts from localhost (tests on Vagrant boxes).
  casper.drush(["sql-query", "DELETE FROM flood WHERE identifier LIKE '%127.0.0.1';"]);

  // Remove failed login attempts from QA server IP address.
  casper.drush(["sql-query", "DELETE FROM flood WHERE identifier LIKE '%192.168.1.161';"]);
};

casper.randomEmail = function() {
  return Date.now() + "@example.com";
};

casper.randomPassword = function() {
  return Math.random().toString(36).slice(-8);
};

/**
 * Generate a user with a random email and password.
 */
casper.createTestUser = function() {
  var email = casper.randomEmail();
  var password = casper.randomPassword();
  return casper.createUser(email, password);
};

/**
 * Create a user with the given email and password.
 */
casper.createUser = function(email, password) {
  casper.logAction("Creating user with email '" + email + "' and password '" + password + "'...");
  casper.drush(['user-create', 'CASPER_USER', '--mail=' + email, '--password=' + password]);
  return casper.getUserWithEmail(email, password);
};

casper.getUserWithEmail = function(email, password) {
  casper.logAction("Getting user information for '" + email + "'...");
  var info = casper.drush(['user-information', email], true);

  if(info) {
    var userKeys = Object.keys(info);

    var response = {
      uid: info[userKeys[0]].uid,
      username: info[userKeys[0]].name,
      email: info[userKeys[0]].mail,
    }

    if(password) {
      response.password = password;
    }

    return response;
  } 


  // If `info` is not defined, user didn't exist.
  casper.echo("User with email '" + email + "' does not exist.", "WARNING");
  return false;
};

casper.deleteUserWithEmail = function(email) {
  casper.logAction("Deleting user with email '" + email + "'...");
  var user = casper.getUserWithEmail(email);
  if(user) {
    casper.deleteUser(user.uid);
  } else {
    casper.logAction("Skipping delete...");
  }
};

casper.deleteUser = function(uid) {
  casper.logAction("Deleting user '" + uid + "'...");
  casper.drush(["user-cancel", uid, "-y"]);
};

casper.createCampaign = function(fixture) {
  casper.logAction("Creating campaign from fixture '" + fixture + "'...");
  var drush_campaign = casper.drush(["campaign-create", "../tests/fixtures/" + fixture]);
  var nid = drush_campaign.replace(/[^0-9]/g, "");

  var data = require(ROOT + "/tests/fixtures/" + fixture);

  return {
    nid: nid,
    url: url + "/node/" + nid,
    data: data
  };
};


casper.deleteAllTestNodes = function(fixture) {
  casper.logAction("Clearing all test nodes...");
  casper.drush(["test-node-delete"]);
};

casper.campaignSignup = function(nid, uid) {
  casper.logAction("Signing user '" + uid + "' up for campaign '" + nid + "'...");
  casper.drush(["php-eval", "dosomething_signup_create(" + nid + ", " + uid + ");"]);
};

// Use to log in before performing a test.
casper.login = function(username, password) {
  casper.logAction("Logging in as '" + username + "'...");

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
  casper.logAction("Logging out of current user...");

  casper.thenOpen(url + "/user/logout", function() {
    if(casper.exists(".messages.error")) {
      casper.log(this.getElementInfo(".messages.error").text, "warning");
    }
  });
}

// Capture a screenshot with timestamp to tmp directory.
casper.timestampCapture = function(label) {
  label = (typeof label === "string" ? label : "");

  var timestamp = new Date().getTime();
  var filename = timestamp + "-" + label + ".png";
  casper.echo("Captured screenshot to `tmp/tests/screenshots/" + filename + "`.", "PARAMETER");
  casper.capture(ROOT + "/tmp/tests/screenshots/" + filename);
}

// Take a screenshot when a test fails
casper.test.on("fail", function(failure) {
  casper.timestampCapture("fail");
});

// We want to clear session after every test.
// @NOTE: You'll have to do this manually if you override the tearDown
//        method on a particular test.
casper.test.tearDown(function() {
  phantom.clearCookies();
})

