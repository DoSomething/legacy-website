define(function(require) {
  "use strict";

  var $ = require("jquery"),
    Stripe = window.Stripe || {},

    // @TODO remove once PHP lib is set
    stripeAPIKeys = {
      secret: "sk_test_OSv0ABa6QlFvj4Ya8GvT3xvM"
    };

  var StripeForm = function ($form, publishKey, opts) {
    if ($form === undefined || !$($form.length)) { return; }
    if (publishKey === undefined) { return; }
    if (!this instanceof StripeForm) { return new StripeForm($form, opts); }
    var _this = this;
    opts = opts || {};
    _this.cfg = opts = {
      // @TODO use API provided by PHP lib
      apiURL: (typeof opts.apiURL === "string") ? opts.apiURL : "https://api.stripe.com/v1"
    };
    _this.$form = $($form);
    _this.$parent = _this.$form.parent();
    _this.publishKey = publishKey;

    // Authorization headers
    // @TODO remove once PHP lib is set
    _this.stripeAuthHeaders = {
      "Authorization": "Bearer " + stripeAPIKeys.secret
    };
    _this.init();
  };
  StripeForm.prototype = {
    init: function () {
      var _this = this;
      Stripe.setPublishableKey(_this.publishKey);
      _this.$parent.removeClass("complete");

      _this.$form.on("submit", function (ev) {
        Stripe.card.createToken(_this.$form, function (status, response) {
          _this.onFormSubmit(status, response);
        });
        ev.preventDefault();
      });
    },
    onFormSubmit: function (status, response) {
      var _this = this,
        $form = _this.$form;

      if (response.error) {
        // Show the errors on the form
        $form.find(".payment-errors").text(response.error.message);
        $form.find("input[type='submit']").prop("disabled", false);
      } else {
        // response contains id and card, which contains additional card details
        var token = response.id,
          email = $form.find("[data-stripe='email']").val(),
          amount = $form.find("[data-stripe='amount']").val();

        // create new Stripe customer
        $.when(
          _this.createCustomer(token, email)
        ).done(function (data) {
          _this.addCharge(data.default_card, data.id, amount).done(function () {
            _this.onFormConfirm();
          });
        });
      }
    },
    onFormConfirm: function () {
      this.$parent.addClass("complete");
    },
    addCharge: function (card, customer, amount) {
      var _this = this;
      var d = $.Deferred(),
        data = {
          currency: "usd",
          description: "DoSomething.org Donation",
          card: card,
          customer: customer,
          amount: amount * 100
        };
      $.ajax({
        url: _this.cfg.apiURL + "/charges",
        data: data,
        headers: _this.stripeAuthHeaders,
        type: "POST",
        success: d.resolve,
        error: d.reject,
      });
      return d.promise();
    },
    createCustomer: function (token, email) {
      var _this = this;
      var d = $.Deferred();
      $.ajax({
        url: _this.cfg.apiURL + "/customers",
        data: {
          card: token,
          email: email
        },
        headers: _this.stripeAuthHeaders,
        type: "POST",
        success: d.resolve,
        error: d.reject,
      });
      return d.promise();
    }
  };

  return StripeForm;

});
