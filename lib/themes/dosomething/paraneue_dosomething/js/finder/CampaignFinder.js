define(["jquery", "lodash", "finder/SolrAdapter", "finder/CampaignResults"], function($, _, SolrAdapter, CampaignResults) {
  "use strict";

  /**
   * CampaignFinder manages the search action
   *
   * @type {Object}
   */
  var CampaignFinder = {
    // TODO: Can we get this from CSS somewhere instead so it's not hard-coded?
    cssBreakpoint: 768,

    // The field groups that contain the checkmarks
    $fields: {},

    // The last field group that was changed (by name)
    lastChanged: null,

    /**
     * Initialize the Campaign Finder and, by extension, the Campaign Results handler
     *
     * @param  {JQuery} $resultsDiv       The div that the results will be injected into
     * @param  {JQuery} $blankSlateDiv    The div that will be shown when no filter is selected
     * @param  {JQuery} $searchButton     <button> that mobile users click to initiate the search
     * @param  {JQuery} $causeFields      Input fields related to the cause field
     * @param  {JQuery} $timeFields       Input fields related to the time field
     * @param  {JQuery} $actionTypeFields Input fields related to the action type field
     */
    init: function ($resultsDiv, $blankSlateDiv, $searchButton, $causeFields, $timeFields, $actionTypeFields) {
      // Prepare checkboxes (?)
      $("[data-toggle]").click(function () {
        var toggleClass = $(this).data("toggle");
        $(this).parents("." + toggleClass).toggleClass("open");
      });

      // Store the inputs so we can access them later
      CampaignFinder.$fields.cause = $causeFields;
      CampaignFinder.$fields.time = $timeFields;
      CampaignFinder.$fields["action-type"] = $actionTypeFields;

      // Initialize the CampaignResults
      CampaignResults.init($resultsDiv, $blankSlateDiv);

      // Store the button
      CampaignFinder.$searchButton = $searchButton;

      // Prepare the Solr adapter
      SolrAdapter.init();

      // Loop through each field selector
      // @TODO This is tightly coupled.
      for (var i in CampaignFinder.$fields) {
        // For each field selector, we need to add a Facet query so we can get counts to
        // disable the checkbox.
        CampaignFinder.$fields[i].each(function(idx, element) {
          /**
           * The Solr field name that we're going to query against
           * @type {String}
           */
          var field = SolrAdapter.fieldMap[$(element).prop("name")];

          /**
           * The value of the field that we're passing in to the query
           * @type {String}
           */
          var val = $(element).val();

          // Add the face query
          SolrAdapter.defaultQuery.push("facet.query=" + field + ":" + val);
        });
      }

      // Now attach events:
      for (var i in CampaignFinder.$fields) {
        // Attach ourselves to the "change" event on the input fields
        CampaignFinder.$fields[i].change(function () {
          $(this).parents("label").toggleClass("checked", $(this).is(":checked"));
          // Save the last checkbox that we checked so we don"t disable any of
          // those fields if we"re trying to select multiple
          CampaignFinder.lastChanged = $(this).attr("name");

          // If we're not on mobile...
          if (document.body.clientWidth >= CampaignFinder.cssBreakpoint) {
            SolrAdapter.throttledQuery(CampaignFinder.$fields, CampaignFinder.displayResults);
          }
        });

        CampaignFinder.$searchButton.click(function () {
          SolrAdapter.query();
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
      // Run the Solr query
      SolrAdapter.query(CampaignFinder.$fields, CampaignFinder.displayResults);

      // Mark the results pane as loading
      CampaignResults.loading();
    },

    /**
     * Displays results after querying Solr.
     * @param data  Results from SolrAdapter
     **/
    displayResults: function(data) {
      CampaignResults.parseResults(data);
      CampaignFinder.disableFields(data["facet_counts"]["facet_queries"]);
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
        if (SolrAdapter.fieldMapInverse[field] !== CampaignFinder.lastChanged) {
          // Let"s find the element that we want to disable! Yay jQuery chaining!
          var $checkbox = $("input[name='" + SolrAdapter.fieldMapInverse[field] + "']")
            .filter("[value='" + value + "']");
          // Should we disable this field? Whelp, if there are no results, the answer is yes!
          var disabled = results[key] === 0;

          // Set the disabled attribute if we need to (note: disabled is a variable!)
          $checkbox.prop("disabled", disabled);

          if (disabled) {
            // Let"s uncheck it if we can't select it. It would be confusing otherwise.
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
  };

  return CampaignFinder;
});
