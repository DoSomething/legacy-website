import Onboarding from './components/Onboarding';
import ContextSlide from './components/ContextSlide';

const $ = require('jquery');
const React = require('react');
const ReactDom = require('react-dom');

/**
 * Welcome to the Laboratory.
 * Run your experiments below.
 */
$(document).ready(function() {

  // Enable the Onboarding experiment.
  if (Drupal.settings.dsOnboarding.enabled) {
    const elementName = 'onboarding';
    const slides = [<ContextSlide />]

    $('.chrome').find('.wrapper').before(`<div id="${elementName}" class="${elementName}"></div>`);

    ReactDom.render(<Onboarding slides={slides} />, document.getElementById(elementName));
  }

});
