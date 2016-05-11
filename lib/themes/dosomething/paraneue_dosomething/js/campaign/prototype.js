import $ from 'jquery';

$(document).on('click', '.js-kudos-button', function(event) {
  event.preventDefault();
  const $this = $(this);

  var postData = {
    'reportback_item_id': $this.closest('[data-reportback-item-id]').attr('data-reportback-item-id'),
    'user_id': $('meta[name="drupal-user-id"]').attr('content'),
    'term_ids': [
      $this.attr('data-kudo-id')
    ]
  };

  $.ajax({
    method: 'POST',
    url: '/api/v1/auth/token',
    dataType: 'json',
    headers: {
      'Accepts': 'application/json',
      'Content-Type': 'application/json',
    }
  }).done(function(data) {
    console.log(data.token);
    $.ajax({
      method: 'POST',
      url: '/api/v1/kudos',
      dataType: 'json',
      data: JSON.stringify(postData),
      headers: {
        'Accepts': 'application/json',
        'Content-Type': 'application/json',
        'X-CSRF-Token': data.token
      }
    }).done(function(data) {
      console.log(data);
      alert('YEA YEAH OKAY');
      // ...
    });
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
