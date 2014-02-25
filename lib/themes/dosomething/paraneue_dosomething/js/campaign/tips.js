module.exports = function() {
  "use strict";

  // View other tips on click
  $(".js-show-tip").on("click", function(e) {
    e.preventDefault();

    // Pass "active" class to move tip indicator
    $(".tip-header").removeClass("active");
    $(this).addClass("active");

    // Get current tip number
    var tipNumber = $(this).attr("href").slice(1);

    // Show current tip
    $(".tip-body").hide();
    $("." + tipNumber).show();
  });

};
