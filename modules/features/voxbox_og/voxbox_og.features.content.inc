<?php

/**
 * Implementation of hook_content_default_fields().
 */
function voxbox_og_content_default_fields() {
  $fields = array();

  // Exported field: field_voicemail_greeting
  $fields['voxbox-field_voicemail_greeting'] = array(
    'field_name' => 'field_voicemail_greeting',
    'type_name' => 'voxbox',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3 wav',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Voicemail greeting',
      'weight' => '15',
      'description' => '',
      'type' => 'audiorecorderfield_widget',
      'module' => 'audiorecorderfield',
    ),
  );

  // Exported field: field_voipnode_adesc
  $fields['voxbox-field_voipnode_adesc'] = array(
    'field_name' => 'field_voipnode_adesc',
    'type_name' => 'voxbox',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3 wav',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Audio Description',
      'weight' => '9',
      'description' => '',
      'type' => 'audiorecorderfield_widget',
      'module' => 'audiorecorderfield',
    ),
  );

  // Exported field: field_voipnode_agreet
  $fields['voxbox-field_voipnode_agreet'] = array(
    'field_name' => 'field_voipnode_agreet',
    'type_name' => 'voxbox',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3 wav',
      'file_path' => NULL,
      'progress_indicator' => NULL,
      'max_filesize_per_file' => NULL,
      'max_filesize_per_node' => NULL,
      'label' => 'Audio Greeting',
      'weight' => '10',
      'description' => '',
      'type' => 'audiorecorderfield_widget',
      'module' => 'audiorecorderfield',
    ),
  );

  // Exported field: field_voipnode_aname
  $fields['voxbox-field_voipnode_aname'] = array(
    'field_name' => 'field_voipnode_aname',
    'type_name' => 'voxbox',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3 wav',
      'file_path' => NULL,
      'progress_indicator' => NULL,
      'max_filesize_per_file' => NULL,
      'max_filesize_per_node' => NULL,
      'label' => 'Audio Name',
      'weight' => '8',
      'description' => '',
      'type' => 'audiorecorderfield_widget',
      'module' => 'audiorecorderfield',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Audio Description');
  t('Audio Greeting');
  t('Audio Name');
  t('Voicemail greeting');

  return $fields;
}
