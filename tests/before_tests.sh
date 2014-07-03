#!/bin/bash

# ==============================================================================
# BEFORE TESTS
# Tasks to run before functional testing.
# ==============================================================================

cd /var/www/vagrant/html

# Clear out localhost from flood table (prevents "more than 5 failed login attempts" error)
drush sql-query "DELETE FROM flood WHERE identifier LIKE '%127.0.0.1';"

