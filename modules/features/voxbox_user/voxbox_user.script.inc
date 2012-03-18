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
  $script->addSay(v('Personal area menu'));
  $prompt = v('To check your announcements, press 1. To hear the list of voxboxes that you are subscribed to, press 2. To go back to the main menu, press the pound key.');
  $script->addGetInput($prompt, 1, '*', 3);
  $script->addGotoIf('no_input_received', "^%input_digits == ''");
  $script->addGotoIf('play_messages', "^%input_digits == '1'");
  $script->addGotoIf('groups_list', "^%input_digits == '2'");
  $script->addGotoIf('end', "^%input_digits == '#'");
  $script->addGoto('begin_menu');

  // No input
  $script->addLabel('no_input_received');
  $script->addSay(variable_get('voipextension_noinput_msg', v('No input received. Please try again.')));
  $script->addGoto('begin_menu');


  // Read out groups list
  $script->addLabel('groups_list');
  $view = views_get_view('og_my_voxbox');
  $view->set_display('block_2');
  $view->pre_execute();
  $prompt = $view->display_handler->preview();
  $prompt = trim(str_replace("\n", " ", strip_tags($prompt)));
  $script->addSay(v("To go to a VoxBox dial the extension number followed by the pound key. Or press the star key to go back."));
  // Get extension.
  $script->addLabel('request_extension');
  $script->addGetInput($prompt, 5, '#', 3);
  $script->addGotoIf('begin_menu', "^%input_digits == ''");
  $script->addGotoIf('begin_menu', "^%input_digits == '*'");
  $script->addGosub('voipextension_play_extension', array('eid' => '%input_digits'));
  $script->addGoto('groups_list');

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
