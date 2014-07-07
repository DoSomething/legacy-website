#!/bin/bash

# ==============================================================================
# AFTER TESTS
# Tasks to run after functional testing has completed.
# ==============================================================================

echo "Performing post-test cleanup:"

cd /var/www/vagrant/html

# Delete test user account created in `user/register.js`
echo "Deleting QA_TEST_REGISTER account if it exists..."
{
  drush user-information QA_TEST_REGISTER@example.com | grep "User ID" | sed -e 's/[ ]*User ID[ ]*\:[ ]*//g' | xargs -i drush user-cancel {} -y
} &> /dev/null

printf "\xE2\x9C\x94\xEF\xB8\x8E Done!\n"
