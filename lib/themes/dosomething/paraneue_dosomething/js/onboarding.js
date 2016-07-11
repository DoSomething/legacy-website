import $ from 'jquery';

const React = require('react');
const ReactDOM = require('react-dom');

import Onboard from 'components/onboard';
import ContextSlide from 'components/context_slide';


/**
 * Enable onboarding
 */
$(document).ready(function() {
  if (Drupal.settings.dsOnboarding.enabled) {
    // Prep for onboarding
    var slides = [<ContextSlide />]
    $('.chrome').prepend('<div id="onboarding" class="wrapper"></div>');

    // Render the onboarding experience
    ReactDOM.render(
      <Onboard slides={slides} />,
      document.getElementById('onboarding')
    );
  }
});
