<?php

function _voxbox_og_node_script($node) {
  $script = new VoipScript('voxbox_og');
  $script->addLabel('begin');
  $script->addSay($node->title);
  $params = array('view_name' => 'og_grp_ron_voip', 'view_display' => 'viewsvoip_1', 'args' => array($node->nid));
  $script->addGosub('voipviews_read_view', $params);
  return $script;
}
