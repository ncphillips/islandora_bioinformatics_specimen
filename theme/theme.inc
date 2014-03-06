// this is where the front end will need to implement preprocess_theme() and I think another one?
// I can't remember off the top of my head.

function islandora_bioinformatics_specimen_preprocess_islandora_porcus(array &$variables) {

  
  $islandora_object = $variables['islandora_object'];
  // Thumbnail.
  if (isset($islandora_object['TN'])) {
    $thumbnail_size_url = url("islandora/object/{$islandora_object->id}/datastream/TN/view");
    $params = array(
      'title' => $islandora_object->label,
      'path' => $thumbnail_size_url,
    );
    $variables['islandora_thumbnail_img'] = theme('image', $params);
  }
}
