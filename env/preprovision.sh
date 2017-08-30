#!/usr/bin/env bash

# Drop in the custom Ansible task for running Drush Make.
cd /vagrant/vendor/geerlingguy/drupal-vm/provisioning/roles/geerlingguy.drupal
rm build-makefile.yml
cp /vagrant/env/build-makefile.yml .

# Install Drush Make Local
mkdir -p /usr/share/drush/commands/
cd /tmp
wget https://github.com/helior/make_local/archive/6.x-1.1.tar.gz
tar xzvf 6.x-1.1.tar.gz
mv make_local-6.x-1.1 /usr/share/drush/commands/make_local