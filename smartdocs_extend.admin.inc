<?php

function smartdocs_model_download_original(array $model_array, array $revision_array = NULL) {
  $uuid = $model_array['id'];
  $revision = $revision_array['revisionNumber'];
  $stored_data = db_select('smartdocs_raw_revisions', 'sr')
    ->condition('uuid', $uuid)
    ->condition('revision', $revision)
    ->fields('sr')
    ->execute()
    ->fetchAssoc();
  $raw_spec = $stored_data['raw_spec'];
  $format = $stored_data['spec_format'];
  if ($format == 'application/json') {
     $filename = $model_array['name'] . "-" . $revision . "-" . time() . '.json';
  } else if ($format == 'application/yaml') {
    $filename = $model_array['name'] . "-" . $revision . "-" . time() . '.yaml';
  } else if ($format == 'application/xml') {
    $filename = $model_array['name'] . "-" . $revision . "-" . time() . '.xml';
  }
  // Full complement of headers so IE behaves
  header("Cache-Control: public");
  header("Content-Type: application/octet-stream");
  header("Cache-Control: no-store, no-cache, must-revalidate");
  header("Cache-Control: post-check=0, pre-check=0");
  header("Content-Disposition: attachment; filename=\"". $filename . "\";" );
  header("Content-Transfer-Encoding: binary");

  // Print your CSV data here
  print $raw_spec;
  // Exit the script
  drupal_exit();
}
