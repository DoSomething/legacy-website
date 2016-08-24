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
  var campaignTplSrc =  require("finder/templates/campaign.tpl.html");

  /**
   * Campaign JS object representation
   * @param {Object} data The raw campaign data
   */
  var Campaign = function (data) {
    // Default values for a newly created campaign
    var defaults = {
      title: "",
      description: "",
      url: "#",
      staffPick: false,
      featured: false
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
      "ss_field_search_image_400x400": "image"
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
    var renderTile = template(campaignTplSrc);

    return renderTile({
      "image": this.image,
      "staffPick": this.staffPick,
      "featured": this.featured,
      "title": this.title,
      "description": this.description,
      "url": this.url
    });
  };

  return Campaign;
});
