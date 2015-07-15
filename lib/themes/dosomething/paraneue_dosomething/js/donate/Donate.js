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
