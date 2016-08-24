/* global Drupal */

const get = require('lodash/get');

function setting(key, defaultValue) {
  return get(Drupal.settings, key) || defaultValue;
}

export default setting;
