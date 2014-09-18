# Drupal

# ------------------------------------------------------------------------
# Test Drupal configuration

casper.test.begin "Test that Drupal configure for the UK correctly", 4, (test) ->

  # OAuth Base URL.
  result = casper.drush ["vget", "dosomething_uk_oauth_url"]
  test.assertTruthy result, 'OAuth Base URL setting present.'

  # OAuth Key.
  result = casper.drush ["vget", "dosomething_uk_oauth_key"]
  test.assertTruthy result, 'OAuth Key setting present.'

  # OAuth Secret.
  result = casper.drush ["vget", "dosomething_uk_oauth_secret"]
  test.assertTruthy result, 'OAuth Secret setting present.'

  # OAuth Secret.
  result = casper.drush ["vget", "date_format_short"]
  test.assertEquals result,
    """date_format_short: 'd/m/Y - H:i'\n""",
    'Date format is d/m/Y.'

  test.done()
  return

# ------------------------------------------------------------------------
