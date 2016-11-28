/**
 * We use the Google Analytics custom events API to fire events for client-side
 * events that we want to track, such as opening or closing modals, share buttons,
 * or form validation events.
 */

const $ = require('jquery');
const Analytics = require('@dosomething/analytics');
const Validation = require('dosomething-validation');
const Modal = require('dosomething-modal');

/**
 * Set a custom Optimizely dimension for segmenting results.
 * @see https://goo.gl/R9QLpS
 *
 * @param {String} dimension
 * @param {String} value
 */
function setOptimizelyDimension(dimension, value) {
  if (process.env.NODE_ENV !== 'production') {
    console.info(`Set Optimizely Dimension - ${dimension}:${value}`);
  }

  window['optimizely'] = window['optimizely'] || [];
  optimizely.push(['setDimensionValue', dimension, value]);
}

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

  // Optimizely Dimensions
  $('#link--login, #link--openid-connect-login').on('click', () => setOptimizelyDimension('link', 'auth'));
  $('#link--campaign-signup-login, #link--openid-connect-campaign-signup-login').on('click', () => setOptimizelyDimension('link', 'signup'));

  // Attach any custom events.
  $(document).ready(() => {
    $('#user-login-form').on('submit', () => {
      Analytics.analyze('Form', 'Submitted', 'user-login-form')
    });
  });
}

export default { init };
