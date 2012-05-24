; ------------
; voxbox make
; ------------
; Make file for voxbox distro.

; Core version
; ------------
; Each makefile should begin by declaring the core version of Drupal that all
; projects should be compatible with.
  
core = 6.x
  
; API version
; ------------
; Every makefile needs to declare its Drush Make API version. This version of
; drush make uses API version `2`.
  
api = 2
  
; Core project
; ------------
; In order for your makefile to generate a full Drupal site, you must include
; a core project. This is usually Drupal core, but you can also specify
; alternative core projects like Pressflow. Note that makefiles included with
; install profiles *should not* include a core project.
  
; Drupal 6.x core:
; projects[drupal][version] = 6

; Modules
; --------
projects[admin_menu][version] = 1.8
projects[admin_menu][type] = "module"
projects[admin_menu][subdir] = "contrib"
; tools, helpers, api
projects[ctools][version] = 1.8
projects[ctools][type] = "module"
projects[ctools][subdir] = "contrib"
projects[features][version] = 1.2
projects[features][type] = "module"
projects[features][subdir] = "contrib"
projects[strongarm][version] = 2.1
projects[strongarm][type] = "module"
projects[strongarm][subdir] = "contrib"
projects[autoload][version] = 2.1
projects[autoload][type] = "module"
projects[autoload][subdir] = "contrib"
projects[install_profile_api][version] = 2.2
projects[install_profile_api][type] = "module"
projects[install_profile_api][subdir] = "contrib"
; Token dev version needed to avoid warnings related to
; https://drupal.org/node/1329024
projects[token][type] = "module"
projects[token][download][type] = "git"
projects[token][download][url] = "git://git.drupal.org/project/token.git"
projects[token][download][branch] = "6.x-1.x"
projects[token][subdir] = "contrib"
projects[transliteration][version] = 3.0
projects[transliteration][type] = "module"
projects[transliteration][subdir] = "contrib"
projects[auto_nodetitle][version] = 1.2
projects[auto_nodetitle][type] = "module"
projects[auto_nodetitle][subdir] = "contrib"
; essential contrib for project
projects[views][version] = 2.16
projects[views][type] = "module"
projects[views][subdir] = "contrib"
projects[og][version] = 2.2
projects[og][type] = "module"
projects[og][subdir] = "contrib"
; support contrib
projects[draggableviews][version] = 3.5
projects[draggableviews][type] = "module"
projects[draggableviews][subdir] = "contrib"
; ui improvements
projects[better_formats][version] = 1.2
projects[better_formats][type] = "module"
projects[better_formats][subdir] = "contrib"
projects[vertical_tabs][version] = 1.0-rc2
projects[vertical_tabs][type] = "module"
projects[vertical_tabs][subdir] = "contrib"
; fields
projects[cck][version] = 2.9
projects[cck][type] = "module"
projects[cck][subdir] = "contrib"
projects[filefield][version] = 3.10
projects[filefield][type] = "module"
projects[filefield][subdir] = "contrib"
projects[filefield_paths][version] = 1.4
projects[filefield_paths][type] = "module"
projects[filefield_paths][subdir] = "contrib"
projects[audiofield][version] = 1.0
projects[audiofield][type] = "module"
projects[audiofield][subdir] = "contrib"
; Use dev for https://drupal.org/node/1442402 load API even without hook_init().
projects[audiorecorderfield][type] = "module"
projects[audiorecorderfield][download][type] = "git"
projects[audiorecorderfield][download][url] = "git://git.drupal.org/project/audiorecorderfield.git"
projects[audiorecorderfield][download][branch] = "6.x-1.x"
projects[audiorecorderfield][subdir] = "contrib"
;
projects[wysiwyg][version] = 2.4
projects[wysiwyg][type] = "module"
projects[wysiwyg][subdir] = "contrib"
; voip modules
projects[voipdrupal][type] = "module"
projects[voipdrupal][download][type] = "git"
projects[voipdrupal][download][url] = "git://git.drupal.org/project/voipdrupal.git"
projects[voipdrupal][download][branch] = "6.x-1.x"
projects[voipdrupal][subdir] = "contrib"
projects[voipnumber][type] = "module"
projects[voipnumber][download][type] = "git"
projects[voipnumber][download][url] = "git://git.drupal.org/project/voipnumber.git"
projects[voipnumber][download][branch] = "6.x-1.x"
projects[voipnumber][subdir] = "contrib"
projects[voipnode][type] = "module"
projects[voipnode][download][type] = "git"
projects[voipnode][download][url] = "git://git.drupal.org/project/voipnode.git"
projects[voipnode][download][branch] = "6.x-1.x"
projects[voipnode][subdir] = "contrib"
projects[voipextension][type] = "module"
projects[voipextension][download][type] = "git"
projects[voipextension][download][url] = "git://git.drupal.org/project/voipextension.git"
projects[voipextension][download][branch] = "6.x-1.x"
projects[voipextension][subdir] = "contrib"
projects[voicemail][type] = "module"
projects[voicemail][download][type] = "git"
projects[voicemail][download][url] = "git://git.drupal.org/project/voicemail.git"
projects[voicemail][download][branch] = "6.x-1.x"
projects[voicemail][subdir] = "contrib"
projects[voipviews][type] = "module"
projects[voipviews][download][type] = "git"
projects[voipviews][download][url] = "git://git.drupal.org/project/voipviews.git"
projects[voipviews][download][branch] = "6.x-2.x"
projects[voipviews][subdir] = "contrib"
projects[voipusernumber][type] = "module"
projects[voipusernumber][download][type] = "git"
projects[voipusernumber][download][url] = "git://git.drupal.org/project/voipusernumber.git"
projects[voipusernumber][download][branch] = "6.x-1.x"
projects[voipusernumber][subdir] = "contrib"

