//
//
// The main DS app. This guy runs the show.
//
//

define(["campaign/tips", "validation/auth", "validation/reportback"],
function(CampaignTips, ValidationAuth, ValidationReportBack) {
  CampaignTips();
  ValidationAuth();
  ValidationReportBack();
});
