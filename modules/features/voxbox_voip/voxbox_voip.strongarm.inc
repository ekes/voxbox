<?php

/**
 * Implementation of hook_strongarm().
 */
function voxbox_voip_strongarm() {
  $export = array();

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
