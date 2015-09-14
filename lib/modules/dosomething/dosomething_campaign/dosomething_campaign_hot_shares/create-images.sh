#!/bin/bash

TEMP_FILE_1=tmp1.png
TEMP_FILE_2=tmp2.png
TEMP_FILE_3=tmp3.png
TEMP_FILE_4=tmp4.png
BOLD_FONT_PATH="$1/ProximaNova-Bold.otf"
REG_FONT_PATH="$1/ProximaNova-Reg.otf"
FINAL_FILE=$2/images/hot-$3.png

# noun verbed
convert \
  -size 471x248 \
  canvas:#23B7FB \
  -fill "#337D9F" \
  -pointsize 16 \
  -font $BOLD_FONT_PATH \
  -annotate +20+40 "$4" \
  $TEMP_FILE_1

# count
convert \
  -background transparent \
  -size 431x228 \
  -fill white \
  -font $BOLD_FONT_PATH \
  -pointsize 72 \
  caption:"$5" \
  $TEMP_FILE_2

# time left banner at bottom
convert \
  -size 471x48 \
  canvas:#337D9F \
  -fill white \
  -font $BOLD_FONT_PATH \
  -pointsize 16 \
  -annotate +20+30 "$6" \
  $TEMP_FILE_3

# goal
convert \
  -background transparent \
  -size 431x24 \
  -fill white \
  -fill white \
  -font $BOLD_FONT_PATH \
  -pointsize 16 \
  caption:"$7" \
  $TEMP_FILE_4

composite \
  $TEMP_FILE_2 \
  -gravity northwest \
  -geometry +20+50 \
  $TEMP_FILE_1 \
  $FINAL_FILE

composite \
  $TEMP_FILE_3 \
  -gravity southwest \
  -geometry +0+0 \
  $FINAL_FILE \
  $FINAL_FILE

composite \
  $TEMP_FILE_4 \
  -gravity northwest \
  -geometry +20+140 \
  $FINAL_FILE \
  $FINAL_FILE

rm $TEMP_FILE_1
rm $TEMP_FILE_2
rm $TEMP_FILE_3
rm $TEMP_FILE_4
