#!/usr/bin/env bash

rm -rf test/

drush make build-dosomething.make test

cd test

drush site-install dosomething --db-url=mysql://root@localhost/dosomething_test --site-name=Testing -y

php scripts/run-tests.sh --verbose --class DoSomethingSignupWebTestCase
