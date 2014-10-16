# Drupal

# ------------------------------------------------------------------------
# Test Drupal configuration

casper.test.begin "Test that Drupal configure for the Canada SSO correctly", 3, (test) ->

  # OAuth Base URL.
  result = casper.drush ["vget", "dosomething_canada_sso_url"]
  test.assertTruthy result, 'OAuth Base URL setting present.'

  # OAuth App ID.
  result = casper.drush ["vget", "dosomething_canada_sso_appid"]
  test.assertTruthy result, 'OAuth App ID setting present.'

  # OAuth Key.
  result = casper.drush ["vget", "dosomething_canada_sso_key"]
  test.assertTruthy result, 'OAuth Key setting present.'

  test.done()
  return

# ------------------------------------------------------------------------
