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
      if ($task->type === 'reportback') {
        // Check to see if the MIME type is missing
        if (strpos($task->file, 'data:;') !== false) {
          // Split file string to access the data
          $data = explode(',', $task->file)[1];

          // Decode and use getimagesizefromstring() to access the MIME type
          $image_size_info = getimagesizefromstring(base64_decode($data));
          $mimetype = $image_size_info['mime'];

          // Split the file string where the MIME type will go and rebuild to include MIME type
          $mime_split = explode(':', $task->file);
          $task->file = $mime_split[0] . ':' . $mimetype . $mime_split[1];
        }

        $user = user_load($task->drupal_id);
        $data = (array)$task;

        $rogue_reportback = dosomething_rogue_send_reportback_to_rogue($data, $user);

        dosomething_rogue_check_rbid_and_store_ref($rogue_reportback);
      } else {
        $data = [
          [
            'rogue_reportback_item_id' => $task->rogue_item_id,
            'status' => $task->status,
          ]
        ];

        dosomething_rogue_update_rogue_reportback_items($data);
      }
   }
 }
