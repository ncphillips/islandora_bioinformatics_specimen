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
//$path = drupal_get_path('module', 'islandora_lab_object_specimen');

echo "<pre>";
//print_r($variables['taxonomy']);
//print_r($variables['geography']);
//print_r($variables['methods']);
echo "</pre>";
?>

<div class="islandora-specimen-object islandora">
  <div class ="specimen_image">
    <table>
    <tr>
    <td><?php if (isset($variables['islandora_thumbnail_img'])): ?><?php print $variables['islandora_thumbnail_img'] ?><?php endif; ?></td>
    <td><table style="width:300px">
      <tr><th>Taxonomic Information</th></tr>
      <?php if (isset ($variables['taxonomy']['phylum'])):?><tr><td>Phylum: <?php print $variables['taxonomy']['phylum'] ?></td></tr><?php endif; ?>
      <?php if (isset ($variables['taxonomy']['subphylum'])):?><tr><td>Subphylum: <?php print $variables['taxonomy']['subphylum'] ?></td></tr><?php endif; ?>
      <?php if (isset ($variables['taxonomy']['class'])):?><tr><td>Class: <?php print $variables['taxonomy']['class'] ?></td></tr><?php endif; ?>
      <?php if (isset ($variables['taxonomy']['order'])):?><tr><td>Order: <?php print $variables['taxonomy']['order'] ?></td></tr><?php endif; ?>
      <?php if (isset ($variables['taxonomy']['family'])):?><tr><td>Family: <?php print $variables['taxonomy']['family'] ?></td></tr><?php endif; ?>
      <?php if (isset ($variables['taxonomy']['genus'])):?><tr><td>Genus: <?php print $variables['taxonomy']['genus'] ?></td></tr><?php endif; ?>
      <?php if (isset ($variables['taxonomy']['species'])):?><tr><td>Species: <?php print $variables['taxonomy']['species'] ?></td></tr><?php endif; ?>
    </table></td>
    <td><table style="width:300px">
      <tr><th>Geographical Information</th></tr>
      <?php if (isset ($variables['geography']['siteName'])):?><tr><td>Site Name: <?php print $variables['geography']['siteName'] ?></td></tr><?php endif; ?>
      <?php if (isset ($variables['geography']['north'])):?><tr><td>Location: <?php print $variables['geography']['north'] ?>N, <?php print $variables['geography']['west'] ?>W</td></tr><?php endif; ?>
    </table></td>
    </table>
  </div>
</div>
