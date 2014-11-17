define(function(require) {
  "use strict";

  var $ = require("jquery");
  var StripeForm = require("StripeForm");
  var $donateForm = $("#dosomething-payment-form");

  var Donate = {
    init: function () {
      try {
        var stripeAPIPublishKey = Drupal.settings.dosomethingPayment.stripeAPIPublish;
        new StripeForm($donateForm, stripeAPIPublishKey);
      } catch(e) {
        $donateForm.html("<div class='messages'>Whoops! Something's not right. Please email us!</div>");
      }
    }
  };

  return Donate;

});
