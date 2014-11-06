define(function(require) {
  "use strict";

  var $ = require("jquery"),
    StripeForm = require("StripeForm"),
    $donateForm = $("#donate-payment-form"),
    $donateAmountHero = $(".-hero input").val(100),
    $donateAmountModal = $("#modal--payment [data-stripe='amount']"),

  // @TODO pull API keys from a config file
  stripeAPIKeys = {
    publish: "pk_test_FWzmVshDHfsLXB3TV8JtFaLG"
  };

  function setDonateAmount () {
    $donateAmountModal.val($donateAmountHero.val());
  }

  new StripeForm($donateForm, stripeAPIKeys.publish);
  setDonateAmount();
  $donateAmountHero.on("change", setDonateAmount);
});
