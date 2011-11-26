<?php

/**
 * @file
 *   voipscripts for voxbox announcements content type.
 */
function _voxbox_announcements_node_script($node) {
  $script = new VoipScript('voxbox_announcement');
  $script->addLabel('begin');
  $script->addSay($node->title);
  $script->addSay($node->body);
  if (!empty($script->field_voipnode_adesc[0]['fid'])) {
  }

  $script->addLabel('options');
  $script->addBeep();
  $script->addRunIvrMenu(t('To hear the announcement again, dial 1. To return to the previous menu press the # key.'), array(1 => 'begin', '#' => 'return'));
  $script->addGoto('%ivr_option_selected');
  $script->addLabel('no_input_received');
  $script->addSay('Selection not recognized.');
  $script->addGoto('options');
 
  return $script;
}
