<?php
/**
 * @file
 * This is the template file for the specimen object page.
 *
 * Here we build an html page using the variables passed in by
 * the islandora_bioinformatics_specimen_preprocess_islandora_specimen
 * function.  Elements such as labels and buttons can be added here
 */
//$islandora_content = $islandora_object['SPECIMEN']->content;
//$path = drupal_get_path('module', 'islandora_bioinformatics_specimen');

echo "<pre>";
//print_r($variables['taxonomy']);
//print_r($variables['geography']);
//print_r($variables['methods']);
echo "</pre>";
?>

<div class="islandora-specimen-object islandora">
  <div class ="specimen_image">
    <div class="m-btn-group">
      <a href="/islandora/object/islandora%3A293/manage/overview/ingest" class="m-btn green">Add a Specimen</a>
    </div>
    <table>
    <tr>
    <td><?php if (isset($variables['islandora_thumbnail_img'])): ?><?php print $variables['islandora_thumbnail_img'] ?><?php endif; ?></td>
    <td><table style="width:300px">
      <tr><th>Taxonomic Information</th></tr>
      <tr><td>Phylum: <?php print $variables['taxonomy']['phylum'] ?></td></tr>
      <tr><td>Subphylum: <?php print $variables['taxonomy']['subphylum'] ?></td></tr>
      <tr><td>Class: <?php print $variables['taxonomy']['class'] ?></td></tr>
      <tr><td>Order: <?php print $variables['taxonomy']['order'] ?></td></tr>
      <tr><td>Family: <?php print $variables['taxonomy']['family'] ?></td></tr>
      <tr><td>Genus: <?php print $variables['taxonomy']['genus'] ?></td></tr>
      <tr><td>Species: <?php print $variables['taxonomy']['species'] ?></td></tr>
    </table></td>
    <td><table style="width:300px">
      <tr><th>Geographical Information</th></tr>
      <tr><td>Site Name: <?php print $variables['geography']['siteName'] ?></td></tr>
      <tr><td>Location: <?php print $variables['geography']['north'] ?>N, <?php print $variables['geography']['west'] ?>W</td></tr>
    </table></td>
    </table>
  </div>
</div>
