<?php

/**
 * @file
 *   Voxbox Organic Groups VoIP Scripts.
 */

/**
 * VoIP Script Callback: Organic group options.
 *
 * $param['nid'] = Node ID.
 */
function _voxbox_og_node_script($node) {
  $script = new VoipScript('voxbox_og');
  $script->addSet('voxbox_og_gid', $node->nid);

  $script->addLabel('begin');
  // if (member of group:
  $script->addSet('voxbox_og_member', '^og_is_group_member(%voxbox_og_gid, FALSE, %user_uid)');
  $script->addGotoIf('not_member', '^%voxbox_og_member == 0');
  // )
  // {
    $script->addLabel('member');
    // @todo we really need the logic of
    // og_men_access_unsubscribe() here.
    $script->addSet('voxbox_og_option_3', 'To stop following this Vox Box press 3.');
    // if (subscribed for notifications:
    $script->addSet('voxbox_og_subscribed', '^_voxbox_og_notifications_subscribed(%user_uid, %voxbox_og_gid)');
    $script->addGotoIf('not_subscribed', '^%voxbox_og_subscribed == 0');
    // )
    // {
      $script->addSet('voxbox_og_option_4', 'To stop receiving alerts of announcements, press 4.');
      $script->addGoto('title');
    // }
    // {
      $script->addLabel('not_subscribed');
      $script->addSet('voxbox_og_option_4', 'To receive SMS alerts of announcements, press 4.');
      $script->addGoto('title');
    // }
  // }
  // {
    $script->addLabel('not_member');
    $script->addSet('voxbox_og_option_3', 'To follow this Vox Box press, 3.');
    $script->addSet('voxbox_og_option_4', '');
  // }

  $script->addLabel('title');
  $script->addSay($node->title . '. ');
  $script->addLabel('intro');
  $text = t('To hear announcements press 1. To record an announcement press 2. %voxbox_og_option_3 %voxbox_og_option_4 To leave a message to the Vox Box administrators, press the star key. To return and select another Vox Box press the pound key.') . ' ';
  $script->addGetInput($text, 1, '', 6);
  $script->addGotoIf('not_recognised', "^%input_digits == ''");
  $script->addGotoIf('start_voicemail', "^%input_digits == '*'");
  $script->addGotoIf('play_announcements', "^%input_digits == '1'");
  $script->addGotoIf('record_announcement', "^%input_digits == '2'");
  $script->addGotoIf('join_group', "^%input_digits == '3' && %voxbox_og_member == 0");
  $script->addGotoIf('leave_group', "^%input_digits == '3' && %voxbox_og_member != 0");
  $script->addGotoIf('subscribe', "^%input_digits == '4' && %voxbox_og_member != 0 && %voxbox_og_subscribed == 0");
  $script->addGotoIf('unsubscribe', "^%input_digits == '4' && %voxbox_og_member != 0 && %voxbox_og_subscribed != 0");
  $script->addGotoIf('return', "^%input_digits == '#'");
  $script->addLabel('not_recognised');
  $script->addSay(t('Input not recognised'));
  $script->addGoto('intro');
  $script->addLabel('play_announcements');
  $params = array('view_name' => 'og_ghp_ron_voip', 'display_id' => 'voipviews_1', 'args' => json_encode(array($node->nid)));
  $script->addGosub('voipviews_read_view', $params);
  $script->addGoto('begin');

  $script->addLabel('start_voicemail');
  $script->addGosub('voicemail_node_basic', array('nid' => $node->nid));
  $script->addGoto('begin');

  $script->addLabel('record_announcement');
  $script->addGosub('voxbox_og_record_announcement', array('nid' => $node->nid));
  // @todo record script, just base on voicemail, but login first and save to
  // node... We need the call the script with the group id, that's it.
  $script->addGoto('begin');

  $script->addLabel('join_group');
  // Log in - with user creation (a 'gosub if' would make sense here).
  $script->addGosub('voipusernumber_autologin', array('number' => '%caller_number', 'create' => TRUE));
  $script->addGosub('voxbox_og_subscribe_user', array('gid' => $node->nid));
  $script->addGoto('begin');

  $script->addLabel('leave_group');
  $script->addGosub('voxbox_og_delete_subscription', array('gid' => $node->nid));
  $script->addGoto('begin');

  $script->addLabel('unsubscribe');
  $script->addGosub('voxbox_og_notifications_unsubscribe', array('gid' => $node->nid));
  $script->addGoto('begin');

  $script->addLabel('subscribe');
  $script->addGosub('voxbox_og_notifications_subscribe', array('gid' => $node->nid));
  $script->addGoto('begin');

  $script->addLabel('return');
  $script->addReturn();
  return $script;
}

