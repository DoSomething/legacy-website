(function ($) {
  $(document).ready(function(){

    // Hide all flag forms to start.
    $('.flag-form').hide();
    $('.promote-form').hide();

    // Listen for changes to Status radios.
    $('.form-radio:input[name*="status"]').click(function() {
      // Find the flagForm that corresponds to this checkbox.
      var flagForm = $(this).parents('td').find('.flag-form');
      var promoteForm = $(this).parents('td').find('.promote-form');

      // If "flagged" was checked:
      if ($(this).val() == 'flagged') {
        // Display the flagForm, hide promoteForm.
        flagForm.show();
        promoteForm.hide();
      }
      // If "promotted" was checked:
      else if ($(this).val() == 'promoted') {
        // Show promoteForm, hide flagForm.
        promoteForm.show();
        flagForm.hide();

      }
      // If any other option was clicked, hide both forms.
      else {
        flagForm.hide();
        promoteForm.hide();
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
