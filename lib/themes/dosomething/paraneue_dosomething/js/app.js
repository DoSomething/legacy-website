/**
 * This is where we load and initialize components of our app.
 */

import $ from 'jquery';
import debounce from 'lodash/function/debounce';

import Finder from 'finder/Finder';
import Donate from 'donate/Donate';
import Revealer from 'revealer/Revealer';
import Swapper from 'swapper/Swapper';
import Reportback from 'reportback/Reportback';
import Share from 'utils/Share';
import LineGraph from 'campaign/Graph';

import 'dosomething-neue';
import Validation from 'dosomething-validation';
import Modal from 'dosomething-modal';

// Attach Validation & Modal to the window so `<script>` tags can use it.
window.DSValidation = Validation;
window.DSModal = Modal;

import 'campaign/SchoolFinder';
import 'validators/auth';
import 'validators/reportback';
import 'validators/address';
import 'validators/donate';
import 'utils/Analytics';
import 'patterns/tiles';

/**
 * Initialize modules on load.
 */
$(document).ready(function() {
  // If a fixed-sticky element is on the page, hook it up.
  $(".js-fixedsticky").fixedsticky();

  var $body = $("body");

  var $campaignFinderForm = $(".js-finder-form");
  if( $campaignFinderForm.length ) {
    var $results = $(".js-campaign-results");
    var $blankSlate = $(".js-campaign-blankslate");
    Finder.init($campaignFinderForm, $results, $blankSlate);
  }


  var $donateForm = $("#modal--donate-form");
  if( $donateForm.length ) {
    Donate.init();
  }

  var $revealGalleries = $body.find('[data-show-more="true"]');
  /**
   * Show hide large galleries.
   */
  if ($revealGalleries.length > 0) {
    var galleryList = [];

    $revealGalleries.each(function (index, gallery) {
      var $gallery = $(gallery);
      var $tiles = $gallery.find("li");
      var isMosaicGallery = $gallery.hasClass('-mosaic');
      var initialItems = isMosaicGallery ? 5 : 6;
      var stepItems = isMosaicGallery ? 8 : 6;

      if ($tiles.length > initialItems) {
        galleryList[index] = new Revealer($gallery, $tiles, "gallery", initialItems, stepItems);
      }
    });
  }

  var $mosaicGalleries = $body.find(".gallery.-mosaic");

  /**
   * Swap low resolution images for feature tiles in mosaic gallery
   * with higher resolution version from tablet size up.
   */
  if ($mosaicGalleries.length && $mosaicGalleries.hasClass("-featured")) {
    var swappedImagesList = [];

    $(window).on("resize", debounce(function () {

      if (window.matchMedia("(min-width: 768px)").matches && !swappedImagesList.length) {
        $mosaicGalleries.each(function (index) {
          var $featureTile = $(this).find("li").first();
          swappedImagesList[index] = new Swapper($featureTile);
        });
      }
    }, 500));

  }

  /**
   * Initialize Reportback js.
   */
  var $reportback = $body.find("#reportback");

  if ($reportback.length) {
    Reportback.init($reportback);
  }


  /*
   * Show share links in a popup
   */
  if ($body.find("a.js-share-link").length) {
    Share.popup();
  }

  /*
   * Toggle truncated text and long text on permalink pages.
   */
  var $showMoreText = $body.find(".js-permalink-show-more");

  if ($showMoreText.length) {
    $showMoreText.click(function(event) {
      event.preventDefault();
      $(".participate").toggleClass("is-shown");
      ($showMoreText.html() === "Show More") ? $showMoreText.html("Show Less") : $showMoreText.html("Show More");
    });
  }

  var $chart = $body.find("#myChart");

  if ($chart.length) {
    var data = {
      labels: ["JAN 1", "JAN 10", "JAN 21", "JAN 31"],
      datasets: [
        {
          label: "My First dataset",
          fillColor: "#fcd116",
          strokeColor: "#f4ee5e",
          pointColor: "#fff",
          pointStrokeColor: "#f4ee5e",
          pointHighlightFill: "#fcd116",
          pointHighlightStroke: "#FFF",
          data: [3000, 4500, 9000, null]
        },
      ]
    };

    var goal = 10000;

    LineGraph($chart, goal, data);
  }

  $("html").addClass("js-ready");

});
