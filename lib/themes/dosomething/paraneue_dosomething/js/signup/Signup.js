import takeoverTpl from 'signup/templates/takeover.tpl.html';

const $ = require('jquery');
const debounce = require('lodash/function/debounce');
const template = require('lodash/string/template');

const Signup = {

  /**
   * Initialize the Signup interface.
   *
   */
  init: function($takeoverContainer = $('.takeover-container')) {
    this.takeoverContainer = $takeoverContainer;

    const data = {
      'header': 'Thank you for signing up!',
      'caption': 'Want to do more good? Sign up for similar campaigns below!',
      'campaigns': Drupal.settings.dosomethingCampaign.recommendedCampaigns,
    }

    // Add the takeover to the page.
    this.addTakeover(data);

    this.scrollScreens($('.takeover__screen'));

    this.handleSignup($('.signup-button'));
  },
  addTakeover: function(data) {
    const markup = template(takeoverTpl);
    this.takeoverContainer.html(markup(data));
    this.takeoverContent = $('.takeover');
    this.takeoverContent.hide();
    this.takeoverContent.delay(500).slideDown("slow", function() {});
  },
  handleSignup: function($button) {
    const _this = this;
    let ajaxPromise = $.Deferred().resolve().promise();

    $button.click(function(e) {
      e.preventDefault();

      const promise = _this.postSignup($(this));

      ajaxPromise = ajaxPromise.then(function() {
        return promise;
      }).done(_this.handleSuccess($button, promise));
    });
  },
  postSignup: function($button) {
    const _this = this;

    return $.ajax({
      method: 'POST',
      url: '/api/v1/campaigns/' + $button.data('campaign-id') +'/signup',
      dataType: 'json',
      headers: {
        'Accepts': 'application/json',
        'Content-Type': 'application/json',
        'X-CSRF-Token': $('meta[name="csrf-token"]').attr('content'),
      },
      data: JSON.stringify({
        'uid': $('meta[name="drupal-user-id"]').attr('content'),
        'source': 'multi-signup-module',
      }),
      beforeSend: function() {
        _this.addSpinner($button);
      },
    });
  },
  handleSuccess: function($button, data) {
    console.log($button);
    console.log(data);
    // // const $spinner = $('.spinner');
    // const signupId = data[0];
    // // console.log("signupId: " + signupId);
    // if (signupId) {
    //   // if ($spinner.length) {
    //     console.log("signed up");

    //     // this.addSignedUp($spinner);
    //   // }
    // } else {
    //   console.log("Already signedup")
    //   // this.addSignedUp($spinner, 'Already signed up');
    // }
  },
  scrollScreens: function($screens) {
    const screenCount = $screens.length;

    const $firstScreen = $screens.first();
    $firstScreen.addClass("active");

    $(".takeover__next").click(function() {
      // @TODO - move into function.
      const $current = $('.takeover__screen.active');
      // @TODO - ew, clean this up
      let index = ($current.data("index") < screenCount) ? (($current.data("index") + 1) > (screenCount - 1)) ? 0 : ($current.data("index") + 1) : 0;

      $current.removeClass("active");

      $(".takeover__screen[data-index='" + index + "']").addClass("active");
    });

    $(".takeover__previous").click(function() {
      const $current = $('.takeover__screen.active');

      let index = ($current.data("index") > 0) ? $current.data("index") - 1 : 3;

      $current.removeClass("active");

      $(".takeover__screen[data-index='" + index + "']").addClass("active");
    });
  },
  addSpinner: function($element) {
    const $container = $element.closest('.-signup');

    $container.html("<div class='spinner'></div>");
  },
  showFinish: function($element, text = null) {
    const $container = $element.closest('.-signup');
    const displayText = text ? text : 'Signed up!';

    $container.html('<p>' + displayText + '</p>');
  }
};





export default Signup;
