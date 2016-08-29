import $ from 'jquery';

function init($tiles = $('.tile')) {
  // On Mobile Safari, we need to replace `<video>` with a static image so the "play" control does not appear.
  // Yes, this is browser sniffing - but we're fixing a browser-specific quirk so I don't think it's evil.
  if (window.navigator.userAgent.match(/iPad/i) || window.navigator.userAgent.match(/iPhone/i)) {
    // Replace the `video` tag in a tile with a static image, based on either the `poster`
    // attribute of the video, or an included `img` fallback source.
    $tiles.find('video').each(function() {
      const poster = $(this).find('img').attr('src') || $(this).attr('poster');
      $(this).replaceWith($('<img>').attr('src', poster));
    });
  }
}

export default { init };
