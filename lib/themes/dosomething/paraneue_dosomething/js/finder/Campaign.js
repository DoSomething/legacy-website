define(["jquery"], function($) {
  "use strict";

  /**
   * Campaign JS object representation
   * @param {Object} data The raw campaign data
   */
  var Campaign = function (data) {
    // Default values for a newly created campaign
    var defaults = {
      title: "New Campaign",
      description: "Take your dad to get his blood pressure checked",
      url: "#",
      staffPick: false,
      featured: false,
      image: "http://lorempixel.com/600/600?" + Math.random()
    };

    // Merge the campaign object from data with the defaults into
    // this campaign object
    $.extend(this, defaults, this.convert(data));
  };

  /**
   * Convert fields from the Solr results to relevant local, friendlier
   * field names.
   *
   * @param  {Object} data The raw campaign object
   *
   * @return {Object} The new data translated and ignoring
   */
  Campaign.prototype.convert = function (data) {
    var newData = {};
    var map = {
      "label": "title",
      "sm_field_call_to_action": "description",
      "url": "url",
      "bs_field_staff_pick": "staffPick",
      "bs_sticky": "featured",
      "ss_field_search_image": "image"
    };

    // Only populate fields that we care about from the map.
    for (var i in data) {
      if (map[i] !== undefined) {
        newData[map[i]] = data[i];
      }
    }

    return newData;
  };

  /**
   * Render a campaign
   * @return {jQuery} The jQuery object that is the rendered representation of this Campaign
   */
  Campaign.prototype.render = function () {
    // Clone from the embedded template
    var $wrapper = $("#campaign-finder-template>a").clone();

    var preload = new Image();
    preload.src = this.image;
    var t = setInterval(function () {
      if (preload.complete) {
        $wrapper.css("background-image", "url(" + preload.src + ")").addClass("loaded");
        clearInterval(t);
      }
    }, 5);


    // If this isn't a staff pick, remove the flag dif
    if (!this.staffPick) {
      $wrapper.find(".flag").remove();
    }

    // If this is a featured campaign, let's make it big
    if (this.featured) {
      $wrapper.addClass("big");
    }

    // Set the content
    $wrapper.find("p").html(this.description);
    $wrapper.find("h3").html(this.title);
    $wrapper.attr("href", this.url);
    if (false) {
      $wrapper.find(".powered-by img").prop("src", "");
    } else {
      $wrapper.find(".powered-by").remove();
    }

    return $wrapper;
  };
});
