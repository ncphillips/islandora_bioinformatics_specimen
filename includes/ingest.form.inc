<?php

/**
 * @author Quintin Dawson qdawson@upei.ca
 * This function should create a new specimen object and create a relationship between it and the $parent object
 */

function rel_lab_object_specimen_ingest(AbstractObject $parent) {
  $tuque = new IslandoraTuque();

  //create the object to be ingested

  $collection =  $parent->getParents();
  $collection = $collection[0];



  //dpm($parent);
  echo '<pre>';
  echo $collection;
  //var_dump($parent->models);
  //var_dump($parent['COLLECTION_POLICY']);
  //var_dump($parent['COLLECTION_POLICY']->content);
  echo '</pre>';

  $object = $tuque->repository->constructObject('islandora');
  //$object = $tuque->repository->constructObject('fake:pid');

  $object->owner = 'fedoraAdmin';
  $object->label = 'New Object';
  //$object->models = 'islandora:specimen_cmodel';
  $object->models = 'islandora:specimen_collection';

  //add RELS-EXT relation to object for specimen collection
  //$object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', 'islandora:specimen_collection');

  //form a relationship between the parent object and the object being ingested
  //$object->relationships->add(FEDORA_RELS_EXT_URI, 'hasModel', $parent->id);

  //ingest the object
  //$tuque->repository->ingestObject($object);

  //generate the $configuration array
  $configuration = array(
    //'collection' => $parent,    //this was $collection
    'collection' => 'islandora:specimen_collection',
    'models' => array('islandora:specimen_cmodel'),
    'objects' => array($object),
    'parent' => $parent->id,   //this was $collection->id
  );

  return drupal_get_form('Invertebrate Form', $configuration);

  //find how to set the $collection variable in the original example at https://github.com/Islandora/islandora_solution_pack_collection/blob/7.x/includes/ingest.form.inc and reproduce
}