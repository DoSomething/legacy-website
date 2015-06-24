import $ from 'jquery';

$(document).on('click', '.js-kudos-like-button', function(event) {
  event.preventDefault();
  const $this = $(this);

  var $counter = $(this).next('.counter');
  var currentCount = parseInt($counter.text());

  if($this.hasClass('is-active')) {
    $(this).removeClass('is-active');
    $counter.text(currentCount - 1);
    $counter.removeClass('tada is-active');
  } else {
    $(this).addClass('is-active');
    $counter.text(currentCount + 1);
    $counter.addClass('tada is-active');
  }

});

$(document).on('click', '.js-kudos-trash-button', function(event) {
  event.preventDefault();
  const $this = $(this);

  var $counter = $(this).next('.counter');
  var currentCount = parseInt($counter.text());

  if($this.hasClass('is-active')) {
    $(this).removeClass('is-active');
    $counter.text(currentCount - 1);
    $counter.removeClass('tada is-active');
  } else {
    $(this).addClass('is-active');
    $counter.text(currentCount + 1);
    $counter.addClass('tada is-active');
  }

});
