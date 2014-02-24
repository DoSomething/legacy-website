module.exports = function() {
  $('.js-show-tip').on('click', function() {

    // Hide all tips
    $('.tip-body').hide();

    // Show requested tip
    tipNumber = $(this).attr('href').slice(1);
    $('.' + tipNumber).show();

  });
};
