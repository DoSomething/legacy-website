<?php 
/**
 * Returns the HTML for the Campaign Run page.
 */
?>
<h4>Campaign: 
  <p><?php print l($campaign_title, 'node/' . $field_campaigns[0]['target_id']); ?></p>
</h4>

<?php 
  print render($content['field_winners']);
  print render($content['field_gallery_collection']);
  print render($content['field_run_date']);
?>


