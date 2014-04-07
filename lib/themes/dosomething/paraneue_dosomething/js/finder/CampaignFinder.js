define(["jquery", "lodash", "finder/CampaignResults"], function($, _, CampaignResults) {
  "use strict";

  /**
   * CampaignFinder manages the search action
   *
   * @type {Object}
   */
  var CampaignFinder = {
    /*
       You'll want to configure this or play with it.

       Sets how long after a user interaction we run the Solr query. As the
       name implies, this is a throttling mechanism that prevents the browser
       from pinging Solr every...single...time...a checkbox is changed. BOOM!
       */
    throttleTimeout: 1000,

    /*
       Configure this too. What's the base URL of the Solr server that you want
       the browser pinging? And what collection?
       */
    baseURL: "http://192.168.1.169:8008/solr/",
    collection: "collection1",

    // TODO: Can we get this from CSS somewhere instead so it's not hard-coded?
    cssBreakpoint: 768,

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

    // The field groups that contain the checkmarks
    $fields: {},

    // Map the input field names to the Solr query fields
    fieldMap: {
      "cause": "im_field_cause",
      "time": "fs_field_active_hours",
      "action-type": "im_field_action_type"
    },

    // Inverse mapping of fieldMap (duhhh)
    fieldMapInverse: {},

    // The last field group that was changed (by name)
    lastChanged: null,

    /**
     * Initialize the Campaign Finder and, by extension, the Campaign Results handler
     *
     * @param  {JQuery} $resultsDiv       The div that the results will be injected into
     * @param  {JQuery} $searcuBuggon     <button> that mobile users click to initiate the search
     * @param  {JQuery} $causeFields      Input fields related to the cause field
     * @param  {JQuery} $timeFields       Input fields related to the time field
     * @param  {JQuery} $actionTypeFields Input fields related to the action type field
     */
    init: function ($resultsDiv, $searchButton, $causeFields, $timeFields, $actionTypeFields) {
      // Create an inverse mapping so we can go from Solr field name to local field name
      CampaignFinder.fieldMapInverse = _.invert(CampaignFinder.fieldMap);

      // Store the inputs so we can access them later
      CampaignFinder.$fields.cause = $causeFields;
      CampaignFinder.$fields.time = $timeFields;
      CampaignFinder.$fields["action-type"] = $actionTypeFields;

      // Initialize the CampaignResults
      CampaignResults.init($resultsDiv);

      // Store the button
      CampaignFinder.$searchButton = $searchButton;

      // Loop through each field selector
      for (var i in CampaignFinder.$fields) {

        // For each field selector, we need to add a Facet query so we can get counts to
        // disable the checkbox.
        CampaignFinder.$fields[i].each(function (idx, element) {
          /**
           * The Solr field name that we're going to query against
           * @type {String}
           */
          var field = CampaignFinder.fieldMap[$(element).prop("name")];

          /**
           * The value of the field that we're passing in to the query
           * @type {String}
           */
          var val = $(element).val();

          // Add the face query
          CampaignFinder.defaultQuery.push("facet.query=" + field + ":" + val);
        });

        // Attach ourselves to the "change" event on the input fields
        CampaignFinder.$fields[i].change(function () {
          $(this).parents("label").toggleClass("checked", $(this).is(":checked"));
          // Save the last checkbox that we checked so we don"t disable any of
          // those fields if we"re trying to select multiple
          CampaignFinder.lastChanged = $(this).attr("name");

          // If we're not on mobile...
          if (document.body.clientWidth >= CampaignFinder.cssBreakpoint) {
            // Cancel the current pending query and set a new one
            clearTimeout(CampaignFinder.throttle);

            // Set a timeout so we don't immediately ping the Solr server
            CampaignFinder.throttle = setTimeout(CampaignFinder.query, CampaignFinder.throttleTimeout);
          }
        });

        CampaignFinder.$searchButton.click(function () {
          CampaignFinder.query();
          $("html,body").animate({
            scrollTop: CampaignResults.$div.offset().scrollTop
          }, 1000);
        });
      }
    },

    /**
     * Run the query against the Solr server
     */
    query: function () {
      /**
       * A clone of the default query so we don't modify it directly
       * @type {Array}
       */
      var query = CampaignFinder.defaultQuery.slice(0);

      /**
       * The "q" parameter passed to Solr
       * @type {Array}
       */
      var q = [];

      // Loop through each of the field groups
      for (var i in CampaignFinder.$fields) {
        var checked = CampaignFinder.$fields[i].filter(":checked");

        // Only add this to the query if there are fields checked in this field group
        if (checked.length > 0) {
          /**
           * The query we"re going to be building
           * @type {Array}
           */
          var queryBuilder = [];

          // For each checked box, add it to the search query
          checked.each(function (index, e) {
            queryBuilder.push($(e).val());
          });

          // Build a param query
          var param = "(" + queryBuilder.join(") OR (") + ")";

          /*
             Use a powerset to weight items. For example, given:
             ☑ Animals
             ☑ Disasters
             We should weight results that are animals AND disasters before results
             that are animals OR disasters.
             */
          param += CampaignFinder.generatePowerset(queryBuilder);

          // Push the newly built parameter onto the q parameter
          q.push(CampaignFinder.fieldMap[i] + ":" + encodeURIComponent(param));
        }
      }

      // Mark the results pane as loading
      CampaignResults.loading();

      // If we"re already running an AJAX request, cancel it
      if (CampaignFinder.xhr) {
        CampaignFinder.xhr.abort();
      }

      // Store the AJAX request locally
      CampaignFinder.xhr = $.ajax({
        dataType: "jsonp",
        url: CampaignFinder.buildQuery(query, q),
        success: function (data) {
          CampaignResults.parseResults(data);
          CampaignFinder.disableFields(data["facet_counts"]["facet_queries"]);
        },
        // We use jsonp for X-domain compatibility
        jsonp: "json.wrf"
      });
    },

    /**
     * Disable fields that have no results available for the given selection
     *
     * @param  {Object} results The Solr facet_queries result
     */
    disableFields: function (results) {
      // for each of the facet queries
      for (var key in results) {
        // Solr returns results in the format field_label:count instead of a nice
        // associative array. :( Let"s parse that out.
        var keyArr = key.split(":");
        var field = keyArr[0],
            value = keyArr[1];

        // We don't want to grey out items in the field set we just selected an item
        // from, so we're keeping track of the last object clicked and passing up any
        // items that are in that group.
        if (CampaignFinder.fieldMapInverse[field] !== CampaignFinder.lastChanged) {
          // Let"s find the element that we want to disable! Yay jQuery chaining!
          var $checkbox = $("input[name='" + CampaignFinder.fieldMapInverse[field] + "']")
            .filter("[value='" + value + "']");
          // Should we disable this field? Whelp, if there are no results, the answer is yes!
          var disabled = results[key] === 0;

          // Set the disabled attribute if we need to (note: disabled is a variable!)
          $checkbox.prop("disabled", disabled);

          if (disabled) {
            // Let"s uncheck it if we can"t select it. It would be confusing otherwise.
            $checkbox.prop("checked", !disabled);

            // And add a class so we can make it look purdy.
            $checkbox.parents("label").removeClass("checked").addClass("disabled");
          } else {
            // Oh, hey! It"s re-enabled! Let"s make it look purdier than it was.
            $checkbox.parents("label").removeClass("disabled");
          }
        } else {
          // First, we see if all fields are unchecked
          _.each(CampaignFinder.$fields, function(field) {
            if (field.filter(":checked").length > 0) {
              return;
            }
          });

          // If they are, let's remove the disabled class
          _.each(CampaignFinder.$fields, function(field) {
            field.prop("disabled", false)
              .parents("label").removeClass("disabled");
          });
        }
      }
    },

    /**
     * Build a Solr query based on a base query string (what comes after the ?)
     * and a "q" which goes into the "q=" part of said query string.
     *
     * TODO: Move this to a Solr class for separation of roles and reusability!
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
        query[pos] = "q=(" + q.join(") AND (") + ")";
      } else {
        // If there ain"t, let"s QUERY ALL THE THINGS (and leave caps lock on)
        query[pos] = "q=*:*";
      }

      // Join the query array together as a URL query string
      query = query.join("&");

      // TODO: un-hard-code the rows
      return CampaignFinder.baseURL + CampaignFinder.collection + "/select?" + query + "&rows=10";
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

  return CampaignFinder;
});
