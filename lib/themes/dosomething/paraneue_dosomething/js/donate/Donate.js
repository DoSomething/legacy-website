define(function(require) {
  "use strict";

  var $ = require("jquery"),
    StripeForm = require("StripeForm"),
    $donateForm = $("#dosomething-payment-form"),

  stripeAPIKeys = {
    publish: Drupal.settings.dosomethingPayment.stripeAPIPublish
  };

  var Donate = {
    init: function () {
      new StripeForm($donateForm, stripeAPIKeys.publish);
    }
  };

  return Donate;

});
