import takeoverTpl from 'signup/templates/takeover.tpl.html';

const $ = require('jquery');
const debounce = require('lodash/function/debounce');
const template = require('lodash/string/template');

const Signup = {
  baseUrl: '/api/v1/campaigns/',

  green: '#33cd5f',

  checkmark: $("<div>").html("&#10003;").text(),

  spinner: "<div class='spinner'></div>",

  screens: null,

  signupButton: null,

  /**
   * Initialize the Signup interface.
   *
   * @param  {jQuery} $takeoverContainer the element to add the taked over to.
   */
  init: function($takeoverContainer = $('.takeover-container')) {

    const data = {
      'header': 'Thank you for signing up!',
      'caption': 'Want to do more good? Sign up for similar campaigns below!',
      'campaigns': Drupal.settings.dosomethingCampaign.recommendedCampaigns,
    }

    // Add the takeover to the page.
    this.addTakeover($takeoverContainer, data, true);

    // Set up interactions
    this.screens = $('.takeover__screen');
    this.signupButton = $('.signup-button');
    this.scrollScreens(this.screens);
    this.handleSignups(this.signupButton);
  },

  /**
   * Adds the take over to the page with slide animation.
   *
   * @param  {jQuery} $container  the container to add the takeover to.
   * @param  {object} $data       An object containing the data to inject into the templates
   * @param  {bool}   slide       Whether or not to add the takeover with a slide animation.
   */
  addTakeover: function($container, data, slide = false) {
    const markup = template(takeoverTpl);
    $container.html(markup(data));
    this.takeoverContent = $('.takeover');

    if (slide) {
      this.takeoverContent.hide();
      this.takeoverContent.delay(500).slideDown("slow", function() {});
    }
  },

  /**
   * Binds click handlers to signup buttons that posts signs ups to phoenix.
   *
   * @param  {jQuery}   $button   Signup buttons
   */
  handleSignups: function($button) {
    const _this = this;

    // Create custom deferred promise object.
    let ajaxPromise = $.Deferred().resolve().promise();

    // Bind click handler
    $button.click(function(e) {
      e.preventDefault();

      const $this = $(this);
      const $buttonContainer = $this.closest('.-signup');

      // Make the ajax call, store the promise.
      const promise = _this.postSignup($this);

      // Fire done call backs in the order in which they were recieved.
      ajaxPromise = ajaxPromise.then(function() {
        return promise;
      }).done(function(data) {
        const signupId = data[0];

        if (signupId) {
          $this.val(_this.checkmark);
          $this.css('background-color', _this.green);
          $buttonContainer.html($this);
        // @TODO - How should we handle campaigns folks are already signed up for.
        // Do we even need to handle this case, ideally we would only show campaigns they
        // are not signed up for.
        } else {
          $this.val('Signed Up');
          $buttonContainer.html($this);
        }
      });
    });
  },

  /**
   * Posts signs up to phoenix via the api.
   *
   * @param  {jQuery}   $button   Signup buttons
   * @return {object}   The api response.
   */
  postSignup: function($button) {
    const _this = this;

    return $.ajax({
      method: 'POST',
      url: this.baseUrl + $button.data('campaign-id') +'/signup',
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

  /**
   * Handles the interaction of scrolling through different screens in the experience.
   *
   * @param  {jQuery}   $screens
   */
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

      // @todo - don't hard code these numbers.
      let index = ($current.data("index") > 0) ? $current.data("index") - 1 : 3;

      $current.removeClass("active");

      $(".takeover__screen[data-index='" + index + "']").addClass("active");
    });
  },

  /**
   * Handles the interaction of scrolling through different screens in the experience.
   *
   * @param  {jQuery}   $screens
   */
  addSpinner: function($element) {
    console.log("add spinner");
    console.log($element);
    const $container = $element.closest('.-signup');
    console.log($container);

    $container.html("<div class='spinner'></div>");
  },
};

export default Signup;
