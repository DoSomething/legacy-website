#!/bin/sh

DRUSH_OPTS='--prepare-install --no-gitinfofile --no-cache'
MAKEFILE='build-dosomething.make'
TARGET='html'

CALLPATH=`dirname "$0"`
ABS_CALLPATH=`cd "$CALLPATH"; pwd -P`
BASE_PATH=`cd ..; pwd`

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
# Do the build
echo 'Running drush make...'
drush make $DRUSH_OPTS "$ABS_CALLPATH/$MAKEFILE" "$TARGET"
set +e

# Clear caches and Run updates
cd "$DRUPAL"
echo 'Clearing caches...'
#drush cc all; drush cc all;
#echo 'Running updates...'
#drush updb -y;
# @TODO Figure out why this cc all is needed
#drush cc drush;
#echo 'Reverting all features...'
#drush fra -y;
#drush cc all;
echo 'Build complete.'