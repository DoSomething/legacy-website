define(["jquery", "lodash"], function($, _) {
  "use strict";

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
    baseURL: "http://98.129.111.171:8080/solr/",
    collection: "collection1",

    // The current throttle timeout identifier
    throttle: null,

    // This would be awesome with an object key:value, but Solr allows multiple of the same key
    defaultQuery: [
      "fq=bundle:campaign",
      //"fq=ss_field_search_image:[* TO *]",
      "wt=json",
      "indent=false",
      "facet=true",
      "facet.field=fs_field_active_hours",
      "facet.field=im_field_cause",
      "facet.field=im_field_action_type",
      "sort=bs_sticky+desc,bs_field_staff_pick+desc",
      "rows=10"
    ],

    // Map the input field names to the Solr query fields
    fieldMap: {
      "cause": "im_field_cause",
      "time": "fs_field_active_hours",
      "action-type": "im_field_action_type"
    },

    // Inverse mapping of fieldMap (duhhh)
    fieldMapInverse: {},

    /**
     * Initialize the SolrAdapter.
     */
    init: function() {
      // Create an inverse mapping so we can go from Solr field name to local field name
      SolrAdapter.fieldMapInverse = _.invert(SolrAdapter.fieldMap);

    },

    /**
     * Run the query after a specified timeout.
     *
     * @param {jQuery} $fields  Array of fields selected in the interface.
     * @param successCallback   Function called when query successfully completes.
     */
    throttledQuery: function($fields, successCallback) {
      // Cancel the current pending query and set a new one
      clearTimeout(SolrAdapter.throttle);

      // Set a timeout so we don't immediately ping the Solr server
      SolrAdapter.throttle = setTimeout(function() {
        SolrAdapter.query($fields, successCallback);
      }, SolrAdapter.throttleTimeout);
    },

    /**
     * Run the query against the Solr server
     *
     * @param checkedFields     Array of fields selected in the interface.
     * @param successCallback   Function called when query successfully completes.
     */
    query: function (checkedFields, successCallback) {
      /**
       * A clone of the default query so we don't modify it directly
       * @type {Array}
       */
      var query = _.clone(SolrAdapter.defaultQuery);

      /**
       * The "q" parameter passed to Solr
       * @type {Array}
       */
      var q = [];

      _.forOwn(checkedFields, function(fields, fieldGroup) {
        // Don't build parameter if we're not sorting by anything in this field group.
        if( !_.isEmpty(fields) ) {
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

      // If we"re already running an AJAX request, cancel it
      if (SolrAdapter.xhr) {
        SolrAdapter.xhr.abort();
      }

      // Store the AJAX request locally
      SolrAdapter.xhr = $.ajax({
        dataType: "jsonp",
        url: SolrAdapter.buildQuery(query, q),
        success: function (data) {
          successCallback(data);
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

      if (q.length > 0) {
        // If there is a query, join that sucker together
        if (q.length === 1) {
          query[pos] = "q=" + q[0];
        } else {
          query[pos] = "q=(" + q.join(") AND (") + ")";
        }
      } else {
        // If there ain"t, let"s QUERY ALL THE THINGS (and leave caps lock on)
        query[pos] = "q=*:*";
      }

      // Join the query array together as a URL query string
      query = query.join("&");

      // TODO: un-hard-code the rows
      return SolrAdapter.baseURL + SolrAdapter.collection + "/select?" + query + "&rows=10";
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
