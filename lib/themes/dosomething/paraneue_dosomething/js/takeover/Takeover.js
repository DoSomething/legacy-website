import Validation from 'dosomething-validation';
import setting from '../utilities/Setting';

const $ = require('jquery');
const template = require('lodash/string/template');

class Takeover {
  constructor($takeoverContainer) {
    this.$el = $takeoverContainer;
    this.baseUrl  = window.location.origin;
    this.spinner  = '<div class="spinner"></div>';
    this.activeClass = 'is-active';

    this.screenInit(this.$el.find('.takeover__screen'));
  }

  /*
   * Stores all the screens in an array based on the indexes in template. Store the first/last screen.
   *
   * @param  {jQuery}  $screens
   */
  screenInit($screens) {
    this.screenIndexes = this.setScreenIndexes($screens);
    this.firstScreen = $screens.first();
    this.lastScreen = $screens.last();
  }

  /*
   * Store the indexes of each of the screens provided in the template.
   *
   * @param  {jQuery}  $screens
   */
  setScreenIndexes($screens) {
    let indexes = [];

    $screens.each((key, scr) => indexes.push($(scr).data('index')));

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
   * Sends a request using the provided information in the request object that is passed in.
   *
   * @param  {request}   The object containing the details about the request i.e URL, method, data
   * @return {object}    Promise
   */
  sendRequest(request) {
    return fetch(request.url, {
      method: request.method,
      credentials: 'same-origin',
      headers: {
        'X-CSRF-Token': $('meta[name="csrf-token"]').attr('content')
      }
    })
    .then(response => response.json());
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
    console.log(msg);
    Validation.showValidationMessage($element, {message: msg});
  }

  /**
   * Prepare fields for validation.
   *
   * @param  {jQuery}   $fields
   */
  prepareFieldValidation($fields) {
    Validation.prepareFields($fields);
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

  /*
   * Load a specific screen in the modal flow.
   *
   * @param  {jQuery}   $screen
   */
  loadScreen($screen) {
    this.$el.find(`.takeover__screen.${this.activeClass}`).removeClass(this.activeClass);
    $screen.addClass(this.activeClass);
  }

  /*
   * Add a compiled lodash template to a container element.
   *
   * @param  {jQuery}   $container
   * @param  {string}   tpl
   * @param  {object}   data
   */
  addTemplate($container, tpl, data) {
    data = (data) ? data : {};

    const markup = template(tpl);

    $container.html(markup(data))
  }

  /*
   * Resize an elemen based on the height of it's contents
   *
   * @param  {jQuery}   $container
   * @param  {jQuery}   $referenceHeight
   * @param  {int}      padding
   */
  resizeContainerHeight($container, $referenceHeight, padding = 100) {
    $container.height($referenceHeight.height() + padding);
  }
}

export default Takeover;
