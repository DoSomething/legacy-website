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

; Features
projects[features] = "2.0-rc5"
projects[features][subdir] = "contrib"

; Google Analytics
projects[google_analytics] = "1.3"
projects[google_analytics][subdir] = "contrib"

; Libraries
projects[libraries] = "2.1"
projects[libraries][subdir] = "contrib"

; MailSystem
projects[mailsystem] = "2.34"
projects[mailsystem][subdir] = "contrib"

; Mandrill
projects[mandrill] = "1.4"
projects[mandrill][subdir] = "contrib"

; Metatag
projects[metatag] = "1.0-beta7"
projects[metatag][subdir] = "contrib"

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

; Views
projects[views] = "3.7"
projects[views][subdir] = "contrib"

; WYSIWYG
projects[wysiwyg] = "2.2"
projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][patch][] = "https://drupal.org/files/wysiwyg-support_v4_ckeditor-1853550-46.patch"

; GIT PROJECTS

; Conductor
projects[conductor][type] = module
projects[conductor][download][type] = git
projects[conductor][download][url] = "https://github.com/DoSomething/Conductor.git"
projects[conductor][download][revision] = "ac9956d"
projects[conductor][subdir] = "contrib"

; Conductor SMS
projects[conductor_sms][type] = module
projects[conductor_sms][download][type] = git
projects[conductor_sms][download][url] = "https://github.com/DoSomething/conductor_sms.git"
projects[conductor_sms][download][revision] = "f76470d"
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
projects[paraneue][type] = theme
projects[paraneue][download][type] = git
projects[paraneue][download][url] = "git@github.com:DoSomething/paraneue.git"
projects[paraneue][subdir] = "dosomething"

; LIBRARIES

; CKEditor
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.2.2/ckeditor_4.2.2_standard.tar.gz"

; DSAPI PHP Library
libraries[dsapi][download][type] = "git"
libraries[dsapi][download][url] = "git@github.com:DoSomething/dsapi-php.git"

; NEUE
libraries[neue][download][type] = "git"
libraries[neue][download][url] = "git@github.com:DoSomething/ds-neue.git"
