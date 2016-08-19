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
 * @param  string $link
 *   The url to share.
 * @param  string $type
 *   The type of facebook share intent link to use.
 *   - 'feed_dialog': Allows for customized stories, outside of what is set in the metatags.
 * @param Array $custom_options
 *   An array of customized options for the type of share being used.
 *
 * @return string   The facebook intent url.
 */
function dosomething_helpers_get_facebook_intent($link, $type = NULL, $custom_options = NULL) {
  switch ($type) {
    // Used to create a facebook share link that uses a custom image,
    // different from what is set in the metatags.
    case 'feed_dialog':
      // Build the redirect url.
      $base_path = url(base_path(), ['absolute' => TRUE, 'language' => dosomething_global_get_language_by_language_code('en-global')]);
      $redirect_path = url(base_path(), ['absolute' => TRUE, 'language' => dosomething_global_get_language_by_language_code('en-global')]) . 'ds-share-complete';

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
 * @param  string $tweet
 *   The text that should prepopulate the tweet (can include the url of the page to share).
 * @return string
 *   The twitter intent url.
 */
function dosomething_helpers_get_twitter_intent($tweet) {
  return "https://twitter.com/intent/tweet?text=" . urlencode($tweet);
}

/**
 * Returns a tumblr share url.
 *
 * @param string $path - the canonical URL being shared (required)
 * @param  array $options
 *   - source: url of the image to share.
 *   - caption: share language.
 *   - clickthru: url to share
 * @return string
 *   The tumblr intent url to share a photo.
 */
function dosomething_helpers_get_tumblr_intent($path, $options) {
  $options['canonicalUrl'] = $path;
  return url('https://www.tumblr.com/widgets/share/tool', array('query' => $options));
}

/**
 * Returns an array of paths to share on each social network with the
 * correct utm parameters attached.
 *
 * @param  array $share_types
 *   - array of social networks to create paths for.
 *     i.e ['facebook', 'twitter', 'tumblr']
 * @param string $path
 *   The absolute path of the page being shared.
 * @param string $utm_campaign
 *   A custom value to use for 'utm_campaign'.
 * @param string $custom_share_source
 *   A custom value to use for 'source'.
 * @return
 *   An array of paths, indexed by type.
 */
function dosomething_helpers_utm_share_paths($share_types, $path, $utm_campaign, $custom_share_source = NULL) {
  foreach ($share_types as $type => $options) {
    $utm_params = dosomething_helpers_utm_parameters(NULL,
      array(
        'utm_medium' => $type,
        'utm_campaign' => $utm_campaign,
      )
    );
    $share_paths[$type] = $path . $utm_params;

    // Append the custom share source to the URL if we have one
    if ($custom_share_source) {
      $share_paths[$type] .= '&source=' . $custom_share_source;
    }
  }

  return $share_paths;
}

/**
 * Return the markup for share button.
 *
 * @param string $path
 *   The absolute path of the page being shared.
 * @param  array $share_types
 *   - array of social networks to create paths for.
 *     including the relevant parameters needed to create the custom intents.
 * @param string $share_description
 *   A custom value to use for 'utm_campaign'.
 * @param string $custom_share_source
 *   If included, the custom share source to be included in the url
 * @return string
 *   Share bar markup.
 */
function dosomething_helpers_share_bar($path, $share_types, $share_description, $classes = NULL, $custom_share_source = NULL) {
  $share_utm_paths = dosomething_helpers_utm_share_paths($share_types, $path, $share_description, $custom_share_source);

  $share_bar = '<ul class="' . $classes . '">';
  $share_intents = [];

  foreach ($share_types as $type => $options) {
    switch ($type) {
      case 'facebook':
        $share_intents['facebook'] = dosomething_helpers_get_facebook_intent($share_utm_paths['facebook'], $options['type'], $options['parameters']);
        break;
      case 'twitter':
        $share_intents['twitter'] = dosomething_helpers_get_twitter_intent($options['tweet'] . ' ' . $share_utm_paths['twitter']);
        break;
      case 'tumblr':
        $options['caption'] = $options['caption'] . $share_utm_paths['tumblr'];
        $share_intents['tumblr'] = dosomething_helpers_get_tumblr_intent($share_utm_paths['tumblr'], $options);
      default:
        break;
    }

    if ($share_intents[$type]) {
      $share_bar .= '<li><a class="social-icon -' . $type . ' js-share-link ga-click" href="' . $share_intents[$type] . '" data-ga-category="Share" data-ga-label="' . $type .'" data-ga-action="' . $share_description .'"><span>'. $type . '</span></a></li>';
    }
  }

  return $share_bar . "</ul>";
}
