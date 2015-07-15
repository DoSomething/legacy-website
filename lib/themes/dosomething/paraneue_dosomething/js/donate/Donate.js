/* eslint-disable */

/* ----------------------------------------------------------
 * @TODO: ^ Enable linting by removing `eslint-disable`! ^
 * ----------------------------------------------------------
 * Linting is disabled in this file. Remove this line and
 * clean this file up according to our coding standards next
 * time it is touched.
 */

import $ from 'jquery';
import StripeForm from './StripeForm';
import setting from '../utilities/Setting';

const $donateForm = $('#dosomething-payment-form');

/**
 * Initialize the Stripe donation form.
 */
function init() {
  if(!$donateForm.length) return;

  try {
    var stripeAPIPublishKey = setting('dosomethingPayment.stripeAPIPublish');
    new StripeForm($donateForm, stripeAPIPublishKey);
  } catch(e) {
    $donateForm.html(`<div class="messages">Whoops! Something's not right. Please email us!</div>`);
  }
}

export default { init };
