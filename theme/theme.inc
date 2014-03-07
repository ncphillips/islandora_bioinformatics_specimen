<?php
// here's where you can change the $variables array before the page is loaded


function islandora_bioinformatics_specimen_preprocess_specimen_theme(array &$variables) {
  
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

  // get some of the EML data
  if (isset($islandora_object['EML'])){
    $eml_data = url("islandora/object/{$islandora_object->id}/datastream/EML/view");
    
    $variables["EML_DATA"] = $eml_data;
  }
}
