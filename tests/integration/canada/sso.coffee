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

USER_COUNTRY = 'CA'

# Generate user.
user = casper.getRandomUser()
uid = false

# ------------------------------------------------------------------------
# Test registration form

casper.test.begin "Test the registration form", 2, (test) ->

  # Launch browser on registration page.
  casper.start "#{url}/user/register"

  # Wait for user to be loaded.
  casper.waitFor userIsLoaded = -> !!user.username

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
# Test the user created

casper.test.begin "Test the registred user", 4, (test) ->
  casper.start url
  login test
  user_profile test
  casper.run -> @test.done()
  return

# ------------------------------------------------------------------------
# Test user created from new login

casper.test.begin "Test the user created from new login", 5, (test) ->
  # Test the nid is present so we can remove it.
  test.assertTruthy uid, "User id from the signup test found."

  casper.start url
  casper.then ->
    # Delete user account.
    @logAction "Remove the user to test login using remote account only:"
    @deleteUser uid

  # Check user profile.
  login test
  user_profile test
  casper.run -> @test.done()
  return

# ------------------------------------------------------------------------
# Test login form

casper.test.begin "Test that the user created can login again", 1, (test) ->
  casper.start url
  login test
  casper.then -> @logAction "Cleanup:"; @deleteUser uid
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

# Fills and submits the login form.
login = (test) ->
  # Login user.
  casper.then -> @login user.email, user.password

  # Ensure user has landed on its profile page.
  casper.then ->
    test.assertSelectorHasText "h1.__title", "Hey, #{user.first_name}",
      "Test if user is logged in."
    return
  return

# Performs 3 tests to check user's profile.
user_profile = (test) ->
  # Test user's profile.
  # Go to the edit profile page.
  # We don't know new uid yet, but user/register will redirect to the page.
  casper.thenOpen "#{url}/user/register"

  # Ensure user data is consistent with the original one.
  casper.then ->
    test.assertField FIELD_FIRST_NAME, user.first_name,
      "Test if user has correct first name."

    test.assertField FIELD_BIRTHDATE, user.dob.format("MM/DD/YYYY"),
      "Test if user has correct birthdate."

    test.assertExists "div.addressfield-container-inline.country-#{USER_COUNTRY}",
      "Test if user has correct country."

    saveUserUid()
    return

  return

# ------------------------------------------------------------------------
