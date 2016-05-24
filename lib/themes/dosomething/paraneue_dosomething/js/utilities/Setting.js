import objectGet from 'lodash/object/get';

function setting(key, defaultValue) {
  return objectGet(Drupal.settings, key) || defaultValue;
}

export default setting;
