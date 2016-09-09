import ApiClient from './utilities/ApiClient';

const $ = require('jquery');
const apiClient = new ApiClient('v1');

function addHiddenLoginInput(key, value) {
  $('<input>').attr('type', 'hidden').attr('name', key).attr('value', value).appendTo('#facebook_login');
}

function getFacebookProfile(callback) {
  // Birthday doesn't actually return anything cause we don't have reviewed status yet. Just an example of what we *could* do.
  FB.api('/me', {fields: 'last_name,name,email,birthday'}, function(profile) {
    // Rename properties to match our spec.
    if (profile.name) {
      profile.first_name = profile.name;
      delete profile.name;
    }

    if (profile.id) {
      profile.facebook_id = profile.id;
      delete profile.id;
    }

    callback(profile);
  });
}

function checkFacebookLoginState() {
  FB.getLoginStatus((response) => {
    if (response.status === 'connected') {
      const userData = getFacebookProfile(function(profile) {
        profile.access_token = response.authResponse.accessToken;
        Object.keys(profile).forEach(key => {
          addHiddenLoginInput(key, profile[key]);
        });
        $('#facebook_login').trigger('submit');
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

  const $facebookLoginButton = $(`<form id="facebook_login" action=${apiClient.domain + '/user/social/facebook'} method="post"><fb:login-button scope="public_profile,email" onlogin="window.checkFacebookLoginState();"></fb:login-button></form>`);
  $('#modal--login').append($facebookLoginButton);
});
