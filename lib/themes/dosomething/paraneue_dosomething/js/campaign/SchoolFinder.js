define(function(require) {
  "use strict";

  var $ = require("jquery");
  var _ = require("lodash");
  var Validation = require("neue/validation");

  var shouldValidateForm = true;
  var resultTpl = _.template("<li><a data-gsid='<%- gsid %>' href='#'><span><%- name %></span> <em><%- city %>, <%- state %></em></a></li>");

  var getResults = function(state, query, callback) {
    if(_.isEmpty(query) || _.isEmpty(state)) return callback([]);

    $.getJSON("http://lofischools.herokuapp.com/search?state=" + state + "&query=" + query, function(data) {
      callback(data.results);
    });
  };

  var displayResults = function($el, results) {
    $el.empty();

    _.each(results, function(result) {
      $el.append(resultTpl(result));
    });

    $el.show();
  };

  var initializeSchoolFinder = function($schoolSignupForm) {
    var $stateField = $("#edit-school-administrative-area");
    var $schoolIDField = $schoolSignupForm.find("[name='school_id']");
    var $schoolSearchField = $schoolSignupForm.find(".js-schoolfinder-search");
    var $schoolSearchResults = $schoolSignupForm.find(".js-schoolfinder-results");
    var $notAffiliatedField = $("#edit-school-not-affiliated");
    var $notAffiliatedConfirmationMessage = $schoolSignupForm.find(".js-school-not-affiliated-confirmation");

    var savedStateFieldState = "";
    var getResultsThrottled = _.throttle(getResults, 1000, { leading: false });

    // Set the form to default state.
    $schoolSearchField.hide();
    $schoolSearchResults.hide();

    /**
     * Event handler for the state select field.
     */
    $stateField.on("change", function() {
      // Show the school name field once user has chosen a state.
      var stateSelected = $(this).val() !== "";
      $schoolSearchField.toggle(stateSelected);

      if(stateSelected) {
        $schoolSearchField.focus();
      }
    });

    /**
     * Event handler for school search field text input.
     */
    $schoolSearchField.on("keyup", function() {
      var val = $(this).val();

      if(val !== "") {
        getResultsThrottled( $stateField.val(), val, function(res) {
          displayResults($schoolSearchResults, res);
        });
      } else {
        $schoolSearchResults.hide();
      }
    });

    /**
     * Event handler for clicking a result.
     */
    $schoolSearchResults.on("click", "a", function(e) {
      e.preventDefault();

      var $this = $(this);
      $schoolIDField.val( $this.data("gsid") );
      $schoolSearchField.val( $this.find("span").text() );

      $this.addClass("is-selected");
      $this.parent("li").siblings().hide();
    });

    /**
     * Event handler for the "I'm not affiliated with a school" checkbox.
     */
    $notAffiliatedField.on("change", function() {
      // If user is not entering a school, don't validate form.
      shouldValidateForm = !this.checked;
      $notAffiliatedConfirmationMessage.toggle(this.checked);

      if(this.checked) {
        savedStateFieldState = $stateField.val();
        $stateField.val("");
        $schoolSearchField.val("");
        $schoolSearchField.trigger("keyup");
      } else {
        $stateField.val(savedStateFieldState);
        $notAffiliatedConfirmationMessage.hide();
      }

      $stateField.trigger("focus").trigger("change").trigger("blur");
      $schoolSignupForm.find("input[type='submit']").trigger("focus");
    });
  };

  $(document).ready(function() {
    var $schoolSignupForm = $("#dosomething-signup-user-signup-data-form");
    if( $schoolSignupForm ) {
      initializeSchoolFinder($schoolSignupForm);
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
