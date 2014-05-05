/**
 * @module utils/Features
 * Methods to test browser support.
 */
define(function() {
  "use strict";

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


  // Export API
  return {
    mediaQueries: mediaQueries,
    remUnits: remUnits
  };
});
