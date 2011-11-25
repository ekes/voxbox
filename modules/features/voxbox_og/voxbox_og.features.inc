<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function voxbox_og_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function voxbox_og_node_info() {
  $items = array(
    'voxbox' => array(
      'name' => t('Voxbox'),
      'module' => 'features',
      'description' => t('Group, with an extension number, that can contain announcements that will be read out.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function voxbox_og_views_api() {
  return array(
    'api' => '2',
  );
}
