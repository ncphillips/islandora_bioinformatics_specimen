<?php

/**
 * @file
 * This file, at least for the time being, contains the preprocessing stuff.
 * 
 */

/**
 * The preprocess hook. It is responsible for putting anything that the template
 * might need into an array called variables. Doesn't technically return 
 * this $variables array. This must just be included before theme stuff
 *
 * @param variables
 * Reference to the variables array that we'll populate
 */
function islandora_bioinformatics_specimen_preprocess_islandora_bioinformatics_specimen(array &$variables) {
  
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
    
    // namespace needs to be set for children() calls
    $ns = "eml://ecoinformatics.org/eml-2.1.0";

    // get all of the EML XML 
    $eml_data = $islandora_object['EML']->content;

    // turn this XML into an object
    $obj = new SimpleXMLElement($eml_data);

    // this is not being done the ideal way. There really should only be one child
    // so essentially it should only loop once
    foreach ($obj->children($ns) as $dataset){
      $taxonomy = parse_taxonomy($dataset->coverage->taxonomicCoverage->taxonomicClassification);
    }

    $variables['taxonomy'] = $taxonomy; 
  }
}


/**
 * This is responsible for taking a specific SimpleXMLElement and returning an
 * array with the correct taxonomy information. This should be able to be
 * put directly into the variables array
 *
 * @param taxon_container
 * A SimpleXMLElement corresponding the the <taxonmicClassification> xml block
 *
 * @return taxonomy
 * A simple array with rankNames as indices and rankValues as values
 */
function parse_taxonomy($taxon_container){

  $taxonomy = array();

  foreach($taxon_container as $rank){
    // i'd rather deal with strings than objects
    $rv = (string) $rank->taxonRankValue;
    $rn = (string) $rank->taxonRankName;

    // only add a val and name if the val has been filled out
    if ($rv){
      $taxonomy[$rn] = $rv;
    }
  }
  return $taxonomy;
}
