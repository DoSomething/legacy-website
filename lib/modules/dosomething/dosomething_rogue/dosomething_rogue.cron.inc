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

        $data = [
          'nid' => $task->campaign_id,
          'campaign_run_id' => $task->campaign_run_id,
          'quantity' => $task->quantity,
          'why_participated' => $task->why_participated,
          'file' => $task->file,
          'caption' => $task->caption,
          'type' => $task->type,
        ];

        if ($task->crop_x) {
          $cropped_values = dosomething_rogue_send_crop_values($task);

          foreach ($cropped_values as $key => $value) {
            $data[$key] = $value;
          }
        }

        $user = user_load($task->drupal_id);

        dosomething_rogue_send_reportback_to_rogue($data, $user);
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
