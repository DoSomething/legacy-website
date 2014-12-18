(function ($) {
  $(document).ready(function(){

    // Hide all flag forms to start.
    $('.flag-form').hide();

    // Listen for changes to Status radios.
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

    // Listen for changes to Delete checkboxes.
    $(':input[name*="delete"]').click(function() {

      // If "flagged" was checked:
      if ($(this).is(':checked')) {
        alert(Drupal.t("Deleting this image cannot be undone.\n\nOnly do this if you really, really mean it!"));
      }
    });

  });
}(jQuery));
