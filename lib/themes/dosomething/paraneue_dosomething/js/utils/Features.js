/**
 * @module utils/Features
 * Methods to test browser support.
 */
define(function() {
  "use strict";

  var $ = require("jquery");

  /**
   * Checks if media queries are supported by the browser.
   * @see https://github.com/scottjehl/Respond/blob/master/src/respond.js#L68
   *
   * @returns {Boolean} Browser support for media queries.
   */
  var mediaQueries = function() {
    return window.matchMedia && window.matchMedia("only all") !== null && window.matchMedia("only all").matches;
  };

  /**
   * Checks if REM units are supported by the browser.
   * @see https://github.com/chuckcarpenter/REM-unit-polyfill/blob/master/js/rem.js#L4-L9
   *
   * @returns {Boolean} Browser support for REM units.
   */
  var remUnits = function() {
    var div = document.createElement("div");
    div.style.cssText = "font-size: 1rem;";

    return (/rem/).test(div.style.fontSize);
  };

  /**
   * Checks if Internet Explorer 8 or lower.
   * @returns {Boolean} Browser is IE8 or lower.
   */
  var _ie8 = $("html").hasClass("ie8");
  var ie8 = function() {
    return _ie8;
  };

  /**
   * Checks if Internet Explorer 9.
   * @returns {Boolean} Browser is IE9.
   */
  var _ie9 = $("html").hasClass("ie9");
  var ie9 = function() {
    return _ie9;
  };

  // Export API
  return {
    mediaQueries: mediaQueries,
    remUnits: remUnits,
    ie8: ie8,
    ie9: ie9
  };
});
