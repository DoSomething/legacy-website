import Onboarding from './components/Onboarding';
import ContextSlide from './components/ContextSlide';
import InstructionSlide from './components/InstructionSlide';

const $ = require('jquery');
const React = require('react');
const ReactDom = require('react-dom');

/**
 * Welcome to the Laboratory.
 * Run your experiments below.
 */
$(document).ready(function() {
  const campaign = Drupal.settings.dsCampaign || null;
  const user = Drupal.settings.dsUser || null;
  const disabledByLanguage = ['mx', 'br'].indexOf(campaign.language.language_code) != -1;
  let localStorageKey = null;

  if (campaign && user && !disabledByLanguage) {
    localStorageKey = `onboarding:campaign=${campaign.id}-user=${user.info.id}`;
  }

  // Enable the Onboarding experiment.
  if (Drupal.settings.dsOnboarding.enabled && localStorage.getItem(localStorageKey) !== 'true') {
    const jsxElementHook = 'jsx-onboarding';
    const slides = [ContextSlide, InstructionSlide];

    $('.chrome').find('> .wrapper').before(`<div id="${jsxElementHook}"></div>`);

    if (localStorageKey) {
      localStorage.setItem(localStorageKey, true);
    }

    ReactDom.render(<Onboarding slides={slides} campaign={campaign} user={user} />, document.getElementById(jsxElementHook));
  }

});
