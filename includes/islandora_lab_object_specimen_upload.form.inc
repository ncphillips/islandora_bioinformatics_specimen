<?php

 /**
  * @file
  * handles uploading an image file to a specimen as part of ingest
  */

function islandora_lab_object_specimen_upload_form(array $form, array &$form_state) {

  // sets the max upload size to whatever php has defined.
  $upload_size = min((int) ini_get('post_max_size'), (int) ini_get('upload_max_filesize'));
  $extensions = array('png jpg jpeg gif');

  $form = array(
    "image1" => array(
      '#title' => t('Specimen Image #1'),
      '#type' => 'managed_file',
      '#required' => FALSE,
      '#description' => t('Select an image to associate with the specimen. This image will be used as the thumbnail for the specimen.'),
      '#default_value' => isset($form_state['values']['files']) ? $form_state['values']['files'] : NULL,
      '#upload_location' => 'temporary://',
      '#upload_validators' => array(
        'file_validate_extensions' => $extensions,
        'file_validate_size' => array($upload_size * 1024 * 1024),
      ),
    ),
    "image2" => array(
        '#title' => t('Specimen Image #2'),
        '#type' => 'managed_file',
        '#required' => FALSE,
        '#description' => t('Select an image to associate with the specimen.'),
        '#default_value' => isset($form_state['values']['files']) ? $form_state['values']['files'] : NULL,
        '#upload_location' => 'temporary://',
        '#upload_validators' => array(
            'file_validate_extensions' => $extensions,
            'file_validate_size' => array($upload_size * 1024 * 1024),
        ),
    ),
    "image3" => array(
        '#title' => t('Specimen Image #3'),
        '#type' => 'managed_file',
        '#required' => FALSE,
        '#description' => t('Select an image to associate with the specimen.'),
        '#default_value' => isset($form_state['values']['files']) ? $form_state['values']['files'] : NULL,
        '#upload_location' => 'temporary://',
        '#upload_validators' => array(
            'file_validate_extensions' => $extensions,
            'file_validate_size' => array($upload_size * 1024 * 1024),
        ),
    ),
    "image4" => array(
        '#title' => t('Specimen Image #4'),
        '#type' => 'managed_file',
        '#required' => FALSE,
        '#description' => t('Select an image to associate with the specimen.'),
        '#default_value' => isset($form_state['values']['files']) ? $form_state['values']['files'] : NULL,
        '#upload_location' => 'temporary://',
        '#upload_validators' => array(
            'file_validate_extensions' => $extensions,
            'file_validate_size' => array($upload_size * 1024 * 1024),
        ),
    ),
    "image5" => array(
        '#title' => t('Specimen Image #5'),
        '#type' => 'managed_file',
        '#required' => FALSE,
        '#description' => t('Select an image to associate with the specimen.'),
        '#default_value' => isset($form_state['values']['files']) ? $form_state['values']['files'] : NULL,
        '#upload_location' => 'temporary://',
        '#upload_validators' => array(
            'file_validate_extensions' => $extensions,
            'file_validate_size' => array($upload_size * 1024 * 1024),
        ),
    ));


  return $form;
}

/**
 * Adds the uploaded file into the ingestable objects 'TN' datastream.
 *
 * @param array $form
 *   The drupal form.
 * @param array $form_state
 *   The drupal form state.
 */
function islandora_lab_object_specimen_upload_form_submit(array $form, array &$form_state) {
  $image_files[0] = file_load($form_state['values']['image1']);
  $image_files[1] = file_load($form_state['values']['image2']);
  $image_files[2] = file_load($form_state['values']['image3']);
  $image_files[3] = file_load($form_state['values']['image4']);
  $image_files[4] = file_load($form_state['values']['image5']);

  associate_image($image_files, $form, $form_state);
}

/**
 * Allows for association of multiple images with the TN datastream.
 *
 * @param $image_files
 *  An array of image files
 * @param $form
 *  The drupal form
 * @param $form_state
 *  Reference to the drupal form state
 */
function associate_image($image_files, array $form, array &$form_state){
  $i = 0;

  foreach ($image_files as $img){
    $tn_num = (!$i) ? "":$i;
    $i++;
    if (!empty($img)) {  //check if a file has been uploaded

      $object = $form_state['islandora']['objects'][0];
      $ds = $object->constructDatastream('TN'. $tn_num, 'M');
      $object->ingestDatastream($ds);


      $image_path = drupal_realpath($img->uri);
      $ds->setContentFromFile($image_path, FALSE);
      $ds->label = $img->filename;
      $ds->mimetype = $img->filemime;
    }

  }

}
