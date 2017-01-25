// Attach jQuery to the window for backwards compatibility
const jQuery = require('jquery');
window.jQuery = jQuery;

// jQuery Once plugin
require('jquery-once');

// window.requestAnimationFrame polyfill
require('raf.js');

// Filament Group's fixed-sticky polyfill for `position: sticky`
require('fixed-sticky');

// WHATWG fetch API polyfill
require('whatwg-fetch');
