#!/usr/bin/env bash

# Copy settings files into place
cp /vagrant/config/* /var/www/dev.dosomething.org/html/sites/default/

# Grab a copy of the Staging DB
drush sql-sync @ds.staging @ds.local --yes