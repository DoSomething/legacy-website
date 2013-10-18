#!/bin/sh

DRUSH_OPTS='--prepare-install --no-gitinfofile --no-cache'
MAKEFILE='build-dosomething.make'
TARGET='html'

CALLPATH=`dirname "$0"`
ABS_CALLPATH=`cd "$CALLPATH"; pwd -P`
BASE_PATH=`cd ..; pwd`

RUN_INSTALL="false"
if [[ $1 == "--install" ]]
  then
    RUN_INSTALL="true"
fi

echo '     _____          ___     ';
echo '    /  /::\        /  /\    ';
echo '   /  /:/\:\      /  /:/_   ';
echo '  /  /:/  \:\    /  /:/ /\  ';
echo ' /__/:/ \__\:|  /  /:/ /::\ ';
echo ' \  \:\ /  /:/ /__/:/ /:/\:\';
echo '  \  \:\  /:/  \  \:\/:/~/:/';
echo '   \  \:\/:/    \  \::/ /:/ ';
echo '    \  \::/      \__\/ /:/  ';
echo '     \__\/         /__/:/   ';
echo '                   \__\/    ';

set -e
echo 'Wiping build directory...'
rm -rf "$TARGET"

# Create the db, if for some reason it's not there yet.
mysql -uroot -e "CREATE DATABASE IF NOT EXISTS dosomething;"

# Do the build
echo 'Running drush make...'
drush make $DRUSH_OPTS "$ABS_CALLPATH/$MAKEFILE" "$TARGET"
set +e

# echo 'Symlink profile, module and themes'
# echo 'Linking dosomething.info'
# rm -rf "$ABS_CALLPATH/$TARGET/profiles/dosomething/dosomething.info"
# ln -s "$ABS_CALLPATH/dosomething.info" "$ABS_CALLPATH/$TARGET/profiles/dosomething/dosomething.info"

# echo 'Linking dosomething.install'
# rm -rf "$ABS_CALLPATH/$TARGET/profiles/dosomething/dosomething.install"
# ln -s "$ABS_CALLPATH/dosomething.install" "$ABS_CALLPATH/$TARGET/profiles/dosomething/dosomething.install"

# echo 'Linking dosomething.profile'
# rm -rf "$ABS_CALLPATH/$TARGET/profiles/dosomething/dosomething.profile"
# ln -s "$ABS_CALLPATH/dosomething.profile" "$ABS_CALLPATH/$TARGET/profiles/dosomething/dosomething.profile"

echo 'Linking modules'
rm -rf "$ABS_CALLPATH/$TARGET/profiles/dosomething/modules/dosomething"
ln -s "$ABS_CALLPATH/modules/dosomething" "$ABS_CALLPATH/$TARGET/profiles/dosomething/modules/dosomething"

echo 'Linking themes'
rm -rf "$ABS_CALLPATH/$TARGET/profiles/dosomething/themes/dosomething"
ln -s "$ABS_CALLPATH/themes/dosomething" "$ABS_CALLPATH/$TARGET/profiles/dosomething/themes/dosomething"

# Clear caches and Run updates
cd "$TARGET"

if [[ $1 == "--install" ]]
  then
    echo 'Installing site...'
    drush site-install dosomething -y --db-url=mysql://root@localhost/dosomething --site-name=DoSomething

    echo 'Granting basic permissions...'
    drush rap 'anonymous user' 'access content'
    drush rap 'authenticated user' 'access content'
fi

echo 'Replacing settings.php file...'
rm -f ./sites/default/settings.php && ln -s /vagrant/settings.php ./sites/default/settings.php

echo 'Clearing caches...'
drush cc all

#echo 'Running updates...'
#drush updb -y;
# @TODO Figure out why this cc all is needed
#drush cc drush;
#echo 'Reverting all features...'
#drush fra -y;
#drush cc all;
echo 'Build complete.'
