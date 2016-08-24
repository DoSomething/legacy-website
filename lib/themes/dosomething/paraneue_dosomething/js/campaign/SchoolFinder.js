/* eslint-disable */

/* ----------------------------------------------------------
 * @TODO: ^ Enable linting by removing `eslint-disable`! ^
 * ----------------------------------------------------------
 * Linting is disabled in this file. Remove this line and
 * clean this file up according to our coding standards next
 * time it is touched.
 */

import setting from '../utilities/Setting';

var $ = require("jquery");
var template = require("lodash/template");
var isEmpty = require("lodash/isEmpty");
var forEach = require("lodash/forEach");
var throttle = require("lodash/throttle");
var Validation = require("dosomething-validation");

var shouldValidateForm = true;
var resultTpl = template("<li><a class='js-schoolfinder-result' data-gsid='<%- gsid %>' href='#'><span><%- name %></span> <em><%- city %>, <%- state %></em></a></li>");

function getResults(state, query, limit, callback) {
  if(isEmpty(query) || isEmpty(state)) return callback([]);

  var endpoint = setting('dosomethingUser.schoolFinderAPIEndpoint', 'http://lofischools.herokuapp.com/search');

  $.ajax({
    dataType: "json",
    url: endpoint + "?state=" + state + "&query=" + query + "&limit=" + limit
  }).done(function(data) {
    callback(data.results, data.meta.more_results); // jshint ignore:line
  }).fail(function() {
    callback(false);
  });
}

function displayResults($el, results, canShowMore) {
  $el.empty();

  if(!results) {
    $el.append("<div class='messages error'>We couldn't load schools. Check your internet connection, or try refreshing the page.</div>");
    $el.show();
    return;
  }

  forEach(results, function(result) {
    $el.append(resultTpl(result));
  });

  if(results.length === 0) {
    $el.append("<div class='messages error'>Hmm, we couldn't find your school based on how the name was entered. But it may still be there! Click on the link below for tips on finding your school.</div>");
  }

  if(canShowMore) {
    $el.append("<p class='schoolfinder-showmore'><a href='#' class='secondary js-schoolfinder-showmore'>Show More Results</a></p>");
  }

  $el.show();
}

function init($schoolSignupForm = $("#dosomething-signup-user-signup-data-form")) {
  if(!$schoolSignupForm) return;

  var $stateField = $("#edit-school-administrative-area");
  var $schoolIDField = $schoolSignupForm.find("[name='school_id']");
  var $schoolSearchField = $schoolSignupForm.find(".js-schoolfinder-search");
  var $schoolSearchResults = $schoolSignupForm.find(".js-schoolfinder-results");
  var $notAffiliatedField = $("#edit-school-not-affiliated");
  var $notAffiliatedConfirmationMessage = $schoolSignupForm.find(".js-school-not-affiliated-confirmation");

  var savedStateFieldState = "";
  var getResultsThrottled = throttle(getResults, 1000);

  // Set the form to default state.
  $schoolSearchField.hide();
  $schoolSearchResults.hide();

  /**
   * Event handler for the state select field.
   */
  $stateField.on("change", function() {
    // Show the school name field once user has chosen a state.
    var stateSelected = $(this).val() !== "";
    $schoolSignupForm.find(".messages").hide();
    $schoolSearchField.val("");
    $schoolSearchField.trigger("keyup");
    $schoolSearchField.toggle(stateSelected);

    if(stateSelected) {
      $schoolSearchField.focus();
    }
  });

  /**
   * Event handler for school search field text input.
   */
  $schoolSearchField.on("keyup", function() {
    $schoolSignupForm.find(".messages").hide();
    var val = $(this).val();

    if(val !== "") {
      $schoolSearchField.addClass("loading");
      getResultsThrottled( $stateField.val(), val, 10, function(res, moreAvailable) {
        displayResults($schoolSearchResults, res, moreAvailable);
        $schoolSearchField.removeClass("loading");
      });
    } else {
      $schoolSearchResults.hide();
      $schoolIDField.val("");
    }
  });

  /**
   * Event handler for clicking a result.
   */
  $schoolSearchResults.on("click", ".js-schoolfinder-result", function(e) {
    e.preventDefault();

    var $this = $(this);
    $schoolIDField.val( $this.data("gsid") );
    $schoolSearchField.val( $this.find("span").text() );

    $this.addClass("is-selected");
    $this.parent("li").siblings().hide();
  });

  /**
   * Event handler for "Show More" link.
   */
  $schoolSignupForm.on("click", ".js-schoolfinder-showmore", function(e) {
    e.preventDefault();

    $(this).remove();

    $schoolSearchField.addClass("loading");
    getResultsThrottled( $stateField.val(), $schoolSearchField.val(), 50, function(res) {
      displayResults($schoolSearchResults, res, false);
      $schoolSearchField.removeClass("loading");
    });
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

    $stateField.trigger("change");
  });

  $schoolSignupForm.find(".js-schoolfinder-help").on("click", function(event) {
    event.preventDefault();
    $(".js-schoolfinder-help-content").toggle();
  });
}

/**
 * Custom validation for the School Finder.
 */
Validation.registerValidationFunction("school_finder", function($el, done) {
  var $schoolID = $el.find("[name='school_id']");

  if(!shouldValidateForm) {
    // User has selected "I'm not affiliated" checkbox. Skip validation.
    return done({ success: true });
  }

  if($schoolID.val() === "") {
    // User has not selected a school.
    $el.addClass("shake");

    // Remove any existing error messages.
    $el.find(".messages.error").remove();

    $el.append("<div class='messages error'>You haven't entered your school. Find your school by entering your state and then selecting a school from the search results.</div>");

    return done({ success: false });
  }

  // User has selected a school.
  return done({ success: true });
});

export default { init };
