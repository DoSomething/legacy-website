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
 	// console.log(markup({ 'fake': 'fake shit'}));
 	// $takeoverContainer.css("height", 1000);
	$takeoverContainer.html(markup({ 'fake': 'fake shitdsfjkldsfjkldsfjkdslfjksdl'}));
	const $takeoverContent = $('.takeover');
	$takeoverContent.hide();
 	$takeoverContent.delay(2000).slideDown("slow", function() {

 	});
  },
 
};





export default Signup;
