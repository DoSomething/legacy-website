import setting from '../utilities/Setting';

const $ = require('jquery');
const get = require('lodash/get');

/**
 * Make an API request to create/delete the Kudos Reaction for that item.
 *
 * @param {jQuery} $el
 * @param {String} id - An existing Kudo id
 */
function makeKudosRequest($el, id)
{
  return $.ajax({
    method: id ? 'DELETE' : 'POST',
    url: id ? `/api/v1/kudos/${id}` : '/api/v1/kudos',
    dataType: 'json',
    headers: {
      'Content-Type': 'application/json',
      'X-CSRF-Token': $('meta[name="csrf-token"]').attr('content'),
    },
    data: JSON.stringify({
      'reportback_item_id': $el.closest('[data-reportback-item-id]').attr('data-reportback-item-id'),
      'term_ids': [$el.attr('data-kudos-term-id')]
    }),
  });
}

/**
 * Show the things we've accomplished.
 *
 * @param {jQuery} $el
 */
function updateKudosInterface($el)
{
  const hasKudos = $el.attr('data-kid') !== '';

  let $counter = $el.next('.counter');
  let currentCount = parseInt($counter.text());
  let diff = hasKudos ? 1 : -1;

  $el.toggleClass('is-active', hasKudos);

  $counter.text(currentCount + diff);

  $counter.toggleClass('tada is-active', hasKudos);
}

/*
 * Alright, let's tell that button what it's gonna do.
 */
$(document).on('click', '.js-kudos-button', function(event) {
  event.preventDefault();

  const $el = $(this);

  $el.attr('disabled','disabled');
  const dataKid = $el.attr('data-kid');
  const method = dataKid ? 'DELETE' : 'POST';

  // if (setting('dsKudosReactions.sendToRogue')) {
  //   makeKudosRequestToRogue(setting('dsKudosReactions.northstarId'), setting('dsKudosReactions.postId'))
  // } else {
  makeKudosRequest($el, dataKid)
    .done((response) => {
      const kid = get(response, '0.kid', '');

      if (method === 'POST' && !kid) {
        return;
      }

      $el.attr('data-kid', kid);

      updateKudosInterface($el);
    })
    .always(() => {
      $el.removeAttr('disabled');
    });
  // }
});
