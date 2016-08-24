/* eslint-disable */

/* ----------------------------------------------------------
 * @TODO: ^ Enable linting by removing `eslint-disable`! ^
 * ----------------------------------------------------------
 * Linting is disabled in this file. Remove this line and
 * clean this file up according to our coding standards next
 * time it is touched.
 */

/**
 * Provides a fallback for customized file input if the File API is not supported.
 */
define(function(require) {
  "use strict";

  var $                    = require("jquery");
  var template             = require("lodash/template");
  var fallbackUploadTplSrc = require("images/templates/fallback-upload-interface.tpl.html");


  var ImageUploadFallback = {

    component: {
      $container: null,
      $fileInterface: null,
      $indicator: null,
      $input: null,
      fileName: null,
      id: null,
      classes: [
        'button',
        'button--file',
        '-tertiary'
      ]
    },


    /**
     * Initialize the fallback file input script.
     * @param  {jQuery}  $input     Button input from form.
     * @param  {string}  container  Container Class name for container that should house fallback components.
     * @return void
     */
    init: function ($input, container) {
      $input.attr('class', '');

      this.component.$input = $input;
      this.component.id = $input.attr('id');
      this.component.$container = $(container);

      this.activateInput(this.component.$input);
    },


    /**
     * Activate the input to watch for file input change event.
     * @param  {jQuery}  $input Specific file input.
     * @return void
     */
    activateInput: function ($input) {
      var _this = this;

      $input.on('change', function (event) {
        _this.component.fileName = _this.getFileName(event.target.value);

        if (_this.component.$fileInterface) {
          _this.updateFileSelection();
        }
        else {
          _this.buildUpatedComponent();
        }
      });
    },


    /**
     * Remove markup from the specified container.
     * Clear it out to insert new interface.
     * @return void
     */
    emptyContainer: function () {
      this.component.$container.html('');
    },


    /**
     * Get the file name for the uploaded file.
     * @param  {string}  path  Full path string for uploaded image.
     * @return string          Extracted file name from the full path.
     */
    getFileName: function (path) {
      var start = path.indexOf("fakepath\\");

      if (start >= 0) {
        return path.substring(start + 9, path.length); // 9 is length of "fakepath\"
      }

      return path;
    },


    /**
     * Construct the new interface component for the file api fallback.
     * @return void
     */
    buildUpatedComponent: function () {
      var data = {
        "id": this.component.id,
        "classes": this.component.classes.join(' '),
        "file": this.component.fileName
      };

      var markup = template(fallbackUploadTplSrc)(data);
      var $markup = $(markup);

      this.component.$input.detach();
      $markup.find('.button--file').append(this.component.$input);

      this.emptyContainer();
      this.component.$indicator = $markup.find('.file-selection__name');
      this.component.$fileInterface = $markup;
      this.insertUpdatedComponent();
    },


    /**
     * Insert the new interface into the specified container.
     * @return void
     */
    insertUpdatedComponent: function () {
      this.component.$container.prepend(this.component.$fileInterface);
    },


    /**
     * Update just the file name displayed in the new file api interface.
     * @return void
     */
    updateFileSelection: function () {
      this.component.$indicator.text(this.component.fileName);
    }
  };


  return ImageUploadFallback;
});
