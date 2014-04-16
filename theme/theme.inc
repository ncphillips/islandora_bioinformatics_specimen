<?php

/**
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
function islandora_lab_object_specimen_preprocess_islandora_lab_object_specimen(array &$variables) {
  
  $islandora_object = $variables['islandora_object'];
  // Thumbnail.
  if (isset($islandora_object['TN'])) {
    $thumbnail_size_url = url("islandora/object/{$islandora_object->id}/datastream/TN/view");
    $params = array(
      'title' => $islandora_object->label,
      'path' => $thumbnail_size_url,
    );
    $variables['islandora_thumbnail_img'] = theme('image', $params);
    $variables['img_url'] = $thumbnail_size_url;
  }

  if (isset($islandora_object['TN1'])) {
    $thumbnail_size_url = url("islandora/object/{$islandora_object->id}/datastream/TN1/view");
      $params = array(
        'title' => $islandora_object->label,
        'path' => $thumbnail_size_url,
      );
      $variables['islandora_thumbnail_img1'] = theme('image', $params);
      $variables['img_url1'] = $thumbnail_size_url;
    }

    if (isset($islandora_object['TN2'])) {
        $thumbnail_size_url = url("islandora/object/{$islandora_object->id}/datastream/TN2/view");
        $params = array(
            'title' => $islandora_object->label,
            'path' => $thumbnail_size_url,
        );
        $variables['islandora_thumbnail_img2'] = theme('image', $params);
        $variables['img_url2'] = $thumbnail_size_url;
    }

    if (isset($islandora_object['TN3'])) {
        $thumbnail_size_url = url("islandora/object/{$islandora_object->id}/datastream/TN3/view");
        $params = array(
            'title' => $islandora_object->label,
            'path' => $thumbnail_size_url,
        );
        $variables['islandora_thumbnail_img3'] = theme('image', $params);
        $variables['img_url3'] = $thumbnail_size_url;
    }

    if (isset($islandora_object['TN4'])) {
        $thumbnail_size_url = url("islandora/object/{$islandora_object->id}/datastream/TN4/view");
        $params = array(
            'title' => $islandora_object->label,
            'path' => $thumbnail_size_url,
        );
        $variables['islandora_thumbnail_img4'] = theme('image', $params);
        $variables['img_url4'] = $thumbnail_size_url;
    }

  // get some of the EML data
  if (isset($islandora_object['EML'])) {
    
    // namespace needs to be set for children() calls
    $ns = "eml://ecoinformatics.org/eml-2.1.0";

    // get all of the EML XML 
    $eml_data = $islandora_object['EML']->content;


    // turn this XML into an object
    $obj = new SimpleXMLElement($eml_data);

    // this is not being done the ideal way. There really should only be one child
    // so essentially it should only loop once
    foreach ($obj->children($ns) as $dataset) {
      $taxonomy = parse_taxonomy($dataset->coverage->taxonomicCoverage);
      $geography = parse_geography($dataset->coverage->geographicCoverage);
    //  $methods = parse_methods($dataset->methods->methodStep->description->section);
      $temporal = parse_temporal($dataset->coverage->temporalCoverage);
      break;
    }
    echo "<div style='background-color:red;'><pre>";

    var_dump($taxonomy);
    echo "</pre></div>";
    $variables['taxonomy'] = $taxonomy;
    $variables['geography'] = $geography; 
    $variables['methods'] = $methods;
    $variables['temporal'] = $temporal;
  }

  //get projects associated with the specimen
  $tuque = new IslandoraTuque();
  $project_query = "SELECT ?pid
                    FROM <#ri>
                    WHERE {
                    ?pid <fedora-model:hasModel> <info:fedora/islandora:project_cmodel> .
                    }";
  $result = $tuque->repository->ri->sparqlQuery($project_query, 'unlimited');

  $related_projects = array();
  foreach ($result as $project) {
    $project_object = islandora_object_load($project['pid']['value']);
    if ($islandora_object->relationships->get(FEDORA_RELS_EXT_URI, 'isPartOf', $project_object->id)) {
      $related_projects[$project_object->id] = $project_object->label;
    }
  }
  $variables['related_projects'] = $related_projects;

  $variables['object_id'] = $islandora_object->id;
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
function parse_taxonomy($taxon_container) {


  $taxonomy = array();

  echo "<div style='background-color:blue;'><pre>";
  var_dump($taxon_container);
  echo "</pre></div>";

  foreach ($taxon_container->taxonomicClassification as $taxon_item){


    switch($taxon_item->taxonRankName){
      case "phylum":
        $taxonomy['phylum'] = (string) $taxon_item->taxonRankValue;
        break;
      case "subphylum";
        $taxonomy['subphylum'] = (string) $taxon_item->taxonRankValue;
        break;
      case "class":
        $taxonomy['class'] = (string) $taxon_item->taxonRankValue;
        break;
      case "order":
        $taxonomy['order'] = (string) $taxon_item->taxonRankValue;
        break;
      case "family":
        $taxonomy['family'] = (string) $taxon_item->taxonRankValue;
        break;
      case "genus":
        $taxonomy['genus'] = (string) $taxon_item->taxonRankValue;
        break;
      case "species":
        $taxonomy['species'] = (string) $taxon_item->taxonRankValue;
        break;
    }
  }

  return $taxonomy;
}

function parse_geography($taxon_container) {

  $geography = array();

  if (is_array($taxon_container) || $taxon_container instanceof Traversable) {
  foreach ($taxon_container as $key => $rank) {
    // i'd rather deal with strings than objects
    $west = "west";
    $west_coor = (string) $rank->boundingCoordinates->westBoundingCoordinate;

    $north = "north";
    $north_coor = (string) $rank->boundingCoordinates->northBoundingCoordinate;

    $site = "siteName";
    $site_name = (string) $rank->geographicDescription;

    $depth = "depth";
    $depth_number = (string) $rank->boundingCoordinates->boundingAltitudes->altitudeMinimum;

    $depth_unit = "unit";
    $depth_unit_string = (string) $rank->boundingCoordinates->boundingAltitudes->altitudeUnits;
    

    // only add a val and name if the val has been filled out
    if ($west_coor) {
      $geography[$west] = $west_coor;
    }

    if ($north_coor) {
      $geography[$north] = $north_coor;
    }

    if ($site_name) {
      $geography[$site] = $site_name;
    }

    if ($depth_number) {
        $geography[$depth] = $depth_number;
    }

    if ($depth_unit_string) {
        $geography[$depth_unit] = $depth_unit_string;
    }

  }}
  return $geography;
}

function parse_methods($taxon_container) {

  $methods = array();

  if (is_array($taxon_container) || $taxon_container instanceof Traversable) {
  foreach ($taxon_container as $key => $rank) {
    // i'd rather deal with strings than objects
    $method_title = "title";
    $method_title_value = (string) $rank->title;

    $method_para = "para";
    $method_para_value = (string) $rank->para;

    // only add a val and name if the val has been filled out
    if ($method_para_value) {
      $methods[$method_para] = $method_para_value;
    }

    if ($method_title_value) {
      $methods[$method_title] = $method_title_value;
    }

  }}
  return $methods;
}

function parse_temporal($taxon_container) {

    $temporal = array();

    if (is_array($taxon_container) || $taxon_container instanceof Traversable) {
    foreach ($taxon_container as $key => $rank) {
        // i'd rather deal with strings than objects
        $collection_date = "date";
        $collection_date_value = (string) $rank->singleDateTime->calendarDate;

        // only add a val and name if the val has been filled out
        if ($collection_date_value) {
            $temporal[$collection_date] = $collection_date_value;
        }
    }}
    return $temporal;
}
