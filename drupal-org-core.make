; Include Drupal Core and any core patches.

api = 2
core = 7.x

; Drupal Core
projects[drupal][type] = core
projects[drupal][version] = 7.31

; Patches for Secure Pages module
; See install steps at https://drupal.org/project/securepages
projects[drupal][patch][] = "https://drupal.org/files/issues/471970_0.patch"
projects[drupal][patch][] = "https://drupal.org/files/drupal-https-only-961508-23-32.patch"
