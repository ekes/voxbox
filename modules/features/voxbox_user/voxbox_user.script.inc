<?php

/**
 * @file
 *   VoIP Scripts for basic logged in user..
 */

/**
 * Personal menu.
 */
function _voxbox_user_menu() {
  $script = new VoipScript('voxbox_User_menu');

  $script->addLabel('begin_menu');
  $prompt = v('To check your voxbox announcements press the star key. To hear a list of vox boxes you follow, their extensions and if there are new messages dial zero followed by the pound key. To go to a vox box dial its extension followed by the pound key.');
  $script->addGetInput($prompt, 5, '#', 3);
  $script->addGotoIf('no_input_received', "^%input_digits == ''");
  $script->addGotoIf('groups_list', "^%input_digits == '0'");
  $script->addGotoIf('play_messages', "^%input_digits == '*'");
  $script->addGosub('voipextension_play_extension', array('eid' => '%input_digits'));
  $script->addGoto('begin_menu');

  // No input
  $script->addLabel('no_input_received');
  $script->addSay(variable_get('voipextension_noinput_msg', t('No input received. Please try again.')));
  $script->addGoto('request_extension');

  // Get extension.
  $script->addLabel('request_extension');
  $script->addGetInput('%extension_prompt', 5, '#', 3);
  $script->addGotoIf('no_input_received', "^%input_digits == ''");
  $script->addGotoIf('play_messages', "^%input_digits == '*'");
  $script->addGosub('voipextension_play_extension', array('eid' => '%input_digits'));
  $script->addGoto('begin_menu');

  // Read out groups list
  $script->addLabel('groups_list');
  $params = array(
    'view_name' => 'og_my_voxbox',
    'display_id' => 'voipviews_1',
  );
  $script->addGosub('voipviews_read_view', $params);
  $script->addGoto('begin_menu');

  // Go to messaging script
  $script->addLabel('play_messages');
  $params = array(
    'view_name' => 'og_voxbox_unread',
    'display_id' => 'voipviews_1',
  );
  $script->addGosub('voipviews_read_view', $params);
  $script->addGoto('begin_menu');

  $script->addLabel('end');
  return $script;
} 
