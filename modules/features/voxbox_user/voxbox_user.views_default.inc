<?php

/**
 * Implementation of hook_views_default_views().
 */
function voxbox_user_views_default_views() {
  $views = array();

  // Exported view: og_my_voxbox
  $view = new view;
  $view->name = 'og_my_voxbox';
  $view->description = 'List user\'s subscribed groups and provide link to manage subscription';
  $view->tag = 'og';
  $view->base_table = 'node';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'voipnode' => array(
      'id' => 'voipnode',
      'table' => 'node',
      'field' => 'voipnode',
    ),
  ));
  $handler->override_option('fields', array(
    'title' => array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'label' => 'Group',
      'relationship' => 'none',
      'link_to_node' => 1,
    ),
    'name' => array(
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'label' => 'Manager',
      'link_to_user' => 1,
      'relationship' => 'none',
    ),
    'managelinkmy' => array(
      'label' => 'Manage',
      'exclude' => 0,
      'id' => 'managelinkmy',
      'table' => 'og_uid',
      'field' => 'managelinkmy',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'title' => array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'operator' => '=',
      'value' => 1,
      'group' => 0,
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'relationship' => 'none',
      'expose_button' => array(
        'button' => 'Expose',
      ),
    ),
    'type_groups_all' => array(
      'id' => 'type_groups_all',
      'table' => 'og',
      'field' => 'type_groups_all',
      'operator' => '=',
      'value' => '',
      'group' => 0,
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'relationship' => 'none',
      'expose_button' => array(
        'button' => 'Expose',
      ),
    ),
    'uid' => array(
      'operator' => '=',
      'value' => '1',
      'group' => 0,
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'uid',
      'table' => 'og_uid',
      'field' => 'uid',
      'relationship' => 'none',
      'expose_button' => array(
        'button' => 'Expose',
      ),
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      2 => 2,
      1 => 0,
    ),
    'perm' => 'view advanced help topic',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'My VoxBoxes');
  $handler->override_option('header', 'Groups you are a member of.');
  $handler->override_option('header_empty', 0);
  $handler->override_option('empty', 'You are presently not a member of any vox boxes.');
  $handler->override_option('items_per_page', 50);
  $handler->override_option('use_pager', '1');
  $handler->override_option('use_more', 1);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'override' => 1,
    'order' => 'asc',
    'columns' => array(
      'title' => 'title',
      'name' => 'name',
      'managelink' => 'managelink',
    ),
    'info' => array(
      'title' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'managelink' => array(
        'separator' => '',
      ),
    ),
    'default' => 'title',
  ));
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->override_option('path', 'og/my');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'My groups',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('fields', array(
    'title' => array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'label' => 'Group',
      'relationship' => 'none',
      'link_to_node' => 1,
    ),
    'post_count_new' => array(
      'label' => 'New',
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'post_count_new',
      'table' => 'og',
      'field' => 'post_count_new',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'title' => array(
      'order' => 'ASC',
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('use_pager', '0');
  $handler->override_option('block_description', 'My VoxBoxes');
  $handler->override_option('block_caching', -1);
  $handler = $view->new_display('block', 'Text', 'block_2');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 1,
        'text' => '[title].',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 1,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'hide_alter_empty' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'post_count_new' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 1,
        'text' => 'The VoxBox has [post_count_new] posts.',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 1,
      ),
      'empty' => '',
      'hide_empty' => 1,
      'empty_zero' => 0,
      'hide_alter_empty' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'format_plural' => 0,
      'format_plural_singular' => '1 new post.',
      'format_plural_plural' => '@count new posts.',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'post_count_new',
      'table' => 'og',
      'field' => 'post_count_new',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'eid' => array(
      'label' => 'Extension number',
      'alter' => array(
        'alter_text' => 0,
        'text' => '[title] [post_count_new] [eid]',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'hide_alter_empty' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'format_plural' => 0,
      'format_plural_singular' => '1',
      'format_plural_plural' => '@count',
      'prefix' => '',
      'suffix' => '.',
      'exclude' => 0,
      'id' => 'eid',
      'table' => 'voipextension',
      'field' => 'eid',
      'relationship' => 'voipnode',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('style_plugin', 'default');
  $handler->override_option('style_options', array(
    'grouping' => '',
  ));
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  return $views;
}
