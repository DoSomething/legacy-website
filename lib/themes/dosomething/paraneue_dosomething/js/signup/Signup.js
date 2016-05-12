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
    this.takeoverContent.slideDown("slow", function() {});
    // this.takeoverContent.delay(2000).slideDown("slow", function() {});
  },
 
};





export default Signup;
