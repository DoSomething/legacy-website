import $ from 'jquery';
import setting from './Setting';

function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function buildSnowflake() {
  var $snowflake = $('<p class="snowflake fadeOutDownBig">&#10052;</p>');
  $snowflake.css("left", getRandomInt(0, $(document).width()));
  $('body').append($snowflake);

  // append paragraph to body with or emoji
  // create the animation for that. can we "fake rotate" it by changing width?
  // also feature flag
}

function init() {
  const enableSnowflakes = setting('dosomethingSetting.enableSnowflakes');
  if (enableSnowflakes === undefined || enableSnowflakes === false) {
    return;
  }

  buildSnowflake();

  setInterval(function() {
    buildSnowflake();
  }, 1000);
}

export default { init };
