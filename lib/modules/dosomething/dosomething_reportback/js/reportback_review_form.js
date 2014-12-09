(function ($) {
  $(document).ready(function(){

    // Hide all flag forms to start.
    $('.flag-form').hide();

    // Listen for changes to Status checkboxes.
    $('.form-radio:input[name*="status"]').click(function() {
      // Find the flagForm that corresponds to this checkbox.
      var flagForm = $(this).parents('.form-type-radios').next('.flag-form');
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
