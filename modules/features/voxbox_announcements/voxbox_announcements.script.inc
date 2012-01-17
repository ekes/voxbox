<?php

/**
 * @file
 *   voipscripts for voxbox announcements content type.
 */
function _voxbox_announcements_node_script($node) {
  $script = new VoipScript('voxbox_announcement');
  $script->addLabel('begin');
  if (!empty($node->field_voipnode_adesc[0]['fid'])) {
    $script->addSay(url($node->field_voipnode_adesc[0]['filepath']));
  }
  else {
    $script->addSay($node->body);
  }

  $script->addLabel('options');
  $script->addBeep();
  $script->addRunIvrMenu(t('To hear the announcement again, dial 1. To return to the previous menu press the # key.'), array(1 => 'begin', '#' => 'return'));
  $script->addGoto('%ivr_option_selected');
  $script->addLabel('no_input_received');
  $script->addSay('Selection not recognized.');
  $script->addGoto('options');

  $script->addLabel('return');
  $script->addReturn();
 
  return $script;
}

/**
 * @file
 *   voipscripts for voxbox announcements content type.
 */
function _voxbox_announcements_node_detail_script($node) {
  $script = new VoipScript('voxbox_announcement_detail');
  $script->setVar('user', $node->name);
  $script->setVar('created', format_date($node->created, 'custom', 'F, jS \a\t g:i a')); 
  $script->addSay('This announcement was made by %user, on %created.');
  return $script;
}
