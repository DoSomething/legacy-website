
var moment = require(ROOT + '/node_modules/moment/moment');

var user = {};

// Returns generated random user.
casper.getRandomUser = function() {
  return user;
}

// Generate user asynchronously.
casper.generateRandomUser = function() {
  var page = require('webpage').create();
  page.open('http://api.randomuser.me', function () {
    var randomUser = JSON.parse(page.plainText)['results'][0]['user'];

    user.first_name = ucfirst(randomUser['name']['first']);
    user.last_name  = ucfirst(randomUser['name']['last']);
    user.username   = randomUser['username'];
    user.email      = randomUser['email'];
    user.password   = randomUser['username'];
    user.dob        = moment.unix(randomUser['dob']);
  });
}
// Generate initial user on start.
casper.generateRandomUser();

// Utilities.
function ucfirst(string) {
  return string.charAt(0).toUpperCase() + string.slice(1);
}
