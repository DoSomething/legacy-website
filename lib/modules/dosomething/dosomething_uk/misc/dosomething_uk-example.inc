<?php
/**
 * @file
 * OAuth functionality of DoSomething UK.
 */

/**
 * Implements hook_menu().
 */
function dosomething_uk_menu() {
  $items['sso/register'] = array(
    'page callback' => 'dosomething_uk_test_register',
    'access arguments' => array('access content'),
  );
  $items['sso/request'] = array(
    'page callback' => 'dosomething_uk_test_request',
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

function dosomething_uk_test_register() {
  $random_url = 'http://api.randomuser.me/';
  $randomuser = json_decode(file_get_contents($random_url))->results[0]->user;

  $user_data = array(
    'first_name' => ucfirst($randomuser->name->first),
    'last_name'  => ucfirst($randomuser->name->last),
    'password'   => $randomuser->password . $randomuser->password,
    'email'      => $randomuser->email,
    'postcode'   => 'CF10 5AN',
    'dob'        => new DateTime('1990-05-28T0000Z'),
  );
  $sso_user = DosomethingUkSsoUser::fromArray($user_data);

  // Register remotely.
  $sso = DosomethingUkSsoController::signup($sso_user);
  $result = $sso->getLastResult();

  if (!$result) {
    if ($error_messages = $sso->getErrorMessages()) {
      var_dump($error_messages);
    }
    return;
  }

  var_dump($result);
  return;
}

function dosomething_uk_test_request() {
  $sso = DosomethingUkSsoController::init()
  ->authorizeRequestToken()
  ->authorizeRemoteRedirect();

  $authorize_url = $sso->getAuthorizationUrl(TRUE, TRUE);
  print($authorize_url);
}

function dosomething_uk_test_access() {
  global $user;

  $sso = DosomethingUkSsoController::init()
  ->authorizeAccessToken()
  ->authorizeUserAccess($user->uid);

  if (!$sso->remoteUserAdmitted()) {
    print 'Clearance: ' . $sso->getClearance();
    return;
  }

  print 'Success.';
}

function dosomething_uk_test_get() {
  global $user;

  $sso = DosomethingUkSsoController::initForLocalUser($user->uid);

  if (!$sso->remoteUserAdmitted()) {
    print 'Clearance: ' . $sso->getClearance();
    return;
  }

  var_dump($sso->getRemote('/users/current'));
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

  // A testee user created on staging for test purposes.
  $name = 'evelyn.wilson19@example.com';
  $pass = 'steelersteeler';

  $impersonator = DosomethingUkSsoImpersonator::login($name, $pass);
  $result = $impersonator->acceptRemoteOAuth($url);

  if (!$result) {
    print "Wrong login or pass";
    return;
  }
  print $result . PHP_EOL;

  $remote_user = $sso->authorizeAccessToken()->getRemoteUser();
  if (!$remote_user) {
    print 'Remote user error';
    var_dump($sso);
    return;
  }
  print 'Remote user:' . PHP_EOL;

  var_dump($remote_user);
}

