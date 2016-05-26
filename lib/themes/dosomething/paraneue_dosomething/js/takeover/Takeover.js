import Validation from 'dosomething-validation';
import setting from '../utilities/Setting';

// @IDEA - Let this just take care of screen interactions, pull in custom stuff via classes
import takeoverTpl from 'takeover/templates/takeover.tpl.html';

const $ = require('jquery');
const template = require('lodash/string/template');

const Takeover = {
  baseUrl: $(location).attr("origin"),

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
    this.handleSubmit(this.submitButton, {
      'button' : this.submitButton,
      'method' : 'GET',
      'url'    : 'http://jsonplaceholder.typicode.com/posts/1',
      'data'   : null,
    });
  },

  /**
   * Adds the takeover to the page with or without a slide animation.
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
   * Binds click handlers to $button that sends an AJAX request and uses deferred promises to
   * run callbacks in the order in which they are recieved.
   *
   * @param  {jQuery}   $button   Signup buttons
   * @param  {object}   request   An object that defines the properties we need to make a request.
   */
  handleSubmit: function($button, request) {
    const _this = this;

    // Create custom deferred promise object.
    let ajaxPromise = $.Deferred().resolve().promise();

    // Bind click handler
    $button.click(function(e) {
      e.preventDefault();

      const $this = $(this);

      if (! $('.validation__message.has-error').length) {
        // Make the ajax call, store the promise.
        const promise = _this.sendRequest(request);

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
   * Sends an AJAX request using the provided information in the request object that is passed in.
   *
   * @param  {request}   The object containing the details about the request i.e URL, method, data
   * @return {object}   The api response.
   */
  sendRequest: function(request) {
    const _this = this;

    return $.ajax({
      method: request.method,
      url: request.url,
      dataType: 'json',
      headers: {
        'Accepts': 'application/json',
        'Content-Type': 'application/json',
        'X-CSRF-Token': $('meta[name="csrf-token"]').attr('content'),
      },
      data: request.data,
      beforeSend: function() {
        _this.addSpinner(request.button);
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
   * Adds a spinner to $element to signify a request is in the works.
   *
   * @param  {jQuery}   $element
   */
  addSpinner: function($element) {
    const $container = $element.closest('.submit-button-container');

    $container.html(this.spinner);
  },

  /*
   ****************************
   * MAJOR WIP: This is currently functionality very specific to what we need for organ donations.
   * Will be working on separating out the Takeover/modal responsibilities from the functionality that we
   * actually need in each "screen" of the modal in a different PR. I don't want to block other work while
   * I work on this.
   ****************************
   *
   * Sets up screen functionality.
   */
  reset: function() {
    const _this = this;

    const $submitZipCodeContainer = $('.submit-button-container');

    if ($submitZipCodeContainer.find('.spinner').length) {
      $submitZipCodeContainer.html('<input type="submit" class="button submit-postal-code" value="Submit" />');

      this.submitButton = $('.submit-postal-code');
      // @TODO - actually hit the Oraganize API.
      this.handleSubmit(this.submitButton, {
        'button' : this.submitButton,
        'method' : 'GET',
        'url'    : 'http://jsonplaceholder.typicode.com/posts/1',
        'data'   : null,
      })

      $('.back-button').off('click');
    }

    const $backButton = $('.takeover__screen .back-button');

    if ($backButton.length) {
      $('.takeover__screen .back-button').click(function(e) {
        e.preventDefault();

        _this.changeScreens('previous');
      });
    }

    const $submitRegContainer = $('.submit-registration-container');

    if ($submitRegContainer.length) {
      const sid = setting('dosomethingSignup.sid');

      this.handleSubmit($submitRegContainer.find('.submit-registration'), {
        'button' : $submitRegContainer.find('.submit-registration'),
        'method' : 'GET',
        'url'    : _this.baseUrl + '/organ-donation/registration',
        'data'   : {
          'sid' : sid,
          'uid' : $('meta[name="drupal-user-id"]').attr('content')
        },
      });
    }
  },
};

export default Takeover;
