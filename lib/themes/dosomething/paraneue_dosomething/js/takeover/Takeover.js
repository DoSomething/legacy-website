var Validation = require("dosomething-validation");

// @IDEA - Let this just take care of screen interactions, pull in custom stuff via classes
import takeoverTpl from 'takeover/templates/takeover.tpl.html';

const $ = require('jquery');
const template = require('lodash/string/template');

const Takeover = {
  baseUrl: '/api/v1/campaigns/',

  spinner: '<div class="spinner"></div>',

  screens: null,

  firstScreen: null,

  lastScreen: null,

  screenIndexes: null,

  /**
   * Initialize the Signup interface.
   *
   * @param  {jQuery} $takeoverContainer the element to add the taked over to.
   */
  init: function($takeoverContainer = $('.takeover-container')) {
    const data = {
      'header': 'Thanks for signing up',
    }

    // Add the takeover to the page.
    const slide = $takeoverContainer.hasClass('-no-slide') ? false : true;
    this.addTakeover($takeoverContainer, data, slide);

    // Prepare validation fields that got entered into the DOM after page load.
    Validation.prepareFields($('input'));

    // Set up interactions
    this.screens = $('.takeover__screen');
    this.screenIndexes = this.setScreenIndexes();
    this.firstScreen = this.screens.first();
    this.lastScreen = this.screens.last();
    this.firstScreen.addClass('active');

    // Set up submit handlers.
    this.submitButton = $('.submit-postal-code');
    this.handleSubmit(this.submitButton);
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
      this.takeoverContent.delay(500).slideDown('slow', function() {});
    }
  },

  /**
   * Binds click handlers to signup buttons that posts signs ups to phoenix.
   *
   * @param  {jQuery}   $button   Signup buttons
   */
  handleSubmit: function($button) {
    const _this = this;

    // Create custom deferred promise object.
    let ajaxPromise = $.Deferred().resolve().promise();

    // Bind click handler
    $button.click(function(e) {
      e.preventDefault();

      const $this = $(this);

      if (! $('.validation__message.has-error').length) {
        // Make the ajax call, store the promise.
        const promise = _this.sendRequest($this, 'GET', 'http://jsonplaceholder.typicode.com/posts/1');

        // Fire done call backs in the order in which they were recieved.
        ajaxPromise = ajaxPromise.then(function() {
          return promise;
        }).done(function(data) {
          _this.changeScreens('next');
        });
      }
    });
  },

  /**
   * Posts signs up to phoenix via the api.
   *
   * @param  {jQuery}   $button   Signup buttons
   * @return {object}   The api response.
   */
  sendRequest: function($button, method, url, data = null) {
    const _this = this;

    return $.ajax({
      method: method,
      url: url,
      dataType: 'json',
      // headers: {
      //   'Accepts': 'application/json',
      //   'Content-Type': 'application/json',
      //   'X-CSRF-Token': $('meta[name="csrf-token"]').attr('content'),
      // },
      // data: JSON.stringify({
      //   'uid': $('meta[name="drupal-user-id"]').attr('content'),
      //   'source': 'multi-signup-module',
      // }),
      // data: data,
      beforeSend: function() {
        _this.addSpinner($button);
      },
    });
  },

  /*
   * Store the indexes of each of the screens provided in the template.
   */
  setScreenIndexes: function() {
    let indexes = [];

    $.each(this.screens, function(scr) {
      indexes.push($(scr).data('index'));
    });

    return indexes;
  },

  /**
   * Handles makeing a new scren active based on the direction passed.
   *
   * @param  {string}   direction
   */
  changeScreens: function(direction) {
    // Check if an allowed direction was passed in.
    if ($.inArray(direction, ['next', 'previous']) === -1) {
      return;
    }

    const $current = $('.takeover__screen.active');
    const currentIndex = $current.data('index');
    const newIndex = (direction === 'next') ? currentIndex + 1 : currentIndex - 1;

    // Check if the new screen exists, if so, go there, otherwise we need to loop back.
    if ($.inArray(newIndex, this.screenIndexes)) {
      $current.removeClass('active');
      $('.takeover__screen[data-index="' + newIndex + '"]').addClass('active');
    } else {
      if (direction === 'next') {
        this.firstScreen.addClass('active');
      } else {
        this.lastScreen.addClass('active');
      }
    }

    this.reset();
  },

  /**
   * Handles the interaction of scrolling through different screens in the experience.
   *
   * @param  {jQuery}   $screens
   */
  addSpinner: function($element) {
    const $container = $element.closest('.submit-button-container');

    $container.html(this.spinner);
  },

  /*
   * Resets the functionality.
   * Currently, specific to the organ donation interactions, but would love
   * a way of figuring out if it could be more general. Maybe we could pass in a function
   * defined in some custom js to run when this function gets called.
   */
  reset: function() {
    const _this = this;

    if ($('.submit-button-container').find('.spinner').length) {
      $('.submit-button-container').html('<input type="submit" class="button submit-postal-code" value="Submit" />');
      this.submitButton = $('.submit-postal-code');
      this.handleSubmit(this.submitButton);

      $('.back-button').off('click');
    }

    if ($('.takeover__screen .back-button').length) {
      // @TODO - some sort of load screen function? Maybe take in the different
      // screens as different templates, this function loads the next template and
      // resets it's DOM.
      $('.takeover__screen .back-button').click(function(e) {
        e.preventDefault();

        _this.changeScreens('previous');
      });
    }
  },
};

export default Takeover;
