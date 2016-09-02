const $ = require('jquery');

function loginToPhoenix(profileData) {
  console.log(profileData);
}

function getFacebookProfile(callback) {
  // Birthday doesn't actually return anything cause we don't have reviewed status yet
  FB.api('/me', {fields: 'last_name,name,email,birthday'}, function(profile) {
    callback(profile);
  });
}

function checkFacebookLoginState() {
  FB.getLoginStatus((response) => {
    if (response.status === 'connected') {
      const authData = response.authResponse;
      const userData = getFacebookProfile(function(profile) {
        profile.authData = authData;
        loginToPhoenix(profile);
      });
    }
  });
}
// Attaching this to window so the Facebook element can call it without scope issues.
window.checkFacebookLoginState = checkFacebookLoginState;

$(document).ready(function() {
  window.fbAsyncInit = function() {
    FB.init({
      appId      : '105775762330',
      xfbml      : true,
      version    : 'v2.7'
    });
  };

  const $facebookLoginButton = $('<fb:login-button scope="public_profile,email" onlogin="window.checkFacebookLoginState();"></fb:login-button>');
  $facebookLoginButton.insertBefore('#edit-create-account-link');
});
