/* eslint-disable */

/* ----------------------------------------------------------
 * @TODO: ^ Enable linting by removing `eslint-disable`! ^
 * ----------------------------------------------------------
 * Linting is disabled in this file. Remove this line and
 * clean this file up according to our coding standards next
 * time it is touched.
 */

import setting from '../utilities/Setting';

define(function(require) {
  "use strict";

  var $ = require("jquery");
  var invert = require("lodash/object/invert");
  var forOwn = require("lodash/object/forOwn");
  var clone = require("lodash/lang/clone");
  var isEmpty = require("lodash/lang/isEmpty");

  // Create a callback function for caching the jsonp response.
  /* jshint ignore:start */
  window.solrResponse = function(response) {};
  /* jshint ignore:end */

  /**
   * SolrAdapter acts as a mediator between Solr and the Campaign Finder.
   *
   * @type {Object}
   */
  var SolrAdapter = {
    /*
     * Sets how long after a user interaction we run the Solr query. As the
     * name implies, this is a throttling mechanism that prevents the browser
     * from pinging Solr every...single...time...a checkbox is changed.
     **/
    throttleTimeout: 400,

    /*
     * Configure this too. What's the base URL of the Solr server that you want
     * the browser pinging? And what collection?
     **/
    baseURL: setting('dosomethingSearch.solrURL'),
    collection: setting('dosomethingSearch.collection'),

    // The current throttle timeout identifier
    throttle: null,

    // This would be awesome with an object key:value, but Solr allows multiple of the same key
    defaultQuery: [
      "fq=-sm_field_campaign_status:(closed) bundle:[campaign TO campaign_group] ss_language:(" + setting('dosomethingSearch.language') + " OR en-global)",
      //"fq=ss_field_search_image:[* TO *]",
      "wt=json",
      "indent=false",
      "facet=true",
      "facet.field=fs_field_active_hours",
      "facet.field=im_field_cause",
      "facet.field=im_field_action_type",
      // TODO: un-hard-code the rows
      "rows=8",
      "fl=label,tid,im_vid_1,sm_vid_Action_Type,tm_vid_1_names,im_field_cause,im_vid_2,sm_vid_Cause,tm_vid_2_names,im_field_tags,im_vid_5,sm_vid_Tags,tm_vid_5_names,fs_field_active_hours,sm_field_call_to_action,bs_field_staff_pick,ss_field_search_image_400x400,ss_field_search_image_720x720,url,ss_language",
      "bq=ss_language:" + setting('dosomethingSearch.language') + "^10",
      "group.field=entity_id",
      "group=true"
    ],

    // Map the input field names to the Solr query fields
    fieldMap: {
      "cause": "im_field_cause",
      "time": "fs_field_active_hours",
      "action-type": "im_field_action_type"
    },

    // Inverse mapping of fieldMap (duhhh)
    fieldMapInverse: {},


    // Container for Ajax response data
    responseData: null,

    /**
     * Initialize the SolrAdapter.
     */
    init: function() {
      // Create an inverse mapping so we can go from Solr field name to local field name
      SolrAdapter.fieldMapInverse = invert(SolrAdapter.fieldMap);
    },

    /**
     * Run the query after a specified timeout.
     *
     * @param checkedFields      Array of fields selected in the interface.
     * @param offset             Offset to start results from (used for pagination).
     * @param responseCallback   Function called when query successfully completes.
     */
    throttledQuery: function(checkedFields, offset, responseCallback) {
      // Cancel the current pending query and set a new one
      clearTimeout(SolrAdapter.throttle);

      // Set a timeout so we don't immediately ping the Solr server
      SolrAdapter.throttle = setTimeout(function() {
        SolrAdapter.query(checkedFields, offset, responseCallback);
      }, SolrAdapter.throttleTimeout);
    },

    /**
     * Run the query against the Solr server
     *
     * @param checkedFields      Array of fields selected in the interface.
     * @param offset             Offset to start results from (used for pagination).
     * @param responseCallback   Function called when query successfully completes.
     */
    query: function (checkedFields, offset, responseCallback) {
      /**
       * A clone of the default query so we don't modify it directly
       * @type {Array}
       */
      var query = clone(SolrAdapter.defaultQuery);
      query.push("start=" + offset);

      /**
       * The "q" parameter passed to Solr
       * @type {Array}
       */
      var q = [];

      forOwn(checkedFields, function(fields, fieldGroup) {
        // Don't build parameter if we're not sorting by anything in this field group.
        if( !isEmpty(fields) ) {
          // Build a param query
          var param = "(" + fields.join(") OR (") + ")";

          /*
           * Use a powerset to weight items. For example, given:
           *   ☑ Animals
           *   ☑ Disasters
           * We should weight results that are animals AND disasters before results
           * that are animals OR disasters.
           **/
          var powerset = SolrAdapter.generatePowerset(fields);
          if (powerset.length) {
            param += " OR " + powerset;
          }

          // Push the newly built parameter onto the q parameter
          q.push(SolrAdapter.fieldMap[fieldGroup] + ":" + "(" + encodeURIComponent(param) + ")");
        }
      });

      // If we're already running an AJAX request, cancel it
      if (SolrAdapter.xhr) {
        SolrAdapter.xhr.abort();
      }

      // Store the AJAX request locally
      SolrAdapter.xhr = $.ajax({
        dataType: "jsonp",
        cache: true,
        jsonpCallback: "solrResponse",
        url: SolrAdapter.buildQuery(query, q),
        success: function (data) {
          responseCallback({
            result: data,
            retrieved: data.grouped.entity_id['groups'].length,
          });
        },
        error: function(data, errorType) {
          responseCallback({
            result: false,
            error: errorType
          });
        },
        // We use jsonp for X-domain compatibility
        jsonp: "json.wrf"
      });
    },

    /**
     * Build a Solr query based on a base query string (what comes after the ?)
     * and a "q" which goes into the "q=" part of said query string.
     *
     * @param  {String} query The query string
     * @param  {String} q     The string for concatting into the q= parameter
     *
     * @return {String} The entire URL to query against
     */
    buildQuery: function (query, q) {
      // Add "q=" to the query array, and keep track of its position because we"re going
      // to need to modify it (less memory!)
      var pos = query.push("q=") - 1;

      // Add a function query to bubble staff picks, sponsored, and high season to the top.
      var bubble = "_query_:\"{!func}scale(is_bubble_factor,0,100)\" AND ";

      if (q.length > 0) {
        // If there is a query, join that sucker together
        if (q.length === 1) {
          query[pos] = "q=" + bubble + q[0];
        } else {
          query[pos] = "q=" + bubble + "(" + q.join(") AND (") + ")";
        }
      } else {
        query[pos] = bubble;
      }

      // Join the query array together as a URL query string
      query = query.join("&");

      return SolrAdapter.baseURL + SolrAdapter.collection + "/select?" + query;
    },

    /**
     * This one's fun! We want to generate power sets so we can weight results in a search.
     *
     * Instead of reading the code, here's an example!
     *
     * [a, b, c]"s powerset+weight is:
     * - []             IGNORED (i=0)
     * - [a]            IGNORED (length=1)
     * - [b]            IGNORED (length=1)
     * - [c]            IGNORED (length=1)
     * - (a AND b)      ^200
     * - (b AND c)      ^200
     * - (a AND b AND c)^300
     *
     *
     * @param  {Array} params Parameters to powerset-ize
     *
     * @return {String} A powerset-ized query string joined by OR
     */
    generatePowerset: function (params) {
      // Create a powerset
      // See: http://rosettacode.org/wiki/Power_set#JavaScript
      function powerset(ary) {
        var ps = [[]];
        for (var i=0; i < ary.length; i++) {
          for (var j = 0, len = ps.length; j < len; j++) {
            ps.push(ps[j].concat(ary[i]));
          }
        }
        return ps;
      }

      // Generate the powerset
      var variations = powerset(params);

      // The placeholder query
      var q = [];

      // Loop through and build the string query
      for (var i = 1; i < variations.length; i++) {
        if (variations[i].length > 1) {
          // Generate a string of format: ((a) AND (b) AND (c OR d))^X
          // We need the second set of parenthesis beacuse some parameters are in the format
          // "c OR d" or "[* TO 2]"
          q.push("((" + variations[i].join(") AND (") + "))^" + (100*variations[i].length));
        }
      }

      return q.join(" OR ");
    }
  };

  return SolrAdapter;
});
