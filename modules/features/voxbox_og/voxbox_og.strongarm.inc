<?php

/**
 * Implementation of hook_strongarm().
 */
function voxbox_og_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'audiofield_audioplayer_wav';
  $strongarm->value = 'nanogong';
  $export['audiofield_audioplayer_wav'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'audiofield_audiorecorder';
  $strongarm->value = 'soundcloud';
  $export['audiofield_audiorecorder'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'audiofield_players_dir';
  $strongarm->value = 'profiles/voxbox/libraries/audio-players';
  $export['audiofield_players_dir'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_voxbox';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '20',
    'author' => '20',
    'options' => '25',
    'menu' => '-2',
    'og_description' => '-4',
    'og_selective' => '0',
    'og_register' => '0',
    'og_directory' => '0',
  );
  $export['content_extra_weights_voxbox'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_voxbox';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_voxbox'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_audience_checkboxes';
  $strongarm->value = 1;
  $export['og_audience_checkboxes'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_audience_required';
  $strongarm->value = '1';
  $export['og_audience_required'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_voxbox';
  $strongarm->value = 'group';
  $export['og_content_type_usage_voxbox'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_home_page_view';
  $strongarm->value = 'og_ghp_ron_voip';
  $export['og_home_page_view'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_voxbox';
  $strongarm->value = '';
  $export['og_max_groups_voxbox'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voicemail_node_default_status_voxbox';
  $strongarm->value = '1';
  $export['voicemail_node_default_status_voxbox'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voicemail_node_use_voxbox';
  $strongarm->value = 1;
  $export['voicemail_node_use_voxbox'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipnode_default_extension_status_voxbox';
  $strongarm->value = '1';
  $export['voipnode_default_extension_status_voxbox'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipnode_default_script_name_voxbox';
  $strongarm->value = 'voxbox_og_node_script';
  $export['voipnode_default_script_name_voxbox'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipnode_use_voxbox';
  $strongarm->value = 1;
  $export['voipnode_use_voxbox'] = $strongarm;

  return $export;
}
