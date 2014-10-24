<?php
/**
 * @file
 * devtrac_site_report_importer_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function devtrac_site_report_importer_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'devtrac7_site_report_importer';
  $feeds_importer->config = array(
    'name' => 'Devtrac7 Site Report Importer',
    'description' => 'Imports site report data into a devtrac instance',
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
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Sector',
            'target' => 'taxonomy_vocabulary_8',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          3 => array(
            'source' => 'Status',
            'target' => 'field_ftritem_status',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Public Summary',
            'target' => 'field_ftritem_public_summary',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Full Report',
            'target' => 'field_ftritem_narrative',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Location Type',
            'target' => 'taxonomy_vocabulary_1',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          7 => array(
            'source' => 'Site Report Type',
            'target' => 'taxonomy_vocabulary_7',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          8 => array(
            'source' => 'Field Trip',
            'target' => 'entityreference:field_ftritem_field_trip',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Site Visit Lat',
            'target' => 'field_ftritem_lat_long:lat',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Site Visit Lon',
            'target' => 'field_ftritem_lat_long:lon',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Visited on',
            'target' => 'field_ftritem_date_visited:start',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'ftritem',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  $export['devtrac7_site_report_importer'] = $feeds_importer;

  return $export;
}
