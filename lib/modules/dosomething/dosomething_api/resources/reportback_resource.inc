<?php

function _reportback_resource_definition() {
  $reportback_resource = array();
  $reportback_resource['reportbacks'] = array(
    'operations' => array(
      'index' => array(
        'help' => 'List all Reportbacks.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/reportback_resource'
        ),
        'callback' => '_reportback_resource_index',
        'access callback' => '_reportback_resource_access',
      ),
      'retrieve' => array(
        'help' => 'Retrieve a Reportback, yo!',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/reportback_resource'
        ),
        'callback' => '_reportback_resource_retrieve',
      ),
    ),
  );

  return $reportback_resource;
}


function _reportback_resource_index() {
  $reportbacks = new Reportback;

  return $reportbacks->index();
}

function _reportback_resource_retrieve($rbid) {
  $reportbacks = new Reportback;

  return $reportbacks->show($rbid);
}

function _reportback_resource_access() {
  return TRUE;
}
