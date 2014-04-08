define(["jquery", "unveil", "finder/Campaign"], function($, unveil, Campaign) {
  "use strict";

  /**
   * CampaignResults manages search results from CampaignFinder
   * @type {Object}
   */
  var CampaignResults = {
    // The div where the results go
    $div: null,

    // The single row div for cloning with full-height campaigns
    $singlerow: null,

    // How many slots are currently used. Full-height = 2, half-height = 1
    slots: 0,

    // How many slots are we allowing
    maxSlots: 8,

    // Currently unused. For tracking what page we're on
    start: 0,

    /**
     * Construct the cloneables and set the parent div where the results go
     * @param  {jQuery} $div The div where the results will live
     */
    init: function ($div) {
      CampaignResults.$singlerow = $("<div class='single-result'>");
      CampaignResults.$div = $div;
    },

    /**
     * Loop through the results and convert them to Campaign objects
     * @param  {Object} data The raw data from the query
     */
    parseResults: function (data) {
      // Remove the old results
      CampaignResults.clear();

      // Loopy loop! (Like me after drinking coffeeeee)
      for (var i in data.response.docs) {
        CampaignResults.add(new Campaign(data.response.docs[i]));
      }

      // Hey! We're done loading! I guess we can let the users know we're done.
      CampaignResults.loading(false);
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
      CampaignResults.$div.append("<div class='spinner'></div>");
      CampaignResults.$div.toggleClass("loading", setTo);
    },

    /**
     * Have we run the init method?
     */
    checkInit: function () {
      if (CampaignResults.$div === null) {
        // Nope. I'm gonna vomit...
        throw "Error: CampaignResults tracker is not initialized.";
      }

      // Yup.
    },

    /**
     * Remove the current results and reboot this object.
     */
    clear: function () {
      CampaignResults.checkInit();
      CampaignResults.$div.empty();

      CampaignResults.slots = 0;
      CampaignResults.start = 0;
    },

    /**
     * Add a campaign to the results
     * @param {Campaign} campaign The campaign to add
     */
    add: function (campaign) {
      // Make sure we've initialized ourself
      CampaignResults.checkInit();

      // If we're full, screw it. If we're full height and it won't fit, screw it.
      if (CampaignResults.slots === CampaignResults.maxSlots ||
          (campaign.featured && CampaignResults.slots + 2 > CampaignResults.maxSlots))
      {
        return;
      }

      // At some point this may be useful for paging.
      //   CampaignResults.start++;

      // Render campaign object and preload image
      var $campaignDiv = campaign.render();

      // Display differently depending on if we're full height or not
      if (campaign.featured) {
        // Full height, so we want a single row div
        CampaignResults.$div.append(CampaignResults.$singlerow.clone().append($campaignDiv));

        // We've used up two spaces
        CampaignResults.slots += 2;
      } else {
        CampaignResults.slots += 1;
        CampaignResults.$div.append($campaignDiv);
      }

      // Lazy-load in images
      CampaignResults.$div.find("img").unveil(200, function() {
        $(this).load(function() {
          this.style.opacity = 1;
        });
      });
    }
  };

  return CampaignResults;
});
