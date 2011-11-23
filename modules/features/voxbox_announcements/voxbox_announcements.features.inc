<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function voxbox_announcements_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function voxbox_announcements_node_info() {
  $items = array(
    'announcement' => array(
      'name' => t('Announcement'),
      'module' => 'features',
      'description' => t('Text, or audio, to be read out on a Voxbox.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Text description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
