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

  foreach ($task_log as $task) {
<<<<<<< HEAD
      if ($task->tries < 5) {
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

          $rogue_reportback = dosomething_rogue_send_reportback_to_rogue($data, $user, $task->id);

          if ($rogue_reportback) {
            dosomething_rogue_check_rbid_and_store_ref($rogue_reportback);

            db_delete('dosomething_rogue_failed_task_log')
              ->condition('id', $task->id)
              ->execute();
          }
        } else {
          $data = [
            [
              'rogue_reportback_item_id' => $task->rogue_item_id,
              'status' => $task->status,
            ]
          ];

          $response = dosomething_rogue_update_rogue_reportback_items($data, $task->id);

          if ($response) {
            db_delete('dosomething_rogue_failed_task_log')
              ->condition('id', $task->id)
              ->execute();
          }
=======
    if ($task->tries < 5) {
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
        if ($rogue_reportback) {
          dosomething_rogue_check_rbid_and_store_ref($rogue_reportback);

          db_delete('dosomething_rogue_failed_task_log')
            ->condition('northstar_id', $data['northstar_id'])
            ->condition('campaign_run_id', $data['campaign_run_id'])
            ->condition('caption', $data['caption'])
            ->condition('file', $data['file'])
            ->execute();
        }
      } else {
        $data = [
          [
            'rogue_reportback_item_id' => $task->rogue_item_id,
            'status' => $task->status,
            'reviewer' => $task->reviewer,
          ]
        ];

        $response = dosomething_rogue_update_rogue_reportback_items($data);

        if ($response) {
          db_delete('dosomething_rogue_failed_task_log')
            ->condition('rogue_item_id', $data[0]['rogue_reportback_item_id'])
            ->execute();
>>>>>>> cron job works for rb items
        }
      }
  }
}
