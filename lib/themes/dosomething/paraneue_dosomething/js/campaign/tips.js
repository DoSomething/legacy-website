module.exports = function() {
  $('.js-show-tip').on('click', function() {
    // Hide all tips
    $('.tip-body').hide();

    // Show requested tip
    tip_number = $(this).attr('href').slice(1);
    $(tip_number).show();
  });
};
