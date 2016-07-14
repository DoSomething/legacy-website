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
    const jsxElementHook = 'jsx-onboarding';
    const slides = [ContextSlide, ContextSlide] // @TODO: create other slide components.
    const campaign = {
      // @TODO: switch to use Drupal.settings.dsCampaign once it is available.
      title: 'Awesome Campaign Placeholder'
    }
    const user = Drupal.settings.dsUser || null;

    $('.chrome').find('> .wrapper').before(`<div id="${jsxElementHook}"></div>`);

    ReactDom.render(<Onboarding slides={slides} campaign={campaign} user={user} />, document.getElementById(jsxElementHook));
  }

});
