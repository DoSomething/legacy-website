define(function(require) {
  "use strict";

  var $ = require("jquery");

  /**
   * Allows for specified grouping of elements to be hidden and then revealed 
   * via an interactive "Show More" button.
   * 
   * @param {jQuery} $container The container element object that encloses the items to hide.
   * @param {jQuery} $content   A collection of objects to hide.
   * @param {string} category   Specify a category type for the content to provide more unique behavior.
   */
  var Revealer = function($container, $content, category) {
    this.$container = $container;
    this.$content   = $content;
    this.$button    = $("<button class=\"btn tertiary\">Show More</button>");
    this.category   = category;

    this.init();
  };


  Revealer.prototype.init = function () {
    this.detachContent();
    this.enableButton();
  };


  Revealer.prototype.detachContent = function () {
    if (this.category === "gallery") {
      this.$content = this.$content.slice(5);
    }

    this.$content.detach();
  };


  Revealer.prototype.reattachContent = function () {
    this.$container.append(this.$content);
  };


  Revealer.prototype.enableButton = function () {
    this.$button.insertAfter(this.$container);

    var _this = this;

    this.$button.on("click", function () {
      _this.reattachContent();
      _this.$button.remove();
    });
  };


  return Revealer;

});
