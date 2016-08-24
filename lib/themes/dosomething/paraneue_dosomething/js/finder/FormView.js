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
  var forEach = require("lodash/forEach");
  var template = require("lodash/template");
  var isEmpty = require("lodash/isEmpty");
  var ResultsView = require("finder/ResultsView");
  var SolrAdapter = require("finder/SolrAdapter");
  var errorTplSrc = require("finder/templates/error.tpl.html");

  /**
   * FormView manages the filter form for Finder
   * @type {Object}
   */
  var FormView = {
    // The div where the form goes
    $div: null,

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
        var $this = $(this),
          toggleClass = $this.data("toggle"),
          $parent = $this.parents("." + toggleClass),
          $siblings = $parent.siblings();

        $parent.toggleClass("open");

        // Need to treat siblings slightly differently to safeguard when going from mobile to desktop.
        if ($(window).outerWidth() >= FormView.cssBreakpoint) {
          if ($parent.hasClass("open")) {
            $siblings.addClass("open");
          } else {
            $siblings.removeClass("open");
          }
        }
      });

      // Store the inputs so we can access them later
      FormView.$fields.cause = $div.find("input[name='cause']");
      FormView.$fields.time = $div.find("input[name='time']");
      FormView.$fields["action-type"] = $div.find("input[name='action-type']");

      // Loop through each field selector
      // @TODO This is tightly coupled.
      forEach(FormView.$fields, function(fieldGroup) {
        // For each field selector, we need to add a Facet query so we can get counts to
        // disable the checkbox.
        fieldGroup.each(function(idx, element) {
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

          // Add the facet query
          SolrAdapter.defaultQuery.push("facet.query=" + field + ":" + val);
        });
      });

      // Now attach events:
      forEach(FormView.$fields, function(fieldGroup) {
        // Attach ourselves to the "change" event on the input fields
        fieldGroup.change(function () {
          // check this guy
          $(this).parents("li").toggleClass("checked", $(this).is(":checked"));

          // Save the last checkbox that we checked so we don"t disable any of
          // those fields if we"re trying to select multiple
          FormView.lastChanged = $(this).attr("name");

          // If we're not on mobile...
          queryCallback();
        });
      });
    },

    /**
     * Have we run the init method?
     */
    checkInit: function () {
      if (FormView.$div === null) {
        // Nope. I'm gonna vomit...
        throw Drupal.t("Error: FormView is not initialized.");
      }

      // Yup.
    },

    /**
     * Shows an error message for network issues
     **/
    showErrorMessage: function() {
      var message = template(errorTplSrc);
      var $message = message();

      if ($(".error").length < 1) {
        FormView.$div.parents(".finder--form").after($message);
      }

    },

    /**
     * Returns Boolean if any fields are checked
     **/
    hasCheckedFields: function() {
      var hasChecked = false;

      // Loop through each of the field groups
      forEach(FormView.$fields, function(fieldGroup) {
        if (fieldGroup.filter(":checked").length > 0) {
          hasChecked = true;
        }
      });

      return hasChecked;
    },

    /**
     * Returns an object with arrays of checked fields grouped by fieldGroup.
     **/
    getCheckedFields: function() {
      var checkedFields = [];

      // Loop through each of the field groups
      forEach(FormView.$fields, function(fieldGroup, groupName) {
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
    disableFields: function(results) {
      // Make sure we've initialized ourself
      FormView.checkInit();

      // @TODO: This is super inefficient. We should be storing state in memory
      // rather than in the DOM, and then rendering the form based on that state.

      // for each of the facet queries
      forEach(results, function(query, key) {
        // Solr returns results in the format field_label:count instead of a nice
        // associative array. :( Let"s parse that out.
        var keyArr = key.split(":");
        var field = keyArr[0],
            value = keyArr[1];

        // If we've checked something in this group, disable 'em all. Otherwise, use facets
        // to disable impossible choices.
        var $checkboxes = $("input[name='" + SolrAdapter.fieldMapInverse[field] + "']");

        if( !isEmpty($checkboxes.filter(":checked")) ) {
          $checkboxes.filter(":not(:checked)").prop("disabled", true);
          $checkboxes.filter(":not(:checked)").parents("li").addClass("disabled");
        } else {
          // Should we disable this field? Whelp, if there are no results, the answer is yes!
          var disabled = results[key] === 0;
          var $checkbox = $checkboxes.filter("[value='" + value + "']");

          // Set the disabled attribute if we need to (note: disabled is a variable!)
          $checkbox.prop("disabled", disabled);

          if (disabled) {
            // Let"s uncheck it if we can't select it. It would be confusing otherwise.
            $checkbox.prop("checked", !disabled);

            // And add a class so we can make it look purdy.
            $checkbox.parents("li").addClass("disabled");
          } else {
            // Oh, hey! It's re-enabled! Let"s make it look purdier than it was.
            $checkbox.parents("li").removeClass("disabled");
          }
        }
      });
    },

    /**
     * Remove the current results and reboot this object.
     */
    clear: function() {
      //FormView.checkInit();
      forEach(FormView.$fields, function(fieldGroup) {
        var disabled = fieldGroup.filter(":disabled");
        if (disabled) {
          fieldGroup.prop("disabled", false)
            .parents("li").removeClass("disabled");
        }
      });
    }
  };

  return FormView;
});
