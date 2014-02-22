<?php

 /*
  * @file
  * handles uploading an image file to a specimen as part of ingest
  */

function islandora_bioinformatics_specimen_upload_form(array $form, array &$form_state){

  // sets the max upload size to whatever php has defined.
  $upload_size = min((int) ini_get('post_max_size'), (int) ini_get('upload_max_filesize'));
  $extensions = array('png', 'jpg', 'jpeg');
  $form = array();

  $form['file'] = array(
    '#title' => t('Specimen Image File'),
    '#type' => 'managed_file',
    '#required' => FALSE,
    '#description' => t('Select something. Pls.'),
    '#default_value' => isset($form_state['values']['files']) ? $form_state['values']['files'] : NULL,
    '#upload_location' => 'temporary://',
    '#upload_validators' => array(
      'file_validate_extensions' => $extensions,
      'file_validate_size' => array($upload_size * 1024 * 1024),
    ),
  );
  return $form;
}

