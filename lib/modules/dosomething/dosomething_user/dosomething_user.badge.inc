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

function dosomething_users_map_badge_causes($key, $badges, $type) {
  if (array_key_exists($key, $badges['causes'][$type])) {
    return $badges['causes'][$type][$key];
  }
}

function dosomething_users_map_special_badge($key, $badges, $type) {
  if (array_key_exists($key, $badges['special'][$type])) {
    return $badges['special'][$type][$key];
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

function dosomething_users_get_kudos_badge_images($numbah) {
  $badges['kudos'][1] = '&#128169';
  $badges['kudos'][3] = '&#128169&#128169&#128169';
  $badges['kudos'][5] = '&#128169&#128169&#128169&#128169&#128169';
  $badges['kudos'][10] = '&#128169&#128169&#128169&#128169&#128169&#128169&#128169&#128169&#128169&#128169';
  $badges['kudos'][15] = '&#128169&#128169&#128169&#128169&#128169&#128169&#128169&#128169&#128169&#128169&#128169&#128169&#128169&#128169&#128169';

  return dosomething_users_map_badge($numbah, $badges, 'kudos');
}

function dosomething_users_get_shutterbug_badge_images($numbah) {
  $badges['shutterbug'][1] = '&#128027';
  $badges['shutterbug'][3] = '&#128027&#128027&#128027';
  $badges['shutterbug'][5] = '&#128027&#128027&#128027&#128027&#128027';
  $badges['shutterbug'][10] = '&#128027&#128027&#128027&#128027&#128027&#128027&#128027&#128027&#128027&#128027';
  $badges['shutterbug'][15] = '&#128027&#128027&#128027&#128027&#128027&#128027&#128027&#128027&#128027&#128027&#128027&#128027&#128027&#128027&#128027';

  return dosomething_users_map_badge($numbah, $badges, 'shutterbug');
}

function dosomething_users_get_mental_health_badge_images($numbah) {
  $name = 'mental health';
  $badges['causes']['mental health'][1] = '&#127777';

  return dosomething_users_map_badge_causes($numbah, $badges, $name);
}

function dosomething_users_get_animals_badge_images($numbah) {
  $name = 'animals';
  $badges['causes']['animals'][1] = '&#127777';

  return dosomething_users_map_badge_causes($numbah, $badges, $name);
}

function dosomething_users_get_bullying_badge_images($numbah) {
  $name = 'bullying';
  $badges['causes']['bullying'][1] = '&#127777';

  return dosomething_users_map_badge_causes($numbah, $badges, $name);
}

function dosomething_users_get_disasters_badge_images($numbah) {
  $name = 'disasters';
  $badges['causes']['disasters'][1] = '&#127777';

  return dosomething_users_map_badge_causes($numbah, $badges, $name);
}

function dosomething_users_get_discrimination_badge_images($numbah) {
  $name = 'discrimination';
  $badges['causes']['discrimination'][1] = '&#127777';

  return dosomething_users_map_badge_causes($numbah, $badges, $name);
}

function dosomething_users_get_education_badge_images($numbah) {
  $name = 'education';
  $badges['causes']['education'][1] = '&#127777';

  return dosomething_users_map_badge_causes($numbah, $badges, $name);
}

function dosomething_users_get_environment_badge_images($numbah) {
  $name = 'environment';
  $badges['causes']['environment'][1] = '&#127777';

  return dosomething_users_map_badge_causes($numbah, $badges, $name);
}

function dosomething_users_get_homelessness_badge_images($numbah) {
  $name = 'homelessness';
  $badges['causes']['homelessness'][1] = '&#127777';

  return dosomething_users_map_badge_causes($numbah, $badges, $name);
}

function dosomething_users_get_physical_health_badge_images($numbah) {
  $name = 'physical_health';
  $badges['causes']['physical_health'][1] = '&#127777';

  return dosomething_users_map_badge_causes($numbah, $badges, $name);
}

function dosomething_users_get_poverty_badge_images($numbah) {
  $name = 'poverty';
  $badges['causes']['poverty'][1] = '&#127777';

  return dosomething_users_map_badge_causes($numbah, $badges, $name);
}

function dosomething_users_get_relationships_badge_images($numbah) {
  $name = 'relationships';
  $badges['causes']['relationships'][1] = '&#127777';

  return dosomething_users_map_badge_causes($numbah, $badges, $name);
}

function dosomething_users_get_sex_badge_images($numbah) {
  $name = 'sex';
  $badges['causes']['sex'][1] = '&#127777';

  return dosomething_users_map_badge_causes($numbah, $badges, $name);
}

function dosomething_users_get_violence_badge_images($numbah) {
  $name = 'violence';
  $badges['causes']['violence'][1] = '&#127777';

  return dosomething_users_map_badge_causes($numbah, $badges, $name);
}

function dosomething_users_get_362_badge_images($numbah) {
  $badges['special'][362][1] = '&#127777';

  return dosomething_users_map_special_badge($numbah, $badges, 362);
}

function dosomething_users_get_badge_number_from_count($numbah) {
  $badges['special'][362][1] = '&#127777';

  return $number;
}
/**
 * Gets all badges for a user.
 * @param  [int] $uid
 * @return [array]
 */
function dosomething_user_get_badges($uid) {
  // we can mod this by 5 to give badges for each 5 or something.
  $badges['signups']['count'] = dosomething_user_get_activity_count($uid, 'signup');

  $badges['reportbacks']['count'] = dosomething_user_get_activity_count($uid, 'reportback');
  $badges['kudos']['count'] = dosomething_user_get_kudos_count($uid);

  $badges['signups']['image'] = array_map('dosomething_users_get_signup_badge_images', range(0, $badges['signups']['count']));
  $badges['reportbacks']['image'] = array_map('dosomething_users_get_reportback_badge_images', range(0, $badges['reportbacks']['count']));
  $badges['kudos']['image'] = array_map('dosomething_users_get_kudos_badge_images', range(0, $badges['kudos']['count']));


  // Only if you hit like 5.
  $badges['shutterbug']['count'] = dosomething_user_get_max_reportback_file_updates($uid);
  $badges['shutterbug']['image'] = array_map('dosomething_users_get_shutterbug_badge_images', range(0, $badges['shutterbug']['count']));

  // Loop through each cause space, get by name, and then once you hit 5 show this.
  $causes = taxonomy_get_tree(2);
  foreach ($causes as $cause) {
      $badges['causes'][strtolower($cause->name)]['count'] = dosomething_user_get_cause_space_badge($uid, $cause->tid);
      $badges['causes'][strtolower($cause->name)]['image'] = array_map('dosomething_users_get_' . str_replace(' ', '_', strtolower($cause->name)) . '_badge_images', range(0,$badges['causes'][strtolower($cause->name)]['count']));
    
  }

  // Loop through action types.
  $actions = taxonomy_get_tree(1);
  foreach ($actions as $action) {
    $badges['actions'][strtolower($action->name)] = dosomething_user_get_action_space_badge($uid, $action->tid);
  }

  // Get special type badges.
  $special_badge_campaigns = [362];
  foreach ($special_badge_campaigns as $special_campaign) {
    $badges['special'][$special_campaign]['count'] = dosomething_user_get_superfan($uid, $special_campaign);
    $badges['special'][$special_campaign]['image'] = array_map('dosomething_users_get_' . $special_campaign . '_badge_images', range(0,$badges['special'][$special_campaign]['count']));
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
