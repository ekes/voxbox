<?php

function _voxbox_og_node_script($node) {
  $script = new VoipScript('voxbox_og');
  $script->addLabel('begin');
  $script->addSay($node->title . '. ');
  $script->addLabel('intro');
  $text = t('To leave a message press the star key.') . ' ';
  $text .= t('Announcements will follow.') . ' ';
  $script->addGetInput($text, 1, '', 1);
  $script->addGotoIf('start_voicemail', "^%input_digits == '*'");
  $params = array('view_name' => 'og_ghp_ron_voip', 'display_id' => 'voipviews_1', 'args' => json_encode(array($node->nid)));
  $script->addGosub('voipviews_read_view', $params);
  $script->addReturn();

  $script->addLabel('start_voicemail');
  $script->addGosub('voicemail_node_basic', array('nid' => $node->nid));
  $script->addGoto('begin');

  return $script;
}
