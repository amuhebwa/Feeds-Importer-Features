<?php
/**
 * @file
 * devtrac_action_items_importer_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function devtrac_action_items_importer_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'devtrac7_action_items_importer';
  $feeds_importer->config = array(
    'name' => 'Devtrac Action Items Importer',
    'description' => 'Imports Action Items into a devtrac Instance',
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
            'source' => 'Admin Unit',
            'target' => 'taxonomy_vocabulary_6',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Sector',
            'target' => 'taxonomy_vocabulary_8',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Status',
            'target' => 'field_actionitem_status',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Due Date',
            'target' => 'field_actionitem_due_date:start',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Follow-up Task',
            'target' => 'field_actionitem_followuptask',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Report',
            'target' => 'field_actionitem_ftreportitem:label',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Responsible',
            'target' => 'field_actionitem_responsible:label',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Location UUID',
            'target' => 'field_actionitem_resp_place:label',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'actionitem',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  $export['devtrac7_action_items_importer'] = $feeds_importer;

  return $export;
}
