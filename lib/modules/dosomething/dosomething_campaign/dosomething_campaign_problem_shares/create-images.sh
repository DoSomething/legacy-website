#!/bin/bash

TEMP_FILE_1=tmp1.png
TEMP_FILE_2=tmp2.png
BASE_PATH=/var/www/dev.dosomething.org/lib/modules/dosomething/dosomething_campaign/dosomething_campaign_problem_shares/
FINAL_FILE=$BASE_PATH/images/$1.jpg

convert \
  -size 471x248 \
  canvas:#23B7FB \
  -fill "#337D9F" \
  -pointsize 16 \
  -font $BASE_PATH/fonts/ProximaNova-Bold.otf \
  -annotate +20+40 'make a difference' \
  $TEMP_FILE_1

convert \
  -background transparent \
  -size 431x228 \
  -fill white \
  -font $BASE_PATH/fonts/ProximaNova-Reg.otf \
  -pointsize 24 \
  caption:"$2" \
  $TEMP_FILE_2 \

composite \
  $TEMP_FILE_2 \
  -gravity northwest \
  -geometry +20+50 \
  $TEMP_FILE_1 \
  $FINAL_FILE

rm $TEMP_FILE_1
rm $TEMP_FILE_2
