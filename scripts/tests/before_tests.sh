#!/bin/bash

# ==============================================================================
# BEFORE TESTS
# Tasks to run before functional testing.
# ==============================================================================

printf "\n\033[1;33mPerforming pre-test steps...\033[00m\n"

cd /var/www/vagrant/html

# Clear out localhost from flood table (prevents "more than 5 failed login attempts" error)
drush sql-query "DELETE FROM flood WHERE identifier LIKE '%127.0.0.1';"


# Create fresh test accounts
drush_create_test_user() {
  {
    USERNAME=$1
    drush user-create $USERNAME --mail="$USERNAME@example.com" --password="$USERNAME"
  } &> /dev/null
}

drush_delete_user_with_email() {
  {
    drush user-information $1 | grep "User ID" | sed -e 's/[ ]*User ID[ ]*\:[ ]*//g' | xargs -i drush user-cancel {} -y  &> /dev/null
  } &> /dev/null
}

echo "Creating fresh test accounts..."
## Delete users created during previous test runs...
drush_delete_user_with_email QA_TEST_ACCOUNT@example.com
drush_delete_user_with_email QA_TEST_USER_REGISTER@example.com
drush_delete_user_with_email QA_TEST_CAMPAIGN_SIGNUP_EXISTING@example.com 
drush_delete_user_with_email QA_TEST_CAMPAIGN_SIGNUP_NEW@example.com

## Make fresh test accounts...
drush_create_test_user QA_TEST_ACCOUNT
drush_create_test_user QA_TEST_CAMPAIGN_SIGNUP_EXISTING

