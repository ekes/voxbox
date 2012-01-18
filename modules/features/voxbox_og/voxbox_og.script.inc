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
  if (!empty($node->field_voipnode_agreet[0]['fid'])) {
    $script->addSay(url($node->field_voipnode_agreet[0]['filepath']));
  }
  $script->addGoto('options');

  $script->addLabel('menu');
  if (!empty($node->field_voipnode_aname[0]['fid'])) {
    $script->addSay(url($node->field_voipnode_aname[0]['filepath']));
  }
  else {
    $script->addSay($node->title . '. ');
  }

  $script->addLabel('options');
  if (empty($node->field_voipnode_adesc[0]['fid'])) {
    $script->addRunIvrMenu(t('To listen to current announcements, dial 1. To record a message to the administrators, dial 2. To go back to the main menu, press the pound key.'), array(1 => 'announcements', '2' => 'voicemail', '#' => 'return'));
  }
  else {
    $script->addRunIvrMenu(t('To listen to current announcements, dial 1. To record a message to the administrators, dial 2. To learn more about this voxbox, dial 3. To go back to the main menu, press the pound key.'), array(1 => 'announcements', '2' => 'voicemail', '3' => 'description', '#' => 'return'));
  }
  $script->addGoto('%ivr_option_selected');
  $script->addLabel('no_input_received');
  $script->addSay('Selection not recognized.');
  $script->addGoto('options');

  $script->addLabel('voicemail');
  $script->addGosub('voicemail_node_basic', array('nid' => $node->nid));
  $script->addGoto('menu');

  $script->addLabel('announcements');
  $params = array('view_name' => 'og_ghp_ron_voip', 'display_id' => 'voipviews_1', 'args' => json_encode(array($node->nid)));
  $script->addGosub('voipviews_read_view', $params);
  $script->addGoto('menu');

  $script->addLabel('description');
  $script->addSay(url($node->field_voipnode_adesc[0]['filepath']));
  $script->addGoto('menu');

  $script->addLabel('return');
  $script->addReturn();

  return $script;
}
