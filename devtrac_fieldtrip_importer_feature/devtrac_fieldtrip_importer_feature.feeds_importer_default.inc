<?php
/**
 * @file
 * devtrac_fieldtrip_importer_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function devtrac_fieldtrip_importer_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'devtrac_fieldtrip_importer';
  $feeds_importer->config = array(
    'name' => 'Devtrac FieldTrip Importer',
    'description' => 'Imports field trips into a devtrac instance',
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
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Internal IDentity',
            'target' => 'field_fieldtrip_internal_id',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Tags',
            'target' => 'field_fieldtriptags',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          4 => array(
            'source' => 'Start Date',
            'target' => 'field_fieldtrip_start_end_date:start',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'End Date',
            'target' => 'field_fieldtrip_start_end_date:end',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'User',
            'target' => 'field_fieldtrip_user:label',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Admin Units',
            'target' => 'taxonomy_vocabulary_6',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Public Summary',
            'target' => 'field_fieldtrip_public_summary',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Approval Date',
            'target' => 'field_fieldtrip_approval_date:start',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Approved By',
            'target' => 'field_fieldtrip_approved_by:label',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Status',
            'target' => 'field_fieldtrip_status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'fieldtrip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  $export['devtrac_fieldtrip_importer'] = $feeds_importer;

  return $export;
}
