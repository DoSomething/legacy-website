define(function(require) {
  "use strict";

  var $ = require("jquery");
  var Validation= require("dosomething-validation");

  /** @NOTE: Temporary, testing out some new ideas. */
  var requiredValidator = function(string, done, args) {
    if( string !== "" ) {
      return done({
        success: true,
        message: args.success
      });
    } else {
      return done({
        success: false,
        message: args.failure
      });
    }
  };

  /**
   * Validators for individual address form fields:
   */
  Validation.registerValidationFunction("fname", function(string, done) {
    return requiredValidator(string, done, {
      success: Drupal.t("Oh hey, @fname!", {"@fname": string}),
      failure: Drupal.t("We need your name. We’re on a first-name basis, right?")
    });
  });

  Validation.registerValidationFunction("lname", function(string, done) {
    return requiredValidator(string, done, {
      success: Drupal.t("The @lname-inator! People call you that, right?", {"@lname": string}),
      failure: Drupal.t("We need your last name.")

    });
  });

  Validation.registerValidationFunction("address1", function(string, done) {
    return requiredValidator(string, done, {
      success: Drupal.t("Got it!"),
      failure: Drupal.t("We need your street name and number.")
    });
  });

  Validation.registerValidationFunction("address2", function(string, done) {
    return requiredValidator(string, done, {
      success: Drupal.t("Got that too!"),
      failure: ""
    });
  });

  Validation.registerValidationFunction("city", function(string, done) {
    return requiredValidator(string, done, {
      success: Drupal.t("Sweet, thanks!"),
      failure: Drupal.t("We need your city.")
    });
  });

  Validation.registerValidationFunction("state", function(string, done) {
    return requiredValidator(string, done, {
      success: Drupal.t("I \u2764 @state", {"@state": string}),
      failure: Drupal.t("We need your state.")
    });
  });

  Validation.registerValidationFunction("zipcode", function(string, done) {
    if( string.match(/^\d{5}(?:[-\s]\d{4})?$/) ) {
      return done({
        success: true,
        message: Drupal.t("Almost done!")
      });
    } else {
      return done({
        success: false,
        message: Drupal.t("We need your zip code.")
      });
    }
  });

  Validation.registerValidationFunction("why_signedup", function(string, done) {
    return requiredValidator(string, done, {
      success: Drupal.t("Thanks for caring!"),
      failure: Drupal.t("Oops! Can't leave this one blank.")
    });
  });


  /**
   * Custom validation for UPS address fieldset.
   */
  Validation.registerValidationFunction("ups_address", function($el, done) {
    var $sorryError = $(
      "<div class='messages error'>" +
        "<strong>" + Drupal.t("We couldn't find that address.") + "</strong>" +
        Drupal.t("Double check for typos and try submitting again.") +
      "</div>"
    );

    var $networkError= $(
      "<div class='messages error'>" +
        Drupal.t("We're having trouble submitting the form, are you sure your internet connection is working? Email us if you continue having problems.") +
      "</div>"
    );

    var addressFieldData = $el.find("select, input").serializeArray();

    // Remove previous messages.
    $el.find(".messages").slideUp(function() { $(this).remove(); });

    // Once we know we have, submit them to the AJAX endpoint
    $.ajax({
      type: "POST",
      url: "/user/validate/address",
      dataType: "json",
      data: addressFieldData,
      success: function(data) {

        if(data.sorry) {
          // Address is invalid and we don't have any suggestions
          $el.append($sorryError).hide().slideDown();
          return done({ success: false });
        }

        var hasFieldErrors = false;
        for(var field in data) {
          if(data.hasOwnProperty(field) && field !== "ambiguous") {
            var suggestion = data[field];
            var $fieldEl = $el.find("[name='user_address[" + field + "]']");

            // If just capitalizing or adding extra 4-digit to zip, don't show an error
            if(  (field === "postal_code" && $fieldEl.val().slice(0,4) === suggestion.slice(0,4)) || (suggestion === $fieldEl.val().toUpperCase() ) ) {
              $fieldEl.val( suggestion  );
            } else {
              // Otherwise, mark errors and ask user to correct them
              hasFieldErrors = true;

              Validation.showValidationMessage($fieldEl, {
                success: false,
                suggestion: {
                  full: suggestion,
                  domain: "zip"
                }
              });
            }
          }
        }

        if(hasFieldErrors) {
          done({ success: false });
        } else {
          done({ success: true });
        }

      },
      error: function() {
        // We're having trouble getting the validation over AJAX, let's mark as
        // validated and leave it up to the server just to be safe.
        $el.append($networkError).hide().slideDown();
        done({ success: false });
      }
    });
  });


  /**
   * Validators for shirt reward fields:
   */
  Validation.registerValidationFunction("shirt_size", function(string, done) {
    return requiredValidator(string, done, {
      success: Drupal.t("It'll fit great!"),
      failure: Drupal.t("We need a shirt size!")
    });
  });

  // Shirt style validor
  // @TODO: add support to radio button validation in Neue
  Validation.registerValidationFunction("shirt_style", function($el, done) {
    // collected checked radio's
    var $checked = $el.find("input[type='radio']:checked");

    // message that will be injected upon error
    var $errorMsg = $(
      "<div class='message error'>" + Drupal.t("We need a shirt style!") + "</div>"
    );

    // remove the error message before validation
    $el.find(".message").remove();

    if ($checked.length === 1) {
      done({ success: true });
    } else {
      $el.find("label:first").append($errorMsg);
      done({ success: false });
    }
  });

});
