define([
  "jquery",
  "Campaign",
  "CampaignFinder"
], function ($, Campaign, CampaignFinder) {
  "use strict";

  $("[data-toggle]").click(function () {
    var toggleClass = $(this).data("toggle");
    $(this).parents("." + toggleClass).toggleClass("open");
  });

  CampaignFinder.init(
    $("#campaign-results"),
    $(".campaign-search"),
    $("input[name='cause']"),
    $("input[name='time']"),
    $("input[name='action-type']")
  );

  CampaignFinder.query();
});
