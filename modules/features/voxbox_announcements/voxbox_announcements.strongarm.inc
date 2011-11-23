<?php

/**
 * Implementation of hook_strongarm().
 */
function voxbox_announcements_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_announcement';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '0',
    'revision_information' => '20',
    'author' => '20',
    'options' => '25',
    'menu' => '-2',
    'og_nodeapi' => '0',
  );
  $export['content_extra_weights_announcement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_announcement';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_announcement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_announcement';
  $strongarm->value = 'group_post_standard';
  $export['og_content_type_usage_announcement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_announcement';
  $strongarm->value = '';
  $export['og_max_groups_announcement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipnode_default_extension_status_announcement';
  $strongarm->value = '0';
  $export['voipnode_default_extension_status_announcement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipnode_default_script_name_announcement';
  $strongarm->value = 'voipnode_basic';
  $export['voipnode_default_script_name_announcement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipnode_use_announcement';
  $strongarm->value = 0;
  $export['voipnode_use_announcement'] = $strongarm;

  return $export;
}
