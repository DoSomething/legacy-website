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
	$takeoverContainer.html(markup({ 'fake': 'fake shit'}));
 	// console.log(markup({ 'fake': 'fake shit'}));
  },
 
};





export default Signup;
