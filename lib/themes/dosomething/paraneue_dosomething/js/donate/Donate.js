define(function(require) {
  "use strict";

  var $ = require("jquery"),
    StripeForm = require("StripeForm"),
    $donateForm = $("#dosomething-payment-form"),

  // @TODO pull API keys from a config file
  stripeAPIKeys = {
    publish: "pk_test_FWzmVshDHfsLXB3TV8JtFaLG"
  };

  var Donate = {
    init: function () {
      new StripeForm($donateForm, stripeAPIKeys.publish);
    }
  };

  return Donate;

});
