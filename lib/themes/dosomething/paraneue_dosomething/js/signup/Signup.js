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
    $button.click(function() {
      const $this = $(this);
      const campaignId = $this.data('campaign-id');

      $.ajax({
        method: 'POST',
        url: '/api/v1/campaigns/' + campaignId +'/signup',
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
          const $buttonContainer = $this.closest('.takeover__campaign-item');

          $buttonContainer.html("<div class='spinner'></div>");
        },
        success: function(data) {
          const $buttonContainer = $('.spinner').closest('.takeover__campaign-item');
          console.log($buttonContainer);
          $buttonContainer.html('<p>Signed Up!</p>');
        }
      })
    });
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
      // $(".takeover__screen[data-index='" + index + "']").animate({width:'toggle'},350);
    });

    $(".takeover__previous").click(function() {
      const $current = $('.takeover__screen.active');

      let index = ($current.data("index") > 0) ? $current.data("index") - 1 : 3;

      $current.removeClass("active");

      $(".takeover__screen[data-index='" + index + "']").addClass("active");
      // $(".takeover__screen[data-index='" + index + "']").animate({width:'toggle'},350);
    });
  },
};





export default Signup;
