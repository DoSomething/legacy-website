#!/bin/bash

# ==============================================================================
# BEFORE TESTS
# Tasks to run before functional testing.
# ==============================================================================

cd /var/www/vagrant/html

# Clear out localhost from flood table (prevents "more than 5 failed login attempts" error)
drush sql-query "DELETE FROM flood WHERE identifier LIKE '%127.0.0.1';"

# Get test user account UID...
uid=$( drush user-information QA_TEST_ACCOUNT@example.com | grep "User ID" | sed -e 's/[ ]*User ID[ ]*\:[ ]*//g' )

# Remove all campaign signups for test account
drush sql-query "DELETE FROM dosomething_signup WHERE uid='$uid';"

