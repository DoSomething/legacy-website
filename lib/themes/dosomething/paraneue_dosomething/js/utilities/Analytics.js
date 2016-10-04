/**
 * We use the Google Analytics custom events API to fire events for client-side
 * events that we want to track, such as opening or closing modals, share buttons,
 * or form validation events.
 */

import $ from 'jquery';
import Validation from 'dosomething-validation';
import Modal from 'dosomething-modal';

function subscribeEvents() {
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

  // Modals
  Modal.Events.subscribe('Modal:Open', function(topic, args) {
    const label = args !== null ? '#' + args.attr('id') : '';
    ga('send', 'event', 'Modal', 'Open', label);
  });

  Modal.Events.subscribe('Modal:Close', function(topic, args) {
    const label = args !== null ? '#' + args.attr('id') : '';
    ga('send', 'event', 'Modal', 'Close', label);
  });

  // Signup button on pitch page
  const isPitchPage = $('.pitch').length > 0;
  if (isPitchPage) {
    // This applies to both authenticated & anonymous users. It also covers both modal register & login.
    $('.header__signup form, #user-login-form').on('submit', () => {
      ga('send', 'event', 'Signup button', 'Pitch page');
    });

    Validation.Events.subscribe('Validation:Submitted', (topic, args) => {
      if (args === 'user-register-form') {
        ga('send', 'event', 'Signup button', 'Pitch page');
      }
    });
  }
}

function exists() {
  return typeof ga !== 'undefined' && ga !== null;
}

export function sendEvent(category, action, label) {
  if (exists()) {
    ga('send', 'event', category, action, label);
  }
}

function init() {
  // Only fire GA Custom Events if the GA object exists.
  if (exists()) {
    subscribeEvents();

    /**
     * Google Analytics Event Tracking
     * Optional data attributes:
     *   data-ga-category
     *   data-ga-action
     *   data-ga-label
     *
     * @param {jQuery} $el - The element being tracked.
     **/
    $('body').on('click', '.ga-click', e => {
      const $el = $(e.target);

      const category = (typeof ($el.data('ga-category')) !== 'undefined') ? $el.data('ga-category') : null;
      const action = (typeof ($el.data('ga-action')) !== 'undefined') ? $el.data('ga-action') : null;
      const label = (typeof ($el.data('ga-label')) !== 'undefined') ? $el.data('ga-label') : null;

      sendEvent(category, action, label);
    });
  }
}

export default { init };
