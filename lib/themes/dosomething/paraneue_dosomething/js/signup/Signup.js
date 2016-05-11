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

	// Add the takeover to the page.
	this.takeoverContainer.html(markup({ 'header': 'Thank you for signing up!'}));

	this.takeoverContent = $('.takeover');
	this.takeoverContent.hide();
 	this.takeoverContent.delay(2000).slideDown("slow", function() {});
  },
 
};





export default Signup;
