import dotty from 'dotty';

function setting(key, defaultValue) {
  return dotty.get(Drupal.settings, key) || defaultValue;
}

export default setting;