/**
 * VoIP Script Callback: Record announcment node to group.
 *
 * $param['nid'] = Node ID.
 */
function _voxbox_og_record_announcement($node) {
  $script = new VoipScript('voxbox_og_record_announcement');
 
  $script->addGosub('voipusernumber_autologin', array('number' => '%caller_number', 'create' => TRUE));
  $script->addSet('og_group', $node->title);

  $script->addLabel('start_recording');
  $script->addRecord(
    'Start recording your message for %og_group after the tone. Press the pound key to stop recording.', 
    5, '#', 3600, 'mp3', TRUE
  );
  $script->addSay('You said %recording_public_url');
  
  $script->addLabel('accept menu');
  $script->addGetInput(
    'To accept this recording, press 1. To record it once again, press 2. To return, press the pound key.',
    5, '', 1
  );
  $script->addGotoIf('accept_recording', "^%input_digits == '1'");
  $script->addGotoIf('start_recording', "^%input_digits == '2'");
  $script->addGotoIf('end_record', "^%input_digits == '#'");
  $script->addSay(t('Invalid input received. Please try again.'));
  $script->addGoto('accept menu');

  $script->addLabel('accept_recording');
  $script->addGosub('voxbox_og_save_announcement', array('nid' => $node->nid, 'fid' => '%recording_fid'));

  $script->addLabel('end_record');
  $script->addReturn();

  return $script;
}

/**
 * VoIP Script Callback: Save announcment file to node.
 *
 * $param['nid'] = Group node ID.
 * $param['fid'] = File ID (%recording_fid).
 */
function _voxbox_og_save_announcement($nid, $fid) {
  global $user;
  $script = new VoipScript('voxbox_og_save_announcement');

  $node = new StdClass();
  $node->type = 'announcement';
  $node->status = 1;
  $node->title = ''; // autogenerated
  $node->uid = $user->uid; // required?
  $node->og_groups = array($nid => $nid);
  $field = content_fields('field_voipnode_adesc', 'announcement');
  $target_dir = filefield_widget_file_path($field, $user);
  $file = db_fetch_object(db_query('SELECT * FROM {files} WHERE fid = %d', $fid));
  if (! file_copy($file, $target_dir,  FILE_EXISTS_RENAME)) {
    watchdog('voxbox_og', 'Upload error. Could not move file %file to destination %destination.', array('%file' => $file->filename, '%destination' => $target_dir));
    $script->addSay('Error saving announcement.');
    return $script;
  }
  $file = (array) $file;
  $file['list'] = array();
  if ($field['list_field']) {
    $file['list'] = $field['list_default'];
  }
  $node->field_voipnode_adesc[0] = $file;
  
  node_save($node);

  $script->addSay('Announcement saved.');
  return $script; 
}

/**
 * VoIP Script Callback: Subscribe to notifications in a group.
 *
 * Log user in before calling this script. The notification subscription
 * type is the default for the user (or site if user default not
 * set/altered).
 *
 * @param int $gid
 *   Group ID.
 */
function _voxbox_og_notifications_subscribe($gid) {
  global $user;
  $script = new VoipScript('voxbox_og_notifications_subscribe');

  // Auto notifications subscription would do this.
  og_save_subscription($gid, $user->uid, array('is_active' => 1));
  $script->addSay('You are subscribed.');
  return $script;
}

/**
 * VoIP Script Callback: Unsubscribe to notifications in a group.
 *
 * Log user in before calling this script.
 *
 * @param int $gid
 *   Group ID.
 */
