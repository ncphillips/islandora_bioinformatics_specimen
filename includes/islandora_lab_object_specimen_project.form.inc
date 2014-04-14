<?php 

/*
*
* @file islandora_lab_object_specimen_project.form.inc
*
*
*
*
*/

function islandora_lab_object_specimen_project_form(array $form, array &$form_state, $specimen) {
  
  // connect to the fedora repo. Apparently this function can be called from anywhere and it will
  // work.
  $tuque = new IslandoraTuque();


  // query to get all of the objects with a project content model
  $project_query = "SELECT ?pid
                    FROM <#ri>
                    WHERE {
                    ?pid <fedora-model:hasModel> <info:fedora/islandora:project_cmodel> .
                    }";
  $result = $tuque->repository->ri->sparqlQuery($project_query, 'unlimited');
  
  // now result has an array of some format that will have pids of all projects
  
  
  // i have no idea how to write a SPARQL or ITQL query that would get the label
  // or if that's even possible. So I'm going to try to screw around with Tuque 
  // to try to figure it out

  $project_array = array();
  foreach ($result as $project) {
    // label should contain whatever we've selected as a label for these objects?
    $project_object = islandora_object_load($project['pid']['value']);
    $relations = $project_object->relationships->get(FEDORA_RELS_EXT_URI, 'hasPart', $specimen->id, NULL);
    if(empty($relations))
      $project_array[$project["pid"]["value"]] = $project_object->label;
  }

  $form['projects'] = array(
      '#type' => 'select',
      '#title' => t('Projects'),
      '#options' => $project_array,
       '#multiple' => TRUE,
       '#attributes' => array('size' => 4),
       '#weight' => 8,
  );
  
  return $form;

}

function islandora_lab_object_specimen_project_form_submit(array $form, array &$form_state) {
  $tuque = new IslandoraTuque();

  $specimen_object = $form_state['islandora']['objects'][0];

  $project_ids = array_filter($form_state['values']['projects']);
  
  
  foreach ($project_ids as $id) {

    $specimen_object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOf', $id);
  }
}
