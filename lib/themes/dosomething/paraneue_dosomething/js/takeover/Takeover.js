import Validation from 'dosomething-validation';
import setting from '../utilities/Setting';

const $ = require('jquery');
const template = require('lodash/string/template');

class Takeover {
  constructor($takeoverContainer, tpl) {
    this.$el = $takeoverContainer;
    this.template = tpl;
    this.baseUrl  = window.location.origin;
    this.spinner  = '<div class="spinner"></div>';
    this.activeClass = 'is-active';

    const data = {
      'shareLink': Drupal.settings.dosomethingUser.shareLink,
      'shareButtonMarkup': Drupal.settings.dosomethingUser.shareButtonMarkup,
    }

    this.addTakeover($takeoverContainer, data);

    // Initialize screens in the experience.
    this.screens = this.$el.find('.takeover__screen');
    this.screenInit(this.screens);

    // Initialize Validation
    Validation.prepareFields($('input'));
  }

  screenInit($screens) {
    this.screenIndexes = this.setScreenIndexes();
    this.firstScreen = this.screens.first();
    this.lastScreen = this.screens.last();
    this.firstScreen.addClass('is-active');
  }

  /**
   * Adds the takeover to the page with or without a slide animation.
   *
   * @param  {jQuery} $container  the container to add the takeover to.
   * @param  {object} $data       An object containing the data to inject into the templates
   */
  addTakeover($container, data) {
    const markup = template(this.template);

    $container.html(markup(data));

    this.takeoverContent = this.$el.find('.takeover');
  }

  /*
   * Store the indexes of each of the screens provided in the template.
   */
  setScreenIndexes() {
    let indexes = [];

    this.screens.each((key, scr) => indexes.push($(scr).data('index')));

    return indexes;
  }

  /**
   * Handles makeing a new scren active based on the direction passed.
   *
   * @param  {string}   direction
   */
  changeScreens(direction) {
    // Check if an allowed direction was passed in.
    if ($.inArray(direction, ['next', 'previous']) === -1) {
      return;
    }

    const $current = $(`.takeover__screen.${this.activeClass}`);
    const currentIndex = $current.data('index');
    const newIndex = (direction === 'next') ? currentIndex + 1 : currentIndex - 1;

    // Check if the new screen exists, if so, go there, otherwise we need to loop back.
    if ($.inArray(newIndex, this.screenIndexes) !== -1) {
      $current.removeClass(this.activeClass);
      this.$el.find(`.takeover__screen[data-index="${newIndex}"]`).addClass(this.activeClass);
    } else {
      if (direction === 'next') {
        this.firstScreen.addClass(this.activeClass);
      } else {
        this.lastScreen.addClass(this.activeClass);
      }
    }

    this.set();
  }

  /**
   * Binds click handlers to $button that sends an AJAX request and uses deferred promises to
   * run callbacks in the order in which they are recieved.
   *
   * @param  {jQuery}   $button   Signup buttons
   * @param  {object}   request   An object that defines the properties we need to make a request.
   */
  handleSubmit($button, request) {
    // Create custom deferred promise object.
    let ajaxPromise = $.Deferred().resolve().promise();

    $button.click(e => {
      e.preventDefault();

      if (! this.$el.find('.validation__message.has-error').length) {
        // Make the ajax call, store the promise.
        const promise = this.sendRequest(request);

        // Fire done call backs in the order in which they were recieved.
        ajaxPromise = ajaxPromise.then(promise => { return promise } ).done( data => this.changeScreens('next'));
      }
    });
  }

  /**
   * Sends an AJAX request using the provided information in the request object that is passed in.
   *
   * @param  {request}   The object containing the details about the request i.e URL, method, data
   * @return {object}    The api response.
   */
  sendRequest(request) {
    const _this = this;

    return $.ajax({
      method: request.method,
      url: request.url,
      dataType: 'json',
      data: request.data,
      beforeSend: function() {
        _this.toggleSpinner(request.button);
      },
      complete: function() {
        _this.toggleSpinner(request.button);
      }
    });
  }

  /**
   * Toggles the display of a spinner to signify a request is in the works.
   *
   * @param  {jQuery}   $element
   */
  toggleSpinner($element) {
    if (this.$el.find('.spinner').length) {
      this.$el.find('.spinner').parent().html($element);
    } else {
      $element.parent().html(this.spinner);
    }
  }

  /**
   * Checks if a screen is active
   *
   * @param  {jQuery}   $element
   */
  isActive($element) {
    return $element.hasClass(this.activeClass);
  }

  /**
   * Adds validation message to an element
   *
   * @param  {jQuery}   $element
   * @param  {string}   msg
   */
  showValidationMessage($element, msg) {
    Validation.showValidationMessage($element, {message: msg});
  }

  /*
   * Handles back buttons.
   */
  goBack() {
    const $backButton = this.$el.find('.takeover__screen .back-button');

    if ($backButton.length) {
      $backButton.click(e => {
        e.preventDefault();

        this.changeScreens('previous');
      });
    }
  }
}

export default Takeover;