function _voxbox_og_notifications_unsubscribe($gid) {
  global $user;
  $script = new VoipScript('voxbox_og_notifications_unsubscribe');

  og_notifications_user_unsubscribe($user, $gid);
  $script->addSay('You have been unsubscribed.');
  return $script;
}

/**
 * VoIP Script Callback: Runs og_subscribe_user() for current user.
 *
 * @param int $gid
 *   Group ID.
 */
function _voxbox_og_subscribe_user($gid) {
  global $user;
  $script = new VoipScript('voxbox_og_subscribe_user');
  $result = og_subscribe_user($gid, $user);
  // Force reload of group memberships.
  $user->og_groups = og_get_subscriptions($user->uid, 1, TRUE);
  $script->addSay(strip_tags($result['message']));
  return $script;
}

/**
 * VoIP Script Callback: Runs og_delete_subscription() for current user.
 *
 * @param int $gid
 *   Group ID.
 */
function _voxbox_og_delete_subscription($gid) {
  global $user;
  $script = new VoipScript('voxbox_og_delete_subscription');
  og_delete_subscription($gid, $user->uid);
  // Force reload of group memberships.
  $user->og_groups = og_get_subscriptions($user->uid, 1, TRUE);
  $script->addSay('You are no longer following this Vox Box');
  return $script;
}

/**
 * Incoming SMS to group announcement script.
 *
 * @see _voxbox_og_record_sms_announcement().
 */
function _voxbox_og_record_sms_announcement_script() {
  $script = new VoipScript('voxbox_og_record_sms_announcement');
  // Log user in.
  $script->addGosub('voipusernumber_autologin', array('number' => '%caller_number'));
  // Parse contents.
  $script->addSet('request_result', '^_voxbox_og_record_sms_announcement(%inbound_text_contents)');
  $script->addLog('%request_result');
  // Send result.
  $script->addSendText('%request_result');
  $script->addHangup('reset');
  return $script;
}

/**
 * Helper to parse _voxbox_og_record_sms_announcement_script().
 */
function _voxbox_og_record_sms_announcement($text) {
  global $user;

  // The user should have been logged in by number.
  if (! $user->uid) {
    return t('Unknown user telephone number.');
  }

  // Completely empty SMS.
  $text = trim($text);
  if (empty($text)) {
    return t('Empty request received');
  }

  // Check for Extension.
  if (! preg_match('/^([0-9]*)(\s)*(.*)?$/', $text, $matches)) {
    return t('Send announcements with the voxbox extension number at the beginning of the SMS.');
  }
  // Match [extension][whitespace][body of message].
  $eid = $matches[1];
  $body = $matches[3];
  // Check for text in body.
  if (empty($body)) {
    return t('Include text for announcement after voxbox extension number.');
  }

  // Load extension.
  if (! $extension = voipextension_load($eid)) {
    return t('Unknown voxbox number @eid', array('@eid' => $eid));
  }
  // Load node
  if (! $extension['module'] == 'voipnode') {
    return t('Extension @eid is not a voxbox.', array('@eid' => $eid));
  }
  $group = node_load($extension['module_id']);
  // Check for voxbox type.
  if (! $group->type == 'voxbox') {
    return t('Extension @eid is not a voxbox.', array('@eid' => $eid));
  }

  // Access control.
  // @todo to be upgraded with beta3.
  if (! og_is_group_member($group->nid)) {
    return t('You are not a member of voxbox @title', array('@title' => $group->title));
  }
  
  // Construct, and save node.
  $node = new stdClass();
  $node->type = 'announcement';
  $node->status = 1;
  $node->title = $node->teaser = $node->body = $body;
  $node->format = FILTER_HTML_STRIP;
  $node->uid = $user->uid;
  $node->name = $user->name;
  $node->og_groups = array($group->nid => $group->nid);
  node_save($node);
  if ($node->nid) {
    return t('Announcement saved to @title', array('@title' => $group->title));
  }
  else {
    return t('Sorry there was an error saving your announcement to @title', array('@title' => $group->title));
  }
}




