<?php

/**
 * Parses user message and sends back a response if match is found. If no match
 * is found, should just remain silent unless $no_match_responses are specified.
 */
class ConductorActivityOutOfFlowResponder extends ConductorActivity {

  /**
   * Nested array of responses and their matching criteria.
   *
   * Definition:
   * @code
   * array(
   *   array(
   *     'phrase_match' => array('phrase 1', 'phrase 2'),
   *     'AND_match'    => array(
   *       array('word1A', 'word1B'),
   *       array('word2A', 'word2B', 'phrase 2 C'),
   *       ...
   *     ),
   *     'word_match'   => array('word1', 'word2', ...),
   *     'word_match_exact' => boolean. If true, will not do a levenshtein distance check.
   *     'response'     => string. Message to send back to user if match is found.
   *     'response_negative' => string. Message to send back to user if match is found and user message is a negative form.
   *                            ex: User responds with, "I do NOT love you"
   *     'trigger_opt_out'   => mixed. Could be either a single number or array of numbers for campaign ids to opt out of.
   *   )
   * )
   * @endcode
   *
   * Sets at the beginning of the array will match against the user response
   * first and take priority over later sets.
   *
   * @var array
   */
  public $response_sets = array();

  /**
   * Response to send to the user if no match is found.
   *
   * @var array
   */
  public $no_match_responses = array();

  /**
   * Responses to send if MMS was received from the user.
   *
   * @var array
   */
  public $mms_match_responses = array();

  /**
   * Maximum allowed string edit distance to trigger a successful match.
   *
   * @var int
   */
  public $match_threshold = 1;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    // Check for MMS before attempting to do any message processing
    if (!empty($_REQUEST['mms_image_url']) && count($this->mms_match_responses) > 0) {
      $response = self::selectResponse($this->mms_match_responses);
      $state->setContext('sms_response', $response);
      $state->markCompleted();
      return;
    }

    $userMessage = $_REQUEST['args'];

    $userMessage = self::sanitizeMessage($userMessage);

    // Break message into array of individual words
    $userWords = explode(' ', $userMessage);

    $bMatchFound = FALSE;
    $bIgnoreNegativeForm = FALSE;
    $isNegativeForm = FALSE;
    $matchingSet = -1;
    $bDoDistanceCheck = FALSE;

    do {
      for ($i = 0; $i < count($this->response_sets) && !$bMatchFound; $i++) {
        $set = $this->response_sets[$i];

        // Search for exactly matched responses
        if (isset($set['exact_match'])) {
          foreach ($set['exact_match'] as $exactMatch) {
            if ((!$bDoDistanceCheck && strcasecmp($userMessage, $exactMatch) == 0)
                || ($bDoDistanceCheck && levenshtein($exactMatch, $userMessage) <= $this->match_threshold)) {
              $bMatchFound = TRUE;

              if (self::hasNegativeFormWord($exactMatch)) {
                $bIgnoreNegativeForm = TRUE;
              }

              break;
            }
          }
        }

        // Search for phrases within the user message
        if (!$bMatchFound && isset($set['phrase_match'])) {
          foreach ($set['phrase_match'] as $matchPhrase) {
            if (self::isRegex($matchPhrase)) {
              // All regular expressions should just be handled by preg_match. Skip the other
              // compares and levenshtein distance checks. No need to check a second time
              // during the distance check round.
              if (!$bDoDistanceCheck && preg_match(strtolower($matchPhrase), strtolower($userMessage)) == 1) {
                $bMatchFound = TRUE;
                break;
              }
            }
            elseif ((!$bDoDistanceCheck && stripos($userMessage, $matchPhrase) !== FALSE)
                || ($bDoDistanceCheck && levenshtein($userMessage, $matchPhrase) <= $this->match_threshold)) {
              $bMatchFound = TRUE;

              if (self::hasNegativeFormWord($matchPhrase)) {
                $bIgnoreNegativeForm = TRUE;
              }

              break;
            }
          }
        }

        // Search for sets of words in the user message to match against
        if (!$bMatchFound && !$bDoDistanceCheck && isset($set['AND_match'])) {
          foreach ($set['AND_match'] as $matchSet) {
            $bSetMatches = TRUE;
            foreach ($matchSet as $matchWord) {
              if (!self::in_arrayi($matchWord, $userWords)) {
                $bSetMatches = FALSE;
                break;
              }
            }

            if ($bSetMatches) {
              $bMatchFound = TRUE;
              break;
            }
          }
        }

        // Search for exactly matched words
        if (!$bMatchFound && isset($set['word_match'])) {
          $word_match_exact = isset($set['word_match_exact']) ? $set['word_match_exact'] : FALSE;
          foreach ($set['word_match'] as $matchWord) {
            foreach ($userWords as $userWord) {
              if (self::isRegex($matchWord)) {
                if (!$bDoDistanceCheck && preg_match(strtolower($matchWord), strtolower($userWord)) == 1) {
                  $bMatchFound = TRUE;
                  break;
                }
              }
              elseif ((!$bDoDistanceCheck && strcasecmp($matchWord, $userWord) == 0)
                  || ($bDoDistanceCheck && !$word_match_exact && levenshtein($matchWord, $userWord) <= $this->match_threshold)) {
                $bMatchFound = TRUE;
                break;
              }
            }

            if ($bMatchFound) {
              break;
            }
          }
        }

        // Check if user response is in negative form
        // ie - "I do love you" vs "I do not love you"
        if ($bMatchFound && !$bIgnoreNegativeForm) {
          if (self::hasNegativeFormWord($userWords)) {
            // Negative form response found. Make sure we have a response for that kind of message.
            if (isset($set['response_negative'])) {
              $isNegativeForm = TRUE;
            }
            else {
              $bMatchFound = FALSE;
            }
          }
        }

        // Match is found. No need to check the rest.
        if ($bMatchFound) {
            $matchingSet = $i;
            break;
        }
      }

      // If we've already done a runthrough with the distance check, then ensure we exit out of the while loop
      if ($bDoDistanceCheck) {
        $bExecutedDistanceCheck = TRUE;
      }
      else {
        $bDoDistanceCheck = TRUE;
      }
    } while (!$bMatchFound && !$bExecutedDistanceCheck);

