const jQuery = require('jquery');

const Validation = require('dosomething-validation');

// validate number of items
Validation.registerValidationFunction('positiveInteger', function(string, done) {
  const trimmedString = string.replace(' ', '');
  if ( trimmedString !== '' && /^[1-9]\d*$/.test(trimmedString) ) {
    return done({
      success: true,
      message: Drupal.t("That's great!"),
    });
  }
  return done({
    success: false,
    message: Drupal.t('Enter a valid number!'),
  });
});

// validate that string isn't blank
Validation.registerValidationFunction('reportbackReason', function(string, done) {
  if ( string !== '' ) {
    return done({
      success: true,
      message: Drupal.t('Thanks for caring!'),
    });
  }
  return done({
    success: false,
    message: Drupal.t('Tell us why you cared!'),
  });
});

// make sure an image is uploaded
Validation.registerValidationFunction('hasImage', function(string, done) {
  if ( string !== '' ) {
    return done({
      success: true,
    });
  }
  const $reportbackSubmissions = jQuery('.reportback__submissions');
  if (!($reportbackSubmissions.find('.messages.error').length > 0)) {
    $reportbackSubmissions.prepend("<div class='messages error'>Oops! Make sure to upload a photo of you completing the campaign before submitting.</div>");
  }
  return done({
    success: false,
  });
});

// validate that string isn't blank and less than or equal to 60 characters
Validation.registerValidationFunction('caption', function(string, done) {
  if ( string !== '' && string.length <= 60 ) {
    return done({
      success: true,
      message: Drupal.t('Sounds great!'),
    });
  }
  return done({
    success: false,
    message: Drupal.t('Tell us about your photo in 60 characters or less!'),
  });
});
