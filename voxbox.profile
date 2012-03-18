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
    'menu', 'dblog', 'help',
    /* other contrib */
    'install_profile_api', 'autoload',
    'content', 'number', 'filefield', 'optionwidgets', 'text', 'fieldgroup', 'audiofield',
    'views', 'views_ui', 'draggableviews', 'og', 'og_views', 'ctools', 'strongarm', 'features', 'token', 'transliteration', 'auto_nodetitle',
    'admin_menu', 'wysiwyg', 'better_formats', 'vertical_tabs',
    'voip', 'voipnode', 'voipextension', 'voipcall', 'voiptropo', 'voiptwilio', 'voipviews', 'voipscriptstore', 'voicemail', 'voicemail_node', 'voipusernumber', 'voipnumber',
    'messaging', 'messaging_simple', 'messaging_voip', 'notifications_content', 'notifications', 'notifications_autosubscribe', 'notifications_lite', 'notifications_ui', 'notifications_views',
  );
}

/**
 * Implementation of hook_profile_task_list().
 */
function voxbox_profile_task_list() {
  $tasks = array();
  $tasks['install-voxbox'] = st('Install Voxbox');
  return $tasks;
}


/**
* Implementation of hook_profile_tasks().
*/
function voxbox_profile_tasks(&$task, $url) {
  // Install the core required modules and our extra modules
  $core_required = array('block', 'filter', 'node', 'system', 'user');
  install_include(array_merge(voxbox_profile_modules(), $core_required));

  // Overkill in preparation for a more interactive install option.
  if ($task == 'profile') { $task = 'install-voxbox'; }

  switch ($task) {
    case 'install-voxbox':
      return voxbox_profile_install_voxbox($url);
  }
}

/**
 * Return default array of features to install.
 */
function voxbox_profile_default_features() {
  return array(
    'voxbox_og', 'voxbox_announcements', 'voxbox_voip', 'voxbox_user', 'voxbox_notifications',
  );
}

/**
 * Install profile task: install-voxbox
 */
function voxbox_profile_install_voxbox($url) {
  variable_set('install_profile', 'voxbox');
  // install features - could override list with form options 
  features_install_modules(voxbox_profile_default_features());

  // themes
  install_enable_theme('tao');
  install_admin_theme('rubik');
  install_enable_theme('zen');
  install_enable_theme('zen_voxbox');
  install_default_theme('zen_voxbox');

  // Put the navigation block in the sidebar because the sidebar looks awesome.
  install_init_blocks();
  // add og group admin block
  install_set_block('og', 0, 'zen_voxbox', 'sidebar', -10);
  // default number block
  install_set_block('voxbox_voip', 'phone_number', 'zen_voxbox', 'header', 0);

  // call rebuild - this makes the cck fields 'associate' to their node types properly
  features_rebuild();
 
  // switch off og views that are overriden.
  $status = variable_get('views_defaults', array());
  $status['og'] = TRUE;
  $status['og_unread'] = TRUE;
  $status['og_my'] = TRUE;
  variable_set('views_defaults', $status);

  // Default variables that don't want to strongarmed.
  variable_set('site_mission', st('VoxBox provides voice-based bulletin boards for grassroots organizations such as PTAs, churches, local sports teams and informal groups.'));
  variable_set('site_frontpage', 'og');
  variable_set('locale_custom_strings_en', array(
    'A brief description for the group details block and the group directory.' => 'A brief description for the VoxBox details block and the VoxBox directory.',
    'Should this group appear on the <a href="@url">list of groups page</a> (requires OG Views module)? Disabled if the group is set to <em>private group</em>.' => 'Should this group appear on the <a href="@url">list of Voxboxes page</a>? Disabled if the Voxbox is set to <em>private Voxbox</em>.',
    'How should membership requests be handled in this group? When you select <em>closed</em>, users will not be able to join <strong>or</strong> leave.' => 'How should membership requests be handled in this VoxBox? When you select <em>closed</em>, users will not be able to join <strong>or</strong> leave.',
    'You may not leave this group because you are its owner. A site administrator can assign ownership to another user and then you may leave.' => 'You may not leave this VoxBox because you are its owner. A site administrator can assign ownership to another user and then you may leave.',
    'List in groups directory' => 'List in VoxBox directory',
    'Group' => 'VoxBox',
    'Groups' => 'VoxBoxes',
    'My groups' => 'My VoxBoxes',
    'Group activity' => 'VoxBox activity',
    // Next two are in og_views:
    'Unread posts in my groups' => 'Unread posts in my VoxBoxes',
    'There are no new posts in your groups.' => 'There are no new posts in your VoxBoxes.',
  ));

  // strongarm doesn't seem to reset all variables so
  // we'll force it manually just in case.
  // Code from strongarm.drush.inc
  $vars = strongarm_vars_load(TRUE, TRUE);
  foreach ($vars as $name => $var) {
    if ($force || isset($var->in_code_only)) {
      if (!isset($conf[$name]) || $var->value != $conf[$name]) {
        variable_set($name, $var->value);
      }
    }
  }

  // needed to make autoload reindex
  module_invoke('autoload', 'flush_caches');
}
