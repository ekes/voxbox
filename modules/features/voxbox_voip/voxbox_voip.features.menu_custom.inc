<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function voxbox_voip_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: navigation
  $menus['navigation'] = array(
    'menu_name' => 'navigation',
    'title' => 'Navigation',
    'description' => 'The navigation menu is provided by Drupal and is the main interactive menu for any site. It is usually the only menu that contains personalized links for authenticated users, and is often not even visible to anonymous users.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Navigation');
  t('The navigation menu is provided by Drupal and is the main interactive menu for any site. It is usually the only menu that contains personalized links for authenticated users, and is often not even visible to anonymous users.');


  return $menus;
}
