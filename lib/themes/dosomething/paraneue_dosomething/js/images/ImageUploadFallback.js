/**
 * Provides a fallback for customized file input if the File API is not supported.
 */
define(function(require) {
  "use strict";

  var $                    = require("jquery");
  var _                    = require("lodash");
  var fallbackUploadTplSrc = require("text!images/templates/fallback-upload-interface.tpl.html");


  var ImageUploadFallback = {

    component: {
      $origButton: null,
      $newButton: null,
      id: null,
      name: null,
      classes: [
        'button',
        'button--file',
        '-tertiary'
      ]
    },


    /**
     * Initialize the fallback file input script.
     * @param  jQuery Object $input    Button input from form.
     * @param  String        container Class name for container that should house fallback content.
     * @return void
     */
    init: function ($input, container) {
      _this = this;

      console.log($input);
      console.log(this.component);

      this.$fileInput = $input;

      this.component.$origButton = this.$fileInput.parent();
      // this.button.id = this.$fileInput.attr('id');
      // this.button.name = this.$fileInput.attr('name');
      // this.$container = this.$fileInput.closest(container);

      // console.log(this.button);

      this.$fileInput.on('change', function (event) {
        console.log(_this.component);
      //   var fileName = _this.getFileName(event.target.value);

      //   _this.buildReplacementInterface(fileName);
      });
    },
  };


  return ImageUploadFallback;
});
