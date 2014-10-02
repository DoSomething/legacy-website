define(function(require) {
  "use strict";

  var $ = require("jquery");
  var Validation = require("neue/validation");

  var shouldValidateForm = true;

  $(document).ready(function() {
    var $schoolSignupForm = $("#dosomething-signup-user-signup-data-form");
    if( $schoolSignupForm ) {
      var $schoolIDContainer = $schoolSignupForm.find(".form-item-school-id");
      var $schoolNameContainer = $schoolSignupForm.find(".form-item-school-name");
      var $stateField = $("#edit-school-administrative-area");
      var $schoolIDField = $("#edit-school-id");
      var $schoolNameField = $("#edit-school-name");
      var $notAffiliatedField = $("#edit-school-not-affiliated");
      var $notAffiliatedConfirmationMessage = $("#edit-school-not-affiliated-confirm-msg");

      $schoolIDContainer.hide();
      $schoolNameContainer.hide();
      $notAffiliatedConfirmationMessage.hide();

      $stateField.on("change", function() {
        // Show the school name field once user has chosen a state.
        if($(this).val() !== "") {
          $schoolNameContainer.show();
          $schoolNameField.focus();
        } else {
          $schoolNameContainer.hide();
        }
      });

      $notAffiliatedField.on("change", function() {
        // If user is not entering a school, don't validate form.
        shouldValidateForm = !this.checked;

        if(this.checked) {
          $notAffiliatedConfirmationMessage.show();
        } else {
          $notAffiliatedConfirmationMessage.hide();
        }
      });
    }
  });

  /**
   * Custom validation for the School Finder.
   */
  Validation.registerValidationFunction("school_finder", function($el, done) {
    if(shouldValidateForm) {
      return done({ success: false });
    }


    return done({ success: true });
  });

});
