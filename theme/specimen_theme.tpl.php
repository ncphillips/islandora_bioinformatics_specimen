<?php
/**
 * @file
 * This is the template file for the specimen object page.
 *
 * Here we build an html page using the variables passed in by
 * the islandora_bioinformatics_specimen_preprocess_islandora_specimen
 * function.  Elements such as labels and buttons can be added here
 */
$islandora_content = $islandora_object['SPECIMEN']->content;
$path = drupal_get_path('module', 'islandora_bioinformatics_specimen');
?>

<div class="islandora-specimen-object islandora">
  <button id="specimen_image">Bring Back That Pig!</button>
  <div class ="specimen_image">
    <?php print $variables['islandora_thumbnail_img'] ?>
  </div>
  <div class="islandora-basic-image-content-wrapper clearfix">
    <?php if (isset($islandora_content)): ?>
      <div class="islandora-porcus-content">
        <?php print $islandora_content; ?>
      </div>
    <?php endif; ?>
  </div>
