import $ from 'jquery';
import StripeForm from './StripeForm';
import setting from '../utilities/Setting';

/**
 * Initialize the Stripe donation form.
 * @param {jQuery} $donateForm - Donation form element
 */
function init($donateForm = $('#dosomething-payment-form')) {
  if (!$donateForm.length) return;

  try {
    const stripeAPIPublishKey = setting('dosomethingPayment.stripeAPIPublish');
    const form = new StripeForm($donateForm, stripeAPIPublishKey);
    form.init();
  } catch(e) {
    $donateForm.html(`<div class="messages">Whoops! Something's not right. Please email us!</div>`);
  }
}

export default { init };
