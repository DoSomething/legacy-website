// const $ = require('jquery');
import Validation from 'dosomething-validation';

// Validate that a field isn't blank.
Validation.registerValidationFunction('organ_first_name', function(string, done) {
  if ( string !== '' ) {
    return done({
      success: true,
      message: Drupal.t('First Name'),
    });
  }
  return done({
    success: false,
    message: Drupal.t('This field is required.'),
  });
});

// Validate that a field isn't blank.
Validation.registerValidationFunction('organ_last_name', function(string, done) {
  if ( string !== '' ) {
    return done({
      success: true,
      message: Drupal.t('Last Name'),
    });
  }
  return done({
    success: false,
    message: Drupal.t('This field is required.'),
  });
});

Validation.registerValidationFunction("organ_zipcode", function(string, done) {
  if( string.match(/^\d{5}(?:[-\s]\d{4})?$/) ) {
    return done({
      success: true,
      message: Drupal.t("Thanks!")
    });
  } else {
    return done({
      success: false,
      message: Drupal.t("We need your zip code.")
    });
  }
});

Validation.registerValidationFunction('organ_ssn', function(string, done) {
  if (string.length === 4) {
    return done({
      success: true,
      message: Drupal.t('Got it.'),
    });
  }

  if (string.length > 4) {
    return done({
      success: false,
      message: Drupal.t('We only need the last four digits of your social securtity'),
    });
  }

  return done({
    success: false,
    message: Drupal.t('This field is required.'),
  });
});
