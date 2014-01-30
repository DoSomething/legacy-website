; Contrib modules, themes and libraries

api = 2
core = 7.x

; MODULES

; Admin menu
projects[admin_menu] = "3.0-rc4"
projects[admin_menu][subdir] = "contrib"

; Ctools
projects[ctools] = "1.3"
projects[ctools][subdir] = "contrib"

; Date
projects[date] = "2.6"
projects[date][subdir] = "contrib"

; Diff
projects[diff] = "3.2"
projects[diff][subdir] = "contrib"

; Entity
projects[entity] = "1.2"
projects[entity][subdir] = "contrib"

; Entity Reference
projects[entityreference] = "1.1"
projects[entityreference][subdir] = "contrib"

; Features
projects[features] = "2.0-rc5"
projects[features][subdir] = "contrib"

; Field Collection
projects[field_collection] = "1.0-beta5"
projects[field_collection][subdir] = "contrib"

; Field Group
projects[field_group] = "1.3"
projects[field_group][subdir] = "contrib"

; Google Analytics
projects[google_analytics] = "1.3"
projects[google_analytics][subdir] = "contrib"

; Libraries
projects[libraries] = "2.1"
projects[libraries][subdir] = "contrib"

; Link
projects[link] = "1.2"
projects[link][subdir] = "contrib"

; MailSystem
projects[mailsystem] = "2.34"
projects[mailsystem][subdir] = "contrib"

; Mandrill
projects[mandrill] = "1.4"
projects[mandrill][subdir] = "contrib"

; Markdown
projects[markdown] = "1.2"
projects[markdown][subdir] = "contrib"

; Metatag
projects[metatag] = "1.0-beta9"
projects[metatag][subdir] = "contrib"

; Mobile Commons
projects[mobilecommons] = "1.0"
projects[mobilecommons][subdir] = "contrib"

; Module Filter
projects[module_filter] = "1.8"
projects[module_filter][subdir] = "contrib"

; Optimizely
projects[optimizely] = "2.14"
projects[optimizely][subdir] = "contrib"

; Pathauto
projects[pathauto] = "1.2"
projects[pathauto][subdir] = "contrib"

; Secure Pages
projects[securepages] = "1.0-beta2"
projects[securepages][subdir] "contrib"

; Strongarm
projects[strongarm] = "2.0"
projects[strongarm][subdir] = "contrib"

; Token
projects[token] = "1.5"
projects[token][subdir] = "contrib"

; UUID
projects[uuid] = "1.0-alpha"
projects[uuid][subdir] = "contrib"

; UUID Features
projects[uuid_features] = "1.0-alpha3"
projects[uuid_features][subdir] = "contrib"

; Varnish
projects[varnish] = "1.0-beta2"
projects[varnish][subdir] = "contrib"

; View Unpublished
projects[view_unpublished] = "1.1"
projects[view_unpublished][subdir] = "contrib"
projects[view_unpublished][patch][] = "https://drupal.org/files/view_unpublished_content_admin-1192074-60.patch"

; Views
projects[views] = "3.7"
projects[views][subdir] = "contrib"

; WYSIWYG
projects[wysiwyg] = "2.2"
projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][patch][] = "https://drupal.org/files/wysiwyg-support_v4_ckeditor-1853550-46.patch"

; GIT PROJECTS

; Conductor
projects[conductor][type] = "module"
projects[conductor][download][type] = "git"
projects[conductor][download][url] = "https://github.com/DoSomething/Conductor.git"
projects[conductor][subdir] = "contrib"

; Conductor SMS
projects[conductor_sms][type] = "module"
projects[conductor_sms][download][type] = "git"
projects[conductor_sms][download][url] = "https://github.com/DoSomething/conductor_sms.git"
projects[conductor_sms][subdir] = "contrib"

; DEVELOPMENT

; Devel
projects[devel] = "1.3"
projects[devel][subdir] = "contrib"

; Environment Indicator
projects[environment_indicator] = "2.0"
projects[environment_indicator][subdir] = "contrib"

; Coder
projects[coder] = "2.0"
projects[coder][subdir] = "contrib"

; THEMES

; Paraneue
projects[paraneue][type] = "theme"
projects[paraneue][download][type] = "git"
projects[paraneue][download][url] = "git@github.com:DoSomething/paraneue.git"
projects[paraneue][subdir] = "dosomething"
projects[paraneue][options][working-copy] = TRUE

; LIBRARIES

; CKEditor
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.2.2/ckeditor_4.2.2_standard.tar.gz"

; Mobile Commons PHP
libraries[mobilecommons_php][download][type] = "git"
libraries[mobilecommons_php][download][url] = "https://github.com/DoSomething/mobilecommons-php.git"

; DSAPI PHP Library
;libraries[dsapi][download][type] = "git"
;libraries[dsapi][download][url] = "git@github.com:DoSomething/dsapi-php.git"

