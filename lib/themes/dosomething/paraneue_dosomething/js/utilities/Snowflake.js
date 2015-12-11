import $ from 'jquery';

function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function buildSnowflake() {
  var snowflake = {
    x: getRandomInt(0, $(document).width()),
    y: 0,
    radius: getRandomInt(3, 10),
  };
  return snowflake;
}

function init() {
  var snowflakes = [];
  var canvas = $('#snowflake')[0];
  var ctx = canvas.getContext('2d');

  canvas.width = $(document).width();
  canvas.height = $(document).height();
  ctx.fillStyle = '#FFF';

  setInterval(function() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    snowflakes.forEach(function(element, index) {
      element.y += 1;

      if (element.y > canvas.height) {
        snowflakes.splice(index, 1);
      }

      ctx.beginPath();
      ctx.arc(element.x, element.y, element.radius, 0, 2 * Math.PI);
      ctx.fill();
    });

    if (getRandomInt(0, 100) === 1) {
      snowflakes.push(buildSnowflake());
    }
  }, 20);
}

export default { init };
