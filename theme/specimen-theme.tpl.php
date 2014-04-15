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

/*echo "<pre>";
print_r($variables['taxonomy']);
print_r($variables['geography']);
print_r($variables['methods']);
echo "</pre>";*/
?>
<style>
    .specimen-info {
        width: 33%;
        float: left;
        position: relative;
        top: 8px;
    }

    .specimen-info-label {
        font-weight: bold;
        font-size: 14px;
        width: 180px;
    }

    .specimen-info table {
        border: none;
    }

    .specimen-info-heading {
        font-weight: bold;
        font-size: 14px;
        width: 180px;
        border: none;
        background: none;
        text-decoration:underline;
    }
</style>

<div>
  <table>
    <tbody>
      <tr>
        <td><img src="<?php print ($variables['img_url'])  ? $variables['img_url']:""?>" width="150"></td>
        <td><img src="<?php print ($variables['img_url1']) ? $variables['img_url1']:""?>" width="150"></td>
        <td><img src="<?php print ($variables['img_url2']) ? $variables['img_url2']:""?>" width="150"></td>
        <td><img src="<?php print ($variables['img_url3']) ? $variables['img_url3']:""?>" width="150"></td>
        <td><img src="<?php print ($variables['img_url4']) ? $variables['img_url4']:""?>" width="150"></td>
      </tr>
    </tbody>
  </table>
</div>
<div class="specimen-info">
  <table>
    <tbody>
      <tr><th class="specimen-info-heading">Taxonomic Information</th></tr>
      <tr><td class="specimen-info-label">Phylum: </td><td><?php if (isset ($variables['taxonomy']['phylum'])):?><?php print $variables['taxonomy']['phylum'] ?></td></tr><?php endif; ?>
      <tr><td class="specimen-info-label">Subphylum: </td><td><?php if (isset ($variables['taxonomy']['subphylum'])):?><?php print $variables['taxonomy']['subphylum'] ?></td></tr><?php endif; ?>
      <tr><td class="specimen-info-label">Class: </td><td><?php if (isset ($variables['taxonomy']['class'])):?><?php print $variables['taxonomy']['class'] ?></td></tr><?php endif; ?>
      <tr><td class="specimen-info-label">Order: </td><td><?php if (isset ($variables['taxonomy']['order'])):?><?php print $variables['taxonomy']['order'] ?></td></tr><?php endif; ?>
      <tr><td class="specimen-info-label">Family: </td><td><?php if (isset ($variables['taxonomy']['family'])):?><?php print $variables['taxonomy']['family'] ?></td></tr><?php endif; ?>
      <tr><td class="specimen-info-label">Genus: </td><td><?php if (isset ($variables['taxonomy']['genus'])):?><?php print $variables['taxonomy']['genus'] ?></td></tr><?php endif; ?>
      <tr><td class="specimen-info-label">Species: </td><td><?php if (isset ($variables['taxonomy']['species'])):?><?php print $variables['taxonomy']['species'] ?></td></tr><?php endif; ?>
    </tbody>
  </table>
</div>
<div class="specimen-info">
  <table>
    <tbody>
      <tr><th class="specimen-info-heading">Geographic Information</th></tr>
      <tr><td class="specimen-info-label">Site Name: </td><td><?php if (isset ($variables['geography']['siteName'])):?><?php print $variables['geography']['siteName'] ?></td></tr><?php endif; ?>
      <tr><td class="specimen-info-label">Location: </td><td><?php if (isset ($variables['geography']['north'])):?><?php print $variables['geography']['north'] ?>N, <?php print $variables['geography']['west'] ?>W</td></tr><?php endif; ?>
      <tr><td class="specimen-info-label">Depth: </td><td><?php if (isset ($variables['geography']['depth'])):?><?php print $variables['geography']['depth'] ?> <?php print $variables['geography']['unit'] ?></td></tr><?php endif; ?>
      <tr><td class="specimen-info-label">Collection Date: </td><td><?php if (isset ($variables['temporal']['date'])):?><?php print $variables['temporal']['date'] ?></td></tr><?php endif; ?>
    </tbody>
  </table>
</div>
<div class="specimen-info">
    <table>
        <tbody>
          <tr><th class="specimen-info-heading">Methods</th></tr>
        </tbody>
    </table>
</div>
