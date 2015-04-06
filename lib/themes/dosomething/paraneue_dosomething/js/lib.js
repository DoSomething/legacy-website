// Attach jQuery to the window for backwards compatibility
import jQuery from 'jquery';
window.jQuery = jQuery;
window.$ = jQuery;

// Mailcheck, for email validation & suggestions
import 'mailcheck';

// jQuery Once plugin
var once = require('jquery-once');

// $.unveil plugin for lazy-loading images
var unveil = require('unveil');

// IE8 polyfill for $.ajax CORS support
var iecors = require('jquery.iecors');

// RequestAnimationFrame polyfill
import 'raf.js';

// Filament Group's fixed-sticky polyfill for `position: sticky`
var fixedsticky = require('fixed-sticky');
