#!/bin/sh

sudo /usr/bin/pear config-set auto_discover 1
sudo /usr/bin/pear channel-discover pear.phpunit.de
sudo /usr/bin/pear channel-discover pear.symfony-project.com
sudo /usr/bin/pear channel-discover pear.symfony.com
sudo /usr/bin/pear channel-discover components.ez.no
sudo /usr/bin/pear update-channels
sudo /usr/bin/pear upgrade-all
sudo /usr/bin/pear install --alldeps phpunit/PHPUnit
sudo /usr/bin/pear install --force --alldeps phpunit/PHPUnit
sudo /usr/bin/pear install pear.symfony.com/Yaml
sudo /usr/bin/pear install --alldeps Console_Table
sudo /usr/bin/pear install pear.phpunit.de/phploc
sudo /usr/bin/pear install PHP_CodeSniffer