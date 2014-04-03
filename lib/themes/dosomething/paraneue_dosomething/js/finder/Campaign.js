define(["jquery", "text!finder/templates/campaign.tpl.html"], function($, campaignTplSrc) {
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
    if(!this.staffPick) this.staffPick = false;
    if(!this.featured) this.featured = false;

    var $wrapper = _.template(campaignTplSrc, {
      'image': this.image,
      'staffPick': this.staffPick,
      'featured': this.featured,
      'title': this.title,
      'description': this.description,
      'url': this.url
    });

    return $wrapper;
  };

  return Campaign;
});
