// Attach jQuery to the window for backwards compatibility
var jQuery = require('jquery');
window.jQuery = jQuery;
window.$ = jQuery;

// Mailcheck, for email validation & suggestions
require('mailcheck');

// jQuery Once plugin
require('jquery-once');

// $.unveil plugin for lazy-loading images
require('unveil');

// IE8 polyfill for $.ajax CORS support
require('jquery.iecors');

// RequestAnimationFrame polyfill
require('raf.js');

// Filament Group's fixed-sticky polyfill for `position: sticky`
require('fixed-sticky');
