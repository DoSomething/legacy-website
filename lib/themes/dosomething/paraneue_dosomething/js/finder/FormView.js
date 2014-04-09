define(["jquery", "unveil", "finder/Finder", "finder/Campaign", "finder/SolrAdapter"], function($, unveil, Finder, Campaign, SolrAdapter) {
  "use strict";

  /**
   * FormView manages the filter form for Finder
   * @type {Object}
   */
  var FormView = {
    // The div where the form goes
    $div: null,

    // <button> that mobile users click to initiate the search
    $searchButton: null,

    // The field groups that contain the checkmarks
    $fields: {},

    // The last field group that was changed (by name)
    lastChanged: null,

    // TODO: Can we get this from CSS somewhere instead so it's not hard-coded?
    cssBreakpoint: 768,

    /**
     * Construct the cloneables and set the parent div where the results go
     * @param  {jQuery} $div The div where the results will live
     */
    init: function ($div, queryCallback) {
      FormView.$div = $div;

      // Prepare toggles
      $div.find("[data-toggle]").click(function () {
        var toggleClass = $(this).data("toggle");
        $(this).parents("." + toggleClass).toggleClass("open");
      });

      // Store the inputs so we can access them later
      FormView.$fields.cause = $div.find("input[name='cause']");
      FormView.$fields.time = $div.find("input[name='time']");
      FormView.$fields["action-type"] = $div.find("input[name='action-type']");

      // Hook up to the DOM
      FormView.$searchButton = $div.find(".campaign-search");

      // Loop through each field selector
      // @TODO This is tightly coupled.
      for (var i in FormView.$fields) {
        // For each field selector, we need to add a Facet query so we can get counts to
        // disable the checkbox.
        FormView.$fields[i].each(function(idx, element) {
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
      for (var i in FormView.$fields) {
        // Attach ourselves to the "change" event on the input fields
        FormView.$fields[i].change(function () {
          // Temporarily force single-select until we have more things in the finder
          // Not using [type="radio"] since we want options to be de-selectable.
          $(this).parents("li").siblings("li").find("label").removeClass("checked");
          $(this).parents("li").siblings("li").find("input").attr("checked", false);

          $(this).parents("label").toggleClass("checked", $(this).is(":checked"));

          // Save the last checkbox that we checked so we don"t disable any of
          // those fields if we"re trying to select multiple
          FormView.lastChanged = $(this).attr("name");

          // If we're not on mobile...
          if (document.body.clientWidth >= FormView.cssBreakpoint) {
            queryCallback({ throttle: true });
          }
        });
      }

      // Search button appears on mobile in lieu of live filtering
      FormView.$searchButton.click(function () {
        queryCallback();
        $("html,body").animate({
          scrollTop: ResultsView.$div.offset().scrollTop
        }, 1000);
      });
    },

    /**
     * Returns an object with arrays of checked fields grouped by fieldGroup.
     **/
    getCheckedFields: function() {
      var checkedFields = [];

      // Loop through each of the field groups
      _.each(FormView.$fields, function(fieldGroup, groupName) {
        var checked = fieldGroup.filter(":checked");
        checkedFields[groupName] = [];

        // Only add this to the query if there are fields checked in this field group
        if (checked.length > 0) {
          // For each checked box, add it to the search query
          checked.each(function (index, e) {
            checkedFields[groupName].push($(e).val());
          });
        }
      });

      return checkedFields;
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
        if (SolrAdapter.fieldMapInverse[field] !== FormView.lastChanged) {
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
          _.each(FormView.$fields, function(field) {
            if (field.filter(":checked").length > 0) {
              return;
            }
          });

          // If they are, let's remove the disabled class
          _.each(FormView.$fields, function(field) {
            field.prop("disabled", false)
              .parents("label").removeClass("disabled");
          });
        }
      }
    },

    /**
     * Remove the current results and reboot this object.
     */
    clear: function () {
      // FormView.checkInit();
      console.warn("Not yet implemented!");

      // @TODO Reset field selections!
    }
  };

  return FormView;
});
