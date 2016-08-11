import Onboarding from './components/Onboarding';
import ContextSlide from './components/ContextSlide';
import InstructionSlide from './components/InstructionSlide';
import ReportbackItemKudosSlide from './components/ReportbackItemKudosSlide';
import { getPathnameSegment } from './url/helpers';

const $ = require('jquery');
const React = require('react');
const ReactDom = require('react-dom');
const Modal = require('dosomething-modal');

function getLocalStorageKey(user, campaign) {
  let key = null;
  if (campaign && user) {
    key = `onboarding:campaign=${campaign.id}-user=${user.info.id}`;
  }

  return key;
}

function enableOnboarding(localStorageKey, user, campaign) {
  const jsxElementHook = 'jsx-onboarding';
  const slideComponents = {ContextSlide, InstructionSlide, ReportbackItemKudosSlide};
  const slides = Drupal.settings.dsOnboarding.slides.map(name => slideComponents[name]);

  if (slides.length == 0) {
    return;
  }

  $('.chrome').find('> .wrapper').before(`<div id="${jsxElementHook}"></div>`);
  $('.messages:not(.error)').remove();

  if (localStorageKey) {
    localStorage.setItem(localStorageKey, true);
  }

  ReactDom.render(<Onboarding slides={slides} campaign={campaign} user={user} />, document.getElementById(jsxElementHook));
}

/**
 * Welcome to the Laboratory.
 * Run your experiments below.
 */
$(document).ready(function() {
  const campaign = Drupal.settings.dsCampaign || null;
  const user = Drupal.settings.dsUser || null;
  const isOutsideUnitedStates = getPathnameSegment() !== 'us' ? true : false;
  const localStorageKey = getLocalStorageKey(user, campaign);

  if (isOutsideUnitedStates || Modal.isOpen()) {
    return;
  }
  else if (Drupal.settings.dsOnboarding.enabled && localStorage.getItem(localStorageKey) !== 'true') {
    enableOnboarding(localStorageKey, user, campaign);
  }

});
