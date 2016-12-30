#!/usr/bin/env bash

TMP=$TMPDIR.$RANDOM
VERSION=v$(cat '../VERSION')

# Lets clone the repo
# We clone to make sure nothing is dirty locally

echo "Cloning repo"
git clone git@github.com:DoSomething/dosomething.git $TMP

cd $TMP

git fetch origin

echo "Checkout master"
git checkout master

echo "Merging dev into master"
git merge origin/dev

# VERSION BUMP
# DO THE BUMP
#git add ../VERSION
#git commit -m 'Release for $VERSION'

echo "Tagging $VERSION"
git tag $VERSION

echo "Push"
git push origin master
git push origin $VERSION 

echo "Cleaning up"
rm -rf $TMP
