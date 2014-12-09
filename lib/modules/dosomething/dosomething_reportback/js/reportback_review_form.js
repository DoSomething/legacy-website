(function ($) {
  $(document).ready(function(){

    // Hide all flag forms to start.
    $('.flag-form').hide();

    // Listen for changes to Flagged checkboxes.
    $(':input[name*="status"]').click(function() {
      // Find the next flagForm within the awesome Drupal markup.
      var flagForm = $(this).parent().parent().parent().next('.flag-form');
      // If "flagged" was checked:
      if ($(this).val() == 'flagged') {
        // Display the flagForm.
        flagForm.show();
      }
      else {
        flagForm.hide();
      }
    });
  });
}(jQuery));
