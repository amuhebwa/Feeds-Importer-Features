<?php
/**
 * @file
 * devtrac_locations_importer_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function devtrac_locations_importer_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
