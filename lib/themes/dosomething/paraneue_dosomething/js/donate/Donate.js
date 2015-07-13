import $ from 'jquery';
import StripeForm from './StripeForm';

const $donateForm = $('#dosomething-payment-form');

/**
 * Initialize the Stripe donation form.
 */
function init() {
  if(!$donateForm.length) return;

  try {
    var stripeAPIPublishKey = Drupal.settings.dosomethingPayment.stripeAPIPublish;
    new StripeForm($donateForm, stripeAPIPublishKey);
  } catch(e) {
    $donateForm.html(`<div class="messages">Whoops! Something's not right. Please email us!</div>`);
  }
}

export default { init };
