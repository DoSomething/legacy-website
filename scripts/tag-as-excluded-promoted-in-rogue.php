<?php
/**
 * Script to send more review data to Rogue.
 * RBs "excluded" here will be tagged with "Hide In Gallery" in Rogue
 * RBs "promoted" here will be tagged with "Good Photo" in Rogue
 *
 * to run:
 * drush --script-path=../scripts/ php-script export-activity-to-rogue.php
 */

// Pick up from where we left off
$last_promoted = variable_get('dosomething_rogue_last_post_promoted', NULL);
$last_excluded = variable_get('dosomething_rogue_last_post_excluded', NULL);

// Get all the promoted posts to send
if ($last_promoted) {
	$promoted_posts_in_rogue = db_query("SELECT r.rogue_post_id, rb.uid, rb.nid
										FROM dosomething_reportback_file f
										JOIN dosomething_rogue_reportbacks r ON f.fid = r.fid
										JOIN dosomething_reportback rb ON f.rbid = rb.rbid
										WHERE status = \"promoted\"
										AND r.rogue_post_id > $last_promoted
										ORDER BY r.rogue_post_id");
}
else {
	$promoted_posts_in_rogue = db_query("SELECT r.rogue_post_id, rb.uid, rb.nid
										FROM dosomething_reportback_file f
										JOIN dosomething_rogue_reportbacks r ON f.fid = r.fid
										JOIN dosomething_reportback rb ON f.rbid = rb.rbid
										WHERE status = \"promoted\"
										ORDER BY r.rogue_post_id");
}

// Get all the excluded posts to send
if ($last_excluded) {
	$excluded_posts_in_rogue = db_query("SELECT r.rogue_post_id, rb.uid, rb.nid
										FROM dosomething_reportback_file f
										JOIN dosomething_rogue_reportbacks r ON f.fid = r.fid
										JOIN dosomething_reportback rb ON f.rbid = rb.rbid
										WHERE status = \"excluded\"
										AND r.rogue_post_id > $last_excluded
										ORDER BY r.rogue_post_id");
}
else {
	$excluded_posts_in_rogue = db_query("SELECT r.rogue_post_id, rb.uid, rb.nid
										FROM dosomething_reportback_file f
										JOIN dosomething_rogue_reportbacks r ON f.fid = r.fid
										JOIN dosomething_reportback rb ON f.rbid = rb.rbid
										WHERE status = \"excluded\"
										ORDER BY r.rogue_post_id");
}

$client = dosomething_rogue_client();

foreach ($promoted_posts_in_rogue as $promoted) {
    // @TODO: bust this out into a helper
    // @TODO: see if the post is tagged in Rogue
    if ($last_promoted) {
	    $northstar_id = dosomething_user_get_northstar_id($promoted->uid);
	    $filter = [
			'campaign_id' => $promoted->nid,
			'northstar_id' => $northstar_id,
	    ];
	    $params['filter'] = $filter;

	    // @TODO: write getPosts
	    // @TODO: bust posting tag out into a helper that takes post id and tag
	    $posts = $client->getPosts($params);

	    // @TODO: if the tag already exists, continue
    }

	// Format request
    $data = [
      'post_id' => $promoted->rogue_post_id,
      'tag_name' => 'Good Photo',
    ];

    // Post tag to Rogue
    // @TODO: write postTag
    try {
		$response = $client->postTag($data);

		// handle failure
		// @TODO: how to make sure we tag everything and only send the request once? resending again on a post will cause it to be untagged - only send it if not tagged in Rogue? would need to get the post from Rogue
		if ($response) {
			echo 'Tagged Rogue post ' . $promoted->rogue_post_id . ' as Good Photo';

			variable_set('dosomething_rogue_last_post_promoted', $promoted->rogue_post_id);
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
		echo '***API EXCEPTION ON ROGUE POST '. $promoted->rogue_post_id . ' as Good Photo***';
    }

}

// repeat for excluded
