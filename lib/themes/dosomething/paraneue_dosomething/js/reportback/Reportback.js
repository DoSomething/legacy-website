define(function(require) {
  "use strict";

  var $                   = require("jquery");
  var debounce            = require("lodash/function/debounce");
  var template            = require("lodash/string/template");
  var Modal               = require("dosomething-modal");
  var ImageUpload         = require("../images/ImageUpload");
  var ImageUploadFallback = require("../images/ImageUploadFallback");
  var reportbackTplSrc    = require("reportback/templates/reportback.tpl.html");


  var Reportback = {

    $initialGallery: null,
    $extendedGallery: null,
    $viewMoreContainer: null,
    $viewMoreButton: null,
    $spinner: null,

    apiUrl: "/api/v1/campaigns",

    nid: null,

    offset: 0,

    itemsPrefetched: 0,

    itemsTotal: null,

    bundleSize: 12,

    requestSize: 60,

    inventory: [],

    currentIndex: 0,

    galleryInDom: false,

    adminAccess: null,


    /**
     * Initialize the Reportback interface.
     *
     * @param  {jQuery} $container  Reportback container object.
     */
    init: function ($container) {
      this.reportbackContainer = $container;
      this.$reportbackWrapper  = this.reportbackContainer.find(".wrapper");
      this.$reportbackForm     = this.reportbackContainer.find("#dosomething-reportback-form");
      this.$uploadButton       = this.reportbackContainer.find(".js-image-upload");
      this.$captionField       = this.$reportbackForm.find(".form-item-caption");
      this.$initialGallery     = $container.find(".gallery--reportback");

      // Does the user have admin access?
      this.adminAccess = $container.data("admin");
      // Number of Approved Reportbacks obtained to help fill initial gallery.
      this.itemsPrefetched = $container.data("prefetched");
      // Total number of Approved Reportbacks discounting any that were already prefetched.
      this.itemsTotal      = $container.data("total") - this.itemsPrefetched;
      this.nid             = $container.data("nid");
      this.offset          = this.itemsPrefetched;

      if (this.itemsPrefetched < this.itemsTotal) {
        this.apiUrl = this.buildApiUrl();
        this.enableViewMore();
        this.enableResponsive();
      }

      if (Modernizr.filereader) {
        this.imageUploadInit();
      }
      else {
        ImageUploadFallback.init(this.$uploadButton, '.reportback__submissions');
      }
    },


    imageUploadInit: function () {
      var _this = this;
      var imageUpload = new ImageUpload(this.$uploadButton);

      this.$captionField.hide();
    },


    /**
     * Add the reportback entries to the DOM.
     * Adds the entire extended gallery if it does not exist already,
     * otherwise just appends the additional entries.
     *
     * @param {Integer} inventoryIndex Index to start appending the next Reportback in gallery.
     */
    appendEntries: function (inventoryIndex) {
      var start    = inventoryIndex;
      var end      = start + this.bundleSize;
      var $cluster = $();
      var $images  = null;

      if (this.outOfStock(end)) {
        end = this.itemsTotal;
      }

      for (var i = start; i < end; i++) {
        if (this.inventory[i] !== undefined) {
          $cluster = $cluster.add(this.inventory[i]);
        }
      }

      $images = $cluster.find("img");

      $images.unveil(100, function () {
        var $this = $(this);

        $this.load(function () {
          $this.parent(".photo").addClass("-unveiled");
        });
      });

      if (!this.galleryInDom) {
        this.insertGallery($cluster);
      }
      else {
        this.$extendedGallery.append($cluster);
      }

      // @TODO: There has to be a better way to trigger unveil to execute and not require a scroll.
      $(window).trigger("scroll");
    },


    /**
     * Build out the API URL with the campaign node id.
     *
     * @return {string}  API base url.
     */
    buildApiUrl: function () {
      return this.apiUrl + "/" + this.nid + "/gallery.json";
    },


    /**
     * Remove the View More button.
     */
    disableViewMore: function () {
      this.$viewMoreButton.remove();
    },


    /**
     * Add the View More button if there are additional reportbacks.
     */
    enableViewMore: function () {
      var _this = this;

      this.$viewMoreContainer = $("<div class=\"reportback__view-more\"></div>");
      this.$viewMoreButton = $("<button id=\"view-more-button\" class=\"button button--view-more -tertiary inline-alt-text-color\">View more</button>");

      this.$viewMoreContainer.append(this.$viewMoreButton);

      if (this.isLargerMedia()) {
        this.$viewMoreContainer.insertAfter(this.$reportbackWrapper);
      }
      else {
        this.$viewMoreContainer.insertAfter(this.$initialGallery);
      }


      this.$viewMoreButton.on("click", function () {
        _this.evaluateInventory();
      });
    },


    /**
     * Enable Media Query check to shift around markup.
     */
    enableResponsive: function () {
      var _this = this;

      $(window).on("resize", debounce(function () {
        if (_this.isLargerMedia()) {
          if (_this.$viewMoreContainer) {
            _this.$viewMoreContainer.detach();
            _this.$viewMoreContainer.insertAfter(_this.$reportbackWrapper);
          }
        } else {
          if (_this.$viewMoreContainer) {
            _this.$viewMoreContainer.detach();
            _this.$viewMoreContainer.insertAfter(_this.$initialGallery);
          }
        }
      }, 300));
    },


    /**
     * Check to see if there are any reportback items currently in the
     * inventory after each click of the View More button.
     * If there are items already, then append them, otherwise if there are
     * more in storage then request them to add to the inventory.
     * If there's low inventory and no more in storage then remove the button.
     */
    evaluateInventory: function () {
      if (this.inventory.length) {
        if (this.lowInventory()) {
          this.request(this.currentIndex);

          if ((this.currentIndex += this.bundleSize) >= this.itemsTotal) {
            this.currentIndex = this.itemsTotal;
          }
        }
        else {
          this.appendEntries(this.currentIndex);
          this.currentIndex += this.bundleSize;
        }
      }
      else {
        this.request(this.currentIndex);
        this.currentIndex += this.bundleSize;
      }

      if (this.outOfStock(this.currentIndex)) {
        this.disableViewMore();
      }
    },


    /**
     * Insert the extended gallery into the DOM.
     *
     * @param  {string} data  Markup of list items.
     */
    insertGallery: function (data) {
      var content = data || null;

      this.$extendedGallery = $("<ul class=\"gallery gallery--extended\"></ul>");

      if (content) {
        this.$extendedGallery.html(content);
      }

      this.$viewMoreContainer.prepend(this.$extendedGallery);

      this.galleryInDom = true;
    },


    /**
     * Check to see if media size is large.
     * @return {boolean}
     */
    isLargerMedia: function () {
      return ($(window).outerWidth() >= 760);
    },


    /**
     * Check to see if the stock is running low and will need to retrieve
     * more based on the current index item we are on in the stock list.
     *
     * @return {boolean}
     */
    lowInventory: function () {
      if ((this.currentIndex + this.bundleSize) > this.inventory.length ) {
        return true;
      }

      return false;
    },


    /**
     * Check to see if we are completely out of reportback item stock,
     * and can not request more.
     *
     * @return {boolean}
     */
    outOfStock: function (quantity) {
      if (quantity >= this.itemsTotal) {
        return true;
      }

      return false;
    },


    /**
     * Ajax request to retrieve more reportback entries.
     *
     * @param {int} inventoryIndex  Value to indicate what index to start appending items from.
     */
    request: function (inventoryIndex) {
      var _this = this;

      $.ajax({
        url: this.apiUrl,
        dataType: "json",
        data: {
          offset: this.offset,
          count: this.requestSize
        },
        beforeSend: function () {
          if (_this.$spinner) {
            _this.$spinner.show();
          } else {
            _this.$spinner = $("<div class=\"spinner\"></div>");
            _this.$viewMoreContainer.append(_this.$spinner);
          }
        }
      }).done(function (response) {
        _this.templatize(response);
        _this.$spinner.hide();
        _this.appendEntries(inventoryIndex);
      }).fail(function () {
        // @TODO: handle error here!

      }).always(function () {
        _this.offset = _this.inventory.length + _this.itemsPrefetched;
      });
    },


    /**
     * Use specified template to markup each reportback entry list item.
     *
     * @param {array} items Array of JSON objects containing reportback items.
     */
    templatize: function (items) {
      for (var i = 0, count = items.length; i < count; i++) {
        var data = {
          "id": items[i].rbid,
          "image": items[i].src,
          "caption": items[i].caption,
          "status": items[i].status,
          "isListItem": true  // @TODO: probably a better way to address this... :insert shrug emoji here:
        };

        data.adminLink = this.adminAccess ? '/admin/reportback/' + items[i].rbid : false;

        var markup = template(reportbackTplSrc, data);

        this.inventory.push(markup);
      }
    }

  };


  return Reportback;
});
