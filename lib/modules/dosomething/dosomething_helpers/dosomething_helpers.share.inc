<?php
/**
 * @file
 * dosomething_helpers.share.inc
 */

/**
 * Returns an empty page with javascript that closes the current window.
 * Used as the redirect page for facebook shares that require a redirect uri.
 * Allows us to close the share popup window when the user has finished sharing.
 */
function dosomething_helpers_share_redirect() {
  return "<script>(function(){ window.close(); })();</script>";
}

/**
 * Returns a facebook share url.
 *
 * @param  string $link The url to share.
 * @param  string $type
 *  The type of facebook share intent link to use.
 *    - 'feed_dialog': Allows for customized stories, outside of what is set in the metatags.
 * @param Array $custom_options
 *    An array of customized options for the type of share being used.
 *
 * @return string   The facebook intent url.
 */
function dosomething_helpers_facebook_intent($link, $type = NULL, $custom_options = NULL) {
  switch ($type) {
    // Used to create a facebook share link that uses a custom image,
    // different from what is set in the metatags.
    case 'feed_dialog':
      // Build the redirect url.
      $base_path = url(base_path(), array('absolute' => TRUE));
      $redirect_path = url(base_path(), array('absolute' => TRUE)) . 'ds-share-complete';

      // Pass in all the feed dialog parameters
      $facebook_app_id = variable_get('dosomething_settings_facebook_app_id');
      $standard_options = array(
          'app_id' => $facebook_app_id,
          'display' => 'popup',
          'link'   => $link,
          'redirect_uri' => $redirect_path,
        );

      if ($custom_options) {
        $standard_options = array_merge($standard_options, $custom_options);
      }

      $fb_share_url = url('https://www.facebook.com/dialog/feed', array('query' => $standard_options));
      break;
    // Standard facebook share, just sharing a link and all other data is scraped from the page.
    default:
      $fb_share_url = "https://www.facebook.com/sharer/sharer.php?u=" . urlencode($link);
  }

  return $fb_share_url;
}

/**
 * Returns a twitter share url.
 *
 * @param  string $tweet The text that should prepopulate the tweet (can include the url of the page to share).
 * @return string        The twitter intent url.
 */
function dosomething_helpers_twitter_intent($tweet) {
  return "https://twitter.com/intent/tweet?text=" . urlencode($tweet);
}

/**
 * Returns a tumblr share url.
 *
 * @param  array $options An array including:
 *                            - source: url of the image to share.
 *                            - caption: share language.
 *                            - clickthru: url to share
 * @return string        The tumblr intent url to share a photo.
 */
function dosomething_helpers_tumblr_intent($options) {
  return url('https://www.tumblr.com/widgets/share/tool', array('query' => $options));
}