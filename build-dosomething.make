api = 2
core = 7.x

; Include the definition for how to build Drupal core directly:
includes[] = drupal-org-core.make

; Dosomething Profile
projects[dosomething][type] = profile
projects[dosomething][download][type] = git
projects[dosomething][download][url] = "git@github.com:DoSomething/dosomething.git"

; Paraneue subtheme
projects[dosomething][type] = theme
projects[dosomething][download][type] = git
projects[dosomething][download][url] = "git@github.com:DoSomething/paraneue.git"