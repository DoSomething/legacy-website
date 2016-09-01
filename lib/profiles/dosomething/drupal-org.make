; Contrib modules, themes and libraries

api = 2
core = 7.x

; MODULES

; Address Field
projects[addressfield][version] = "1.0-beta5"
projects[addressfield][subdir] = "contrib"
; Allows addressfield as form element: https://drupal.org/node/970048
projects[addressfield][patch][] = https://drupal.org/files/addressfield-element_info-970048-71.patch

; Admin menu
projects[admin_menu][version] = "3.0-rc5"
projects[admin_menu][subdir] = "contrib"

; Apachesolr
projects[apachesolr][version] = "1.8"
projects[apachesolr][subdir] = "contrib"

; Apachesolr Configen
projects[apachesolr_confgen][version] = "1.1"
projects[apachesolr_confgen][subdir] = "contrib"

; Apachesolr Multilingual
projects[apachesolr_multilingual][version] = "1.3"
projects[apachesolr_multilingual][subdir] = "contrib"
projects[apachesolr_multilingual][patch][] = https://www.drupal.org/files/issues/apachesolr_multilingual-unpub-translations-2616388-1.patch

; Apachesolr Views
projects[apachesolr_views][version] = "1.0-beta2"
projects[apachesolr_views][subdir] = "contrib"

; Blockreference
projects[blockreference][version] = "1.16"
projects[blockreference][subdir] = "contrib"

; CDN
projects[cdn][version] = "2.6"
projects[cdn][subdir] = "contrib"

; Ctools
projects[ctools][version] = "1.8"
projects[ctools][subdir] = "contrib"

; Date
projects[date][version] = "2.8"
projects[date][subdir] = "contrib"

; Diff
projects[diff][version] = "3.2"
projects[diff][subdir] = "contrib"

; Entity
projects[entity][version] = "1.6"
projects[entity][subdir] = "contrib"

; Entity Autocomplete
projects[entity_autocomplete][version] = "1.0-beta3"
projects[entity_autocomplete][subdir] = "contrib"

; Entity Translation
; Updated to dev to be compatible with latest field_collection patch.
; Patch adds the status of the actual node, changes header to from "STATUS" to "TRANSLATION STATUS" for more clarity, and changes TRANSLATION STATUS options to Published, Unpublished, or Not translated.
; See https://github.com/DoSomething/phoenix/issues/5876 and https://www.drupal.org/node/2702055
; Dev branch used: 2015-Aug-16
projects[entity_translation][version] = "1.0-beta5"
projects[entity_translation][subdir] = "contrib"
projects[entity_translation][patch][] = "https://www.drupal.org/files/issues/entity_translation-adds_node_status_changes_to_unpublished_and_adds_translation_status_to_header-2702055-3-7.43.patch"

; Entity Connect
projects[entityconnect][version] = "1.0-rc1"
projects[entityconnect][subdir] = "contrib"

; Entity Reference
projects[entityreference][version] = "1.1"
projects[entityreference][subdir] = "contrib"

; Features
projects[features][version] = "2.9"
projects[features][subdir] = "contrib"

; Field Collection
projects[field_collection][version] = "1.0-beta11"
projects[field_collection][subdir] = "contrib"
; See https://www.drupal.org/node/1344672?page=1#comment-10320327
projects[field_collection][patch][] = "https://www.drupal.org/files/issues/field_collection-add_entity_translation_support-1344672-459.patch"

; Field Group
projects[field_group][version] = "1.5"
projects[field_group][subdir] = "contrib"

; File Entity
projects[file_entity][version] = "2.0-alpha3"
projects[file_entity][subdir] = "contrib"

; Google Analytics
projects[google_analytics][version] = "2.3"
projects[google_analytics][subdir] = "contrib"

; Http Client
projects[http_client][version] = "2.4"
projects[http_client][subdir] = "contrib"

; ImageCache Actions
projects[imagecache_actions][version] = "1.5"
projects[imagecache_actions][subdir] = "contrib"

; Internationalization (required for Sitemap, among others)
projects[i18n][version] = "1.11"
projects[i18n][subdir] = "contrib"

; Localization update
projects[l10n_update][version] = "1.0"
projects[l10n_update][subdir] = "contrib"

; Libraries
projects[libraries][version] = "2.2"
projects[libraries][subdir] = "contrib"

; Link
projects[link][version] = "1.2"
projects[link][subdir] = "contrib"

; Markdown
projects[markdown][version] = "1.2"
projects[markdown][subdir] = "contrib"

; Metatag
projects[metatag][version] = "1.4"
projects[metatag][subdir] = "contrib"

; Mobile Commons
projects[mobilecommons][version] = "1.1"
projects[mobilecommons][subdir] = "contrib"

; Module Filter
projects[module_filter][version] = "2.0-alpha2"
projects[module_filter][subdir] = "contrib"

; New Relic
projects[new_relic_rpm][version] = "1.0-alpha2"
projects[new_relic_rpm][subdir] = "contrib"

; OAuth
projects[oauth][version] = "3.2"
projects[oauth][subdir] = "contrib"
; See https://www.drupal.org/node/2328685
projects[oauth][patch][] = "https://www.drupal.org/files/issues/oauth-OAuth-PHP-library-Authorization-Header-parameters-separator-2328685-1.patch"

