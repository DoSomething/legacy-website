import $ from 'jquery';
import array_get from 'lodash/object/get';

// Set AJAX request defaults.
$.ajaxSetup({
  dataType: 'json',
  headers: {
    'Accepts': 'application/json',
    'Content-Type': 'application/json',
    'X-CSRF-Token': $('meta[name="csrf-token"]').attr('content'),
  }
});

/**
 * Make an API request to create/delete the Kudo for that item.
 *
 * @param {jQuery} $el
 * @param {String} id - An existing Kudo id
 */
function makeKudoRequest($el, id)
{
  return $.ajax({
    method: id ? 'DELETE' : 'POST',
    url: id ? `/api/v1/kudos/${id}` : '/api/v1/kudos',
    data: JSON.stringify({
      'reportback_item_id': $el.closest('[data-reportback-item-id]').attr('data-reportback-item-id'),
      'user_id': $('meta[name="drupal-user-id"]').attr('content'),
      'term_ids': [$el.attr('data-kudo-id')]
    }),
  });
}

/**
 * Show the things we've accomplished.
 *
 * @param {jQuery} $el
 */
function updateKudoInterface($el)
{
  const hasKudo = $el.attr('data-kid') !== '';

  var $counter = $el.next('.counter');
  var currentCount = parseInt($counter.text());
  var diff = hasKudo ? 1 : -1;

  $el.toggleClass('is-active', hasKudo);
  $counter.text(currentCount + diff);
  $counter.toggleClass('tada is-active', hasKudo);
}

/*
 * Alright, let's tell that button what it's gonna do.
 */
$(document).on('click', '.js-kudos-button', function(event) {
  event.preventDefault();

  const $el = $(this);
  const kid = $el.attr('data-kid');

  makeKudoRequest($el, kid).done(function(response) {
    const kid = array_get(response, '0.kid', '');
    $el.attr('data-kid', kid);

    updateKudoInterface($el);
  });
});
