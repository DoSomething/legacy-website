/**
 * We use the Google Analytics custom events API to fire events for client-side
 * events that we want to track, such as opening or closing modals, share buttons,
 * or form validation events.
 */

const $ = require('jquery');
const Analytics = require('@dosomething/analytics');
const Validation = require('dosomething-validation');
const Modal = require('dosomething-modal');

function init() {
  // Configure `data-track-*` links & `analytics()` helper.
  Analytics.init();

  // Validation
  Validation.Events.subscribe('Validation:InlineError', (topic, args) => {
    Analytics.analyze('Form', 'Inline Validation Error', args);
  });

  Validation.Events.subscribe('Validation:Suggestion', (topic, args) => {
    Analytics.analyze('Form', 'Suggestion', args);
  });

  Validation.Events.subscribe('Validation:SuggestionUsed', (topic, args) => {
    Analytics.analyze('Form', 'Suggestion Used', args);
  });

  Validation.Events.subscribe('Validation:Submitted', (topic, args) => {
    Analytics.analyze('Form', 'Submitted', args);
  });

  Validation.Events.subscribe('Validation:SubmitError', (topic, args) => {
    Analytics.analyze('Form', 'Validation Error on submit', args);
  });

  // Modals
  Modal.Events.subscribe('Modal:Open', (topic, args) => {
    const label = args !== null ? '#' + args.attr('id') : '';
    Analytics.analyze('Modal', 'Open', label);
  });

  Modal.Events.subscribe('Modal:Close', (topic, args) => {
    const label = args !== null ? '#' + args.attr('id') : '';
    Analytics.analyze('Modal', 'Close', label);
  });

  // Attach any custom events.
  $(document).ready(() => {
    $('#user-login-form').on('submit', function() {
      Analytics.analyze('Form', 'Submitted', 'user-login-form')
    });
  });
}

export default { init };
