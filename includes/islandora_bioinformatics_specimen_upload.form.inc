<?php

 /**
  * @file
  * handles uploading an image file to a specimen as part of ingest
  */

function islandora_bioinformatics_specimen_upload_form(array $form, array &$form_state) {

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

/**
 * Adds the uploaded file into the ingestable objects 'IMG' datastream.
 *
 * @param array $form
 *   The drupal form.
 * @param array $form_state
 *   The drupal form state.
 */
function islandora_bioinformatics_specimen_upload_form_submit(array $form, array &$form_state) {
  $image_file = file_load($form_state['values']['file']);
  if (!empty($image_file)) {	//check if a file has been uploaded
  
    $object = $form_state['islandora']['objects'][0];
    if (empty($object['IMG'])) {
    $ds = $object->constructDatastream('IMG', 'M');
    $object->ingestDatastream($ds);
    }
    else {
    $ds = $object['IMG'];
    }

    $image_path = drupal_realpath($image_file->uri);
    $ds->setContentFromFile($image_path, FALSE);
    $ds->label = $image_file->filename;
    $ds->mimetype = $image_file->filemime;
  }
}
