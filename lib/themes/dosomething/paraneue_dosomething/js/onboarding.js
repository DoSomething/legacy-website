import Onboarding from './components/Onboarding';
import ContextSlide from './components/ContextSlide';
import InstructionSlide from './components/InstructionSlide';
import ReportbackItemsSlide from './components/ReportbackItemsSlide';
import setting from './utilities/Setting';

const $ = require('jquery');
const React = require('react');
const ReactDom = require('react-dom');
const Modal = require('dosomething-modal');

/**
 * Get the local storage key for Onboarding.
 *
 * @param  {Object} user
 * @param  {Object} campaign
 * @return {String}
 */
function getLocalStorageKey(user, campaign) {
  let key = null;

  if (campaign && user) {
    key = `onboarding:campaign=${campaign.id}&user=${user.info ? user.info.id :  'null'}`;
  }

  return key;
}

function shouldOnboardingBeEnabled(localStorageKey) {
  const developerEnabled = setting('dsOnboarding.developerEnabled', false);
  const moduleEnabled = setting('dsOnboarding.globalEnabled', false);
  const campaignEnabled = setting('dsOnboarding.campaignEnabled', false);

  if (developerEnabled) {
    return true;
  }

  if (moduleEnabled && campaignEnabled) {
    return localStorage.getItem(localStorageKey) !== 'true';
  }

  return false
}

/**
 * Enable the Onboarding experience based on certain conditions.
 *
 * @param  {String} localStorageKey
 * @param  {Object} user
 * @param  {Object} campaign
 * @return {Void}
 */
function enableOnboarding(localStorageKey, user, campaign) {
  const jsxElementHook = 'jsx-onboarding';
  const slideComponents = {ContextSlide, InstructionSlide, ReportbackItemsSlide};
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
 * Document ready... ENGAGE!
 */
$(document).ready(function() {
  const campaign = Drupal.settings.dsCampaign || null;
  const user = Drupal.settings.dsUser || null;
  const isOutsideUnitedStates = setting('pathPrefix', '') !== 'us/' ? true : false;
  const localStorageKey = getLocalStorageKey(user, campaign);

  if (isOutsideUnitedStates || Modal.isOpen()) {
    return;
  }
  else if (shouldOnboardingBeEnabled(localStorageKey)) {
    enableOnboarding(localStorageKey, user, campaign);
  }

});
