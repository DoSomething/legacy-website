<?php

if (!module_exists('dosomething_user') || !module_exists('dosomething_reportback'))
  return;

$plugin = array(
  'title' => t('DoSomething SMS Submit Report Back'),
  'description' => t('Creates or updates a report back delivered via SMS.'),
  'handler' => array('class' => 'ConductorActivitySmsReportBack'),
);