    // Reply back to the user with the appropriate response if available
    if ($bMatchFound && $matchingSet >= 0) {
      $set = $this->response_sets[$matchingSet];

      if (isset($set['trigger_opt_out']) && $set['trigger_opt_out'] > 0) {
        // @todo Convert to use mobilecommons module
        // sms_mobile_commons_campaign_opt_out($mobile, $set['trigger_opt_out']);
        $response = self::selectResponse($set['response']);
      }
      elseif ($isNegativeForm) {
        $response = self::selectResponse($set['response_negative']);
      }
      else {
        $response = self::selectResponse($set['response']);
      }

      $state->setContext('sms_response', $response);
    }
    elseif (count($this->no_match_responses) > 0) {
      $response = self::selectResponse($this->no_match_responses);
      if (is_numeric($this->no_match_responses[0])) {
        // If it's an array of numbers, then push user to the selected opt-in path id
        // @todo Convert to use mobilecommons module
        // sms_mobile_commons_opt_in($mobile, $response);
        $state->setContext('ignore_no_response_error', TRUE);
      }
      else {
        // Otherwise, expect it's an array of strings, then respond with a selected string
        $state->setContext('sms_response', $response);
      }
    }
    else {
      $state->setContext('ignore_no_response_error', TRUE);
    }

    $state->markCompleted();
  }

  // Case-insensitive version of in_array()
  function in_arrayi($needle, $haystack) {
    return in_array(strtolower($needle), array_map('strtolower', $haystack));
  }

  // Determine if negative-form word exists in $needles
  function hasNegativeFormWord($needles) {
    $negativeFormWords = array('no', 'not');

    // If $needles is a string, convert it into an array of its words
    if (is_string($needles)) {
      $needles = explode(' ', $needles);
    }

    foreach ($negativeFormWords as $matchWord) {
      if (self::in_arrayi($matchWord, $needles)) {
        return TRUE;
      }
    }

    return FALSE;
  }

  /**
   * Determines whether or not this string is actually a regular expression
   */
  function isRegex($str) {
    $strLength = strlen($str);
    if ($strLength > 1 && $str[0] == '/' && $str[$strLength - 1] == '/') {
      return TRUE;
    }

    return FALSE;
  }

  // Function to convert select words from their abbreviated form
  function sanitizeMessage($message) {
    // Single quote to be removed instead of replacing with whitespace to conserve integrity of word
    $message = preg_replace('/\'/', '', $message);
    // Remove all non alphanumeric characters from the user message
    $message = preg_replace('/[^A-Za-z0-9 ]/', ' ', $message);
    // Matches multi-character whitespace with a single space
    $message = preg_replace('/\s+/', ' ', $message);
    $message = check_plain($message);

    $abbreviations = array(
      'u' => 'you',
      'ur' => 'your',
      'urself' => 'yourself',
    );

    $words = explode(' ', $message);

    for ($i = 0; $i < count($words); $i++) {
      if(isset($abbreviations[$words[$i]])) {
        $key = $words[$i];
        $words[$i] = $abbreviations[$key];
      }
    }

    $message = implode(' ', $words);
    return $message;
  }

  // Selects a random response if multiple are given, or if $response is a string, just returns it back
  function selectResponse($response) {
    if (is_array($response)) {
      $selectedIdx = array_rand($response);
      return $response[$selectedIdx];
    }
    else {
      return $response;
    }
  }
}
