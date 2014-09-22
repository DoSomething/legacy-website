# SSO

# Sometimes SSO server response takes long.
casper.options.waitTimeout = 10000

# Constants.
AGE_TOO_OLD = 25

# Form selectors.
FORM = '#user-register-form'
FIELD_MAIL       = 'mail'
FIELD_PASS       = 'pass[pass1]'
FIELD_PASS_2     = 'pass[pass2]'
FIELD_FIRST_NAME = 'field_first_name[und][0][value]'
FIELD_LAST_NAME  = 'field_last_name[und][0][value]'
FIELD_BIRTHDATE  = 'field_birthdate[und][0][value][date]'
FIELD_POSTCODE   = 'field_address[und][0][postal_code]'

# Generate user.
user = casper.getRandomUser()
uid = false

# ------------------------------------------------------------------------
# Test registration form

casper.test.begin "Test that registration form is integrated with SSO", 3, (test) ->

  # Launch browser on registration page.
  casper.start "#{url}/user/register"

  # Ensure registration form.
  casper.then -> test.assertExists FORM, 'Registration form found.'

  # Check remote validation by providing user with date out of range.
  casper.then -> growOld user; fillSignupForm user
  casper.thenClick '#edit-submit'

  # Ensure error message is generated.
  casper.waitForSelector '.error', ->
    test.assertSelectorHasText '.error',
      "You're too old for us now",
      'SSO validates data remotely, user can see validation error messages.'
    return

  # Submit valid registration form.
  casper.then -> rejuvenate user; fillSignupForm user
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
# Test user created from SSO

casper.test.begin "Test that user created from SSO has correct data", 6, (test) ->

  # Launch browser on registration page.
  casper.start url

  # Test the nid is present
  test.assertTruthy uid, "User id from the signup test found."

  # Delete user account.
  casper.then ->
    @logAction "Remove the user to test login using remote account only:"
    @deleteUser uid

  # Perform the login.
  login test

  # Go to the edit profile page.
  # We don't know new uid yet, but user/register will redirect to the page.
  casper.thenOpen "#{url}/user/register"

  # Ensure user data is consistent with the original one.
  casper.then ->
    test.assertField FIELD_FIRST_NAME, user.first_name,
      "Test if user has correct first name."

    test.assertField FIELD_LAST_NAME, user.last_name,
      "Test if user has correct last name."

    test.assertField FIELD_BIRTHDATE, user.dob.format("DD/MM/YYYY"),
      "Test if user has correct birthdate."

    test.assertField FIELD_POSTCODE, user.postcode,
      "Test if user has correct postcode."

    saveUserUid()
    return

  # Run tests.
  casper.run -> @test.done()
  return


# ------------------------------------------------------------------------
# Test login form

casper.test.begin "Test that user created from SSO can login", 1, (test) ->

  # Launch browser on registration page.
  casper.start url

  # Perform the login.
  login test

  # Cleanup after success.
  casper.then ->
    @logAction "Cleanup after full success:"
    @deleteUser uid

  # Run tests.
  casper.run -> @test.done()
  return

# ------------------------------------------------------------------------
# Utilities

fillSignupForm = (user) ->
  # Override generated postcode with British.
  user.postcode = "CF10 5AN"

  # Prepare user data.
  data = {}
  data[FIELD_MAIL]       = user.email
  data[FIELD_PASS]       = user.password
  data[FIELD_PASS_2]     = user.password
  data[FIELD_FIRST_NAME] = user.first_name
  data[FIELD_LAST_NAME]  = user.last_name
  data[FIELD_BIRTHDATE]  = user.dob.format "DD/MM/YYYY"
  data[FIELD_POSTCODE]   = user.postcode

  # Fill in the registration form.
  casper.fill FORM, data
  return

# Sets user's birthrate within validation range.
rejuvenate = (user) ->
  user.dob.year moment().subtract(AGE_TOO_OLD - 5, 'years').year()

# Sets user birthrate greater than SSO accepts.
growOld = (user) ->
  user.dob.year moment().subtract(AGE_TOO_OLD + 10, 'years').year()

# Finds user uid on the profile edit page ans saves it to global variable.
saveUserUid = ->
  uid = casper.getCurrentUrl().match(/\/user\/([0-9]+)\/edit$/)[1]

# Finds user uid on the profile edit page ans saves it to global variable.
login = (test) ->

  # Login user.
  casper.then -> @login user.email, user.password

  # Ensure user has landed on its profile page.
  casper.then ->
    test.assertSelectorHasText "h1.__title", "Hey, #{user.first_name}",
      "Test if user is logged in."
  return


# ------------------------------------------------------------------------
