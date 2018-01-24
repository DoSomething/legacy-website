/* eslint-disable */

/* ----------------------------------------------------------
 * @TODO: ^ Enable linting by removing `eslint-disable`! ^
 * ----------------------------------------------------------
 * Linting is disabled in this file. Remove this line and
 * clean this file up according to our coding standards next
 * time it is touched.
 */

define(function(require) {
  "use strict";

  var $                = require("jquery");
  var Modal            = require("dosomething-modal");
  var Validation       = require("dosomething-validation");
  var ImageCrop        = require("images/ImageCrop");
  var ImageCropPreview = require("../images/ImageCropPreview");


  /**
   * Handles the modal interface for image upload buttons.
   * Requires a modal to be on the page with an id '#modal--crop'
   * The modal should have a form '#dosomething-reportback-image-form'
   * and a div to place the image preview '.image-wrapper'.
   *
   * @param {jQuery} $button  The file upload button
   */
  var ImageUpload = function($button) {
    this.$uploadButton          = $button;
    this.$uploadButtonLabel     = this.$uploadButton.closest('label');
    this.$cropModal             = $("#modal--crop");
    this.$reportbackForm        = $("#dosomething-reportback-form");
    this.$reportbackFormSubmit  = this.$reportbackForm.find(".form-submit");
    this.$imageForm             = this.$cropModal.find("#dosomething-reportback-image-form");
    this.$imageCaption          = this.$imageForm.find("#modal-caption");
    this.$cropButton            = this.$imageForm.find(".button");
    this.$imagePreview          = this.$cropModal.find(".image-preview");
    this.$reportbackSubmissions = $(".reportback__submissions");
    this.imageValues            = {};
    this.readyToSave            = false;

    // Validation
    this.fileTypes              = ["image/png", "image/gif", "image/jpeg", "image/pjpeg"];
    this.fileSizeLimit          = 10000000; // 10mb
    this.typeError              = "Only JPEG, PNG, and GIF images are allowed";
    this.dimensionsError        = "Please upload a larger photo. Min. size is 480px by 480px.";
    this.sizeError              = "Please upload an image under 10MB";

    this.init();
  };

  /**
   * Initalizes event listeners
   *
   */
  ImageUpload.prototype.init = function () {
    var _this = this;

    this.$uploadButton.on("change", function(event) {
      event.preventDefault();

      var files = !!this.files ? this.files : [];

      // If no file selected/no FileReader support, we're all done
      if (!files.length || !window.FileReader) {
        return;
      }

      // Validate image type and file size before proceeding.
      if (!_this.validImageType(files)) {
        _this.showError(_this.typeError);

        return;
      }

      if (!_this.validFileSize(files)) {
        if (typeof ga !== 'undefined' && ga !== null) {
          ga('send', 'event', 'Reportback', 'image file too large');
        }
        _this.showError(_this.sizeError);

        return;
      }

      // The image is valid, so let users submit the reportback form.
      _this.enableSubmit(_this.$reportbackFormSubmit);

      var fr = new FileReader();

      if (window.navigator.userAgent.match(/iPad/i) || window.navigator.userAgent.match(/iPhone/i)) {
        fr.readAsArrayBuffer(this.files[0]);
        fr.onload = function () {
          var blob = _this.getStrippedBlob(this.result);
          var urlCreator = window.URL || window.webkitURL;
          var imageUrl = urlCreator.createObjectURL(blob);
          _this.loadImage(imageUrl);
        };
      }
      else {
        fr.readAsDataURL(files[0]);

        fr.onloadend = function() {
          var result = this.result;
          _this.loadImage(result);
        };
      }
    });

    Modal.Events.subscribe("Modal:Close", function() {
      _this.resetFileField();

      // Move the upload button back into the form.
      _this.moveUploadButton(_this.$uploadButtonLabel);

      if (_this.readyToSave) {
        // Add a button to edit the image.
        _this.createEditButton();
      }
    });

    // When the modal opens, move the upload button into the modal,
    // so users can change their photo.
    Modal.Events.subscribe("Modal:Open", function() {
      _this.moveUploadButton($(".-change .button"));
    });
  };

  /**
   * Detatches and moves the current upload button
   * @param {jQuery}  $el  The element to move the button to.
   */
  ImageUpload.prototype.moveUploadButton = function($el) {
    var $button = this.$uploadButton.detach();

    $button.appendTo($el);
  };

  /**
   * Validates the caption field in the modal.
   * @param  {Function} callback  If validation passes, then lets rock on!
   * @return {void}
   */
  ImageUpload.prototype.validateCaption = function(callback, image) {
    var _this = this;

    Validation.validateField(this.$imageCaption, true, function($field, result) {
      Validation.showValidationMessage($field, result);

      if (result.success) {
        callback(_this, image);
      }
    });
  };


  /**
   * Everything is set, engage in cropping the selected image.
   * @param  {object} data  ImageUpload object.
   * @param  {object} image  Image object.
   * @return {void}
   */
  ImageUpload.prototype.engageImageCrop = function(data, image) {
    var _this = data;

    // Send crop information to the main reportback form
    // so backend can use to crop.
    ImageCrop.populateFields(_this.$reportbackForm);

    // Create a crop preview on the client side.
    ImageCropPreview.cropPreview(image, _this.getCropValues());

    // The user clicked "done", so we can save this version of the crop
    // and not reset the file field.
    _this.readyToSave = true;

    // Close the modal.
    Modal.close();
  };


  /**
   * Opens the modal making sure the done button is reset.
   */
  ImageUpload.prototype.openModal = function() {
    this.enableSubmit(this.$cropButton);

    Modal.open(this.$cropModal,
      {
        animated: false,
        closeButton: "closeButtonOnly"
      }
    );
  };

  /**
   * Clears the file field input and resets it globally,
   * if the user accidentally closed out of the modal.
   * Allows the user to re-upload an image and edit it.
   */
  ImageUpload.prototype.resetFileField = function() {
    var $input = this.$uploadButton;

    if (!this.readyToSave) {
      $input.replaceWith(this.$uploadButton = $input.val("").clone(true));
    }
  };

  /**
   * Creates a button the user can click to re-open the modal
   * and edit the crop they selected.
   */
  ImageUpload.prototype.createEditButton = function() {
    var _this = this;
    if (!this.$reportbackSubmissions.find(".button--edit").length) {
      var $editButton = $("<span class='button button--edit -tertiary'>" + Drupal.t('edit photo') + "</span>");
      this.$uploadButton.parent().hide().before($editButton);

      $editButton.click(function() {
        _this.openModal();
      });
    }
  };

  /**
   * Gets crop values from form and returns an object.
   */
  ImageUpload.prototype.getCropValues = function() {
    return {
      x       : this.$reportbackForm.find("input[name='crop_x']").val(),
      y       : this.$reportbackForm.find("input[name='crop_y']").val(),
      width   : this.$reportbackForm.find("input[name='crop_width']").val(),
      height  : this.$reportbackForm.find("input[name='crop_height']").val(),
      degrees : parseInt(this.$reportbackForm.find("input[name='crop_rotate']").val()),
      caption : this.$reportbackForm.find("input[name='caption']").val()
    };
  };

  /**
   * Enables submit button in modal when it opens.
   */
  ImageUpload.prototype.enableSubmit = function($submitButton) {

    if ($submitButton.prop("disabled")) {
      $submitButton.prop("disabled", false);
    }

    if ($submitButton.hasClass("is-loading")) {
      $submitButton.removeClass("is-loading");
    }
  };

  /**
   * Validates image size.
   */
  ImageUpload.prototype.validImageSize = function(image) {
    return (image.width >= 480 && image.height >= 480);
  };

  /**
   * Validates image type.
   */
  ImageUpload.prototype.validImageType = function(files) {
    // Get the file extension.
    var extension = files[0].type;

    // Check that it is a valid file type.
    return this.fileTypes.indexOf(extension) > -1;
  };

  /**
   * Validates file size.
   */
  ImageUpload.prototype.validFileSize = function(files) {
    // Get the file extension.
    var size = files[0].size;

    // Check that it is a valid file type.
    return (size <= this.fileSizeLimit) ? true : false;
  };


  /**
   * Remove any previously added error message.
   */
  ImageUpload.prototype.removeError = function() {
    var $errorMsg = this.$uploadButton.parent().siblings(".error");

    if ($errorMsg.length) {
      $errorMsg.remove();
    }
  };

  /**
   * Show an error message and disable the reportback form
   * so it can't be submitted
   *
   * param {string}  Error message to be shown.
   */
  ImageUpload.prototype.showError = function(msg) {
    this.removeError();

    var $error = $("<div class='messages error'>" + msg + "</div>");

    // Check if the modal was open when they subitted the bad image.
    if (Modal.isOpen()) {
      Modal.close();
    }

    this.$reportbackSubmissions.prepend($error);

    this.$reportbackFormSubmit.prop("disabled", true);
  };

  /**
   * Resizes an image so that the dimensions of the scaled image.
   * are never greater than it's container's maximum width (height of the container is variable).
   *
   * @param {jQuery} $image           The image to resize.
   * @param {jQuery} $container       The container to resize within.
   */
  ImageUpload.prototype.resizeImage = function($image, $container) {
    var imageWidth  = $image.width();
    var imageHeight = $image.height();
    var containerMaxWidth = $container.width();
    var orientation = (imageWidth > imageHeight) ? "landscape" : "portrait";

    if ((imageWidth > containerMaxWidth) || (imageHeight > containerMaxWidth)) {
      if (orientation === "portrait") {
        $image.height(containerMaxWidth);
      }
      else {
        $image.width(containerMaxWidth);
      }
    }
    else {
      return;
    }
  };

  /**
   * Creates a preview image of an uploaded file and adds it to a container.
   * If cropping is enabled, it initiates the cropping script.
   *
   * @param {jQuery} fileReaderResult   The result property of a file reader object.
   * @param {jQuery} $imageContainer    The DOM element to put the preview image in.
   */
  ImageUpload.prototype.previewImage = function(image, $imageContainer) {
    var _this = this;

    var $preview = $("<img class='preview' src=''>");
    $imageContainer.html($preview);

    $preview.attr("src", image.src).on('load', function() {
      var $this = $(this);

      _this.resizeImage($this, $imageContainer);

      ImageCrop.dsCropperInit(image);
    });
  };

  ImageUpload.prototype.loadImage = function(imageUrl) {
    var _this = this;
    var image = new Image();
    image.src = imageUrl;

    image.onload = function() {
      var isValidSize = _this.validImageSize(this);

      _this.removeError();

      if(isValidSize) {
        // Open the modal.
        _this.openModal();

        // Add the preview image to the modal
        _this.previewImage(image, _this.$imagePreview);

        //Unbind before rebind so it doesnt fire twice.
        _this.$cropButton.off("click");

        // When the user submits the modal form, send crop values to the form.
        _this.$cropButton.on("click", function(event) {
          event.preventDefault();

          // Validate the caption field and make sure we are good to proceed.
          _this.validateCaption(_this.engageImageCrop, image);
        });
      }
      // Show user an error if they upload an image that is too small.
      else {
        if (typeof ga !== 'undefined' && ga !== null) {
          ga('send', 'event', 'Reportback', 'image too small');
        }
        _this.showError(_this.dimensionsError);
      }
    };
  };

  /**
   * This function strips out EXIF data from a file and recreates a
   * FileReader Blob that we use to create the image object that is used
   * in the modal. This way we only deal with the RAW image file on both
   * mobile and desktop with out having to wory about it rendering differently
   * and causing all of our image cropping/preview logic to be wrong.
   *
   * @TODO - try moving this into a web worker to enhance performance.
   */
  ImageUpload.prototype.getStrippedBlob = function(fileReaderResult) {
    var dataView = new DataView(fileReaderResult);
    var offset = 0;
    var recess = 0;
    var pieces = [];
    var i = 0;
    var generatedBlob;

    if (dataView.getUint16(offset) === 0xffd8) {
      offset   += 2;
      var app1  = dataView.getUint16(offset);
      offset   += 2;

      // This loop doing the acutal reading of the data
      // and creating an array with only the pieces we want.
      while (offset < dataView.byteLength) {
        if (app1 === 0xffe1) {
          pieces[i] = {
            recess : recess,
            offset : offset - 2
          };

          recess = offset + dataView.getUint16(offset);

          i++;
        }
        else if (app1 === 0xffda) {
          break;
        }

        offset   += dataView.getUint16(offset);
        app1  = dataView.getUint16(offset);
        offset   += 2;
      }

      // If the file had EXIF data and it was removed,
      // create a file blob with using the new array of file data.
      if (pieces.length > 0) {
        var newPieces = [];

        pieces.forEach(function(v) {
          newPieces.push(fileReaderResult.slice(v.recess, v.offset));
        }, this);

        newPieces.push(fileReaderResult.slice(recess));

        generatedBlob = new Blob(newPieces, {type: "image/jpeg"});
      }
      // If no EXIF data existed on the file, then nothing was done to it.
      // We can just create a blob with the original data.
      else {
        generatedBlob = new Blob([dataView], {type: "image/jpeg"});
      }
    }
    // @TODO - If it is not a jpeg, create a png. We can work out a more
    // robust fix for this that maybe only runs through the EXIF
    // stuff if it is a jpeg in the first place.
    else {
      generatedBlob = new Blob([dataView], {type: "image/png"});
    }
    return generatedBlob;
  };

  return ImageUpload;

});
