<?php

/**
 * Implementation of hook_strongarm().
 */
function voxbox_voip_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'conditional_styles_zen_voxbox';
  $strongarm->value = '<!--[if IE]>
<link type="text/css" rel="stylesheet" media="all" href="/profiles/voxbox/themes/zen_voxbox/css/ie.css?v" />
<![endif]-->
<!--[if lte IE 6]>
<link type="text/css" rel="stylesheet" media="all" href="/profiles/voxbox/themes/zen_voxbox/css/ie6.css?v" />
<![endif]-->
';
  $export['conditional_styles_zen_voxbox'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'conditional_styles_zen_voxbox_rtl';
  $strongarm->value = '<!--[if IE]>
<link type="text/css" rel="stylesheet" media="all" href="/profiles/voxbox/themes/zen_voxbox/css/ie.css?v" />
<![endif]-->
<!--[if lte IE 6]>
<link type="text/css" rel="stylesheet" media="all" href="/profiles/voxbox/themes/zen_voxbox/css/ie6.css?v" />
<link type="text/css" rel="stylesheet" media="all" href="/profiles/voxbox/themes/zen_voxbox/css/ie6-rtl.css?v" />
<![endif]-->
';
  $export['conditional_styles_zen_voxbox_rtl'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_zen_voxbox_settings';
  $strongarm->value = array(
    'zen_block_editing' => 1,
    'zen_breadcrumb' => 'yes',
    'zen_breadcrumb_separator' => ' › ',
    'zen_breadcrumb_home' => 1,
    'zen_breadcrumb_trailing' => 1,
    'zen_breadcrumb_title' => 0,
    'zen_rebuild_registry' => 1,
    'zen_wireframes' => 0,
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 0,
    'toggle_mission' => 1,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 0,
    'toggle_search' => 0,
    'toggle_favicon' => 1,
    'toggle_primary_links' => 1,
    'toggle_secondary_links' => 1,
    'default_logo' => 1,
    'logo_path' => 'sites/default/files/logo.png',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
  );
  $export['theme_zen_voxbox_settings'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipcall_default_session_time';
  $strongarm->value = '0';
  $export['voipcall_default_session_time'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipcall_inbound_call_script_name';
  $strongarm->value = 'voxbox_welcome';
  $export['voipcall_inbound_call_script_name'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipcall_inbound_text_script_name';
  $strongarm->value = 'voxbox_og_record_sms_announcement';
  $export['voipcall_inbound_text_script_name'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipcall_outbound_call_script_name';
  $strongarm->value = 'voipcall_default_outbound_call_script';
  $export['voipcall_outbound_call_script_name'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipcall_use_sms_framework';
  $strongarm->value = 0;
  $export['voipcall_use_sms_framework'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipextension_prompt_msg';
  $strongarm->value = 'Please enter the desired Vox Box number, followed by #.';
  $export['voipextension_prompt_msg'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipextension_transferring_msg';
  $strongarm->value = 'Transferring to Vox Box %number.';
  $export['voipextension_transferring_msg'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipextension_unknown_msg';
  $strongarm->value = 'Sorry unknown Vox Box %number.';
  $export['voipextension_unknown_msg'] = $strongarm;

  return $export;
}
