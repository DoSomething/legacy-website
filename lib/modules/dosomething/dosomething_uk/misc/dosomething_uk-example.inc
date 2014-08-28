<?php
/**
 * @file
 * OAuth functionality of DoSomething UK.
 */

/**
 * Implements hook_menu().
 */
function dosomething_uk_menu() {
  $items['sso/request'] = array(
    'page callback' => 'dosomething_uk_test_request',
    'access arguments' => array('access content'),
  );
  $items['sso/login'] = array(
    'page callback' => 'dosomething_uk_test_login',
    'access arguments' => array('access content'),
  );
  $items['sso/access'] = array(
    'page callback' => 'dosomething_uk_test_access',
    'access arguments' => array('access content'),
  );
  $items['sso/get'] = array(
    'page callback' => 'dosomething_uk_test_get',
    'access arguments' => array('access content'),
  );
  $items['sso/flow'] = array(
    'page callback' => 'dosomething_uk_test_flow',
    'access arguments' => array('access content'),
  );
  return $items;
}

function dosomething_uk_test_request() {
  $sso = DosomethingUkSsoController::init()
  ->authorizeRequestToken()
  ->authorizeRemoteRedirect();

  $authorize_url = $sso->getAuthorizationUrl(TRUE, TRUE);
  print($authorize_url);
}

function dosomething_uk_test_login() {
  $imitator = DosomethingUkUserImpersonator::init('email@example.com', 'password');

  $result = $imitator->getTokenAuthorization('/oauth/authorize?oauth_token=RequestToken');
  var_dump($imitator, $result);
}

function dosomething_uk_test_access() {
  global $user;

  $sso = DosomethingUkSsoController::init()
  ->authorizeAccessToken()
  ->authorizeUserAccess($user->uid);

  if (!$sso->isAuthrizedForRemoteApi()) {
    print 'Clearance: ' . $sso->getClearance();
    return;
  }

  print 'Success.';
}

function dosomething_uk_test_get() {
  global $user;

  $sso = DosomethingUkSsoController::initForUser($user->uid);

  if (!$sso->isAuthrizedForRemoteApi()) {
    print 'Clearance: ' . $sso->getClearance();
    return;
  }

  var_dump($sso->get('/users/current'));
}


function dosomething_uk_test_flow() {
  $sso = DosomethingUkSsoController::init()->authorizeRemoteRedirect();
  $url = $sso->getAuthorizationUrl(TRUE, TRUE);

  print '<pre>';
  if (!$url) {
    print 'Authorize URL problem';
    return;
  }
  print $url . PHP_EOL;

  $login = 'email@example.com';
  $pass =  'password';
  $result = DosomethingUkUserImpersonator::init($login, $pass)->authorize($url);

  if (!$result) {
    print "Wrong login or pass";
    return;
  }
  print $login . PHP_EOL;

  $remote_user = $sso->authorizeAccessToken()->getRemoteUser();
  if (!$remote_user) {
    print 'Remote user error';
    var_dump($sso);
    return;
  }
  print 'Remote user:' . PHP_EOL;

  var_dump($remote_user);
}

