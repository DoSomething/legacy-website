/**
 * login.js
 * Test that a user can authenticate correctly.
 */

casper.test.begin('Test that a user can authenticate correctly.', 5, function suite(test) {
  casper.start(url, function() {
    // We reference the login link's ID to avoid a crazy selector.
    test.assertExists("#link--login", "Login link exists on page for anonymous user");
  });

  casper.then(function() {
    // Click the login link in the header navigation menu.
    this.click("#link--login");

    // We should see a modal with the login form.
    this.waitUntilVisible("[data-modal]", function() {
      test.assertExists("[data-modal] form[action='/user/login']", "Clicking the login link shows modal login form");
    });
  });

  casper.then(function() {
    // Fill and submit bogus login credentials:
    this.fill('form[action="/user/login"]', {
      name: 'test@example.com',
      pass: 'zzzzz'
    }, true);

    // We should get a specific error message.
    casper.waitForSelector('.messages', function() {
      test.assertSelectorHasText("div.error", "unrecognized username or password", "Error message appears after submitting invalid credentials");
    });
  });

  casper.thenOpen(url, function() {
    // Now let's go back home and login using the login modal.
    this.waitUntilVisible("#link--login", function() {
      this.click("#link--login");
    });
    
    // We should see a modal with the login form.
    this.waitUntilVisible("[data-modal]", function() {
      this.fill('form[action="/user/login"]', {
        name: 'QA_TEST_ACCOUNT@example.com',
        pass: 'QA_TEST_ACCOUNT'
      }, true);
    });

    this.waitUntilVisible("#link--logout", function() {
      test.assertExists("#link--logout", "Logout link is shown for logged in users");
    });
  });

  casper.thenOpen(url, function() {
    // Let's log out using the logout button.
    this.click("#link--logout");
    
    this.waitUntilVisible("#link--login", function() {
      test.assertExists("#link--login", "Login link is shown again after logging out");
    });
  });

  casper.run(function() {
    test.done();
  });
});
