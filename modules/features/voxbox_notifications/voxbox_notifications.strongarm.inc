<?php

/**
 * Implementation of hook_strongarm().
 */
function voxbox_notifications_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_default_filter';
  $strongarm->value = '3';
  $export['messaging_default_filter'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_default_method';
  $strongarm->value = 'voip_sms';
  $export['messaging_default_method'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_sender_mail';
  $strongarm->value = '[mail]';
  $export['messaging_sender_mail'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_sender_name';
  $strongarm->value = '[user]';
  $export['messaging_sender_name'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_content_per_type';
  $strongarm->value = '0';
  $export['notifications_content_per_type'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_content_type';
  $strongarm->value = array(
    'grouptype' => 'grouptype',
    'thread' => 0,
    'nodetype' => 0,
    'author' => 0,
    'typeauthor' => 0,
  );
  $export['notifications_content_type'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_sender';
  $strongarm->value = '0';
  $export['notifications_sender'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_ui_account_options';
  $strongarm->value = array(
    'links' => 'links',
    'block' => 'block',
  );
  $export['notifications_ui_account_options'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_ui_node';
  $strongarm->value = array(
    'links' => 'links',
    'teaserlinks' => 'teaserlinks',
    'block' => 'block',
    'form' => 0,
    'comment' => 0,
    'subform' => 0,
  );
  $export['notifications_ui_node'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_ui_per_type';
  $strongarm->value = '1';
  $export['notifications_ui_per_type'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_ui_types';
  $strongarm->value = array(
    'grouptype' => 'grouptype',
    'thread' => 0,
    'nodetype' => 0,
    'author' => 0,
    'typeauthor' => 0,
  );
  $export['notifications_ui_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_ui_user';
  $strongarm->value = array(
    'page' => 'page',
    'create' => 'create',
  );
  $export['notifications_ui_user'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_notifications_content_types';
  $strongarm->value = array(
    'announcement' => 'announcement',
  );
  $export['og_notifications_content_types'] = $strongarm;

  return $export;
}
