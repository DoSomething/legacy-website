<?php
/**
 * Returns the HTML for the Campaign Run page.
 */
?>
<h4>Campaign:
  <p><?php print l($campaign_title, 'node/' . $field_campaigns[0]['target_id']); ?></p>
</h4>

<h4>Run Description:
  <p><?php print render($field_instances['node-campaign_run-description_field']['description']); ?></p>
</h4>

<h4>Campaign Closed State:
  <p><?php print l($campaign_title . ': Closed State', 'node/' . $field_campaigns[0]['target_id'] . '/closed'); ?></p>
</h4>

<?php
  print render($content['field_winners']);
  print render($content['field_gallery_collection']);
  print render($content['field_run_date']);
?>


