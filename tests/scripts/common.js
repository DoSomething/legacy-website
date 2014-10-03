/**
 * @file
 * Helper methods and default settings for CasperJS test suites.
 */

/**
 * Log an action to the Casper console output.
 * @param {string} action - Action to be logged. Use present-tense.
 */
casper.logAction = function(action) {
  casper.echo(action, "PARAMETER");
}

/**
 * Wait until JavaScript is finished executing and page is ready.
 * @param {function} callback - Code to execute after page is ready
 */
casper.thenWhenReady = function(fn) {
    casper.then(function() {;
      this.waitUntilVisible("html.js-ready");
    });
    
    casper.then(fn);
};

/**
 * Wait until JavaScript is finished executing and page is ready.
 * @param {function} callback - Code to execute after page is ready
 */
casper.thenOpenWhenReady = function(url, fn) {
  casper.thenOpen(url);
  casper.thenWhenReady(fn);
};


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


/**
 * Generate a randomized fake email.
 */
casper.randomEmail = function() {
  return Date.now() + "@example.com";
};

/**
 * Generate a randomized 8-character password string.
 */
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
 * @param {string} email - Email to create user with
 * @param {string} password - Password for user account
 */
casper.createUser = function(email, password) {
  casper.logAction("Creating user with email '" + email + "' and password '" + password + "'...");
  casper.drush(['user-create', 'CASPER_USER', '--mail=' + email, '--password=' + password]);
  return casper.getUserWithEmail(email, password);
};

/**
 * Get information for user with a given email.
 * @param {string} user - Email address to retrieve account info for.
 * @param {string} [password] - Optionally, include this unhashed password in user object.
 */
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

/**
 * Delete the user with a given email.
 * @param {string} email - Email address associated with user account
 */
casper.deleteUserWithEmail = function(email) {
  casper.logAction("Deleting user with email '" + email + "'...");
  var user = casper.getUserWithEmail(email);
  if(user) {
    casper.deleteUser(user.uid);
  } else {
    casper.logAction("Skipping delete...");
  }
};

/**
 * Delete the user with a given ID.
 * @param {int} uid - User ID
 */
casper.deleteUser = function(uid) {
  casper.logAction("Deleting user '" + uid + "'...");
  casper.drush(["user-cancel", uid, "-y"]);
};

/**
 * Directly sign a user up for a given campaign.
 * @param {int} nid - Node ID of the campaign
 * @param {int} uid - User ID of the user
 */
casper.campaignSignup = function(nid, uid) {
  casper.logAction("Signing user '" + uid + "' up for campaign '" + nid + "'...");
  casper.drush(["php-eval", "dosomething_signup_create(" + nid + ", " + uid + ");"]);
};

/**
 * Log in a user with the given username and password
 */
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
  });
}

/**
 * Log the current user out of the site.
 */
casper.logout = function() {
  casper.logAction("Logging out of current user...");

  casper.thenOpen(url + "/user/logout", function() {
    if(casper.exists(".messages.error")) {
      casper.log(this.getElementInfo(".messages.error").text, "warning");
    }
  });
}

/**
 * Capture a screenshot with timestamp to tmp directory.
 * @param {string} label - Label appended to end of filename.
 */
casper.timestampCapture = function(label) {
  label = (typeof label === "string" ? label : "");

  var timestamp = new Date().getTime();
  var filename = timestamp + "-" + label + ".png";
  casper.echo("Captured screenshot to `tmp/tests/screenshots/" + filename + "`.", "PARAMETER");
  try {
    casper.capture(ROOT + "/tmp/tests/screenshots/" + filename);
  } catch (e) {
    casper.echo('Error saving screenshot.', 'ERROR');
  }
}

/**
 * Configure default CasperJS options.
 */

// Take a screenshot when a test fails
casper.test.on("fail", function(failure) {
  casper.timestampCapture("fail");
});

// Output JavaScript errors to CasperJS log.
casper.on("page.error", function(msg, stack) {
  casper.echo("Page Error: " + msg, "ERROR");
  stack.forEach(function(trace) {
    var line = trace.file + ": Line " + trace.line + " ( " + trace.function + ")";
    casper.echo(line, "WARNING");
  });
});

// Set default viewport for all tests.
casper.options.viewportSize = { width: 1280, height: 1024 };

// Increase default timeout from 5s to 10s.
casper.options.waitTimeout = 10000;

// We want to clear session after every test.
// @NOTE: You'll have to do this manually if you override the tearDown
//        method on a particular test.
casper.test.tearDown(function() {
  phantom.clearCookies();
})

