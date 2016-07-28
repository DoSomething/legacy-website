import $ from 'jquery';
import setting from './Setting';

function init() {
  const globeUpdateUrl = setting('dosomethingSetting.globeUrl');
  if (globeUpdateUrl !== undefined) {
    const countryCode = setting('dosomethingSetting.countryCode');

    // Prevents sensitive information from leaking to 3rd party in the referer.
    let $meta = $('<meta name="referrer" content="no-referrer" />');
    $('head').append($meta);

    $.post(globeUpdateUrl, {code: countryCode});

    $meta.remove();
  }
}

export default { init };
