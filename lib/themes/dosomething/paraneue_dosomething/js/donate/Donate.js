define(function(require) {
  "use strict";

  var $ = require("jquery");
  var StripeForm = require("StripeForm");
  var $donateForm = $("#dosomething-payment-form");

  /**
  * Pads a number with a leading zero if less than 10
  *
  * @param {String}   string  String to be test pad against
  * @return {String}
  */
  function pad(string) {
    if (string !== "") {
      var number = parseInt(string, 10);
      return number < 10 ? "0" + number : number.toString();
    }
  }

  /**
  * Invokes any function after a given timeout
  *
  * @return {function}
  */
  var delay = (function() {
    var timer = 0;
    return function(callback, ms){
      clearTimeout(timer);
      timer = setTimeout(callback, ms);
    };
  }());

  var Donate = {
    init: function () {
      try {
        var stripeAPIPublishKey = Drupal.settings.dosomethingPayment.stripeAPIPublish;
        new StripeForm($donateForm, stripeAPIPublishKey);
      } catch(e) {
        $donateForm.html("<div class='messages'>Whoops! Something's not right. Please email us!</div>");
      }

      // check if leading zero is needed to exp month
      $donateForm.find("[data-stripe='exp-month']").on("keyup", function () {
        var $this = $(this);
        delay(function () {
          $this.val(pad($this.val()));
        }, 200);
      });
    }
  };

  return Donate;

});
