<?php
/**
 * Script to send more review data to Rogue.
 * RBs "excluded" here will be tagged with "Hide In Gallery" in Rogue
 * RBs "promoted" here will be tagged with "Good Photo" in Rogue
 *
 * to run:
 * drush --script-path=../scripts/ php-script export-activity-to-rogue.php
 */

$promoted_posts_in_rogue = db_query("SELECT r.rogue_post_id, rb.uid, rb.nid
									FROM dosomething_reportback_file f
									JOIN dosomething_rogue_reportbacks r ON f.fid = r.fid
									JOIN dosomething_reportback rb ON f.rbid = rb.rbid
									WHERE status = \"promoted\"");

$client = dosomething_rogue_client();

foreach ($promoted_posts_in_rogue as $promoted) {
	// Format request
    $data = [
      'post_id' => $promoted->rogue_post_id,
      'tag_name' => 'Good Photo',
    ];

    // @TODO: see if the post is tagged in Rogue
    // need: northstar_id
    // only need to do this if picking up from a given input, not on the first pass
    $northstar_id = dosomething_user_get_northstar_id($promoted->uid);
    $filter = [
		'campaign_id' => $promoted->nid,
		'northstar_id' => $northstar_id,
    ];
    $params['filter'] = $filter;
    // @TODO: write getPosts
    $posts = $client->getPosts($params);


    // Post tag to Rogue
    // @TODO: write postTag
    try {
		$response = $client->postTag($data);

		// handle failure
		// @TODO: how to make sure we tag everything and only send the request once? resending again on a post will cause it to be untagged - only send it if not tagged in Rogue? would need to get the post from Rogue
		if ($response) {
			echo 'Tagged Rogue post ' . $promoted->rogue_post_id . ' as Good Photo';
		}
		else {
			echo '***FAILED TO TAG ROGUE POST '. $promoted->rogue_post_id . ' as Good Photo***';
		}
    }
    catch (GuzzleHttp\Exception\ServerException $e) {
		// These aren't yet caught by Gateway
		echo '***SERVER EXCEPTION ON ROGUE POST '. $promoted->rogue_post_id . ' as Good Photo***';
    }
    catch (DoSomething\Gateway\Exceptions\ApiException $e) {
      // Put request in failed table for future investigation
      dosomething_rogue_handle_migration_failure($data, $signup->sid, $signup->rbid, $fids);

      // Set where we left off so we don't keep trying this one forever
      variable_set('dosomething_rogue_last_signup_migrated', $signup->sid);
    }

}

// repeat for excluded