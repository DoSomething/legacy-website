#!/bin/bash

# ==============================================================================
# AFTER TESTS
# Tasks to run after functional testing has completed.
# ==============================================================================

printf "\n\033[1;33mPerforming post-test cleanup...\033[00m\n"

cd /var/www/vagrant/html

echo "Deleting test nodes..."
drush test-node-delete

printf "\xE2\x9C\x94\xEF\xB8\x8E Done!\n"
