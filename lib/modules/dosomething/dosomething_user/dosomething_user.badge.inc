<?php
/**
 * @file
 * Code for the DoSomething User badges.
 */

function dosomething_users_map_badge($key, $badges, $type) {
  if (array_key_exists($key, $badges[$type])) {
    return $badges[$type][$key];
  }
}


function dosomething_users_get_signup_badge_images($numbah) {
  // master list of all badges and what they mean.
  $badges['signups'][1] = '&#128150';
  $badges['signups'][3] = '&#128150&#128150&#128150';
  $badges['signups'][5] = '&#128150&#128150&#128150&#128150&#128150';
  $badges['signups'][10] = '&#128150&#128150&#128150&#128150&#128150&#128150&#128150&#128150&#128150&#128150';

  return dosomething_users_map_badge($numbah, $badges, 'signups');
}


function dosomething_users_get_reportback_badge_images($numbah) {
  $badges['reportbacks'][1] = '&#128247';
  $badges['reportbacks'][3] = '&#128247&#128247&#128247';
  $badges['reportbacks'][5] = '&#128247&#128247&#128247&#128247&#128247';
  $badges['reportbacks'][10] = '&#128247&#128247&#128247&#128247&#128247&#128247&#128247&#128247&#128247&#128247';
  $badges['reportbacks'][15] = '&#128247&#128247&#128247&#128247&#128247&#128247&#128247&#128247&#128247&#128247&#128247&#128247&#128247&#128247&#128247';

  return dosomething_users_map_badge($numbah, $badges, 'reportbacks');

}



/**
 * Gets all badges for a user.
 * @param  [int] $uid
 * @return [array]
 */
function dosomething_user_get_badges($uid) {
  // we can mod this by 5 to give badges for each 5 or something.
  $badges['signups']['count']  = dosomething_user_get_activity_count($uid, 'signup');
  $badges['reportbacks']['count'] = dosomething_user_get_activity_count($uid, 'reportback');
  $badges['kudos'] = dosomething_user_get_kudos_count($uid);


  $badges['signups']['image'] = array_map('dosomething_users_get_signup_badge_images', range(0, $badges['signups']['count']));
  $badges['reportbacks']['image'] = array_map('dosomething_users_get_reportback_badge_images', range(0, $badges['reportbacks']['count']));


  // Only if you hit like 5.
  $badges['shutterbug'] = dosomething_user_get_max_reportback_file_updates($uid);

  // Loop through each cause space, get by name, and then once you hit 5 show this.
  $causes = taxonomy_get_tree(2);
  foreach ($causes as $cause) {
    $badges['causes'][strtolower($cause->name)] = dosomething_user_get_cause_space_badge($uid, $cause->tid);
  }

  // Loop through action types.
  $actions = taxonomy_get_tree(1);
  foreach ($actions as $action) {
    $badges['actions'][strtolower($action->name)] = dosomething_user_get_action_space_badge($uid, $action->tid);
  }

  // Get special type badges.
  $special_badge_campaigns = [362];
  foreach ($special_badge_campaigns as $special_campaign) {
    $badges['special'][$special_campaign] = dosomething_user_get_superfan($uid, $special_campaign);
  }

  return $badges;
}

/**
 * Get total signups or reportbacks for a user.
 * @param  $uid
 * @param  $type [signup/reportback]
 * @return int
 */
function dosomething_user_get_activity_count($uid, $type) {
  $table = 'dosomething_' . $type;
  $results = db_query("SELECT *
                      FROM $table
                      WHERE uid = $uid")->rowCount();

  return $results;
}
/**
 * Get the maximum number for how many times one person has updated a reportback.
 * @param  $uid
 * @return int
 */
function dosomething_user_get_max_reportback_file_updates($uid) {
    $results = db_query("SELECT count(fid) as total
                        FROM dosomething_reportback_file rbf
                        INNER JOIN dosomething_reportback rb on rbf.rbid = rb.rbid
                        WHERE rb.uid = $uid
                        GROUP BY rbf.rbid
                        ORDER BY total desc
                        LIMIT 1")->fetchField();

    return $results;
}
/**
 * Get the number of reportbacks for a person in each primary cause space.
 * @param  $uid
 * @param  $cause_tid
 * @return int
 */
function dosomething_user_get_cause_space_badge($uid, $cause_tid) {
  $results = db_query("SELECT rb.rbid
                      FROM dosomething_reportback rb
                      INNER JOIN field_data_field_primary_cause c on rb.nid = c.entity_id
                      INNER JOIN taxonomy_term_data t on t.tid = c.field_primary_cause_tid
                      WHERE rb.uid = $uid
                      AND t.tid = $cause_tid")->rowCount();

  return $results;
}
/**
 * Get number of reportbacks for a person in each primary action type.
 * @param  $uid
 * @param  $action_tid
 * @return int
 */
function dosomething_user_get_action_space_badge($uid, $action_tid) {
  $results = db_query("SELECT rb.rbid
                      FROM dosomething_reportback rb
                      INNER JOIN field_data_field_primary_action_type a on rb.nid = a.entity_id
                      INNER JOIN taxonomy_term_data t on t.tid = a.field_primary_action_type_tid
                      WHERE rb.uid = $uid
                      AND t.tid = $action_tid")->rowCount();

  return $results;
}

/**
 * Get the total number of kudos this user has given.
 * @param   $uid
 * @return  int
 */
function dosomething_user_get_kudos_count($uid) {
  $results = db_query("SELECT fid
                      FROM dosomething_kudos
                      WHERE uid = $uid")->rowCount();

  return $results;
}

/**
 * Get the number of time a user has reported back on a particular campaign
 * @param   $uid
 * @param   $nid
 * @return  int
 */
function dosomething_user_get_superfan($uid, $nid) {
   $results = db_query("SELECT COUNT(rb.rbid)
                       FROM users u
                       INNER JOIN dosomething_reportback rb on rb.uid = u.uid
                       WHERE u.uid = $uid AND rb.nid = $nid
                       GROUP BY rb.uid,rb.nid")->fetchField();

   return $results;
}
