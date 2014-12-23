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

    itemCount: 30,

    itemOffset: 0,

    itemStatus: "approved",

    itemsPerRow: 4,

    rowCount: 2,

    pageNumber: 0,

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

      console.log("::: 02) INSERTING VIEW MORE BUTTON :::");
      this.$viewMoreButton.insertAfter(this.$initialGallery);

      // this.$viewMoreButton.on("click", _.bind(this.request, this));
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

      var start   = this.currentIndex;
      var count   = this.itemsPerRow * this.rowCount;
      var end     = start + count;
      var cluster = "";

      console.log(start);
      console.log(end);

      for (var i = start; i < end; i++) {
        cluster += this.stock[i];
      }

      // this.$extendedGallery.html(cluster).insertAfter(this.$initialGallery);
      console.log("?? Is gallery in the DOM? : " + this.galleryInDom);
      if (!this.galleryInDom) {
        this.insertGallery(cluster);
      } 
      else {
        this.$extendedGallery.append(cluster);
      }

      this.currentIndex += count;
    },


    evaluateStock: function () {
      console.log("::: 03) EVALUATING REPORTBACKS IN STOCK :::");

      if (this.stock.length) {
        console.log("@@ Reportbacks's in stock!");
        this.appendEntries();
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
            // status: 'approved',
          },
          pagesize: this.itemCount,
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
        console.log("@@ Stock Index: " + _this.currentIndex);
        // console.log(_this.stock);
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
