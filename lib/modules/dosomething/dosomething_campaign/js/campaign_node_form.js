(function ($) {
  $(document).ready(function(){

    // Titles of all elements that should only display when Campaign type == 'campaign'.
    var campaignTitles = ["Plan It", "Prove It"];

    // List all elements that should only display when Campaign type == 'campaign'.
    var campaignSections = [];

    $('.fieldset-title').each(function(index, value) {
      // Get the title of the fieldset and strip out unneeded text
      var title = $(value).text().replace("Show", "").trim();
      //Check if it's a campaign only title
      if (campaignTitles.indexOf(title) != -1) {
        campaignSections.push($(value).closest('.form-wrapper'));
      }
    });

    // If SMS Game, hide the campaignSections.
    if ($('#edit-field-campaign-type-und-sms-game').is(':checked')) {
      toggleSections(false);
    }

    // Listen for changes to the campaign type field.
    $('#edit-field-campaign-type-und-campaign, #edit-field-campaign-type-und-sms-game').click(function() {
      if ($('#edit-field-campaign-type-und-campaign').is(':checked')) {
        toggleSections(true);
      }
      if ($('#edit-field-campaign-type-und-sms-game').is(':checked')) {
        toggleSections(false);
      }
    });

    // Toggle the visibility of field sets in campaignSelections
    function toggleSections(show) {
      campaignSections.forEach(function($element, index, array) {
        if (show) {
          $element.show();
        }
        else {
          $element.hide();
        }
      });
    }

    $('.vertical-tab-button a').click(function() {
      if ($('.vertical-tabs-panes').find('#edit-options:visible').length !== 0)
      {
        togglePublish();
      }
    });

    $('select[name*="field_current_run"]').change(function() {
      togglePublish();
    });

    function togglePublish() {
      $currentRun = $( "select[name*='field_current_run']" ).val();
      if ($currentRun === '_none' && !$('.form-item-status input').is(':checked')) {
        displayPublish(false);
      } else {
        displayPublish(true);
      }
    }

    function displayPublish(state) {
      var $publishContainer = $('.node-form-options');
      var $publishOption = $('.form-item-status');

      if (state) {
        var $error = $publishContainer.find('.error');
        if ($error.length) {
          $error.remove();
        }
        $publishOption.find('#edit-status').removeAttr('disabled');
        $publishOption.find('.option').css('color', '#333333');
      } else {
        if (!$publishContainer.find('.error').length) {
          var $error = $('<div class="messages error">Please select a <a href="#edit-field-current-run">campaign run</a> in order to change publish state.</div>');
          $publishContainer.prepend($error);
        }
        $publishOption.find('#edit-status').attr('disabled','disabled');
        $publishOption.find('.option').css('color', 'gray');
      }
    }
  });
}(jQuery));
