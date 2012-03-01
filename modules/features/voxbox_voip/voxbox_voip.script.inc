<?php

/**
 * @file
 *   VoIP Scripts for basic Voxbox voip operation.
 */

/**
 * Incoming call script.
 *
 * Logs user in if they have an account connected with their number.
 * Checks for messages if they are logged in and offers menu to listen if
 * there are any.
 *
 * Gives extension menu.
 */
function _voxbox_voip_welcome() {
  $script = new VoipScript('voxbox_welcome');

  $script->addSay(t('Welcome to Vox Box. Main menu.'));
  // Log users in if they already have an account connected with the caller
  // number.
  $script->addGosub('voipusernumber_autologin', array('number' => '%caller_number'));

  $script->addLabel('begin_menu');
  $script->addSet('extension_prompt', variable_get('voipextension_prompt_msg', 'Please enter the desired Vox Box number, followed by the pound key.'));
  $script->addGotoIf('messages', '^%user_uid != 0');

  $script->addLabel('request_extension');
  $script->addGetInput('%extension_prompt', 5, '#', 3);
  $script->addGotoIf('no_input_received', "^%input_digits == ''");
  $script->addGotoIf('play_messages', "^%input_digits == '*'");
  $script->addGosub('voipextension_play_extension', array('eid' => '%input_digits'));
  $script->addGoto('begin_menu');

  // No input
  $script->addLabel('no_input_received');
  $script->addSay(variable_get('voipextension_noinput_msg', t('No input received. Please try again.')));
  $script->addGoto('request_extension');

  // @todo Give an option to hang up?
  $script->addSay(t('Goodbye'));
  $script->addGoto('end');

  // Check for messages and add option if available
  $script->addLabel('messages');
  $script->addGosub('messaging_voip_script_store_count');
  $script->addSet('extension_prompt',variable_get('voipextension_prompt_msg', 'Please enter the desired Vox Box number, followed by the pound key. To go to your personal area, dial the star key.'));
  $script->addGoto('request_extension');

  // Go to messaging script
  $script->addLabel('play_messages');
  $script->addGosub('voxbox_user_menu');
  $script->addGoto('begin_menu');

  $script->addLabel('end');
  return $script;
}
