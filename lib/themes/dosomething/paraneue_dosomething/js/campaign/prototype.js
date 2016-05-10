import $ from 'jquery';

$(document).on('click', '.js-kudos-button', function(event) {
  event.preventDefault();
  const $this = $(this);

  var data = {
    'reportback_item_id': $this.closest('[data-reportback-item-id]').attr('data-reportback-item-id'),
    'user_id': $('meta[name="drupal-user-id"]').attr('content'),
    'term_ids': [
      $this.attr('data-kudo-id')
    ]
  };

  console.log(data);
  $.ajax({
    method: 'POST',
    url: '/api/v1/kudos',
    dataType: 'json',
    data: JSON.stringify(data),
    headers: {
      'Accepts': 'application/json',
      'Content-Type': 'application/json',
      'X-CSRF-TOKEN': $('meta[name="csrf-token"]').attr('content')
    }
  }).done(function(data) {
    console.log(data);
    alert('YEA YEAH OKAY');
    // ...
  });

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
