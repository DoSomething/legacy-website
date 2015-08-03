/**
 * We use the Google Analytics custom events API to fire events for client-side
 * events that we want to track, such as opening or closing modals, share buttons,
 * or form validation events.
 */

import $ from 'jquery';
import Validation from 'dosomething-validation';
import Modal from 'dosomething-modal';

// Only fire GA Custom Events if the GA object exists.
if (typeof ga !== 'undefined' && ga !== null) {
  // Validation
  Validation.Events.subscribe('Validation:InlineError', function(topic, args) {
    ga('send', 'event', 'Form', 'Inline Validation Error', args);
  });

  Validation.Events.subscribe('Validation:Suggestion', function(topic, args) {
    ga('send', 'event', 'Form', 'Suggestion', args);
  });

  Validation.Events.subscribe('Validation:SuggestionUsed', function(topic, args) {
    ga('send', 'event', 'Form', 'Suggestion Used', args);
  });

  Validation.Events.subscribe('Validation:Submitted', function(topic, args) {
    ga('send', 'event', 'Form', 'Submitted', args);
  });

  Validation.Events.subscribe('Validation:SubmitError', function(topic, args) {
    ga('send', 'event', 'Form', 'Validation Error on submit', args);
  });

  // Confirmation Page Shares
  $('.js-analytics-fb-share').on('click', function() {
    ga('send', 'event', 'Share', 'Confirmation Page', 'Facebook');
  });

  $('.js-analytics-tw-share').on('click', function() {
    ga('send', 'event', 'Share', 'Confirmation Page', 'Twitter');
  });

  $('.js-analytics-tm-share').on('click', function() {
    ga('send', 'event', 'Share', 'Confirmation Page', 'Tumblr');
  });


  // Campaign problem statement shares.
  $('.js-analytics-problem-fb').on('click', function() {
    ga('send', 'event', 'Share', 'Problem Statement', 'Facebook');
  });

  $('.js-analytics-problem-tw').on('click', function() {
    ga('send', 'event', 'Share', 'Problem Statement', 'Twitter');
  });

  $('.js-analytics-problem-tm').on('click', function() {
    ga('send', 'event', 'Share', 'Problem Statement', 'Tumblr');
  });

  // Hot module goal shares.
  $('.js-analytics-hot-fb').on('click', function() {
    ga('send', 'event', 'Share', 'Hot Module', 'Facebook');
  });

  $('.js-analytics-hot-tw').on('click', function() {
    ga('send', 'event', 'Share', 'Hot Module', 'Twitter');
  });

  $('.js-analytics-hot-tm').on('click', function() {
    ga('send', 'event', 'Share', 'Hot Module', 'Tumblr');
  });

  // Modals
  Modal.Events.subscribe('Modal:Open', function(topic, args) {
    const label = args !== null ? '#' + args.attr('id') : '';
    ga('send', 'event', 'Modal', 'Open', label);
  });

  Modal.Events.subscribe('Modal:Close', function(topic, args) {
    const label = args !== null ? '#' + args.attr('id') : '';
    ga('send', 'event', 'Modal', 'Close', label);
  });
}
