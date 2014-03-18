module.exports = function() {
  "use strict";

  (function($) {
    // View other tips on click
    $(".js-show-tip").on("click", function(e) {
      e.preventDefault();

      // Cache $(this) and reference to parent wrapper
      var $this = $(this);
      var $thisParent = $this.closest(".tips--wrapper");

      // Pass "active" class to move tip indicator
      $thisParent.find(".tip-header").removeClass("active");
      $this.addClass("active");

      // Get current tip number
      var tipNumber = $this.attr("href").slice(1);

      // Show current tip
      $thisParent.find(".tip-body").hide();
      $thisParent.find("." + tipNumber).show();
    });
  })(jQuery);

};
