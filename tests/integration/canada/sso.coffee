# SSO

# Sometimes SSO server response takes long.
casper.options.waitTimeout = 10000

# Form selectors.
FORM = '#user-register-form'
FIELD_MAIL       = 'mail'
FIELD_PASS       = 'pass[pass1]'
FIELD_PASS_2     = 'pass[pass2]'
FIELD_FIRST_NAME = 'field_first_name[und][0][value]'
FIELD_BIRTHDATE  = 'field_birthdate[und][0][value][date]'

# Generate user.
user = casper.getRandomUser()
uid = false

# ------------------------------------------------------------------------
# Test registration form

casper.test.begin "Test that registration form is integrated with SSO", 2, (test) ->

  # Launch browser on registration page.
  casper.start "#{url}/user/register"

  # Ensure registration form.
  casper.then -> test.assertExists FORM, 'Registration form found.'

  # Submit valid registration form.
  casper.then -> fillSignupForm user
  casper.thenClick '#edit-submit'

  # Check whether the registration is successful.
  assert_message = 'User is registered can see own profile.'
  casper.waitForUrl /\/user\/[0-9]+\/edit$/,
    ->
      # Success.
      test.assertExists '.status', assert_message
      saveUserUid()
    ->
      @echo 'Registration form errors:', 'ERROR'
      @echo @fetchText('.error').trim(), 'WARNING'
      test.assert false, assert_message

  # Run tests.
  casper.run -> @test.done()
  return

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
  casper.then -> saveUserUid()

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

fillSignupForm = (user) ->
  # Prepare user data.
  data = {}
  data[FIELD_MAIL]       = user.email
  data[FIELD_PASS]       = user.password
  data[FIELD_PASS_2]     = user.password
  data[FIELD_FIRST_NAME] = user.first_name
  data[FIELD_BIRTHDATE]  = user.dob.format "MM/DD/YYYY"

  # Fill in the registration form.
  casper.fill FORM, data
  return

# Finds user uid on the profile edit page ans saves it to global variable.
saveUserUid = ->
  uid = casper.getCurrentUrl().match(/\/user\/([0-9]+)\/edit$/)[1]

# ------------------------------------------------------------------------
