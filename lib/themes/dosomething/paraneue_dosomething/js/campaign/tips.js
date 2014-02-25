module.exports = function() {

  // View other tips on click
  $('.js-show-tip').on('click', function(e) {
    e.preventDefault();

    // Pass "active" class to move tip indicator
    $('.tip-header').removeClass('active');
    $(this).addClass('active');

    // Get current tip number
    var tip_number = $(this).attr('href').slice(1);

    // Show current tip
    $('.tip-body').hide();
    $('.' + tip_number).show();
  });

};
