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

  var $ = require("jquery");
  var template = require("lodash/template");
  var Campaign = require("finder/Campaign");
  var noResultsTplSrc = require("finder/templates/no-results.tpl.html");

  /**
   * ResultsView manages search results from Finder
   * @type {Object}
   */
  var ResultsView = {
    // The container element where the results go
    $container: null,

    // The gallery located in the container
    $gallery: $("<ul class='gallery -quartet -mosaic'></ul>"),

    // The div that is shown if no filters are selected
    $blankSlateDiv: null,

    // How many slots are currently used. Full-height = 2, half-height = 1
    slots: 0,

    // How many slots are we allowing
    maxSlots: 8,

    // For tracking what page we're on
    start: 0,

    /**
     * Construct the cloneables and set the parent div where the results go
     * @param  {jQuery} $container        The container element where the results will live
     * @param  {jQuery} $blankSlateDiv    The div containing initial pre-filtered state
     * @param  {function} paginateAction  Function to query next page of results.
     */
    init: function ($container, $blankSlateDiv, paginateAction, clearFormAction) {
      ResultsView.$container = $container;
      ResultsView.$container.hide();


      ResultsView.$paginationLink = $(
        "<div class='pagination-link'><a href='#' class='secondary js-finder-show-more'>" +
          Drupal.t("Show More") +
        "</a></div>"
      );

      $("body").on("click", ".js-finder-show-more", function(event) {
        event.preventDefault();
        paginateAction(ResultsView.start);
      });

      ResultsView.$blankSlateDiv = $blankSlateDiv;

      ResultsView.$container.on("click", "#reset-filters", function(event) {
        event.preventDefault();

        ResultsView.showBlankSlate();

        // TODO: Maybe allow for FormView.clear() to be called from ResultsView so
        // it doesn't have to be passed in as an argument to the init().
        clearFormAction();
      });
    },

    /**
     * Shows the blank slate div (initial state).
     */
    showBlankSlate: function() {
      ResultsView.$container.hide();
      ResultsView.$blankSlateDiv.show();
    },

    /**
     * Shows the empty slate div (no results state).
     */
    showEmptyState: function() {
      var message = template(noResultsTplSrc)();

      ResultsView.$container.append(message);
    },

    /**
     * Replace current results with new data
     * @param  {Object} data The raw data from the query
     */
    parseResults: function (data) {
      // Remove the old results
      ResultsView.clear();

      if (data.retrieved > 0) {
        // Results view cleared, and since we have results add the gallery into the container.
        ResultsView.$container.append(ResultsView.$gallery);

        ResultsView.campaignHelper(data);

        // There are more results than we've shown so far, add "Show More" button
        ResultsView.showPaginationLink(data.result.grouped.entity_id.matches > ResultsView.start);
      } else {
        ResultsView.showEmptyState();
      }

      // Hey! We're done loading! I guess we can let the users know we're done.
      ResultsView.loading(false);
    },

    /**
     * Show or hide pagination link.
     * @param {boolean} showLink    Should link be shown?
     */
    showPaginationLink: function(showLink) {
      ResultsView.$paginationLink.remove();

      if(showLink) {
        ResultsView.$container.append(ResultsView.$paginationLink);
        ResultsView.$paginationLink.show();
      }
    },

    /**
     * Append to current results with new data.
     * @param  {Object} data The raw data from the query
     */
    appendResults: function (data) {
      // Add those results to the page
      ResultsView.campaignHelper(data);

      // There are more results than we've shown so far, add "Show More" button
      ResultsView.showPaginationLink(data.result.grouped.entity_id.matches > ResultsView.start);

      // Hey! We're done loading! I guess we can let the users know we're done.
      ResultsView.loading(false);
    },

    /**
     * Toggle the loading indicator for the results div
     * @param  {boolean} setTo Should I stay or should I go? If I go there will be trouble...or clicking.
     */
    loading: function (setTo) {
      // Allow the function to be called without a parameter, since X.loading() would seem
      // to be a logical call.
      if (setTo === undefined) {
        setTo = true;
      }

      // If we're loading, add a class to the results div. Otherwise, remove it.
      ResultsView.$container.append("<div class='spinner'></div>");
      ResultsView.$container.toggleClass("loading", setTo);
    },

    /**
     * Have we run the init method?
     */
    checkInit: function () {
      if (ResultsView.$container === null) {
        // Nope. I'm gonna vomit...
        throw Drupal.t("Error: ResultsView is not initialized.");
      }

      // Yup.
    },

    /**
     * Remove the current results and reboot this object.
     */
    clear: function () {
      ResultsView.checkInit();
      ResultsView.$container.empty();
      ResultsView.$gallery.empty();

      ResultsView.$container.show();
      ResultsView.$blankSlateDiv.hide();


      ResultsView.slots = 0;
      ResultsView.start = 0;
    },

    /**
     * Add a campaign to the results
     * @param {Campaign} campaign The campaign to add
     */
    add: function (campaign) {
      // Make sure we've initialized ourself
      ResultsView.checkInit();

      // If we're full, screw it.
      // if (ResultsView.slots === ResultsView.maxSlots) {
      //   return;
      // }

      // Render campaign object and append to the gallery
      ResultsView.$gallery.append(campaign.render());
      ResultsView.slots++;

      // Track where we are for paging
      ResultsView.start++;

      // Lazy-load in images
      ResultsView.$container.find("img").unveil(200, function() {
        $(this).load(function() {
          this.style.opacity = 1;
        });
      });
    },

    campaignHelper: function (data) {
      // Loopy loop! (Like me after drinking coffeeeee)
      for (var i in data.result.grouped.entity_id.groups) {
        var group = data.result.grouped.entity_id.groups[i];
        let campaign = new Campaign(group.doclist.docs[0]);
        ResultsView.add(campaign);
      }
    }
  };

  return ResultsView;
});
