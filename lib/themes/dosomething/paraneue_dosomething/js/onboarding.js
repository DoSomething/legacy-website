import Onboarding from './components/Onboarding';
import ContextSlide from './components/ContextSlide';
import InstructionSlide from './components/InstructionSlide';
import ReportbackItemsSlide from './components/ReportbackItemsSlide';
import CampaignSlide from './components/CampaignSlide';
import setting from './utilities/Setting';
import ApiClient from './utilities/ApiClient';

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

/**
 * Check if onboaridng is enabled
 *
 * @param  {String} localStorageKey
 * @param  {Object} config
 * @return {Boolean}
 */
function isOnboardingEnabled(localStorageKey, config) {
  const developerModeEnabled = config.developerMode;
  const moduleEnabled = config.enabled;
  const campaignEnabled = config.campaignEnabled;

  if (developerModeEnabled) {
    return true;
  }

  if (moduleEnabled && campaignEnabled && localStorage.getItem(localStorageKey) !== 'true') {
    return true;
  }

  return false
}

/**
 * Enable the Onboarding experience based on given slide configuration.
 *
 * @param  {String} localStorageKey
 * @param  {Object} user
 * @param  {Object} campaign
 * @param  {Object} slideConfiguration
 * @return {Void}
 */
function enableOnboarding(localStorageKey, user, campaign, slideConfiguration) {
  const jsxElementHook = 'jsx-onboarding';
  const slideComponents = {ContextSlide, InstructionSlide, ReportbackItemsSlide, CampaignSlide};
  const slides = slideConfiguration.map(name => slideComponents[name]);

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
  const client = new ApiClient(setting('dsOnboarding.api.version'), setting('dsOnboarding.api.host'), setting('dsOnboarding.api.port'), false);
  const localStorageKey = getLocalStorageKey(user, campaign);

  if (isOutsideUnitedStates || Modal.isOpen()) {
    return;
  }

  client.get(`config/${campaign.id}`).then(configuration => {
    if (isOnboardingEnabled(localStorageKey, configuration.config)) {
      enableOnboarding(localStorageKey, user, campaign, configuration.slides);
    }
  });
});
