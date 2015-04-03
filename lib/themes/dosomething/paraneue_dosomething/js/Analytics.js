/**
 * @module Analytics
 * Uses Google Analytics custom events API to fire events for client-side
 * Modal and Form Validation flows.
 */
define(["dosomething-validation", "dosomething-modal", "jquery"], function(Validation, Modal, $) {
  "use strict";

  // We'll only fire GA Custom Events if the GA object exists
  if(typeof(ga) !== "undefined" && ga !== null) {
    // Validation
    Validation.Events.subscribe("Validation:InlineError", function(topic, args) {
      ga("send", "event", "Form", "Inline Validation Error", args);
    });

    Validation.Events.subscribe("Validation:Suggestion", function(topic, args) {
      ga("send", "event", "Form", "Suggestion", args);
    });

    Validation.Events.subscribe("Validation:SuggestionUsed", function(topic, args) {
      ga("send", "event", "Form", "Suggestion Used", args);
    });

    Validation.Events.subscribe("Validation:Submitted", function(topic, args) {
      ga("send", "event", "Form", "Submitted", args);
    });

    Validation.Events.subscribe("Validation:SubmitError", function(topic, args) {
      ga("send", "event", "Form", "Validation Error on submit", args);
    });

    // Confirmation Page Shares
    $(".js-analytics-fb-share").on("click", function() {
      ga("send", "event", "Share", "Confirmation Page", "Facebook");
    });

    $(".js-analytics-tw-share").on("click", function() {
      ga("send", "event", "Share", "Confirmation Page", "Twitter");
    });

    $(".js-analytics-tm-share").on("click", function() {
      ga("send", "event", "Share", "Confirmation Page", "Tumblr");
    });


    // Modals
    Modal.Events.subscribe("Modal:Open", function(topic, args) {
      var label = args !== null ? "#" + args.attr("id") : "";
      ga("send", "event", "Modal", "Open", label);
    });

    Modal.Events.subscribe("Modal:Close", function(topic, args) {
      var label = args !== null ? "#" + args.attr("id") : "";
      ga("send", "event", "Modal", "Close", label);
    });
  }

});
