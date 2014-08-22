(function ($) {
  $(document).ready(function(){

    // List all id's that should only display when Campaign type == 'campaign'.
    var campaignSections = [];
    campaignSections.push("#node_campaign_form_group_prep_it");
    campaignSections.push("#node_campaign_form_group_do_it");
    campaignSections.push("#node_campaign_form_group_report_back");
    campaignSections.push("#node_campaign_form_group_pitch_additional_info");

    // If SMS Game, hide the campaignSections.
    if ($('#edit-field-campaign-type-und-sms-game').is(':checked')) { 
      for (var i = 0; i < campaignSections.length; i++) {
        $(campaignSections[i]).hide();
      }
    }
    
    // Listen for changes to the campaign type field.
    $('#edit-field-campaign-type-und-campaign, #edit-field-campaign-type-und-sms-game').click(function() {
      if ($('#edit-field-campaign-type-und-campaign').is(':checked')) { 
        for (var i = 0; i < campaignSections.length; i++) {
          $(campaignSections[i]).show();
        }
      }
      if ($('#edit-field-campaign-type-und-sms-game').is(':checked')) { 
        for (var i = 0; i < campaignSections.length; i++) {
          $(campaignSections[i]).hide();
        }
      }
    });

  });
}(jQuery));
