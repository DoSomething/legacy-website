/**
 * @module Analytics
 * Uses Google Analytics custom events API to fire events for client-side
 * Modal and Form Validation flows.
 */
define(["neue/events"], function(Events) {
  "use strict";

  // We'll only fire GA Custom Events if the GA object exists
  if(typeof(_gaq) !== "undefined" && _gaq !== null) {
    Events.subscribe("Validation:InlineError", function(topic, args) {
      _gaq.push(["_trackEvent", "Form", "Inline Validation Error", args, null, true]);
    });

    Events.subscribe("Validation:Suggestion", function(topic, args) {
      _gaq.push(["_trackEvent", "Form", "Suggestion", args, null, true]);
    });

    Events.subscribe("Validation:SuggestionUsed", function(topic, args) {
      _gaq.push(["_trackEvent", "Form", "Suggestion Used", args, null, true]);
    });

    Events.subscribe("Validation:Submitted", function(topic, args) {
      _gaq.push(["_trackEvent", "Form", "Submitted", args, null, false]);
    });

    Events.subscribe("Validation:SubmitError", function(topic, args) {
      _gaq.push(["_trackEvent", "Form", "Validation Error on submit", args, null, true]);
    });
  }

});
