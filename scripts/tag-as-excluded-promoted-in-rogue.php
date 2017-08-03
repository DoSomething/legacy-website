<?php
/**
 * Script to send more review data to Rogue.
 * RBs "excluded" here will be tagged with "Hide In Gallery" in Rogue
 * RBs "promoted" here will be tagged with "Good Photo" in Rogue
 *
 * to run:
 * drush --script-path=../scripts/ php-script export-activity-to-rogue.php
 */

$promoted_posts_in_rogue = db_query("SELECT r.rogue_post_id
									FROM dosomething_reportback_file f
									JOIN dosomething_rogue_reportbacks r ON f.fid = r.fid
									WHERE status = \"promoted\"");

foreach ($promoted_posts_in_rogue as $promoted) {
	// send to tags endpoint
	// handle failure
}

// repeat for excluded