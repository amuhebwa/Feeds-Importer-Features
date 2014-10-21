<?php
/**
 * @file
 * devtrac_users_importer_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function devtrac_users_importer_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'devtrac_users_importer';
  $feeds_importer->config = array(
    'name' => 'Devtrac Users Importer',
    'description' => 'Imports a list of users into a devtrac instance',
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
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          5 => '5',
          3 => 0,
          4 => 0,
          6 => 0,
          7 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'UUID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Username',
            'target' => 'name',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'First Name',
            'target' => 'field_user_firstname',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Surname',
            'target' => 'field_user_surname',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Email',
            'target' => 'mail',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Function',
            'target' => 'taxonomy_vocabulary_5',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          6 => array(
            'source' => 'Manager',
            'target' => 'field_user_superior:label',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Department',
            'target' => 'taxonomy_vocabulary_4',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          8 => array(
            'source' => 'About Me',
            'target' => 'field_user_aboutme',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Password',
            'target' => 'pass',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  $export['devtrac_users_importer'] = $feeds_importer;

  return $export;
}
