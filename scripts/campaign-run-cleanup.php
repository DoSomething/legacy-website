<?php
/*
 * Script to create campaign runs for all open campaigns.
 */

// get all campaigns with status active
$active_campaigns = db_query('SELECT n.nid, n.title, n.created
FROM node n
INNER JOIN field_data_field_campaign_status s on s.entity_id = n.nid
WHERE field_campaign_status_value = 'active';');



// foreach actvie campaign
// create a new node with title of campaign + current year?
// n = new node()
// n.title = 'whatever fantini wants'
// n.campaign = active.nid
// n.start_date active.created
// n.save()
