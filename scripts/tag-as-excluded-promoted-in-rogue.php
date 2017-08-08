<?php
/**
 * Script to send more review data to Rogue.
 * RBs "excluded" here will be tagged with "Hide In Gallery" in Rogue
 * RBs "promoted" here will be tagged with "Good Photo" in Rogue
 *
 * to run:
 * drush --script-path=../scripts/ php-script tag-as-excluded-promoted-in-rogue.php
 */

// Pick up from where we left off
$last_promoted = variable_get('dosomething_rogue_last_post_promoted', NULL);
$last_excluded = variable_get('dosomething_rogue_last_post_excluded', NULL);

// Get all the promoted posts to send
if (isset($last_promoted)) {
	$promoted_posts_in_rogue = db_query("SELECT r.rogue_post_id, rb.uid, rb.nid
										FROM dosomething_reportback_file f
										JOIN dosomething_rogue_reportbacks r ON f.fid = r.fid
										JOIN dosomething_reportback rb ON f.rbid = rb.rbid
										WHERE f.status = 'promoted'
										AND r.rogue_post_id > $last_promoted
										ORDER BY r.rogue_post_id");
}
else {
	$promoted_posts_in_rogue = db_query("SELECT r.rogue_post_id, rb.uid, rb.nid
										FROM dosomething_reportback_file f
										JOIN dosomething_rogue_reportbacks r ON f.fid = r.fid
										JOIN dosomething_reportback rb ON f.rbid = rb.rbid
										WHERE f.status = 'promoted'
										ORDER BY r.rogue_post_id");
}

// Get all the excluded posts to send
if (isset($last_excluded)) {
	$excluded_posts_in_rogue = db_query("SELECT r.rogue_post_id, rb.uid, rb.nid
										FROM dosomething_reportback_file f
										JOIN dosomething_rogue_reportbacks r ON f.fid = r.fid
										JOIN dosomething_reportback rb ON f.rbid = rb.rbid
										WHERE f.status = 'excluded'
										AND r.rogue_post_id > $last_excluded
										ORDER BY r.rogue_post_id");
}
else {
	$excluded_posts_in_rogue = db_query("SELECT r.rogue_post_id, rb.uid, rb.nid
										FROM dosomething_reportback_file f
										JOIN dosomething_rogue_reportbacks r ON f.fid = r.fid
										JOIN dosomething_reportback rb ON f.rbid = rb.rbid
										WHERE f.status = 'excluded'
										ORDER BY r.rogue_post_id");
}

$client = dosomething_rogue_client();

// Tag promoted posts
foreach ($promoted_posts_in_rogue as $promoted) {
	echo 'Checking out Rogue post ' . $promoted->rogue_post_id . PHP_EOL;
    // @TODO: bust this out into a helper
    if (isset($last_promoted)) {
	    $northstar_id = dosomething_user_get_northstar_id($promoted->uid);
	    $params['filter'] = [
			'campaign_id' => $promoted->nid,
			'northstar_id' => $northstar_id,
	    ];

	    // Grab all posts for the given user for the given campaign from Rogue so we can check for existing tags
	    $posts = $client->getPosts($params);


	    // Grab the particular post we are looking for from the response
	    $rogue_post = null;
	    foreach ($posts['data'] as $post) {
			if ($post['id'] == $promoted->rogue_post_id) {
				$rogue_post = $post;
			}
	    }

	    // If we cannot find the post in Rogue, skip it
	    if (!$rogue_post) {
			echo 'Could not find post ' . $promoted->rogue_post_id . ' in Rogue' . PHP_EOL;
			continue;
	    }

	    // If the post is already tagged good-photo in Rogue, skip it
	    if (in_array('good-photo', $rogue_post['tagged'])) {
			echo 'Post ' . $promoted->rogue_post_id . ' already tagged good-photo in Rogue' . PHP_EOL;

			// We can say that this post is done because it is already marked
			variable_set('dosomething_rogue_last_post_promoted', $promoted->rogue_post_id);

			continue;
	    }
    }

	// Format request to tag post
    $data = [
      'post_id' => $promoted->rogue_post_id,
      'tag_name' => 'Good Photo',
    ];

    // Post tag to Rogue
    try {
		echo 'Trying to add tag Good Photo to post id ' . $promoted->rogue_post_id . '...' . PHP_EOL;
		$response = $client->postTag($data);

		if ($response) {
			echo 'Tagged Rogue post ' . $promoted->rogue_post_id . ' as Good Photo' . PHP_EOL;

			variable_set('dosomething_rogue_last_post_promoted', $promoted->rogue_post_id);
		}
		else {
			// Handle failure
			echo '***FAILED TO TAG ROGUE POST '. $promoted->rogue_post_id . ' as Good Photo***' . PHP_EOL;
		}
    }
    catch (GuzzleHttp\Exception\ServerException $e) {
		// These aren't yet caught by Gateway
		echo '***SERVER EXCEPTION ON ROGUE POST '. $promoted->rogue_post_id . ' as Good Photo***' . PHP_EOL;
    }
    catch (DoSomething\Gateway\Exceptions\ApiException $e) {
		echo '***API EXCEPTION ON ROGUE POST '. $promoted->rogue_post_id . ' as Good Photo***' . PHP_EOL;
    }
}

// Tag excluded posts
foreach ($excluded_posts_in_rogue as $excluded) {
	echo 'Checking out Rogue post ' . $excluded->rogue_post_id . PHP_EOL;
    // @TODO: bust this out into a helper
    if (isset($last_excluded)) {
	    $northstar_id = dosomething_user_get_northstar_id($excluded->uid);
	    $params['filter'] = [
			'campaign_id' => $excluded->nid,
			'northstar_id' => $northstar_id,
	    ];

	    // Grab all posts for the given user for the given campaign from Rogue so we can check for existing tags
	    $posts = $client->getPosts($params);


	    // Grab the particular post we are looking for from the response
	    $rogue_post = null;
	    foreach ($posts['data'] as $post) {
			if ($post['id'] == $excluded->rogue_post_id) {
				$rogue_post = $post;
			}
	    }

	    // If we cannot find the post in Rogue, skip it
	    if (!$rogue_post) {
			echo 'Could not find post ' . $excluded->rogue_post_id . ' in Rogue' . PHP_EOL;
			continue;
	    }

	    // If the post is already tagged hide-in-gallery in Rogue, skip it
	    if (in_array('hide-in-gallery', $rogue_post['tagged'])) {
			echo 'Post ' . $excluded->rogue_post_id . ' already tagged hide-in-gallery in Rogue' . PHP_EOL;

			// We can say that this post is done because it is already marked
			variable_set('dosomething_rogue_last_post_excluded', $excluded->rogue_post_id);

			continue;
	    }
    }

	// Format request to tag post
    $data = [
      'post_id' => $excluded->rogue_post_id,
      'tag_name' => 'Hide In Gallery',
    ];

    // Post tag to Rogue
    try {
		echo 'Trying to add tag Hide In Gallery to post id ' . $excluded->rogue_post_id . '...' . PHP_EOL;
		$response = $client->postTag($data);

		if ($response) {
			echo 'Tagged Rogue post ' . $excluded->rogue_post_id . ' as Hide In Gallery' . PHP_EOL;

			variable_set('dosomething_rogue_last_post_excluded', $excluded->rogue_post_id);
		}
		else {
			// Handle failure
			echo '***FAILED TO TAG ROGUE POST '. $excluded->rogue_post_id . ' as Hide In Gallery***' . PHP_EOL;
		}
    }
    catch (GuzzleHttp\Exception\ServerException $e) {
		// These aren't yet caught by Gateway
		echo '***SERVER EXCEPTION ON ROGUE POST '. $excluded->rogue_post_id . ' as Hide In Gallery***' . PHP_EOL;
    }
    catch (DoSomething\Gateway\Exceptions\ApiException $e) {
		echo '***API EXCEPTION ON ROGUE POST '. $excluded->rogue_post_id . ' as Hide In Gallery***' . PHP_EOL;
    }
}

echo 'Nothing else to tag!' . PHP_EOL;
