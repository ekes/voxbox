<?php

/**
 * Implementation of hook_views_default_views().
 */
function voxbox_og_views_default_views() {
  $views = array();

  // Exported view: og_ghp_ron_voip
  $view = new view;
  $view->name = 'og_ghp_ron_voip';
  $view->description = 'OG: Group home page - River of news. VoIP';
  $view->tag = 'og';
  $view->base_table = 'node';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
    ),
  ));
  $handler->override_option('sorts', array(
    'sticky' => array(
      'id' => 'sticky',
      'table' => 'node',
      'field' => 'sticky',
      'order' => 'DESC',
      'relationship' => 'none',
    ),
    'created' => array(
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'order' => 'DESC',
      'granularity' => 'second',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'group_nid' => array(
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(
        'count' => TRUE,
        'override' => FALSE,
        'items_per_page' => 25,
      ),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '%1',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'og_group_types',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'add_table' => 0,
      'relationship' => 'none',
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'poll' => 0,
        'book' => 0,
        'group1' => 0,
        'group2' => 0,
        'page' => 0,
        'story' => 0,
      ),
      'validate_argument_php' => '',
      'require_value' => 0,
      'reduce_duplicates' => 0,
      'default_argument_user' => 0,
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
      ),
      'validate_argument_type' => 'tid',
      'not' => 0,
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
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('empty', 'There are presently no announcements for this Voxbox.');
  $handler->override_option('empty_format', 1);
  $handler->override_option('items_per_page', 20);
  $handler->override_option('use_pager', '1');
  $handler->override_option('distinct', 0);
  $handler->override_option('style_options', NULL);
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'teaser' => 1,
    'links' => 1,
  ));
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->override_option('style_plugin', 'rss');
  $handler->override_option('style_options', array(
    'mission_description' => 0,
    'description' => 'rss desc',
  ));
  $handler->override_option('row_plugin', 'node_rss');
  $handler->override_option('row_options', array(
    'item_length' => 'default',
  ));
  $handler->override_option('path', 'not_used');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array(
    'default' => 0,
  ));
  $handler->override_option('sitename_title', FALSE);
  $handler = $view->new_display('voipviews', 'VoIP', 'voipviews_1');
  $handler->override_option('fields', array(
    'nid' => array(
      'label' => 'Nid',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
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
      'hide_alter_empty' => 1,
      'link_to_node' => 0,
      'exclude' => 1,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
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
      'hide_alter_empty' => 1,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'ivr_next_row' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => FALSE,
        'text' => '',
        'make_link' => FALSE,
        'path' => '',
        'absolute' => '',
        'alt' => '',
        'rel' => '',
        'link_class' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'trim' => FALSE,
        'max_length' => '',
        'word_boundary' => TRUE,
        'ellipsis' => TRUE,
        'strip_tags' => TRUE,
        'html' => FALSE,
      ),
      'empty' => '',
      'hide_empty' => NULL,
      'empty_zero' => NULL,
      'hide_alter_empty' => 1,
      'exclude' => 0,
      'id' => 'ivr_next_row',
      'table' => 'voipviews',
      'field' => 'ivr_next_row',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'gosub' => array(
      'gosub_script' => 'voxbox_announcements_node_script',
      'gosub_params' => '{ "nid" : "[nid]"}',
      'exclude' => '',
      'id' => 'gosub',
      'table' => 'voipviews',
      'field' => 'gosub',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'ivr_return' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => FALSE,
        'text' => '',
        'make_link' => FALSE,
        'path' => '',
        'absolute' => '',
        'alt' => '',
        'rel' => '',
        'link_class' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'trim' => FALSE,
        'max_length' => '',
        'word_boundary' => TRUE,
        'ellipsis' => TRUE,
        'strip_tags' => TRUE,
        'html' => FALSE,
      ),
      'empty' => '',
      'hide_empty' => NULL,
      'empty_zero' => NULL,
      'hide_alter_empty' => 1,
      'exclude' => 0,
      'id' => 'ivr_return',
      'table' => 'voipviews',
      'field' => 'ivr_return',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'gosub_1' => array(
      'gosub_script' => 'voicemail_node_basic',
      'gosub_params' => '{"nid" : "[nid]"}',
      'exclude' => '',
      'id' => 'gosub_1',
      'table' => 'voipviews',
      'field' => 'gosub',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('empty_format', 0);
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_plugin', 'voipviews_list');
  $handler->override_option('style_options', array());
  $handler->override_option('row_plugin', 'voipviews_row_ivr');
  $handler->override_option('row_options', array(
    'ivr_prompt_intro' => '',
    'ivr_invalid_msg' => 'Invalid option selected.',
    'ivr_no_input_msg' => 'Invalid option selected.',
    'ivr_max_attempts' => '3',
    'ivr_timeout' => '5',
    'ivr_options' => array(
      'title' => '',
      'ivr_next_row' => '2',
      'gosub' => '1',
      'ivr_return' => '#',
      'gosub_1' => '*',
    ),
    'ivr_prompt' => array(
      '\\0' => '',
      '\\1' => 'To hear more details press 1.',
      '\\2' => 'To go to the next announcement press 2.',
      '\\3' => '',
      '\\4' => '',
      '\\5' => '',
      '\\6' => '',
      '\\7' => '',
      '\\8' => '',
      '\\9' => '',
      '\\*' => '',
      '\\#' => 'To return to the previous menu press #.',
    ),
    'ivr_notfirst' => array(
      '\\0' => 0,
      '\\1' => 0,
      '\\2' => 0,
      '\\3' => 0,
      '\\4' => 0,
      '\\5' => 0,
      '\\6' => 0,
      '\\7' => 0,
      '\\8' => 0,
      '\\9' => 0,
      '\\*' => 0,
      '\\#' => 0,
    ),
    'ivr_notlast' => array(
      '\\0' => 0,
      '\\1' => 0,
      '\\2' => 1,
      '\\3' => 0,
      '\\4' => 0,
      '\\5' => 0,
      '\\6' => 0,
      '\\7' => 0,
      '\\8' => 0,
      '\\9' => 0,
      '\\*' => 0,
      '\\#' => 0,
    ),
  ));
  $handler->override_option('voipextension_enable', 0);
  $handler->override_option('voipextension_directory_type', 1);
  $handler->override_option('voipextension_title', '');
  $handler->override_option('voipextension_description', '');

  $views[$view->name] = $view;

  return $views;
}
