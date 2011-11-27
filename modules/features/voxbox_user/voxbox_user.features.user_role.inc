<?php

/**
 * Implementation of hook_user_default_roles().
 */
function voxbox_user_user_default_roles() {
  $roles = array();

  // Exported role: site admin
  $roles['site admin'] = array(
    'name' => 'site admin',
  );

  // Exported role: voxbox admin
  $roles['voxbox admin'] = array(
    'name' => 'voxbox admin',
  );

  return $roles;
}
