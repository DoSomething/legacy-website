// Example API request:
// http://dev.dosomething.org:8888/api/v1/reportback_files.json?parameters[nid]=362&pagesize=4&page=0

// Steps:
//
// • Click View More link
// • Determine if have enough rb entries to show in stock.
// • If not enough entries, request more entires.
// • If enough, show 8 entries.

define(function(require) {
  "use strict";

  var $                = require("jquery");
  var _                = require("lodash");
  // var ImageUploadBeta  = require("campaign/ImageUploadBeta");
  // var Revealer         = require("revealer/Revealer");
  var reportbackTplSrc = require("text!reportback/templates/reportback.tpl.html");


  var Reportback = {

    // $viewMoreContent: $("<div class=\"view-more\"></div>"),
    $initialGallery: null,
    $extendedGallery: $("<ul class=\"gallery gallery--extended -quartet\"></ul>"),
    $viewMoreButton: $("<button id=\"view-more-button\" class=\"btn btn--view-more tertiary\">View more</button>"),

    apiUrl: "/api/v1/reportback_files.json",

    nid: null,

    itemOffset: 0,

    itemStatus: "approved",

    bundleSize: 8,

    pageNumber: 0,

    pageSize: 30,  // Default

    pagesTotal: null,

    stock: [],

    currentIndex: 0,

    galleryInDom: false,


    /**
     * Initialize the Reportback interface.
     *
     * @param  {jQuery} $container  Reportback container object.
     */
    init: function ($container) {
      console.log("::: 01) INITIALIZING THE REPORTBACK :::");

      this.$initialGallery = $container.find(".gallery--reportback");
      var _this = this;

      this.nid        = $container.data("nid");
      this.itemOffset = $container.data("offset");
      this.pageSize   = $container.data("page-size");
      this.pagesTotal = $container.data("pages-total");

      console.log("::: 02) INSERTING VIEW MORE BUTTON :::");
      this.$viewMoreButton.insertAfter(this.$initialGallery);

      this.$viewMoreButton.on("click", function () {
        _this.evaluateStock();
      });

      // new ImageUploadBeta();


      $(window).on("resize", _.debounce(function () {
        console.log("@@ Resizing...");
        // if (window.matchMedia("(min-width: 768px)").matches) {
        //   // _this.$viewMoreContent.detach();
        // } else {
        // }
      }, 500));
    },


    appendEntries: function () {
      console.log("::: 09) APPENDING ENTRIES TO DOM :::");

      var start   = this.currentIndex + this.itemOffset;
      var end     = start + this.bundleSize;
      var cluster = "";

      console.log("@@ Starting @: " + start);
      console.log("@@ Ending @: " + end);

      for (var i = start; i < end; i++) {
        if (this.stock[i] !== undefined) {
          cluster += this.stock[i];
        }
      }

      if (!this.galleryInDom) {
        this.insertGallery(cluster);
      } 
      else {
        this.$extendedGallery.append(cluster);
      }

      this.currentIndex += this.bundleSize;

      this.outOfStock();
    },


    outOfStock: function () {
      console.log("::: 11) CHECKING TO SEE IF COMPLETELY OUT OF STOCK :::");

      if (this.lowInventory() && this.pageNumber > this.pagesTotal) {
        this.$viewMoreButton.remove();
      }
    },

    evaluateStock: function () {
      console.log("::: 03) EVALUATING REPORTBACKS IN STOCK :::");

      if (this.stock.length) {
        console.log("@@ Reportbacks's in stock!");

        if (this.lowInventory()) {
          console.log("@@ Need to get more reportbacks!");
          this.request();
        }
        else {
          this.appendEntries();

          // Maybe move outOfStock() check from appendEntries() to here??
        }
      }
      else {
        console.log("@@ NO Reportback's in stock!");
        this.request();
      }


    },


    insertGallery: function (data) {
      var content = data || null;

      if (content) {
        this.$extendedGallery.html(content);  
      }
      
      this.$extendedGallery.insertAfter(this.$initialGallery);

      this.galleryInDom = true;
    },


    lowInventory: function () {
      console.log("::: 10) CHECKING TO SEE IF RUNNING LOW ON INVENTORY :::");
      console.log(this.stock.length);

      var currentIndex = this.currentIndex + this.itemOffset;

      if ((currentIndex + this.bundleSize) > this.stock.length ) {
        return true;
      }

      return false;
    },


    /**
     * [request description]
     */
    request: function () {
      console.log("::: 04) REQUESTING REPORTBACKS VIA AJAX :::");

      var _this = this;

      $.ajax({
        url: this.apiUrl,
        dataType: "json",
        data: {
          parameters: {
            nid: this.nid,
            status: 'approved',
          },
          pagesize: this.pageSize,
          page: this.pageNumber
        }
      }).done(function (response) {
        console.log("::: 05) RESPONSE FROM AJAX :::");

        _this.templatize(response);

        console.log("::: 08) UPDATING PAGINATION NUMBER :::");
        _this.pageNumber++;

        _this.appendEntries();

      }).fail(function () {
        console.log("::: ERROR: AJAX FAILED :::");

      }).always(function () {
        console.log("::: ??) POST AJAX COMPLETE COMMANDS :::");

        console.log("@@ Stock Count: " + _this.stock.length);
      });
    },


    /**
     * [show description]
     */
    show: function () {
      console.log("Showing Entries...");

      // output entries to page.
    },


    /**
     * [templatize description]
     */
    templatize: function (items) {
      console.log("::: 06) TEMPLATING ENTRIES RETRIEVED :::");

      for (var i = 0, count = items.length; i < count; i++) {
        var data = {
          "id": items[i].rbid,
          "image": items[i].src,
          "caption": items[i].caption,
          "status": items[i].status,
          "isListItem": true  // @TODO: probably a better way to address this... :insert shrug emoji here:
        };

        var markup = _.template(reportbackTplSrc, data);

        this.stock.push(markup);
      }
      console.log("::: 07) NEW ENTRIES ADDED TO STOCK :::");
    }

  };


  return Reportback;
});
