const $ = require('jquery');

function checkFacebookLoginState() {
  FB.getLoginStatus((response) => {
    console.log(response);
    switch (response.status) {
      case 'connected': console.log('Logged in'); break;
      case 'not_authorized': console.log('App needs authorization'); break;
      default: console.log("not logged into facebook");
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
