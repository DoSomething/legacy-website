import $ from 'jquery';

/**
 * Toggle truncated text and long text on permalink pages.
 */
function init($showMoreText = $('.js-permalink-show-more')) {
  if (!$showMoreText.length) return;


  $showMoreText.on('click', function(event) {
    event.preventDefault();

    $('.participate').toggleClass('is-shown');

    if ($showMoreText.html() === 'Show More') {
      $showMoreText.html('Show Less');
    } else {
      $showMoreText.html('Show More');
    }
  });
}

export default { init };
