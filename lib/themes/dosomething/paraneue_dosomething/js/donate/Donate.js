define(function(require) {
  "use strict";

  var $ = require("jquery"),
    StripeForm = require("StripeForm"),
    $donateForm = $("#donate-payment-form"),
    $donateAmountHero = $(".-hero input"),
    $donateAmountModal = $("#modal--payment [data-stripe='amount']"),

  // @TODO pull API keys from a config file
  stripeAPIKeys = {
    publish: "pk_test_FWzmVshDHfsLXB3TV8JtFaLG"
  };

  var Donate = {
    init: function () {
      new StripeForm($donateForm, stripeAPIKeys.publish);
      $donateAmountHero.on("change", Donate.setDonateAmount).focus();
    },
    setDonateAmount: function () {
      $donateAmountModal.val($donateAmountHero.val());
    }
  };

  return Donate;

});
