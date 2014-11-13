define(function(require) {
  "use strict";

  var $ = require("jquery"),
    Stripe = window.Stripe || {};

  /**
    * Creates an instance of StripeForm.
    *
    * @constructor
    * @this {StripeForm}
    * @param {jQuery} $form The payment form
    * @param {String} publishKey Publishable Stripe key.
  */
  var StripeForm = function ($form, publishKey) {
    if ($form === undefined || !$($form.length)) { return; }
    if (publishKey === undefined) { return; }
    if (!this instanceof StripeForm) { return new StripeForm($form, publishKey); }
    var _this = this;
    _this.$form = $($form);
    _this.$parent = _this.$form.parent();
    _this.publishKey = publishKey;
    _this.init();
  };
  StripeForm.prototype = {
    /**
      * Sets the publishable key to Stripe and adds event listeners to the form
    */
    init: function () {
      var _this = this;
      Stripe.setPublishableKey(_this.publishKey);

      _this.$form.on("submit", function (ev) {
        Stripe.card.createToken(_this.$form, function (status, response) {
          _this.onFormSubmit(status, response);
        });
        ev.preventDefault();
      });
    },

    /**
      * Callback method when form is submitted
      * @param {String} Response status code
      * @param {object} JSON response from submitted token
    */
    onFormSubmit: function (status, response) {
      var _this = this,
        $form = _this.$form;

      if (response.error) {
        // Show the errors on the form
        $form.find(".payment-errors").text(response.error.message);
        //$form.find("input[type='submit']").prop("disabled", false);
      } else {
        // response contains id and card, which contains additional card details
        var token = response.id;
        $form.find("input[name='token']").val(token);
        $form.get(0).submit();
      }
    }
  };

  return StripeForm;

});
