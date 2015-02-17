define(function(require) {
  "use strict";

  var $                = require("jquery");
  var Modal            = require("modal");
  var Validation       = require("validation");
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
  var ImageUploadBeta = function($button) {
    this.$uploadButton   = $button;
    this.$cropModal      = $("#modal--crop");
    this.$reportbackForm = $("#dosomething-reportback-form");
    this.$imageForm      = this.$cropModal.find("#dosomething-reportback-image-form");
    this.$imageCaption   = this.$imageForm.find("#modal-caption");
    this.$cropButton     = this.$imageForm.find(".button");
    this.$imagePreview   = this.$cropModal.find(".image-preview");
    this.imageValues     = {};
    this.cropEnabled     = (typeof Drupal.settings.dsReportback.cropEnabled !== "undefined") ? Drupal.settings.dsReportback.cropEnabled : false;
    this.readyToSave     = false;

    this.init();
  };

  /**
   * Initalizes event listeners
   *
   */
  ImageUploadBeta.prototype.init = function () {
    var _this = this;

    this.$uploadButton.on("change", function(event) {
      event.preventDefault();

      var files = !!this.files ? this.files : [];

      // If no file selected/no FileReader support, we're all done
      if (!files.length || !window.FileReader) {
        return;
      }

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

    // Close the modal when a user wants to change their photo.
    this.$cropModal.find(".-change").click(function(event) {
      event.preventDefault();
      Modal.close();
    });

    Modal.Events.subscribe("Modal:Close", function() {
      _this.resetFileField();
    });
  };

  /**
   * Validates the caption field in the modal.
   * @param  {Function} callback  If validation passes, then lets rock on!
   * @return {void}
   */
  ImageUploadBeta.prototype.validateCaption = function(callback, image) {
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
  ImageUploadBeta.prototype.engageImageCrop = function(data, image) {
    var _this = data;

    // Send crop information to the main reportback form
    // so backend can use to crop.
    ImageCrop.populateFields(_this.$reportbackForm);

    // Create a crop preview on the client side.
    ImageCropPreview.cropPreview(image, _this.getCropValues());

    // Add a button to edit the image.
    _this.createEditButton();

    // The user clicked "done", so we can save this version of the crop
    // and not reset the file field.
    _this.readyToSave = true;

    // Close the modal.
    Modal.close();
  };


  /**
   * Opens the modal making sure the done button is reset.
   */
  ImageUploadBeta.prototype.openModal = function() {
    this.enableSubmit();
    Modal.open(this.$cropModal,
      {
        animated: false,
      }
    );
  };

  /**
   * Clears the file field input and resets it globally,
   * if the user accidentally closed out of the modal.
   * Allows the user to re-upload an image and edit it.
   */
  ImageUploadBeta.prototype.resetFileField = function() {
    var $input = this.$uploadButton;

    if (!this.readyToSave) {
      $input.replaceWith(this.$uploadButton = $input.val("").clone(true));
    }
  };

  /**
   * Creates a button the user can click to re-open the modal
   * and edit the crop they selected.
   */
  ImageUploadBeta.prototype.createEditButton = function() {
    var _this = this;

    if (!$(".reportback__submissions").find(".button--edit").length) {
      var $editButton = $("<span class='button button--edit -tertiary'>edit photo</span>");
      this.$uploadButton.parent().hide().before($editButton);

      $editButton.click(function() {
        _this.openModal();
      });
    }
  };

  /**
   * Gets crop values from form and returns an object.
   */
  ImageUploadBeta.prototype.getCropValues = function() {
    return {
      x       : this.$reportbackForm.find("input[name='crop_x']").val(),
      y       : this.$reportbackForm.find("input[name='crop_y']").val(),
      width   : this.$reportbackForm.find("input[name='crop_width']").val(),
      height  : this.$reportbackForm.find("input[name='crop_height']").val(),
      degrees : parseInt(this.$reportbackForm.find("input[name='crop_rotate']").val()),
      caption : this.$reportbackForm.find("input[name='caption']").val(),
    };
  };

  /**
   * Enables submit button in modal when it opens.
   */
  ImageUploadBeta.prototype.enableSubmit = function() {
    var $submitButton = this.$cropModal.find(".-done");

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
  ImageUploadBeta.prototype.validImage = function(image) {
    return (image.width >= 480 && image.height >= 480);
  };

  /**
   * Resizes an image so that the dimensions of the scaled image.
   * are never greater than it's container's maximum width (height of the container is variable).
   *
   * @param {jQuery} $image           The image to resize.
   * @param {jQuery} $container       The container to resize within.
   */
  ImageUploadBeta.prototype.resizeImage = function($image, $container) {
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
  ImageUploadBeta.prototype.previewImage = function(image, $imageContainer) {
    var _this = this;

    var $preview = $("<img class='preview' src=''>");
    $imageContainer.html($preview);

    $preview.attr("src", image.src).load(function() {
      var $this = $(this);

      _this.resizeImage($this, $imageContainer);

      // Initiate cropping if it is enabled.
      if (_this.cropEnabled) {
        ImageCrop.dsCropperInit(image);
      }
    });
  };

  ImageUploadBeta.prototype.loadImage = function(imageUrl) {
    var _this = this;
    var image = new Image();
    image.src = imageUrl;

    image.onload = function() {
      var isValid = _this.validImage(this);
      var $errorMsg = _this.$uploadButton.parent().siblings(".error");

      if(isValid) {
        // Remove any previously added error message.
        if ($errorMsg.length) {
          $errorMsg.remove();
        }

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
        if (!$errorMsg.length) {
          var $error = $("<div class='messages error'>Please upload a larger photo. Min. size is 480px by 480px.</div>");
          $error.insertAfter(_this.$uploadButton.parent());
        }
      }
    }
  };

  /**
   * This function strips out EXIF data from a file and recreates a
   * FileReader Blob that we use to create the image object that is used
   * in the modal. This way we only deal with the RAW image file on both
   * mobile and desktop with out having to wory about it rendering differently
   * and causing all of our image cropping/preview logic to be wrong.
   *
   * @TODO!!!!
   * This code is UGLY and complicated. Largely, if not entirely, based on this
   * flickr blog post: http://code.flickr.net/2012/06/01/parsing-exif-client-side-using-javascript-2/
   * and this JS fiddle. http://jsfiddle.net/mowglisanu/frhwm2xe/3/
   * We need to revist this, some options:
   *  - We can try writing our own EXIF parser to remove or edit orientation data
   *  - Use the exif-js (https://github.com/jseidelin/exif-js) library to read EXIF information
   *    and try to update or crop preview logic based on the EXIF data.
   */
  ImageUploadBeta.prototype.getStrippedBlob = function(fileReaderResult) {
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

  return ImageUploadBeta;

});
