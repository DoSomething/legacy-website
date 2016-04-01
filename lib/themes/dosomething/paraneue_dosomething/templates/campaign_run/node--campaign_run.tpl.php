<?php 
/**
 * Returns the HTML for the Campaign Run page.
 */
?>

<h4>Campaign: 
  <p><?php print l($campaign_title, 'node/' . $campaign_nid); ?></p>
</h4>

<h4>Winners:</h4>
  <p><?php print l('Add', '/field-collection/field-winners/add/node/' . $nid . '/?destination=node/' . $nid); ?></p>

<h4>Klout Gallery:</h4>
  <p><?php print l('Add', '/field-collection/field-gallery-collection/add/node/' . $nid . '/?destination=node/' . $nid); ?></p>

<h4>Run Date: 
  <p><?php print t($run_date); ?></p>
</h4




