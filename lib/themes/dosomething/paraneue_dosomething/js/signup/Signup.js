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
    const markup = template(takeoverTpl);

    this.takeoverContainer = $takeoverContainer;

    const data = {
      'header': 'Thank you for signing up!',
      'caption': 'Want to do more good? Sign up for similar campaigns below!',
    }

    // Add the takeover to the page.
    this.takeoverContainer.html(markup(data));

    this.takeoverContent = $('.takeover');
    this.takeoverContent.hide();
    // this.takeoverContent.slideDown("slow", function() {});
    this.takeoverContent.delay(1000).slideDown("slow", function() {});

   const $signupButton = $('.signup-button');

   $signupButton.click(function() {
      const $this = $(this);
      const campaignId = $this.data('campaign-id');

      $.ajax({
        method: 'POST',
        url: '/api/v1/campaigns/' + campaignId +'/signup', //id ? `/api/v1/kudos/${id}` : '/api/v1/kudos',
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
          console.log("beforeSend");
          const $buttonContainer = $this.closest('.takeover__campaign-item');
          $buttonContainer.html("<div class='spinner'></div>");
        },
        success: function(data) {
          console.log('success');
          console.log(data);

          const $buttonContainer = $('.spinner').closest('.takeover__campaign-item');
          console.log($buttonContainer);
          $buttonContainer.html('<p>done</p>');
        }
      })
   });
  },
 
};





export default Signup;
