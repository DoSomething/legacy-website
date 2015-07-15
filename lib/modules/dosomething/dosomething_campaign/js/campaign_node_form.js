(function ($) {
  $(document).ready(function(){

    // Titles of all elements that should only display when Campaign type == 'campaign'.
    var campaignTitles = ["Know It", "Plan It", "Prove It"];

    // List all elements that should only display when Campaign type == 'campaign'.
    var campaignSections = [];
    // campaignSections.push("#node_campaign_form_group_prep_it");
    // campaignSections.push("#node_campaign_form_group_do_it");
    // campaignSections.push("#node_campaign_form_group_report_back");
    // campaignSections.push("#node_campaign_form_group_pitch_additional_info");

    $('.fieldset-title').each(function(index, value) {
      // Get the title of the fieldset and strip out unneeded text
      var title = $(value).text().replace("Show", "").trim();
      //Check if it's a campaign only title
      if (campaignTitles.indexOf(title) != -1) {
        campaignSections.push($(value).closest('.form-wrapper'));
        console.log(campaignSections);
      }
    });

    // If SMS Game, hide the campaignSections.
    if ($('#edit-field-campaign-type-und-sms-game').is(':checked')) {
      // for (var i = 0; i < campaignSections.length; i++) {
      //   $(campaignSections[i]).hide();
      // }
      toggleSections(false);
    }

    // Listen for changes to the campaign type field.
    $('#edit-field-campaign-type-und-campaign, #edit-field-campaign-type-und-sms-game').click(function() {
      if ($('#edit-field-campaign-type-und-campaign').is(':checked')) {
        // for (var i = 0; i < campaignSections.length; i++) {
        //   $(campaignSections[i]).show();
        // }
        toggleSections(true);
      }
      if ($('#edit-field-campaign-type-und-sms-game').is(':checked')) {
        // for (var i = 0; i < campaignSections.length; i++) {
        //   $(campaignSections[i]).hide();
        // }
        toggleSections(false);
      }
    });

    function toggleSections(show) {
      campaignSections.forEach(function($element, index, array) {
        console.log($element);
        if (show) {
          $element.show();
        }
        else {
          $element.hide();
        }
      });
    }

  });
}(jQuery));
