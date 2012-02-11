<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function voxbox_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: Administer VoIP user numbers
  $permissions['Administer VoIP user numbers'] = array(
    'name' => 'Administer VoIP user numbers',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: Allow Reordering
  $permissions['Allow Reordering'] = array(
    'name' => 'Allow Reordering',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: Delete any voicemial
  $permissions['Delete any voicemial'] = array(
    'name' => 'Delete any voicemial',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: Delete own voicemail
  $permissions['Delete own voicemail'] = array(
    'name' => 'Delete own voicemail',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: Edit own VoIP user number
  $permissions['Edit own VoIP user number'] = array(
    'name' => 'Edit own VoIP user number',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: Have VoIP user number
  $permissions['Have VoIP user number'] = array(
    'name' => 'Have VoIP user number',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: Use PHP input for field settings (dangerous - grant with care)
  $permissions['Use PHP input for field settings (dangerous - grant with care)'] = array(
    'name' => 'Use PHP input for field settings (dangerous - grant with care)',
    'roles' => array(),
  );

  // Exported permission: access administration menu
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: access administration pages
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: access all views
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: access all voicemail mailboxes
  $permissions['access all voicemail mailboxes'] = array(
    'name' => 'access all voicemail mailboxes',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: access content
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: access site reports
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: access user profiles
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer actions
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer blocks
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer content types
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer features
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer files
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer filters
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer menu
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer nodes
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer organic groups
  $permissions['administer organic groups'] = array(
    'name' => 'administer organic groups',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'voxbox admin',
    ),
  );

  // Exported permission: administer permissions
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer site configuration
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer users
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer views
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer voicemail mailboxes
  $permissions['administer voicemail mailboxes'] = array(
    'name' => 'administer voicemail mailboxes',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer voip drupal framework
  $permissions['administer voip drupal framework'] = array(
    'name' => 'administer voip drupal framework',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer voipcall setup
  $permissions['administer voipcall setup'] = array(
    'name' => 'administer voipcall setup',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer voipnode settings
  $permissions['administer voipnode settings'] = array(
    'name' => 'administer voipnode settings',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: change own username
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: collapse format fieldset by default
  $permissions['collapse format fieldset by default'] = array(
    'name' => 'collapse format fieldset by default',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: collapsible format selection
  $permissions['collapsible format selection'] = array(
    'name' => 'collapsible format selection',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: create announcement content
  $permissions['create announcement content'] = array(
    'name' => 'create announcement content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: create voxbox content
  $permissions['create voxbox content'] = array(
    'name' => 'create voxbox content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
      '2' => 'voxbox admin',
    ),
  );

  // Exported permission: delete any announcement content
  $permissions['delete any announcement content'] = array(
    'name' => 'delete any announcement content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'voxbox admin',
    ),
  );

  // Exported permission: delete any voxbox content
  $permissions['delete any voxbox content'] = array(
    'name' => 'delete any voxbox content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'voxbox admin',
    ),
  );

  // Exported permission: delete own announcement content
  $permissions['delete own announcement content'] = array(
    'name' => 'delete own announcement content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: delete own voxbox content
  $permissions['delete own voxbox content'] = array(
    'name' => 'delete own voxbox content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: delete revisions
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: display drupal links
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: download all audio files
  $permissions['download all audio files'] = array(
    'name' => 'download all audio files',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: download own audio files
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit any announcement content
  $permissions['edit any announcement content'] = array(
    'name' => 'edit any announcement content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'voxbox admin',
    ),
  );

  // Exported permission: edit any voxbox content
  $permissions['edit any voxbox content'] = array(
    'name' => 'edit any voxbox content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'voxbox admin',
    ),
  );

  // Exported permission: edit own announcement content
  $permissions['edit own announcement content'] = array(
    'name' => 'edit own announcement content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: edit own voxbox content
  $permissions['edit own voxbox content'] = array(
    'name' => 'edit own voxbox content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: hangup any calls
  $permissions['hangup any calls'] = array(
    'name' => 'hangup any calls',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: hangup own calls
  $permissions['hangup own calls'] = array(
    'name' => 'hangup own calls',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: make outbound calls
  $permissions['make outbound calls'] = array(
    'name' => 'make outbound calls',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: manage features
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: revert revisions
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: select different theme
  $permissions['select different theme'] = array(
    'name' => 'select different theme',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: show format selection for blocks
  $permissions['show format selection for blocks'] = array(
    'name' => 'show format selection for blocks',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: show format selection for comments
  $permissions['show format selection for comments'] = array(
    'name' => 'show format selection for comments',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: show format selection for nodes
  $permissions['show format selection for nodes'] = array(
    'name' => 'show format selection for nodes',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: show format tips
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: show more format tips link
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: use PHP for block visibility
  $permissions['use PHP for block visibility'] = array(
    'name' => 'use PHP for block visibility',
    'roles' => array(),
  );

  // Exported permission: use default voip number
  $permissions['use default voip number'] = array(
    'name' => 'use default voip number',
    'roles' => array(),
  );

  // Exported permission: view revisions
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  return $permissions;
}
