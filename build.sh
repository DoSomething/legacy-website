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
