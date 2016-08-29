// Attach jQuery to the window for backwards compatibility
import jQuery from 'jquery';
window.jQuery = jQuery;
window.$ = jQuery;

// Mailcheck, for email validation & suggestions
import 'mailcheck';

// jQuery Once plugin
import 'jquery-once';

// $.unveil plugin for lazy-loading images
import 'unveil';

// IE8 polyfill for $.ajax CORS support
import 'jquery.iecors';

// RequestAnimationFrame polyfill
import 'raf.js';

// Filament Group's fixed-sticky polyfill for `position: sticky`
import 'fixed-sticky';

// WHATWG fetch API polyfill
import 'whatwg-fetch';
