const $ = require('jquery');

$(document).ready(function() {
  const $facebookLoginButton = $('<fb:login-button scope="public_profile,email" onlogin="checkLoginState();"></fb:login-button>');
  $facebookLoginButton.insertBefore('#edit-create-account-link');
});
