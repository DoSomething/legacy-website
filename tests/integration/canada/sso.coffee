# SSO

# Sometimes SSO server response takes long.
casper.options.waitTimeout = 10000

# Generate user.
system = require 'system';
# Temporary. Will be replaced with generated user when SSO registration is ready.
user =
  email: system.env.DS_CA_USER
  password: system.env.DS_CA_PASS
uid = false

# ------------------------------------------------------------------------
# Test login form

casper.test.begin "Test that user created from SSO can login", 1, (test) ->

  # Launch browser on registration page.
  casper.start url

  # Perform the login.
  casper.then -> @login user.email, user.password

  # Go to the edit profile page.
  # We don't know new uid yet, but user/register will redirect to the page.
  casper.thenOpen "#{url}/user/register"
  casper.then ->
    saveUserUid()

    # Test the nid is present
    test.assertTruthy uid, "User is found."

  # Cleanup after success.
  casper.then ->
    @logAction "Cleanup:"
    @deleteUser uid

  # Run tests.
  casper.run -> @test.done()
  return

# ------------------------------------------------------------------------
# Utilities

# Finds user uid on the profile edit page ans saves it to global variable.
saveUserUid = ->
  uid = casper.getCurrentUrl().match(/\/user\/([0-9]+)\/edit$/)[1]

# ------------------------------------------------------------------------
