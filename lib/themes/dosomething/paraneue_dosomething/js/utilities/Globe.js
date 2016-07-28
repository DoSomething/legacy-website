import $ from 'jquery';
import setting from './Setting';

function init() {
  const globeUpdateUrl = setting('dosomethingSetting.globeUrl');
  if (globeUpdateUrl !== undefined) {
    const countryCode = setting('dosomethingSetting.countryCode');
    $.post(globeUpdateUrl, {code: countryCode});
  }
}

export default { init };