; Notifications
; Messaging needs a token patch, testing before putting into d.o issue queue.
projects[messaging][subdir] = "contrib"
projects[messaging][download][type] = "git"
projects[messaging][download][url] = "git://git.drupal.org/project/messaging"
projects[messaging][download][branch] = "6.x-2.x"
projects[messaging][patch][] = "http://iskra.net/patches/58-1-messaging-clear_tokens.patch"
projects[notifications][subdir] = "contrib"
projects[notifications][version] = 2.3
; temporarily using git dev version of messaging_voip
projects[messaging_voip][type] = "module"
projects[messaging_voip][download][type] = "git"
projects[messaging_voip][download][url] = "git://git.iskra.net/drupal/contrib/messaging_voip.git"
projects[messaging_voip][download][branch] = "6.x-1.x-sms_and_pull"
projects[messaging_voip][subdir] = "contrib"
; presently a dependency for messaging_voip
projects[job_scheduler][subdir] = "contrib"

; Themes
; --------
projects[rubik][version] = 3.0-beta2
projects[rubik][type] = "theme"
projects[tao][version] = 3.2
projects[tao][type] = "theme"
projects[zen][version] = 2.1
projects[zen][type] = "theme"

; Libraries
; ---------
; wysiwyg
libraries[ckeditor][type] = "libraries"
libraries[ckeditor][download][type] = "file"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.2/ckeditor_3.6.2.tar.gz"
; audiofield
libraries[audio_player][type] = "libraries"
libraries[audio_player][download][type] = "file"
libraries[audio_player][download][url] = "http://wpaudioplayer.com/wp-content/downloads/audio-player-standalone.zip"
libraries[audio_player][destination] = "libraries/audio_players"
libraries[audio_player][directory_name] = "audio-player"
; audiorecorderfield
; http://github.com/jwagener/recorder.js
;libraries[audiorecorderfield][download][type] = "get"
;libraries[audiorecorderfield][download][url] = "http://github.com/jwagener/recorder.js/raw/881498c1b8dbb8b10bc480be6fbad8b723fb1895/recorder.swf"
;libraries[audiorecorderfield][destination] = "modules/contrib/audiorecorderfield"
;libraries[audiorecorderfield][directory_name] = "recorders"
