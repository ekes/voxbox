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
  $strongarm->value = 'voipextension_basic_menu';
  $export['voipcall_inbound_call_script_name'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipcall_inbound_text_script_name';
  $strongarm->value = 'voipcall_default_inbound_text_script';
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

  return $export;
}
