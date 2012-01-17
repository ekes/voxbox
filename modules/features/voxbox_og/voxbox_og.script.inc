<?php

function _voxbox_og_node_script($node) {
  $script = new VoipScript('voxbox_og');
  $script->addLabel('begin');
  if (!empty($node->field_voipnode_aname[0]['fid'])) {
    $script->addSay(url($node->field_voipnode_aname[0]['filepath']));
  }
  else {
    $script->addSay($node->title . '. ');
  }

  $script->addLabel('intro');
  if (!empty($node->field_voipnode_agreet[0]['fid'])) {
    $script->addSay(url($node->field_voipnode_agreet[0]['filepath']));
  }

  $script->addLabel('options');
  $script->addRunIvrMenu(t('To listen to current announcements, dial 1. To record a message to the administrators, dial 2. To go back to the main menu, press the pound key.'), array(1 => 'announcements', '2' => 'voicemail', '#' => 'return'));
  $script->addGoto('%ivr_option_selected');
  $script->addLabel('no_input_received');
  $script->addSay('Selection not recognized.');
  $script->addGoto('options');

  $script->addLabel('voicemail');
  $script->addGosub('voicemail_node_basic', array('nid' => $node->nid));
  $script->addGoto('options');

  $script->addLabel('announcements');
  $params = array('view_name' => 'og_ghp_ron_voip', 'display_id' => 'voipviews_1', 'args' => json_encode(array($node->nid)));
  $script->addGosub('voipviews_read_view', $params);
  $script->addGoto('options');

  $script->addLabel('return');
  $script->addReturn();

  return $script;
}
