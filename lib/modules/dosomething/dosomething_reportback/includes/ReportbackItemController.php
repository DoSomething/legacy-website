<?php

class ReportbackItemController extends EntityAPIController {
  /**
   * Overrides buildContent() method.
   *
   * Adds Reportback properties into Reportback entity's render.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = []) {
    global $user;
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);

    $build['image'] = [
      '#markup' => $entity->getImage(),
    ];

    $build['caption'] = [
      '#prefix' => '<p><strong>',
      '#markup' => filter_xss($entity->caption),
      '#suffix' => '</strong></p>',
    ];

    $file = file_load($entity->fid);
    $build['file_url'] = [
      '#prefix' => '<p>',
      '#markup' => l(t('(View original upload)'), file_create_url($file->uri)),
      '#suffix' => '</p>',
    ];

    if ($view_mode == 'full') {
      $reportback = reportback_load($entity->rbid);
      $author = user_load($reportback->uid);
      $files_count = count($reportback->fids);
      $total_files = t('@count files uploaded', [
        '@count' => $files_count,
      ]);

      $build['username'] = [
        '#prefix' => '<p>',
        '#markup' => l($author->mail, 'user/' . $author->uid),
        '#suffix' => '</p>',
      ];
      $build['quantity'] = [
        '#prefix' => '<p>',
        '#markup' => '<strong>' . $reportback->quantity . '</strong> ' . $reportback->quantity_label,
        '#suffix' => '</p>',
      ];
      if ($files_count > 1) {
        $build['num_files'] = [
          '#prefix' => '<p>',
          '#markup' => l($total_files, 'reportback/' . $entity->rbid),
          '#suffix' => '</p>',
        ];
      }

      $build['why'] = [
        '#prefix' => '<p>',
        '#markup' => filter_xss($reportback->why_participated),
        '#suffix' => '</p>',
      ];
    }

    $build['source'] = [
      '#prefix' => '<p>',
      '#markup' => t('Source') . ': ' . $entity->source,
      '#suffix' => '</p>',
    ];

    if (!empty($entity->reviewed)) {
      $reviewer = user_load($entity->reviewer);
      $reason = NULL;
      if (!empty($reportback->flagged_reason)) {
        $reason = ' ' . t('as') . ' ' . $reportback->flagged_reason;
      }
      $summary = $reviewer->mail . ' <strong>' . $entity->status . '</strong> ';
      $summary .= format_date($entity->reviewed, 'short') . $reason . ' from ';
      $summary .= '<pre>' . $entity->review_source . '</pre>';

      $build['reviewed'] = [
        '#prefix' => '<p><hr />',
        '#markup' => $summary,
        '#suffix' => '</p>',
      ];
    }
    return $build;
  }

  /**
   * Overrides save() method.
   *
   * Updates count variables for corresponding nodes and taxonomy terms.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    if (DOSOMETHING_REPORTBACK_LOG) {
      watchdog('dosomething_reportback_file', 'save:' . json_encode($entity));
    }
    $status = 'pending';
    if (isset($entity->is_new)) {
      $op = 'insert';
    }
    parent::save($entity, $transaction);
    // Update the pending count for the node reportback was saved for.
    $reportback = reportback_load($entity->rbid);
    dosomething_reportback_reset_count('node', $reportback->nid, $status);
    if (module_exists('dosomething_campaign')) {
      if ($tid = dosomething_campaign_get_primary_cause_tid($reportback->nid)) {
        dosomething_reportback_reset_count('taxonomy_term', $tid, $status);
      }
    }
  }

  /**
   * Overrides delete() method.
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    // Delete the related Files.
    foreach ($ids as $fid) {
      $rbf = reportback_file_load($fid);
      $rbf->deleteFile();
    }
    parent::delete($ids, $transaction);
  }
}
