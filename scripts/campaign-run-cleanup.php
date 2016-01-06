<?php
/*
 * Script to create campaign runs for all open campaigns.
 */

// get all campaigns with status active
$active_campaigns = db_query('SELECT nid FROM node WHERE campaign status == active');
// create a new node with title of campaign + current year?
