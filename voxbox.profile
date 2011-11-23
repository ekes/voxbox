<?php

/**
* Return a description of the profile for the initial installation screen.
*
* @return
* An array with keys 'name' and 'description' describing this profile.
*/
function voxbox_profile_details() {
  return array(
    'name' => 'Voxbox',
    'description' => 'Select this profile to deploy a voxbox site.'
  );
}

/**
* Return an array of the modules to be enabled when this profile is installed.
*
* @return
* An array of modules to be enabled.
*/
function voxbox_profile_modules() {
  return array(
    /* optional core */
    'menu', 'dblog', 'help', 'taxonomy',
    /* other contrib */
    'install_profile_api',
    'content', 'number', 'filefield', 'optionwidgets', 'text', 'fieldgroup',
    'views', 'views_ui', 'og', 'ctools', 'strongarm', 'features', 'token', 'transliteration', 
    'admin_menu', 'wysiwyg', 'better_formats',
    'voip', 'voipnode', 'voipextension', 'voipcall', 'voiptropo', 'voiptwilio',
  );
}

/**
* Implementation of hook_profile_tasks().
*/
function voxbox_profile_tasks(&$task, $url) {
  // just doing profile for now...
  install_enable_theme("tao");

  // Enable default theme - this will be subtheme
  install_default_theme("omega");

  // Put the navigation block in the sidebar because the sidebar looks awesome.
  install_init_blocks();

  // call rebuild - this makes the cck fields 'associate' to their node types properly
  features_rebuild();
}