; Optimizely
projects[optimizely][version] = "2.18"
projects[optimizely][subdir] = "contrib"

; Pathauto
projects[pathauto][version] = "1.2"
projects[pathauto][subdir] = "contrib"

; Pathauto i18n
projects[pathauto_i18n][version] = "1.4"
projects[pathauto_i18n][subdir] = "contrib"

; POEditor
projects[poeditor][version] = "1.3"
projects[poeditor][subdir] = "contrib"

; POTX (Translation template extractor)
projects[potx][version] = "1.0"
projects[potx][subdir] = "contrib"

; Redirect
projects[redirect][version] = "1.0-rc1"
projects[redirect][subdir] = "contrib"

; Redis
projects[redis][version] = "2.6"
projects[redis][subdir] = "contrib"

; Security Kit
projects[seckit][subdir] = "contrib"
projects[seckit][version] = "1.9"

; Services
projects[services][version] = "3.12"
projects[services][subdir] = "contrib"

; Stathat
projects[stathat][version] = "1.0"
projects[stathat][subdir] = "contrib"

; String Overrides
projects[stringoverrides][version] = "1.8"
projects[stringoverrides][subdir] = "contrib"

; Strongarm
projects[strongarm][version] = "2.0"
projects[strongarm][subdir] = "contrib"

; Taxonomy Access Fix
projects[taxonomy_access_fix][version] = "2.1"
projects[taxonomy_access_fix][subdir] = "contrib"

; Title
; Dev branch used: 2015-Mar-23
; Fixes a bug with table layout on content type manage fields page.
projects[title][version] = "1.x-dev"
projects[title][subdir] = "contrib"
; Fixes #4973: title translation overwrites original title.
; See https://www.drupal.org/node/1991988.
projects[title][patch][] = https://www.drupal.org/files/title_1991988-10.patch

; Token
projects[token][version] = "1.5"
projects[token][subdir] = "contrib"

; UUID
projects[uuid][version] = "1.0-alpha5"
projects[uuid][subdir] = "contrib"

; UUID Features
projects[uuid_features][version] = "1.0-alpha4"
projects[uuid_features][subdir] = "contrib"

; Variable
projects[variable][version] = "2.5"
projects[variable][subdir] = "contrib"

; Varnish
projects[varnish][version] = "1.0-beta2"
projects[varnish][subdir] = "contrib"

; View Unpublished
projects[view_unpublished][version] = "1.2"
projects[view_unpublished][subdir] = "contrib"

; Views
projects[views][version] = "3.14"
projects[views][subdir] = "contrib"

; Views Data Export
projects[views_data_export][version] = "3.0-beta8"
projects[views_data_export][subdir] = "contrib"

; Views Grouping Row Limit
projects[views_limit_grouping][version] = "1.x-dev"
projects[views_limit_grouping][subdir] = "contrib"

; XML Sitemap
projects[xmlsitemap][version] = "2.3"
projects[xmlsitemap][subdir] = "contrib"


; GIT PROJECTS

; External Auth
projects[external_auth][type] = "module"
projects[external_auth][download][type] = "git"
projects[external_auth][download][url] = "https://github.com/DoSomething/drupal-external-auth.git"
projects[external_auth][download][revision] = "c6bda54"
projects[external_auth][subdir] = "contrib"

; Message Broker Producer
projects[message_broker_producer][type] = "module"
projects[message_broker_producer][download][type] = "git"
projects[message_broker_producer][download][url] = "https://github.com/DoSomething/message_broker_producer.git"
projects[message_broker_producer][download][tag] = "0.2.5"
projects[message_broker_producer][subdir] = "contrib"

; DEVELOPMENT

; Devel
projects[devel][version] = "1.4"
projects[devel][subdir] = "contrib"

; Coder
projects[coder][version] = "2.6"
projects[coder][subdir] = "contrib"

; Stage File Proxy
projects[stage_file_proxy][version] = "1.6"
projects[stage_file_proxy][subdir] = "contrib"


; LIBRARIES

; Message Broker PHP Library
libraries[messagebroker-phplib][download][type] = "git"
libraries[messagebroker-phplib][download][url] = "https://github.com/DoSomething/messagebroker-phplib.git"
libraries[messagebroker-phplib][download][tag] = "0.2.9"

; Message Broker Configuration
libraries[messagebroker-config][download][type] = "git"
libraries[messagebroker-config][download][url] = "https://github.com/DoSomething/messagebroker-config.git"

; Mobile Commons PHP
libraries[mobilecommons-php][download][type] = "git"
libraries[mobilecommons-php][download][url] = "https://github.com/DoSomething/mobilecommons-php.git"

; Predis
libraries[predis][download][type] = "git"
libraries[predis][download][url] = "https://github.com/nrk/predis.git"
; Pin to 0.8 release, which still has the lib directory.
libraries[predis][download][revision] = "4123fcd85d61354c6c9900db76c9597dbd129bf6"

; Stathat
; @TODO: We should use our Stathat-PHP library here! :)
libraries[stathat][download][type] = "get"
libraries[stathat][download][url] = "https://www.stathat.com/downloads/stathat.php"
