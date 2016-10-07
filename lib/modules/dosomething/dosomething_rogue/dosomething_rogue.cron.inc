<?php

/**
 * Implements hook_cron()
 */
 function dosomething_rogue_cron() {
    dosomething_rogue_retry_failed_reportbacks();
 }

 function dosomething_rogue_retry_failed_reportbacks() {
    $task_log = db_select('dosomething_rogue_failed_task_log', 't')
      ->fields('t')
      ->execute()
      ->fetchAll();
    db_truncate('dosomething_rogue_failed_task_log')->execute();

    foreach ($task_log as $task) {
      $values = [
        'nid' => $task->campaign_id,
        'campaign_run_id' => $task->campaign_run_id,
        'quantity' => $task->quantity,
        'why_participated' => $task->why_participated,
        'file' => $task->file,
        'caption' => $task->caption,
      ];

      $user = user_load($task->drupal_id);

      dosomething_rogue_send_reportback_to_rogue($values, $user);
   }
 }
