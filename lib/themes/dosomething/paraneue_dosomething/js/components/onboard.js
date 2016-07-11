const React = require('react');
const ReactDOM = require('react-dom');

import $ from 'jquery';
import Carousel from './carousel.js';

const Onboard = React.createClass({
  render: function() {
    return (
      <div className="onboard">
        <Carousel />
      </div>
    );
  }
});

/**
 * Enable onboarding
 */
$(document).ready(function() {
  if (Drupal.settings.dsOnboarding.enabled) {
    $('.chrome').prepend('<div id="onboarding" class="wrapper"></div>');
    ReactDOM.render(
      <Onboard />,
      document.getElementById('onboarding')
    );
  }
});
