<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function voxbox_og_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_voipnode_settings
  $groups['voxbox-group_voipnode_settings'] = array(
    'group_type' => 'standard',
    'type_name' => 'voxbox',
    'group_name' => 'group_voipnode_settings',
    'label' => 'VoIP Extension Settings',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsible',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '7',
    'fields' => array(
      '0' => 'field_voipnode_aname',
      '1' => 'field_voipnode_adesc',
      '2' => 'field_voipnode_agreet',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('VoIP Extension Settings');

  return $groups;
}
