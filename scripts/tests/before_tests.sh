#!/bin/bash

# ==============================================================================
# BEFORE TESTS
# Tasks to run before functional testing.
# ==============================================================================

printf "\n\033[1;33mPerforming pre-test steps...\033[00m\n"

cd /var/www/vagrant/html

# Clear out localhost from flood table (prevents "more than 5 failed login attempts" error)
drush sql-query "DELETE FROM flood WHERE identifier LIKE '%127.0.0.1';"


# Delete test user account created in `user/register.js`
echo "Creating fresh test accounts..."
{
  ## Delete users created during previous test runs...
  drush user-information QA_TEST_ACCOUNT@example.com | grep "User ID" | sed -e 's/[ ]*User ID[ ]*\:[ ]*//g' | xargs -i drush user-cancel {} -y
  drush user-information QA_TEST_USER_REGISTER@example.com | grep "User ID" | sed -e 's/[ ]*User ID[ ]*\:[ ]*//g' | xargs -i drush user-cancel {} -y
  drush user-information QA_TEST_CAMPAIGN_SIGNUP_EXISTING@example.com | grep "User ID" | sed -e 's/[ ]*User ID[ ]*\:[ ]*//g' | xargs -i drush user-cancel {} -y
  drush user-information QA_TEST_CAMPAIGN_SIGNUP_NEW@example.com | grep "User ID" | sed -e 's/[ ]*User ID[ ]*\:[ ]*//g' | xargs -i drush user-cancel {} -y

  ## Make fresh test accounts...
  drush user-create qa_test_account --mail=QA_TEST_ACCOUNT@example.com --password=QA_TEST_ACCOUNT
  drush user-create qa_test_signup_existing --mail=QA_TEST_CAMPAIGN_SIGNUP_EXISTING@example.com --password=QA_TEST_CAMPAIGN_SIGNUP_EXISTING
} &> /dev/null

