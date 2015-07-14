import $ from 'jquery';
const Stripe = window.Stripe || {};

class StripeForm {

  /**
   * Creates an instance of StripeForm.
   * @param {jQuery} form - The payment form
   * @param {String} publishKey - Publishable Stripe key.
   */
  constructor(form, publishKey) {
    if (form === undefined || !$(form).length) throw 'Form element is required.';
    if (publishKey === undefined) throw 'Stripe key is required.';

    this.$form = $(form);

    Stripe.setPublishableKey(publishKey);

    this.onFormSubmit = this.onFormSubmit.bind(this);

    this.$form.on("submit", function (event) {
      event.preventDefault();
    });

    // attach event listener to submit button to avoid double binding
    this.$form.find(".form-submit").on("click", this.onFormSubmit);
  }

  /**
   * Handle form submission events.
   */
  onFormSubmit() {
    // Timeout needed so errors (if any) can render first
    setTimeout(() => {
      if (!this.isValid()) {
        return;
      }

      Stripe.card.createToken(this.$form, (status, response) => {
        if (response.error) {
          // Show the errors on the form
          this.$form.find('.payment-errors').text(response.error.message);
          return false;
        }

        // response contains id and card, which contains additional card details
        this.$form.find('input[name="token"]').val(response.id);
        this.$form.get(0).submit();
      });
    }, 100);
  }

  /**
   * Checks for invalid form fields
   * @returns {boolean} Whether form contains zero errors or not
   */
  isValid() {
    return (this.$form.find('.error').length === 0);
  }

}

export default StripeForm;
