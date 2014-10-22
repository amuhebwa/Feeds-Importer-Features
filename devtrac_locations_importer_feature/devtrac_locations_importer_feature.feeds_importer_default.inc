<?php
/**
 * @file
 * devtrac_locations_importer_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function devtrac_locations_importer_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'devtrac_locations_importer';
  $feeds_importer->config = array(
    'name' => 'Devtrac Locations Importer',
    'description' => 'Imports Location information into a devtrac instance',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'csv',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'UUID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Admin Unit',
            'target' => 'taxonomy_vocabulary_6',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          2 => array(
            'source' => 'Lat',
            'target' => 'field_place_lat_long:lat',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Lon',
            'target' => 'field_place_lat_long:lon',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Location Types',
            'target' => 'taxonomy_vocabulary_1',
            'term_search' => '0',
            'autocreate' => 1,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'place',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  $export['devtrac_locations_importer'] = $feeds_importer;

  return $export;
}
