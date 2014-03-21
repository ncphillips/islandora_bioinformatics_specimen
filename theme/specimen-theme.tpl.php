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

echo "<pre>";
print_r($variables['taxonomy']);
echo "</pre>";
?>

<div class="islandora-specimen-object islandora">
  <div class ="specimen_image">
    <?php print $variables['islandora_thumbnail_img'] ?>
    <?php print $variables['islandora_eml'] ?>
  </div>
  <div class="islandora-basic-image-content-wrapper clearfix">
    <?php if (isset($islandora_content)): ?>
      <div class="islandora-porcus-content">
        <?php print $islandora_content; ?>
    
      </div>
    <?php endif; ?>
  </div>
