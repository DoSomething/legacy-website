define(["jquery", "lodash", "finder/SolrAdapter", "finder/FormView", "finder/ResultsView"], function($, _, SolrAdapter, FormView, ResultsView) {
  "use strict";

  /**
   * Finder manages the search action
   *
   * @type {Object}
   */
  var Finder = {

    /**
     * Initialize the Campaign Finder and, by extension, the Campaign Results handler
     *
     * @param  {JQuery} $formDiv          The div that the filters will be shown in
     * @param  {JQuery} $resultsDiv       The div that the results will be injected into
     * @param  {JQuery} $blankSlateDiv    The div that will be shown when no filter is selected
     */
    init: function ($formDiv, $resultsDiv, $blankSlateDiv) {
      // Initialize the ResultsView
      FormView.init($formDiv, Finder.query);
      ResultsView.init($resultsDiv, $blankSlateDiv, Finder.query);

      // Prepare the Solr adapter
      SolrAdapter.init();
    },

    /**
     * Run the query against the Solr server
     * @param  {int} offset   Offset to start results at (used for pagination).
     */
    query: function(offset) {
      var queryOffset = offset || 0;
      var checkedFields = FormView.getCheckedFields();

      // Run the Solr query
      if(!queryOffset) {
        // If no offset, we display a new set of results
        SolrAdapter.throttledQuery(checkedFields, queryOffset, Finder.displayResults);
      } else {
        // Otherwise, append to existing result set
        SolrAdapter.throttledQuery(checkedFields, queryOffset, ResultsView.appendResults);
      }

      // Mark the results pane as loading
      ResultsView.loading();
    },

    /**
     * Displays results after querying Solr.
     * @param data  Results from SolrAdapter
     **/
    displayResults: function(data) {
      if( FormView.hasCheckedFields() ) {
        ResultsView.parseResults(data);
        /* jshint ignore:start */
        // Using that underscore variable notation for Solr.
        FormView.disableFields(data["facet_counts"]["facet_queries"]);
        /* jshint ignore:end */
      } else {
        ResultsView.showBlankSlate();
        FormView.clear();
      }
    }
  };

  return Finder;
});
